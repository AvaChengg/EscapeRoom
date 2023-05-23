#include <iostream>
#include "ScreenFormat.h"

using namespace std;

// to set full screen
void ScreenFormat::FullScreen()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

// to set height
void ScreenFormat::SetHeight(string text)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO screenInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(console, screenInfo);
    COORD NewSize = screenInfo->dwSize;
    if (NewSize.X > text.size())
    {
        int newPosition = ((NewSize.X - text.size()) / 2);
        for (int i = 0; i < newPosition; i++) cout << " ";
    }

    cout << text << endl;
}