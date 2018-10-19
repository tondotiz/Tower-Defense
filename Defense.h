/**
* File: defense.h
*
* Author: Tondotiz
* Date: January 15, 2016
* Summary of File:
*
* This file contains the attributes and functions of the defense class. The functions
* are used to get the position of the desfense, check the status of the defense
* if it is dead or hit.
*
*/

#include <iostream>
using namespace std;

class Defense
{

	//defense attributes
protected:
	int hit;
	int posR;
	int posC;
	bool dead;

public:

	Defense(void);
	Defense(int, int);
	~Defense(void);

	int getposR() { return posR; }
	int getposC() { return posC; }

	// gets the status of defense
	bool isdead() { return dead; }

	// checks if tower hit 2 enemies. If true, it dies.
	void enemyHit();

};

