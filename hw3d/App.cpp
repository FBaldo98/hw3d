#include "App.h"

App::App()
    : wnd(800, 600, L"Baldo Chronicles")
{
}

int App::Go()
{
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        DoFrame();
    }

    if (gResult == -1)
    {
        throw BHWND_LAST_EXCEPT();
    }

    return static_cast<int>(msg.wParam);
}

void App::DoFrame()
{

}
