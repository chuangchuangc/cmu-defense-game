#include "tower.h"
#include"yspng.h"
#include "ysglfontdata.h"
#include<cmath>
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for tower.
*/
void ArrowT::checkenemy() {
	if (attackCount < attackInterval) {
		attackCount++;
		return;
	}
	
	float min_dis = attactRange*attactRange;
	int min_index = -1;
	for (int i = 0; i < enemies.size(); i++) {
		if (!enemies[i]->checkVisible()) {
			continue;
		}
		loc l = enemies[i]->getLocation();
		float dx = l.x - location.x;
		float dy = l.y - location.y;
		float dis = pow(dx, 2) + pow(dy, 2);
		if (dis<pow(attactRange,2)) {
			if (dis < min_dis) {
				min_dis = dis;
				min_index = i;
			}
		}
	}
	if (min_index >= 0) {
		attck(enemies[min_index]);
	}
	attackCount = 0;
}


void GunT::checkenemy() {
	if (attackCount < attackInterval) {
		attackCount++;
		return;
	}

	for (int i = 0; i < enemies.size(); i++) {
		loc l = enemies[i]->getLocation();
		float dx = l.x - location.x;
		float dy = l.y - location.y;
		float dis = pow(dx, 2) + pow(dy, 2);
		if (dis < pow(attactRange, 2)) {
			attck(enemies[i]);
		}
	}
	attackCount = 0;
}

void IceT::checkenemy() {
	if (attackCount < attackInterval) {
		attackCount++;
		return;
	}

	for (int i = 0; i < enemies.size(); i++) {
		loc l = enemies[i]->getLocation();
		float dx = l.x - location.x;
		float dy = l.y - location.y;
		float dis = pow(dx, 2) + pow(dy, 2);
		if (dis < pow(attactRange, 2)) {
			if (enemies[i]->getSpeed() > 1) {
				enemies[i]->lowerSpeed();
			}
			
		}
	}
	attackCount = 0;
}


void ArrowT::show() {
	if(level==1)
		enemy::putPng2(location.x, location.y, 40, 40, "tower1.png");
	else if (level==2)
	{
		enemy::putPng2(location.x, location.y, 40, 40, "tower1.2.png");
	}
	else {
		enemy::putPng2(location.x, location.y, 40, 40, "tower1.3.png");
	}
	glColor3ub(255, 0, 0);
	DrawingUtilNG::drawCircle(location.x, location.y, attactRange * 2, attactRange * 2,
		false, 0, 360, true, 0);
}

void IceT::show() {
	if (level == 1)
		enemy::putPng2(location.x, location.y, 40, 40, "tower3.png");
	else if (level == 2)
	{
		enemy::putPng2(location.x, location.y, 40, 40, "tower3.2.png");
	}
	else {
		enemy::putPng2(location.x, location.y, 40, 40, "tower3.3.png");
	}
	glColor3ub(0, 255, 0);
	DrawingUtilNG::drawCircle(location.x, location.y, attactRange * 2, attactRange * 2,
		false, 0, 360, true, 0);
}


void GunT::show() {
	if (level == 1)
		enemy::putPng2(location.x, location.y, 40, 40, "tower2.png");
	else if (level == 2)
	{
		enemy::putPng2(location.x, location.y, 40, 40, "tower2.2.png");
	}
	else {
		enemy::putPng2(location.x, location.y, 40, 40, "tower2.3.png");
	}
	glColor3ub(0, 0, 255);
	DrawingUtilNG::drawCircle(location.x, location.y, attactRange * 2, attactRange * 2,
		false, 0, 360, true, 0);
}

void Tower::attck(enemy* en) { 
	en->underAttack(damage);
	Bullet* b = new Bullet(location, en);
	bullets.push_back(b);
}

void Tower::checkBullet() {
	for (int i=0; i < bullets.size(); i++) {
		bullets[i]->show();
		if (bullets[i]->fly()) {
			Bullet* tmp = bullets[i];
			bullets.erase(bullets.begin() + i);
			delete tmp;
		}
		
	}
}

void Tower::upgrade() {
	if (level >= 3) {
		return;
	}
	level += 1;
	attackInterval -= 1;
	attactRange *= 1.3;
	damage *= 1.5;

}