/**
* File: enemy.cpp
*
* Author: Tondotiz
* Date: January 15, 2016
* Summary of File:
*
* This file implements the functions of the class Enemy.
*
*/
#include "Enemy.h"

//default enemy constructor
Enemy::Enemy(void)
{
	posC = 0;
	posR = 0;
}

//enemy constructor with the row and column position
Enemy::Enemy(int r, int c)
{
	posR = c;
	posC = r;
}

//enemy destructor
Enemy::~Enemy(void)
{
}

//advances the enemy to one column.
void Enemy::move() {
	posC++;
}

