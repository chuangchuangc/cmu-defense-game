#pragma once
//#include "cmu.h"
#include "enemy.h"
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for gold coin(money).
*/
class Money {
private:
	int count;
	loc location;
public:
	Money(loc c) {
		location = c;
		count = 40;
	}
	void show() {
		enemy::putPng2(location.x, location.y, 40, 40, "money.png");
		count--;
		
	}
	bool checkLive() { return count > 0; }
};
