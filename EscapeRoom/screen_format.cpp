#include <iostream>
#include "screen_format.h"

using namespace std;

//int width = 10;
//COORD screenSize;
//
//// set full screen
//void ScreenFormat::FullScreen()
//{
//    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
//}
//
//// store the console screen info and gets the size of the screen
//void ScreenFormat::GetScreenSize(COORD size)
//{
//    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//    PCONSOLE_SCREEN_BUFFER_INFO screenInfo = new CONSOLE_SCREEN_BUFFER_INFO();
//    GetConsoleScreenBufferInfo(console, screenInfo);
//    size = screenInfo->dwSize;
//    screenSize = size;
//}
//
//// set text in the upper middle
//void ScreenFormat::TextOnCenter()
//{
//    string text = " Press W, A, S, D to move";
//    GetScreenSize(screenSize);
//
//    for (int i = 0; i < width; i++)
//    {
//        if (screenSize.X > text.size())
//        {
//            int newPosition = ((screenSize.X - text.size()) / 2);
//            for (int j = 0; j < newPosition; j++) cout << " ";
//        }
//    }
//    cout << text << endl;
//}
