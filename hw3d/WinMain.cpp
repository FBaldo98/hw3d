#include "Window.h"

int CALLBACK WinMain(
	_In_ HINSTANCE		hInstance,
	_In_opt_ HINSTANCE	hPrevInstance,
	_In_ LPSTR			plCmdLine,
	_In_ int			nCmdShow)
{
	try
	{
		Window wnd(800, 300, L"Test Window");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (gResult == -1)
		{
			return -1;
		}

		return static_cast<int>(msg.wParam);
	}
	catch (const BaldoException& e)
	{
		MessageBox(nullptr, reinterpret_cast<LPCWSTR>(e.what()), reinterpret_cast<LPCWSTR>(e.GetType()), MB_OK | MB_ICONEXCLAMATION);
	}
	catch(const std::exception & e)
	{
		MessageBox(nullptr, reinterpret_cast<LPCWSTR>(e.what()), L"Standard exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, L"No details available", L"Standard exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}