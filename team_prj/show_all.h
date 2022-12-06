#pragma once
#include"mapManager.h"
class Show :MenuManager {
public:
	Show() {};
	void showMenu() {
		drawPng(texture_menu, { 0, 0 }, 1200, 800);

		drawPng(texture_back, { 800,400 }, 120, 50);
	}
    void manage() {

    }
};
