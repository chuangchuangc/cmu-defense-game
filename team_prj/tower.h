#pragma once
#include <iostream>
#include <vector>
#include "enemy.h"
#include "bullet.h"
using namespace std;
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for tower.
*/

enum ToKind {
	ARROW, GUN,ICE, NONE, UPGRADE, REMOVE, DEFAULT
};

class Tower {
protected:
	float attackCount;
	float attactRange;
	int level;
	loc location;
	float attackInterval;
	float damage;
	vector <enemy*> enemies;
	vector <Bullet*> bullets;
	void attck(enemy* en);
	float wid, hei;

public:
	Tower(){};
	virtual void checkenemy(){};
	void upgrade();
	loc getLoc() { return location; }
	void getenemy(vector <enemy*> en) { enemies = en; }
	virtual void show(){};
	void checkBullet();
};

class ArrowT : public Tower {
public:
	ArrowT(vector <enemy*> e,loc c) {
		location = c;
		attactRange = 150;
		level = 1;
		attackInterval = 2;
		damage = 10;
		enemies = e;
		attackCount = 0;
		wid = 50;
		hei = 50;
	}
	void checkenemy();
	void show();
};

class GunT : public Tower {
public:
	GunT(vector <enemy*> e, loc c) {
		location = c;
		attactRange = 200;
		level = 1;
		attackInterval = 4;
		damage = 10;
		enemies = e;
		attackCount = 0;
		wid = 60;
		hei = 60;
	}
	void checkenemy();
	void show();
};

class IceT : public Tower {
public:
	IceT(vector <enemy*> e, loc c) {
		location = c;
		attactRange = 200;
		level = 1;
		attackInterval = 4;
		damage = 10;
		enemies = e;
		attackCount = 0;
		wid = 60;
		hei = 60;
	}
	void checkenemy();
	void show();
};
