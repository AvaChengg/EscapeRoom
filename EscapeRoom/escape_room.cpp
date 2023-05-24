// EscapeRoom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "screen_format.h"
#include "World.h"
//#include "World.cpp"

//#define KEY_UP 72;
//#define KEY_DOWN 80;
//#define KEY_LEFT 75;
//#define KEY_RIGHT 77;
//#define KEY_X 72;

using namespace std;
using namespace Level;

GameMap gameMap;

void LoadLevel()
{
	gameMap.FullScreen();
	gameMap.SetHeight();
	cout << "                                                                                                          Press W, A, S, D to move" << endl;
	gameMap.SetHeight();
	gameMap.DrawGameMap();
}

int main()
{
	LoadLevel();
	gameMap.PlayGame();
}
