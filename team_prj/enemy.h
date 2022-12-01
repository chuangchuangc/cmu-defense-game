#pragma once
#include <iostream>
#include <vector>
#include"yspng.h"
#include "cmu.h"
using namespace std;
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for enemy.
*/

enum direction {UP,DOWN,LEFT,RIGHT};
enum enemyType {WIZARD,ORCS, SUMM};

class enemy {
protected:
	vector <direction> directions;
	vector <loc> checkLoc;
	loc location;
	float health;
	float max_health;
	float speed;
	virtual void skill() {};
	int moveCheck;
	Cmu* base;
	int act;
	bool reachGoal = false;

	enemyType type;


	void showHealth();




public:
	enemyType getTpye(){
		return type;
	}
	static void putPng(int x, int y, int width, int height, const char name[]);
	static void putPng2(int x, int y, int width, int height, const char name[]);
	enemy(loc start, vector <direction> d, vector <loc> c, Cmu* b);
	void underAttack(float damage) { health -= damage; }
	void move();
	bool checkLive() { return health > 0; }
	virtual void show() {};
	void showImg(const char p1[], const char p2[], const char p3[], const char p4[]);
	virtual bool checkVisible() { return true; };
	loc getLocation() { return location; }
	bool checkReach() { return reachGoal; }
	void lowerSpeed();
	float getSpeed() { return speed; }

};

class Wizard :public enemy {
private:
	bool visible = true;
public:
	Wizard(loc start,vector <direction> d, vector <loc> c,Cmu* b):enemy(start,d,c,b) {
		health = 100;
		max_health = health;
		speed = 2;
		type = WIZARD;
	}
	void show();

	void skill() {
		if (health < max_health / 4)
			visible = false;
	}
	bool checkVisible() {
		return visible;
	}
};

class Orcs :public enemy {
public:
	Orcs(loc start, vector <direction> d, vector <loc> c,Cmu*b) :enemy(start, d, c,b) {
		health = 200;
		max_health = health;
		speed = 1.5;
		type = ORCS;
	}
	void skill() {
		if (health < max_health / 2 && health > max_health / 4) {
			speed = max_health/health*0.8;
		}
	}
	void show();
};

class Summoner :public enemy {
public:
	Summoner(loc start, vector <direction> d, vector <loc> c, Cmu* b) :enemy(start, d, c, b) {
		health = 400;
		max_health = health;
		speed = 1.2;
		type = SUMM;
	}
	void skill() {
		;
	}
	void show();
};
