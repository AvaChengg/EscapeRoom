// EscapeRoom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <windows.h>
#include "ScreenFormat.h"
#include "World.h"

using namespace std;
using namespace Level;

ScreenFormat screenFormat;

int main()
{
	string text = " Hello How are you? ";
	screenFormat.FullScreen();
	screenFormat.SetHeight(text);
}
