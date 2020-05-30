#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
    : wnd(800, 600, L"Baldo Chronicles")
{
}

int App::Go()
{
    while (true) {
        // process all messages pending
        if (const auto ecode = Window::ProcessMessages()) {
            return *ecode;
        }
        DoFrame();
    }

    return -1;
}

void App::DoFrame()
{
    wnd.Gfx().EndFrame();
}
