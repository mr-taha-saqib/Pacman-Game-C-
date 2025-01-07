#include<iostream>
#include<Windows.h>
#include <cstdlib>
#include <time.h>
//#include<bits/stdc++.h>
using namespace std;

const int LEFT = 1;
const int RIGHT = 2;
const int UP = 3;
const int DOWN = 4;

const char WALL_SPACE='#';   //constants
const char EMPTY_SPACE=' ';
const char PACMAN='@';
const char PELLET_SPACE='.';

int direction=LEFT;
int score = 0;


char map[30][30] = 
{
	"############################",    //map
	"#  ....           ###      #",
	"#     .#######  .......  # #",
	"#  #  .#######  .#####.  # #",
	"# .   ..    ..  .. .. .... #",
	"# .   ###  .   .   #       #",
	"# . ####   .   .  ####  .. #",
	"# . ... . .. ...      .... #",
	"############################"
};

struct Player 
{
	int x, y;
	Player()
	{
		x = 2;
		y = 2;
	}
};

void scorekeep(int score)    //Total Score display
{
	cout<<"Score : "<<score<<endl;
}

bool isValidPos(int x, int y) 
{ 
	return (x >= 0 && x < 10 && y >= 0 && y < 30);
}
bool movePlayer(Player &player, int x, int y)  //Movement of player
{
	if (!isValidPos(x, y)) 
	{ 
		return false;
	}
	
	char ch = map[x][y];   //map display
	
	if(ch== WALL_SPACE) 
	{
		return false;
	}
	
	if(ch==PELLET_SPACE)
		score+=10;    //Score
	if (isValidPos(player.x, player.y))     //positions 
	{ 
		map[player.x][player.y] = EMPTY_SPACE;
	}
	player.x = x; player.y = y;
	map[player.x][player.y] = PACMAN;
	
	return true;
}
bool checkWin(int score)  //Win
{
	if(score<500)
		return false;
	else
		return true;
}

void showMap()   //Display of map
{
	for (int x = 0; x < 9; x++) 
	{
		cout << map[x] << endl;
	}
}

void GamePac()
{
	Player player;
	movePlayer(player, 1, 2);
	
	while (true) 
	{
		system("cls");
		showMap();
		scorekeep(score);
		
		if (GetAsyncKeyState(VK_UP))   //Conditions
		{
			direction = UP;
		} 
		else if (GetAsyncKeyState(VK_DOWN)) 
		{
			direction = DOWN;
		} 
		else if (GetAsyncKeyState(VK_LEFT)) 
		{
			direction = LEFT;
		} 
		else if (GetAsyncKeyState(VK_RIGHT)) 
		{
			direction = RIGHT;
		}
		
		if(checkWin(score))   //Display
			{
				cout<<"You Win the Game"<<endl;
				system("pause");				
				return;
		}
				
		switch (direction)
		{
		case UP:                                      //Movement display
			movePlayer(player, player.x-1, player.y);
			Sleep(100);
			break;
		case DOWN:
			movePlayer(player, player.x+1, player.y);
			Sleep(100);
			break;
		case LEFT:
			movePlayer(player, player.x, player.y-1);
			Sleep(100);
			break;
		case RIGHT:
			movePlayer(player, player.x, player.y+1);
			Sleep(100);
			break;
		}
			
		}
		Sleep(15000);
		
	}

int main()
{
	GamePac();   //Call function
	
	return 0;
}
