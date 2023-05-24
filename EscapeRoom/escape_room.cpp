// EscapeRoom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "World.h"

using namespace std;
using namespace Level;

GameMap gameMap;

int main()
{
	gameMap.FullScreen();
	gameMap.SetKey();
	gameMap.PlayGame();
}
