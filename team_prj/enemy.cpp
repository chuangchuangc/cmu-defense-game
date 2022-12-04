#include "enemy.h"
#include "yspng.h"
#include "ysglfontdata.h"
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for enemy.
*/
void enemy::showHealth() {
	float longX = 50;
	float y = 15;
	float dis_y = 25;
	float shortX = 50 * health / max_health;
	glColor3ub(255, 0, 0);
	DrawingUtilNG::drawRectangle(location.x - longX / 2, location.y - dis_y,
		longX, y, true, -1, -1);
	glColor3ub(0, 255, 0);
	DrawingUtilNG::drawRectangle(location.x - longX / 2, location.y - dis_y,
		shortX, y, true, -1, -1);
};

enemy::enemy(loc start, vector <direction> d, vector <loc> c, Cmu* b) {
	location = start;
	directions = d;
	checkLoc = c;
	moveCheck = 0;
	base = b;
	act = 0;
}

void enemy::move() {
	if (moveCheck > directions.size()) {
		return;
	}
	if (moveCheck==directions.size()) {
		base->underAttact();
		reachGoal = true;
		moveCheck++;
		return;
	}
	direction d = directions[moveCheck];
	loc check = checkLoc[moveCheck];
	switch (d)
	{
	case UP:
		location.y -= speed;
		break;
	case DOWN:
		location.y += speed;
		break;
	case LEFT:
		location.x -= speed;
		break;
	case RIGHT:
		location.x += speed;
		break;
	default:
		break;
	}
	if ((d == UP && location.y < check.y) ||
		(d == DOWN && location.y > check.y) ||
		(d == LEFT && location.x < check.x) ||
		(d == RIGHT && location.x > check.x)) {
		moveCheck++;
	}
}

void enemy::showImg(const char p1[], const char p2[], const char p3[], const char p4[]) {


	if (act >= 0 && act < 4) {
		putPng2(location.x, location.y, 40, 40, p1);
		act++;
	}
	else if (act >= 4 && act < 8) {
		putPng2(location.x, location.y, 40, 40, p2);
		act++;
	}
	else if (act >= 8 && act < 12) {
		putPng2(location.x, location.y, 40, 40, p3);
		act++;
	}
	else {
		putPng2(location.x, location.y, 40, 40, p4);
		act++;
		if (act == 16) {
			act = 0;
		}
	}
	showHealth();
	skill();
}

void enemy::putPng(int x, int y, int width, int height, const char name[]) {
	
	YsRawPngDecoder png; // create decoder object
	png.Decode(name);
	png.Flip();
	x = x - png.wid / 2;
	y = y - png.hei / 2 + png.hei;
	glRasterPos2d(x, y);
	glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
}

void enemy::putPng2(int x, int y, int width, int height, const char png[]) {
	
	x = x - width / 2;
	y = y - height / 2;
	YsRawPngDecoder pngTemp;
	pngTemp.Decode(png);
	GLuint currTexture;
	glGenTextures(1, &currTexture);
	glBindTexture(GL_TEXTURE_2D, currTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pngTemp.wid, pngTemp.hei, 0, GL_RGBA, GL_UNSIGNED_BYTE, pngTemp.rgba);
	

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, currTexture);

	glBegin(GL_QUADS);
	// For each vertex, assign texture coordinate before vertex coordinate.
	glTexCoord2f(0.0, 0.0);
	glVertex2f(x, y);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(x + width, y);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(x + width, y + height);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(x, y + height);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	
}

void Wizard::show() {
	if (!visible) {
		putPng2(location.x, location.y, 80, 80, "shell.png");
	}
	
	enemy::showImg("enemy2_0.png", "enemy2_0.png", "enemy2_1.png", "enemy2_1.png");
}

void Orcs::show() {
	

	enemy::showImg("enemy1.png", "enemy1.2.png", "enemy1.3.png", "enemy1.1.png");
}

void enemy::lowerSpeed() {
	speed *= 0.9;
}

void Summoner::show()
{
	enemy::showImg("enemy3.png", "enemy3_2.png", "enemy3_3.png", "enemy3_4.png");
}
