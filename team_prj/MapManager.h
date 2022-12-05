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
#include "gameManager.h"

void drawPng(GLuint texture, loc l, int width, int height);
class MenuManager {
public:
	const string CHOOSE_ARROW = "ARROW is chosen";
	const string CHOOSE_GUN = "GUN is chosen";
	const string CHOOSE_ICE = "ICE is chosen";
	const string CHOOSE_UPGRADE = "Choose a tower to upgrade";
	const string CHOOSE_REMOVE = "Choose a tower to remove";
	const string TOWER_REMOVED = "Tower removed";
	const string TOWER_UPGRADED = "Tower upgraded";
	const string NOT_ENOUGH_ARROW = "Not enought money for ARROW!";
	const string NOT_ENOUGH_GUN = "Not enought money for GUN!";
	const string NOT_ENOUGH_ICE = "Not enought money for ICE!";
	const string NOT_ENOUGH_UPGRADE = "Not enought money to upgrade!";
	const string NOT_ENOUGH_REMOVE = "Not enought money to remove!";
	const string UPGRADE_SUCCESS = "Tower was upgraded!";
	const string REMOVE_SUCCESS = "Tower was removed!";
	const string BUILD_SUCCESS = "A tower was built";
	const string HIGHEST_LEVEL = "Tower can't upgrade anymore!";
	const string YOU_WIN = "You Win!";
	const string YOU_LOSE = "You Lose";
protected:
	loc tower1_loc = { 900, 200 }, tower3_loc = { 900, 300 }, tower2_loc = { 1050, 200 };
	loc upgrade_loc = { 870, 650 }, remove_loc = { 1030, 650 }, back_loc = { 950, 650 };
	GLuint texture_menu, texture_coin, texture_tower1, texture_tower3, texture_tower2, texture_upgrade, texture_remove, texture_back;
	float tower_wid = 67.5, tower_hei = 72.7, button_wid = 120, button_hei = 50;
	float coin_wid, coin_hei;
	time_t prev_time;
	int goldpersec = 2;
	int mouseEvent = 0, leftButton = 0, middleButton = 0, rightButton = 0, screenX = 0, screenY = 0;
	bool isLegal(loc l) { return l.x > 800; };
	void GLSetup(const char menufn[], const char coinfn[], const char tower3fn[], const char tower1fn[], const char tower2fn[], const char upgradefn[], const char removefn[], const char backfn[]);

public:
	MenuManager(const char menufn[] = "menu.png", const char coinfn[] = "money.png", const char tower1fn[] = "tower1.png", const char tower2fn[] = "tower2.png", const char tower3fn[] = "tower3.png", const char upgradefn[] = "Upgrade.png", const char removefn[] = "Remove.png", const char backfn[] = "Back.png") {
		GLSetup(menufn, coinfn, tower1fn, tower2fn, tower3fn, upgradefn, removefn, backfn);
		prev_time = time(NULL);
	}
	string indicator = "Welcome to CMU Defense!";
	bool inPlaceMode = false;
	ToKind selected_tower = NONE;
	int gold = 20;
	int tower1_gold = 20, tower2_gold = 40,tower3_gold=30;
	int remove_gold = 10, upgrade_gold = 50;
	ToKind mode = DEFAULT;
	void managemouse();
	ToKind getTower(loc click_loc);
	void showMenu();
	void accrue(time_t game_time);
	void setIndicator(string content);
	bool success = false;
	bool fail = false;
	bool exit = false;
};

class MapManager {

protected:
	GLuint texture_map;
	float grid_size = 800.0 / 12;
	int key = FSKEY_NULL;
	int mouseEvent = 0, leftButton = 0, middleButton = 0, rightButton = 0, screenX = 0, screenY = 0;
	bool inPlaceMode = false;
	ToKind mode = NONE;
	bool inEditMode = false;
	int areas[12][12];
	loc click_loc;
	bool isLegal(loc l) { return l.x < 800; };
	void GLSetup(const char mapfn[]);


public:
	MapManager(vector<posi> avail_areas, const char mapfn[] = "map.png") {
		GLSetup(mapfn);
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				areas[i][j] = -1;
			}
		}

		for (posi position : avail_areas) {
			areas[position.x][position.y] = 0;
		}
	}

	GameManager1* game;
	MenuManager* menu;

	bool success = false;
	bool fail = false;

	bool existtower[12][12] = {};

	bool manage();

	void manageMouse();

	tuple<int, int> getTowerIdx(loc input_loc);
	loc getTowerPos(loc input_loc);

	void showMap();

	void paintAvailableArea();

	void paintUpgradeArea();

	void paintRemoveArea();
};