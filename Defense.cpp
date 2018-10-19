/**
* File: defense.cpp
*
* Author: Tondotiz
* Date: January 15, 2016
* Summary of File:
*
* This file implements the functions of the class Defense.
*
*/

#include "Defense.h"


//default defense constructor
Defense::Defense(void)
{
	hit = 0;
	posC = 0;
	posR = 0;
	dead = false;
}

//defense constructor with the row and column position
Defense::Defense(int c, int r)
{
	hit = 0;
	posR = c;
	posC = r;
	dead = false;
}

// defense destrcutor 
Defense::~Defense(void)
{
}

// checks if tower hit 2 enemies. If true, it dies.
void Defense::enemyHit() {
	hit++;
	if (hit == 2)
		dead = true;

}