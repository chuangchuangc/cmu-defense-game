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
#include "menu.h"
#include "GraphicFont.h"

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


void addButtons(ButtonCollection& someButtons, GraphicFont* aFont, int xLoc, int wid);

int main() {
	FsOpenWindow(16, 16, 1200, 800, 1, "Demo");


	//
	int key = FSKEY_NULL;
	int mouseEvent, leftButton, middleButton, rightButton, locX, locY;
	ButtonCollection* myButtons = new ButtonCollection; // put this AFTER FsOpenWindow()
	int buttonKey = FSKEY_NULL;
	GraphicFont* buttonFont = new ComicSansFont;
	buttonFont->setColorRGB(0, 0, 0); // black
	addButtons(*myButtons, buttonFont, 350, 100);


	int flag = 0;
	while (flag != 4) {
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		FsPollDevice();
		key = FsInkey();
		mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);

		int wid, hei;
		FsGetWindowSize(wid, hei);

		// check if a button was clicked
		if (key == FSKEY_NULL && mouseEvent == FSMOUSEEVENT_LBUTTONDOWN) {
			buttonKey = myButtons->checkClick(locX, locY);

			if (buttonKey != FSKEY_NULL)
				key = buttonKey;  // pretend the user pressed a key 
		}
		myButtons->showImg(0, 0, 1200, 800, "start_background.png");

		myButtons->paint();
		myButtons->showImg(550, 400, 110, 30, "esay.png");
		myButtons->showImg(550, 440, 110, 30, "normal.png");
		myButtons->showImg(550, 480, 110, 30, "hard.png");
		myButtons->showImg(550, 520, 110, 30, "exit.png");



		switch (key) {
		case FSKEY_1:
			flag = 1;
			break;
		case FSKEY_2:
			flag = 2;
			break;
		case FSKEY_3:
			flag = 3;
			break;
		case FSKEY_4:
			flag = 4;
			break;
		}

		if (flag == 1) {
			int gold = 0;
			time_t start = time(NULL);
			vector <direction> ts = { UP, LEFT, UP , LEFT, UP, RIGHT, UP, RIGHT, DOWN };
			vector <loc> ds = { {375, 570}, {305, 570}, {305, 440}, {230, 440}, {230, 235}, {295, 235}, {295, 170}, {570, 170}, {570, 350} };
			vector <posi> areas = { {2, 3}, {2, 4}, {2, 5}, {2, 6}, {4, 4}, {4, 5}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}, {6, 8}, {7, 3}, {7, 4}, {7, 7}, {8, 7}, {9, 3}, {9, 4}, {9, 5}, {9, 6} };
			GameManager1 game1({ 534, 400 }, { 365, 800 }, ds, ts, start, 20, 10, 30, 15, 10, 5);
			MenuManager menu;
			MapManager map(areas, "map.png");
			map.game = &game1; map.menu = &menu;
			while (map.manage()) {
				glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
				menu.showMenu();
				map.showMap();
				menu.gold += game1.motion();
				menu.accrue(time(NULL));
				FsSwapBuffers();
				// prepare for next loop
				FsSleep(50);
			}
			flag = 0;
		}

		FsSwapBuffers();
		// prepare for next loop
		FsSleep(25);
	}

	

	delete myButtons;
	delete buttonFont;
	return 0;
}

void addButtons(ButtonCollection& someButtons, GraphicFont* aFont, int xLoc, int wid)
{
	int hei = 30;
	int spacing = 10;
	int currY = 400;


	someButtons.add(550, currY, wid, hei, FSKEY_1, "easy", aFont,
		"");

	currY += hei + spacing;
	someButtons.add(550, currY, wid, hei, FSKEY_2, "noamal", aFont,
		"");

	currY += hei + spacing;
	someButtons.add(550, currY, wid, hei, FSKEY_3, "hard", aFont,
		"");

	currY += hei + spacing;
	someButtons.add(550, currY, wid, hei, FSKEY_ESC, "exit", aFont,
		"");

}


















