#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "yssimplesound.h"
#include "yspng.h"
//#include "enemy.h"
//#include "tower.h"
//#include "cmu.h"
//#include "bullet.h"
//#include "gameManger.h"
#include "MapManager.h"
using namespace std;
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for testing.
*/



int main() {
	FsOpenWindow(16, 16, 1200, 800, 1, "Demo");
	int gold = 0;
	time_t start = time(NULL);
	vector <direction> ts = { UP, LEFT, UP , LEFT, UP, RIGHT, UP, RIGHT, DOWN };
	vector <loc> ds = { {375, 570}, {305, 570}, {305, 440}, {230, 440}, {230, 235}, {295, 235}, {295, 170}, {570, 170}, {570, 350} };
	GameManager1 game1({ 570, 350 }, { 365, 800 },ds,ts,start,4,6,3);
	MenuManager menu;
	MapManager map("map.png");
	map.game = &game1; map.menu = &menu;
	
	loc t1 = { 300, 400 };
	loc t2 = { 700, 400 };
	//game1.getTower(ICE, t2);
	game1.getTower(ICE, t1);
	game1.upgradeTower(t1);

	while (map.manage()) {
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		menu.showMenu();
		map.showMap();
		menu.gold += game1.motion();
		menu.accrue(time(NULL));
		
		/*int money = game1.motion();
		if (money!=0) {
			gold += money;
			cout << gold;
		}*/


		FsSwapBuffers();
		// prepare for next loop
		FsSleep(50);
	}
	return 0;
}