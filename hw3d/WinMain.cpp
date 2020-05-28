#include "App.h"

int CALLBACK WinMain(
	_In_ HINSTANCE		hInstance,
	_In_opt_ HINSTANCE	hPrevInstance,
	_In_ LPSTR			plCmdLine,
	_In_ int			nCmdShow)
{
	try
	{
		return App{}.Go();
	}
	catch (const BaldoException& e)
	{
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch(const std::exception & e)
	{
		MessageBoxA(nullptr, e.what(), "Standard exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBoxA(nullptr, "No details available", "Standard exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}