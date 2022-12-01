#pragma once
#include "DrawingUtilNG.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "yssimplesound.h"
using namespace std;
/*
* full name: Chuang Ma
* date: Nov. 16, 2022
* andrew ID: chuangm
* course: 24780 B
* description: Class for basement.
*/
struct loc {
	float x;
	float y;
};
class Cmu {
private:
	loc location;
	float health;
	YsRawPngDecoder pngTemp;
public:
	Cmu(loc c) {
		location = c;
		health = 10;
		pngTemp.Decode("cmu1.png");
	}
	void underAttact() {
		health--;
		cout << health;
	}
	void show() {
		float x = location.x;
		float y = location.y;
		float width = 60;
		float height = 60;
		x = x - width / 2;
		y = y - height / 2;
		
		GLuint currTexture;
		glGenTextures(1, &currTexture);
		glBindTexture(GL_TEXTURE_2D, currTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pngTemp.wid, pngTemp.hei, 0, GL_RGBA, GL_UNSIGNED_BYTE, pngTemp.rgba);


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
	int showhealth() { return health; }
};
