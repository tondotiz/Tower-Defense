/**
* File: enemy.h
*
* Author: Tondotiz
* Date: January 15, 2016
* Summary of File:
*
* This file contains the attributes and functions of the enemy class. The functions
* are used to get the position of the enemy,  move the enenmy to new position.
*
*/

class Enemy
{
private:
	int posR;
	int posC;

public:

	Enemy(void);
	Enemy(int, int);
	~Enemy(void);

	// advances the enemy to one column.
	void move();

	int getposR() { return posR; }
	int getposC() { return posC; }

};

