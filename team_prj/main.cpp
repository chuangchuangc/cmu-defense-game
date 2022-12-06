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
#include "show_all.h"

//#include "enemy.h"
//#include "tower.h"
//#include "cmu.h"
//#include "bullet.h"
//#include "gameManager.h"
#include "MapManager.h"
using namespace std;



void addButtons(ButtonCollection& someButtons, GraphicFont* aFont, int xLoc, int wid);

int main() {
	FsOpenWindow(16, 16, 1200, 800, 1, "CMU Defense!");
	YsSoundPlayer player;
	YsSoundPlayer::SoundData myWav;

	char filename[] = "buddy.wav";
	if (YSOK != myWav.LoadWav(filename)) //load file contents to wav variable
	{
		cout << "Failed to read: " << filename << endl;
		return 1;
	}

	//
	int key = FSKEY_NULL;
	int mouseEvent, leftButton, middleButton, rightButton, locX, locY;
	ButtonCollection* myButtons = new ButtonCollection; // put this AFTER FsOpenWindow()
	int buttonKey = FSKEY_NULL;
	GraphicFont* buttonFont = new ComicSansFont;
	buttonFont->setColorRGB(0, 0, 0); // black
	addButtons(*myButtons, buttonFont, 350, 100);
	cout << time(NULL);



	int flag = 0;
	player.Start();
	player.PlayBackground(myWav);
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

	
		myButtons->showImg(550, 400, 110, 30, "easy.png");
		myButtons->showImg(550, 440, 110, 30, "normal.png");
		myButtons->showImg(550, 480, 110, 30, "hard.png");
		myButtons->showImg(550, 520, 110, 30, "exit.png");
		myButtons->showImg(550, 360, 110, 30, "show_all.png");



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
		case FSKEY_ESC:
			flag = 4;
			break;
		case FSKEY_S:
			flag = 5;
			break;
		}

		if (flag == 1) {
			int gold = 0;
			time_t start = time(NULL);
			vector <direction> ts = { UP, LEFT, UP , LEFT, UP, RIGHT, UP, RIGHT, DOWN };
			vector <loc> ds = { {375, 570}, {305, 570}, {305, 440}, {230, 440}, {230, 235}, {295, 235}, {295, 170}, {570, 170}, {570, 350} };
			vector <posi> areas = { {2, 3}, {2, 4}, {2, 5}, {2, 6}, {4, 4}, {4, 5}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}, {6, 8}, {7, 3}, {7, 4}, {7, 7}, {8, 7}, {9, 3}, {9, 4}, {9, 5}, {9, 6} };
			GameManager1 game1({ 534, 400 }, { 365, 800 }, ds, ts, start, 20, 20, 30, 10, 15,5);
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

		if (flag == 2) {
			int gold = 0;
			time_t start = time(NULL);
			float gs = 800.0 / 12;
			vector <direction> ts = { RIGHT,DOWN,RIGHT,DOWN,LEFT,UP };
			vector <loc> ds = { {gs*8,gs*3},{gs * 8,gs * 4-15},{gs * 10,gs * 4-15},{gs * 10,gs * 10},{gs * 2,gs * 10},{ 2 * gs, 8 * gs } };
			
			vector <posi> areas = { };
			for (int i = 0; i < 12; i++) {
				areas.push_back({ i,0 });
			}
			for (int i = 8; i < 12; i++) {
				areas.push_back({ i,1 });
			}
			for (int i = 10; i < 12; i++) {
				areas.push_back({ i,2 });
			}
			for (int i = 0; i < 7; i++) {
				areas.push_back({ i,3 });
			}
			for (int i = 0; i < 8; i++) {
				areas.push_back({ i,4 });
			}
			for (int i = 0; i < 9; i++) {
				areas.push_back({ i,5 });
			}
			for (int i = 0; i < 9; i++) {
				areas.push_back({ i,6 });
			}
			for (int i = 3; i < 9; i++) {
				areas.push_back({ i,7 });
			}
			for (int i = 3; i < 9; i++) {
				areas.push_back({ i,8 });
			}
			for (int i = 2; i < 12; i++) {
				areas.push_back({ 11,i });
			}
			for (int i = 7; i < 12; i++) {
				areas.push_back({ 0,i });
			}
			for (int i = 0; i < 12; i++) {
				areas.push_back({ i,11 });
			}
			areas.push_back({ 1,10 });
			GameManager1 game1({ 2*gs, 8*gs }, { -5, gs*2 }, ds, ts, start, 15, 15, 20, 25, 20, 10);
			MenuManager menu;
			MapManager map(areas, "map2.png");
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
		if (flag == 3) {
			int gold = 0;
			time_t start = time(NULL);
			float gs = 800.0 / 12;
			vector <direction> ts = { DOWN,RIGHT,DOWN,RIGHT,DOWN,LEFT,DOWN,LEFT };
			vector <loc> ds = { {gs*2,gs*2},{gs * 4,gs * 2},{gs * 4,gs * 4-15},{gs * 9,gs * 4-15},{gs * 10,gs * 9},
			{gs * 3,gs * 9},{ 3 * gs, 11 * gs },{ 1 * gs, 11 * gs } };
			vector <posi> areas = {  };
			int j = 0;
			for (int i = 3; i < 5;i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 0; i < 1; i++) {
				areas.push_back({ i,j });
			}
			for (int i = 4; i < 7; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 0; i < 2; i++) {
				areas.push_back({ i,j });
			}
			for (int i = 6; i < 9; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 1; i < 3; i++) {
				areas.push_back({ i,j });
			}
			for (int i = 8; i < 11; i++) {
				areas.push_back({ i,j });
			}
			j++;
			


			for (int i = 2; i < 5; i++) {
				areas.push_back({ i,j });
			}
			for (int i = 10; i < 12; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 3; i < 6; i++) {
				areas.push_back({ i,j });
			}
			for (int i = 11; i < 12; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 5; i < 8; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 6; i < 9; i++) {
				areas.push_back({ i,j });
			}
			j++;

			for (int i = 2; i < 5; i++) {
				areas.push_back({ i,j });
			}
			for (int i = 11; i < 12; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 0; i < 2; i++) {
				areas.push_back({ i,j });
			}
			for (int i = 10; i < 12; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 6; i < 11; i++) {
				areas.push_back({ i,j });
			}
			j++;
			for (int i = 3; i < 10; i++) {
				areas.push_back({ i,j });
			}
			GameManager1 game1({ 1 * gs, 11 * gs }, { 2*gs, -5 }, ds, ts, start, 10, 10, 15, 20, 20, 15);
			MenuManager menu;
			MapManager map(areas, "map3.png");
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

		if (flag == 5) {
			Show show;
			bool exit_flag = true;
			while (exit_flag) {
				glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
				exit_flag = !show.manage();
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
	int currY = 400-40;

	someButtons.add(550, currY, wid, hei, FSKEY_S, "show", aFont,
		"");

	currY += hei + spacing;

	someButtons.add(550, currY, wid, hei, FSKEY_1, "easy", aFont,
		"");

	currY += hei + spacing;
	someButtons.add(550, currY, wid, hei, FSKEY_2, "noamal", aFont, "");

	currY += hei + spacing;
	someButtons.add(550, currY, wid, hei, FSKEY_3, "hard", aFont, "");

	currY += hei + spacing;
	someButtons.add(550, currY, wid, hei, FSKEY_ESC, "exit", aFont,
		"");

}


















