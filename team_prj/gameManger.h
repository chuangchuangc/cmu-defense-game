#pragma once
//#include"cmu.h"
//#include"enemy.h"
#include"tower.h"
#include"money.h"
using namespace std; 
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for a game manager.
*/

class  GameManager1
{
private:
	vector<enemy*> enemies;
	vector<Tower*> towers;
	vector<Money*> moneys;
	time_t start;
	int timeInter;
	time_t start2;
	int timeInter2;
	time_t start3;
	int timeInter3;
	Cmu* c;
	loc beg;
	vector <loc> ds;
	vector <direction> ts;
	int wizard_num;
	int orcs_num;
	int summ_num;
	bool fail() {
		return c->showhealth() <= 0;
	}
	void enemy_ge() {
		if (wizard_num>0 && time(NULL) - start == timeInter) {
			Wizard* w = new Wizard(beg, ts, ds, c);
			enemies.push_back(w);
			start = time(NULL);
			wizard_num--;
		}
		if (orcs_num>0 && time(NULL) - start2 == timeInter2) {
			Orcs* o = new Orcs(beg, ts, ds, c);
			enemies.push_back(o);
			start2 = time(NULL);
			orcs_num--;
		}
		if (summ_num > 0 && time(NULL) - start3 == timeInter3) {
			Summoner* s = new Summoner(beg, ts, ds, c);
			enemies.push_back(s);
			start3 = time(NULL);
			summ_num--;
		}
	}


	template<typename Base, typename T>
	inline bool instanceof(const T*) {
		return typeid(Base) == typeid(T);
		//return dynamic_cast<const Base*>(&T) != 0;
	}

	int en_motion() {
		int money = 0;
		if (enemies.size() == 0) {
			return 0;
		}
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->move();
			enemies[i]->show();
			if (!enemies[i]->checkLive()) {
				
				enemy* tmp = enemies[i];

				if (tmp->getTpye()==ORCS) {
					money = 5;
				}
				else if (tmp->getTpye() == WIZARD) {
					money = 10;
				}
				else if (tmp->getTpye() == SUMM) {
					money = 15;
					Orcs* o1 = new Orcs(enemies[i]->getLocation(), ts, ds, c);
					enemies.push_back(o1);
					Orcs* o2 = new Orcs(enemies[i]->getLocation(), ts, ds, c);
					enemies.push_back(o2);
				}

				

				Money* m = new Money(enemies[i]->getLocation());
				moneys.push_back(m);
				enemies.erase(enemies.begin() + i);
				delete tmp;
				
			}
		
		}
		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i]->checkReach()) {
				enemy* tmp = enemies[i];
				enemies.erase(enemies.begin() + i);
				delete tmp;
			}
		}
		return money;
	}
	void to_motion() {
		for (auto to : towers) {
			to->show();
			to->getenemy(enemies);
			to->checkenemy();
			to->getenemy(enemies);
			to->checkBullet();
		}
	}
	void mo_motion() {
		if (moneys.size() == 0) {
			return;
		}
		for (int i = 0; i < moneys.size(); i++) {
			moneys[i]->show();

			if (!moneys[i]->checkLive()) {
				Money* tmp = moneys[i];
				moneys.erase(moneys.begin() + i);
				delete tmp;
			}
		}
	}
public:
	GameManager1(loc cmuLoc, loc beginLoc, vector <loc> turns, vector <direction> dirs, time_t t, int t2, int t3,int t4) {
		c = new Cmu(cmuLoc);
		beg = beginLoc;
		ds = turns;
		ts = dirs;
		start = t;
		start2 = t;
		start3 = t;
		wizard_num = 4;
		orcs_num = 5;
		summ_num = 3;

		timeInter = t2;
		timeInter2 = t3;
		timeInter3 = t4;

		

	}
	int motion() {
		c->show();
		int money = en_motion();
		to_motion();
		mo_motion();
		enemy_ge();
		if (success()) {
			cout << "success";
		}
		if (fail()) {
			cout << "GG";
		}
		return money;
	}
	void getTower(ToKind t,loc c ) {
		switch (t)
		{
		case ARROW: {
			ArrowT* a = new ArrowT(enemies, c);
			towers.push_back(a);
			break;
		}
		case GUN: {
			GunT* g = new GunT(enemies, c);
			towers.push_back(g);
			break;
		}
		case ICE: {
			IceT* g = new IceT(enemies, c);
			towers.push_back(g);
			break;
		}
		default:
			break;
		}
	}
	void removeTower(loc c) {
		if (towers.size() == 0) {
			return;
		}
		for (int i = 0; i < towers.size(); i++) {
			if (towers[i]->getLoc().x == c.x&& towers[i]->getLoc().y == c.y) {
				Tower* tmp = towers[i];
				towers.erase(towers.begin() + i);
				delete tmp;
			}
		}
	}
	void upgradeTower(loc c) {
		if (towers.size() == 0) {
			return;
		}
		for (int i = 0; i < towers.size(); i++) {
			if (towers[i]->getLoc().x == c.x && towers[i]->getLoc().y == c.y) {
				towers[i]->upgrade();
			}
		}
	}
	bool success() {
		return (wizard_num <= 0 && orcs_num <= 0 && summ_num <= 0 && enemies.size() <= 0);
	}
};
