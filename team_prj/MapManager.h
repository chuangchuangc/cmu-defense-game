//
//  MapManager.h
//
//  Created by Valen Hsu on 11/21/22.
//

#pragma once
#include <tuple>
//#include "enemy.h"
//#include "tower.h"
#include <iostream>
#include "gameManger.h"

void drawPng(GLuint texture, loc l, int width, int height);
class MenuManager {
protected:
	loc tower1_loc = { 900, 200 }, tower2_loc = {1050, 200}, tower3_loc = { 900, 350 };
	GLuint texture_menu, texture_coin, texture_tower1, texture_tower2, texture_tower3;
	float tower_wid = 67.5, tower_hei = 72.7;
	float coin_wid, coin_hei;
	time_t prev_time;
	int goldpersec = 3;
	int mouseEvent = 0, leftButton = 0, middleButton = 0, rightButton = 0, screenX = 0, screenY = 0;
	bool isLegal(loc l) { return l.x > 800; };
	void GLSetup(const char menufn[], const char coinfn[], const char tower1fn[], const char tower2fn[], const char tower3fn[]);

public:
	MenuManager(const char menufn[] = "menu.png", const char coinfn[] = "money.png", const char tower1fn[] = "tower1.png", const char tower2fn[] = "tower2.png", const char tower3fn[] = "tower3.png") {
		GLSetup(menufn, coinfn, tower1fn, tower2fn, tower3fn);
		prev_time = time(NULL);
	}
	bool inPlaceMode = false;
	ToKind selected_tower = NONE;
	int gold = 0;
	int tower1_gold = 20, tower2_gold = 40;
	int remove_gold = 10, upgrade_gold = 50;

	void managemouse();
	ToKind getTower(loc click_loc);
	void showMenu();

	void accrue(time_t game_time);

};

class MapManager {
protected:
	GLuint texture_map;
	float grid_size = 800.0 / 12;
	int key = FSKEY_NULL;
	int mouseEvent = 0, leftButton = 0, middleButton = 0, rightButton = 0, screenX = 0, screenY = 0;
	bool inPlaceMode = false;
	bool inEditMode = false;
	loc click_loc;
	bool isLegal(loc l) { return l.x < 800; };
	void GLSetup(const char mapfn[]);


	

public:
	MapManager(const char mapfn[] = "map.png") {
		GLSetup(mapfn);
	}
	GameManager1* game;
	MenuManager* menu;

	bool existtower[12][12] = {};

	bool manage();

	void manageMouse();

	tuple<int,int> getTowerIdx(loc input_loc);
	loc getTowerPos(loc input_loc);

	//void editTower(loc click_loc);

	//loc placeTower(loc click_loc);

	void showMap();

};