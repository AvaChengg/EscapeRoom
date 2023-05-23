#pragma once
#include <windows.h>
#define _WIN32_WINNT 0x0500

using namespace std;


class ScreenFormat
{
	// set full screen
public:
	void FullScreen();
	void GetScreenSize(COORD screenSize);
	void TextOnCenter(string text);
};

