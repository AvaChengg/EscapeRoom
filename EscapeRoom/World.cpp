#include <iostream>
#include "world.h"

using namespace std;
using namespace Level;

const int WIDTH = 30;
const int HEIGHT = 30;
int xPos = 28;
int yPos = 2;
int xPrePos = 0;
int yPrePos = 0;
string player = { "0" };
string spike = { "#" };
string key = { "1" };
string input;
COORD screenSize;

string path[WIDTH][HEIGHT] =
{
    { "שÝ", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש","שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש","שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שß" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שר", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "שר" },
    { "שד", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש","שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש","שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שש", "שו" },
};

// set full screen
void GameMap::FullScreen()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

// store the console screen info and gets the size of the screen
void GameMap::GetScreenSize(COORD size)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO screenInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(console, screenInfo);
    size = screenInfo->dwSize;
    screenSize = size;
}

// set text in the upper middle
void GameMap::TextOnCenter()
{
    string text = "";
    GetScreenSize(screenSize);

    if (screenSize.X > text.size())
    {
        int newPosition = ((screenSize.X - text.size()) / 2 - WIDTH);
        for (int j = 0; j < newPosition; j++) cout << " ";
    }
    cout << text;
}

// set heigh
void GameMap::SetHeight()
{
    string text = " ";
    GetScreenSize(screenSize);

    for (int i = 0; i < WIDTH - 15; i++)
    {
        if (screenSize.X > text.size())
        {
            int newPosition = ((screenSize.X - text.size()) / 2);
            for (int j = 0; j < newPosition; j++) cout << " ";
        }
    }
    cout << text << endl;
}

void GameMap::SetSpike()
{
    int xRandom = rand() % WIDTH;
    int yRandom = rand() % HEIGHT;

    if ((path[xRandom][yRandom] != "שש") && (path[xRandom][yRandom] != "שר"))
    {
        if (path[xRandom][yRandom] != "1")
        {
            path[xRandom][yRandom] = spike;
        }
    }
}

void GameMap::SetKey()
{
    int xRandom = rand() % WIDTH;
    int yRandom = rand() % HEIGHT;

    path[xRandom][yRandom] = key;
}

void GameMap::DrawGameMap()
{
    path[xPos][yPos] = player;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < WIDTH; i++)
    {
        GameMap::TextOnCenter();
        for (int j = 0; j < HEIGHT; j++)
        {
            if (path[i][j] == "#")
            {
                // set text to red
                SetConsoleTextAttribute(h, 4);
            }
            else if (path[i][j] == "1")
            {
                // set text to green
                SetConsoleTextAttribute(h, 2);
            }
            else
            {
                // set text to white
                SetConsoleTextAttribute(h, 15);
            }
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

void GameMap::ReloadLevel()
{
    GameMap::SetHeight();
    cout << "                                                                                                          Press W, A, S, D to move" << endl;
    GameMap::SetHeight();
    GameMap::SetSpike();
    GameMap::DrawGameMap();
    GameMap::PlayerAction();
}

void GameMap::CheckInput()
{
    string space = " ";

    if ((input == "a" || input == "A") && path[xPos][yPos - 1] != "שר")
    {
        yPos--;
        path[xPrePos][yPrePos] = space;
    }
    else if ((input == "d" || input == "D") && path[xPos][yPos + 1] != "שר")
    {
        yPos++;
        path[xPrePos][yPrePos] = space;
    }
    else if ((input == "w" || input == "W") && path[xPos - 1][yPos] != "שש")
    {
        xPos--;
        path[xPrePos][yPrePos] = space;
    }
    else if ((input == "s" || input == "S") && path[xPos + 1][yPos] != "שש")
    {
        xPos++;
        path[xPrePos][yPrePos] = space;
    }
    else
    {
        cout << " Press W, A, S, D to Move !!!!!" << endl;
    }
    system("cls");
}

void GameMap::PlayerAction()
{
    cout << endl;
    cout << "                                                                                         Action: ";
    cin >> input;

    xPrePos = xPos;
    yPrePos = yPos;

}

void GameMap::PlayGame()
{
    while (input != "q")
    {
        CheckInput();
        ReloadLevel();
    }
}

