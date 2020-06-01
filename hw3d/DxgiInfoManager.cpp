#include "DxgiInfoManager.h"
#include "Window.h"
#include "Graphics.h"
#include <memory>

#pragma comment(lib, "dxguid.lib")

#define GFX_THROW_NOINFO(hrcall) if (FAILED(hr = (hrcall))) throw Graphics::HrException(__LINE__, __FILE__, hr)

DxgiInfoManager::DxgiInfoManager()
{
	// define function signature of DXGIGetDebugInterface
	typedef HRESULT(WINAPI* DXGIGetDebugInterface)(REFIID, void**);

	// load the dll that contains the function DXGIGetDebugInterface
	const auto hModDxgiDebug = LoadLibraryExA("dxgidebug.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
	if (hModDxgiDebug == nullptr) {
		throw BHWND_LAST_EXCEPT();
	}

	// Get address of DXGIGetDebugInterface in dll
	const auto DxgiGetDebugInterface = reinterpret_cast<DXGIGetDebugInterface>(
		reinterpret_cast<void*>(GetProcAddress(hModDxgiDebug, "DXGIGetDebugInterface")));
	if (DxgiGetDebugInterface == nullptr) {
		throw BHWND_LAST_EXCEPT();
	}

	HRESULT hr;
	GFX_THROW_NOINFO(DxgiGetDebugInterface(__uuidof(IDXGIInfoQueue), &pDxgiInfoQueue ) );
}

void DxgiInfoManager::Set() noexcept
{
	// Set the index (next) so that the next call to GetMessages()
	// will only get errors generated after this call
	next = pDxgiInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
}

std::vector<std::string> DxgiInfoManager::GetMessages() const
{
	std::vector<std::string> messages;

	const auto end = pDxgiInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
	for (auto i = next; i < end; i++) {
		HRESULT hr;
		SIZE_T messageLenght;
		// get size of message in bytes
		GFX_THROW_NOINFO(pDxgiInfoQueue->GetMessageW(DXGI_DEBUG_ALL, i, nullptr, &messageLenght));
		// allocate memory for message
		auto bytes = std::make_unique<byte[]>(messageLenght);
		auto pMessage = reinterpret_cast<DXGI_INFO_QUEUE_MESSAGE*>(bytes.get());
		// Get the message and push its description into vector
		GFX_THROW_NOINFO(pDxgiInfoQueue->GetMessageW(DXGI_DEBUG_ALL, i, pMessage, &messageLenght));
		messages.emplace_back(pMessage->pDescription);
	}

	return messages;
}
