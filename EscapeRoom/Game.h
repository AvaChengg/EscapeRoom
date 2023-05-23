#pragma once
#include "World.h"

using namespace std;
using namespace Level;


namespace GameChecker
{
	class Game
	{
	public:
		void StartGame();
		bool EndGame();
		bool Restart();
	};
}
