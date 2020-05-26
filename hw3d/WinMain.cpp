#include <Windows.h>

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		plCmdLine,
	int			nCmdShow)
{

	const auto pClassName = L"hw3dwnd";

	// Create window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
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
	// Get message returns 0 when it receives a WM_QUIT message
	while (GetMessage(&msg, nullptr, 0, 0) > 0) {

		TranslateMessage(&msg);
		// Send message to the WndProc function
		DispatchMessage(&msg);
	}

	return 0;
}