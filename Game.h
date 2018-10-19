/**
* File: game.h
*
* Author: Tondotiz
* Date: January 15, 2016
* Summary of File:
*
* This file contains code which run assignement2. The functions allow the user to
* run the tower defense game. In tower defense games, the user must protect
* their house/land/castle from enemies by building towers and other defensive tools.
*
*/

#include "Enemy.h"
#include "Defense.h"
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// Define as constants the parameters of the game
#define MAXENEMIES 10
#define MAXDEFENSES 4
#define ROWS 4
#define COLUMNS 8

// Num equivalents for the type of elements in a cell
#define EMPTY 0
#define ENEMY 1
#define DEFENSE 2

class Game
{
private:

	vector< Enemy > e; //vector containing all the enemies
	vector< Defense > d; //vector containing all the defenses
	int enemies; //number of enemies created;

	bool enemywin;

public:
	Game(void);  //default game constructor
	~Game(void);  // game destructor

	void run();

	//checks the end of the game
	bool win();

	//Creates a new enemy & defence
	bool new_enemy(int, int);
	bool new_defense(int, int);

	// determines how many enemies to create: 0, 1 or 2
	void createRandomEnemy();

	// determines if the locations of a tower and an enemy are the same
	int towerMatchingEnemyLocation(Enemy &e);

	// Draw the game board 
	void board_draw();

	// draws a horizontal dotted line
	void board_draw_line();

	// replaces the content of a cell in the game board with a character
	char content_tochar(int);

};


