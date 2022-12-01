#pragma once
#include <iostream>
#include <vector>
#include "enemy.h"
using namespace std;
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for bullet.
*/
class Bullet {
protected:
	loc start;
	loc end;
	loc location;
	float flyTime;
	float xSpeed;
	float ySpeed;
	float flyCount;

	loc getLoc() { return location; }
public:
	Bullet(loc s, enemy* e) {
		start = s;
		flyTime = 10;
		end = e->getLocation();
		location = start;
		xSpeed = abs(end.x - start.x)/flyTime;
		ySpeed = abs(end.y - start.y)/flyTime;
		flyCount = 0;
	}
	void show() {
		glColor3ub(0, 255, 255);
		DrawingUtilNG::drawCircle(location.x, location.y, 10, 10,
			true, 0, 360, true, 0);
	}
	bool fly() {
		if (flyCount >= flyTime) {
			return true;
		}
		if (end.x > start.x) {
			location.x += xSpeed;
		}
		else {
			location.x -= xSpeed;
		}
		if (end.y > start.y) {
			location.y += ySpeed;
		}
		else {
			location.y -= ySpeed;
		}
		flyCount++;
		return false;
	}
};
