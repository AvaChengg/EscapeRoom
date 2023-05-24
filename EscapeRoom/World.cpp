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
string input;
COORD screenSize;

string path[WIDTH][HEIGHT] =
{
    { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��","��", "��", "��", "��", "��", "��", "��", "��", "��", "��","��", "��", "��", "��", "��", "��", "��", "��", "��", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", " "," ", " ", " ", " ", " ", " ", " ", " ", " ", "��" },
    { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��","��", "��", "��", "��", "��", "��", "��", "��", "��", "��","��", "��", "��", "��", "��", "��", "��", "��", "��", "��" },
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

void GameMap::DrawGameMap()
{
    path[xPos][yPos] = player;
    for (int i = 0; i < WIDTH; i++)
    {
        GameMap::TextOnCenter();
        for (int j = 0; j < HEIGHT; j++)
        {
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
    GameMap::DrawGameMap();
    GameMap::PlayerAction();
}

void GameMap::CheckInput()
{
    string space = " ";

    if (input == "a" || "A")
    {
        yPos--;
    }
    else if (input == "d" || "D")
    {
        yPos++;
    }
    else if (input == "w" || "W")
    {
        xPos--;
    }
    else if (input == "s" || "S")
    {
        xPos++;
    }
    else
    {
        cout << " Press W, A, S, D to Move !!!!!" << endl;
    }
    path[xPrePos][yPrePos] = space;
    system("cls");
    ReloadLevel();
}

void GameMap::PlayerAction()
{
    cout << " Action: ";
    cin >> input;

    xPrePos = xPos;
    yPrePos = yPos;

}

void GameMap::PlayGame()
{
    while (input != "q" || "Q")
    {
        CheckInput();
    }
}

