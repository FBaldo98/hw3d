#include <Windows.h>
#include <sstream>
#include "WindowsMessageMap.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	static WindowsMessageMap mm;
	OutputDebugStringA(mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		// Doesn't differentiate between upper and lowercase
		if (wParam == 'F') {
			SetWindowTextA(hWnd, "Respects");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F') {
			SetWindowTextA(hWnd, "Dangerfield");
		}
		break;
	case WM_CHAR:
	{
		// Used for text input. Differentiate between upper and lower case
		// It is posted by TranslateMessage
		static std::string title;
		title.push_back((char)wParam);
		SetWindowTextA(hWnd, title.c_str());
	}
		break;
	case WM_LBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << "(" << pt.x << ";" << pt.y << ")";
		SetWindowTextA(hWnd, oss.str().c_str());
	}
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	_In_ HINSTANCE		hInstance,
	_In_opt_ HINSTANCE	hPrevInstance,
	_In_ LPSTR			plCmdLine,
	_In_ int			nCmdShow)
{

	const auto pClassName = L"hw3dwnd";

	// Create window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hIcon = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	// Register window class
	RegisterClassEx(&wc);

	// Create the window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		L"Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr,
		hInstance,
		nullptr
	);

	// Show the window
	ShowWindow(hWnd, SW_SHOW);

	// Message handling
	MSG msg;
	BOOL gResult;
	// Get message returns 0 when it receives a WM_QUIT message
	// return < 0 if there is a error
	while ( (gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {

		TranslateMessage(&msg);
		// Send message to the WndProc function
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else 
	{
		// wParam stores the PostQuitMessage exit code
		return msg.wParam;
	}

	return 0;
}