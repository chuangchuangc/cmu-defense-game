#pragma once
#include"mapManager.h"
/*
* full name: Chuang Ma
* date: Dec. 5, 2022
* andrew ID: chuangm
* course: 24780 B
*/
class Show :MenuManager {
protected:
    GLuint tower1_2;
    GLuint tower1_3;
    GLuint tower2_2;
    GLuint tower2_3;
    GLuint tower3_2;
    GLuint tower3_3;

    GLuint e1;
    GLuint e2;
    GLuint e3;


    loc back_loc = { 1000,650 };
    bool exit_show = false;
    void addPic(GLuint t, GLuint t2, GLuint t3,float x,float& y) {

        glColor3d(1.0, 1.0, 1.0);
        drawPng(t, { x,y }, tower_wid, tower_hei);
        drawPng(t2, { x+50,y }, tower_wid, tower_hei);
        drawPng(t3, { x + 100,y }, tower_wid, tower_hei);
        y += 60;
    }
    void addPic(GLuint t, float x, float& y) {
        glColor3d(1.0, 1.0, 1.0);
        drawPng(t, { x,y }, tower_wid, tower_hei);
        y += 60;
    }
    void addS(string s, float x, float& y) {
        glColor3d(0, 0, 0);
        glRasterPos2i(x, y);
        YsGlDrawFontBitmap12x16(s.c_str());
        y += 20;
    }
public:
	Show() {
        setup();
    };
    void setup();
	void showMenu() {
        int wid, hei;
        FsGetWindowSize(wid, hei);

        glViewport(0, 0, wid, hei);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, (float)wid - 1, (float)hei - 1, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor4d(1.0, 1.0, 1.0, 1.0);
		drawPng(texture_menu, { 0, 0 }, 1200, 800);

		drawPng(texture_back, back_loc, 120, 50);
	}
    void show_pic();
    bool manage() {
        
        managemouse();
        showMenu();
        show_pic();
        return exit_show;
    }
	void managemouse() {
        FsPollDevice();
        int mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, screenX, screenY);
        loc click_loc = { screenX * 1.f, screenY * 1.f };
        if (mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && isLegal(click_loc)) {
            if (isLegal(click_loc) && abs(click_loc.x - back_loc.x) > 0 && abs(click_loc.x - back_loc.x) < button_wid && abs(click_loc.y - back_loc.y) > 0 && abs(click_loc.y - back_loc.y) < button_hei) {
                exit_show = true;
            }
        }
        return;
	}
};
