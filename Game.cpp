/**
* File: game.cpp
*
* Author: Tondotiz
* Date: January 15, 2016
* Summary of File:
*
* This file implements the functions of the class Game.
*
*/
#include "Game.h"

//default game constrctor
Game::Game(void)
{
	srand(time(NULL));
	
	enemies = 0;
	enemywin = false;
}

// game destructor
Game::~Game(void)
{
}

//  run the game by first drawing the board game
// then creating a vector enemies and towers. The enemies start
// moving and the user is moving the towers to prevent the enemies
// from reaching the last column.
void Game::run()
{
	int i; //counter
	int t;


	//Infinitive loop unless someone wins
	while (!win()) {

		//Create new enemies
		createRandomEnemy();

		//Draw board 
		board_draw();
		cout << "NbEnemies  current: " << e.size() << " total: " << enemies << endl;
		
		// === User's turn ===
		//Get user move
		if (d.size() < MAXDEFENSES) {
			char* move = new char[2];
			cout << "What's your move? ";
			cin >> move;
			//user passes his turn
			if (move[0] == 'p')
				cout << "You pass your turn" << endl;
			else {
				// Create a defense
				if (!new_defense((int)(move[0] - 97), (int)(move[1] - 49)))
					cout << "Invalid move. You pass your turn" << endl;
			}
			cout << endl;
		}
		else
			cout << "Maximum number of towers on the board. You cannot add one." << endl;

	
		// === Enemy's turn === 
		// Move enemies on board
		// Loop in the reverse order, otherwise if you erase an enemy, you won't loop through all of them
		for (i = e.size() - 1; i >= 0; i--){
			e[i].move();

			//determine if the locations of a tower and an enemy are matched
			t = towerMatchingEnemyLocation(e[i]);
			if (t >= 0) {
				e.erase(e.begin() + i);

				// Determine if the tower is dead or not
				d[t].enemyHit();
				if (d[t].isdead())
					d.erase(d.begin() + t);

			}
			else {
				// Has an enemy walked past the end of the board?
				if (e[i].getposC() == COLUMNS)
					enemywin = true;
			}
		}

	}


}

// checks the end of the game by checking if all enemies are dead
// or one of the enemies passed to the last column (colummn 11).
bool Game::win() {

	bool userwin = false;

	//if all enemy are dead
	if (enemies == MAXENEMIES) {
		if (e.size() == 0) {
			userwin = true;
			cout << endl << "All the enemies are dead!" << endl;
			cout << "Congratulations!!! You have won!" << endl << endl;
		}
	}

	//if enemy has moved to 11
	if (enemywin) {
		cout << endl << "I'm sorry, the enemies have won." << endl << endl;
	}

	return (userwin || enemywin);


}

// creates a new enemy.
bool Game::new_enemy(int r, int c) {
	if (enemies < MAXENEMIES) {
		//If this is a valid location 
		if (r < ROWS && c < COLUMNS){
			e.push_back(Enemy(c, r));
			enemies++;

			return true;
		}
	}
	return false;
}


// creates a new defense.
bool Game::new_defense(int r, int c) {
	if (d.size() < MAXDEFENSES) {
		//If this is a valid location 
		if (r >= 0 && r < ROWS && c >= 0 && c < COLUMNS){
			d.push_back(Defense(r, c));

			return true;
		}
	}
	return false;
}
// determines how many enemies to create: 0, 1 or 2
void Game::createRandomEnemy(){

	int row1, row2;
	int nbE = rand() % 3;

	//First enemy
	if (nbE > 0) {
		row1 = rand() % 4;
		new_enemy(row1, 0);
	}

	//Second enemy
	if (nbE == 2) {
		row2 = rand() % 4;
		while (row2 == row1) // to make sure the two enemies are not create at the same location
			row2 = rand() % 4;
		new_enemy(row2, 0);
	}
}


// Determines if the locations of a tower and an enemy are the same
int Game::towerMatchingEnemyLocation(Enemy &en) {
	//loop for all defense vector
	for (int i = 0; i < d.size(); i++)
		// the condition checks if positions (column and raw) of an enemy and defense are equal.
		if (en.getposR() == d[i].getposR() && en.getposC() == d[i].getposC())
			return i;

	return -1;
}

/* Draw the game board

1   2   3   4   5   6   7   8   9  10
-----------------------------------------
A |   |   |   |   |   |   |   |   |   |   |
-----------------------------------------
B | E |   |   |   |   |   | T |   |   |   |
-----------------------------------------
C |   |   | E |   |   |   |   | T |   |   |
-----------------------------------------
D |   |   |   |   |   |   |   |   |   |   |
-----------------------------------------

*/
void Game::board_draw() {

	int i, j;

	//Create the board
	int b[ROWS][COLUMNS];
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			b[i][j] = EMPTY;

	//Fill with enemies
	for (int i = 0; i < e.size(); i++)
		b[e[i].getposR()][e[i].getposC()] = ENEMY;

	//Fill with defenses
	for (int i = 0; i < d.size(); i++)
		b[d[i].getposR()][d[i].getposC()] = DEFENSE;

	//write column numbers
	cout << "    ";
	for (j = 0; j < COLUMNS; j++) {
		cout << j + 1 << "   ";
	}
	cout << endl;
	board_draw_line();

	//for every row
	for (i = 0; i < ROWS; i++) {
		//write row name
		cout << (char)(i + 97);
		cout << " | ";

		//for every column
		for (j = 0; j < COLUMNS; j++) {
			//write content
			cout << content_tochar(b[i][j]);
			cout << " | ";
		}
		cout << endl;
		board_draw_line();
	}

	cout << endl;
}

// Draws a horizontal dotted line
void Game::board_draw_line() {
	cout << "  ---------------------------------" << endl;
}

// Replaces the content of a cell in the game board with a character
char Game::content_tochar(int c) {
	switch (c) {
	case(0) : return ' ';
	case(1) : return 'E';
	case(2) : return 'T';
	default: return 'X';
	}
}

