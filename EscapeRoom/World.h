#pragma once
#include <windows.h>
#include <string>
#define _WIN32_WINNT 0x0500

using namespace std;

namespace Level
{
	class GameMap
	{
	public:
		void FullScreen();
		void GetScreenSize(COORD screenSize);
		void SetHeight();
		void TextOnCenter();
		void SetSpike();
		void SetKey();
		void DrawGameMap();
		void PlayGame();
		void PlayerAction();
		void CheckInput();
		void ReloadLevel();
	};
}