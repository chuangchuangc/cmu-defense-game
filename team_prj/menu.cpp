#include "menu.h"
#include <string>
#include "DrawingUtilNG.h"
#include "StringPlus.h"
#include "GraphicFont.h"



using namespace std;



Button::Button(int locX, int locY, int wid, int hei, int val, std::string text, GraphicFont* aFont, std::string description)
{
	x = locX; y = locY; xSize = wid; ySize = hei;
	value = val; label = text;
	theFont = aFont;
	hover = description;
}

int Button::getVal(int locX, int locY)
{
	if (enabled && x <= locX && locX <= x + xSize && y <= locY && locY <= y + ySize)
		return value;
	else
		return FSKEY_NULL;
}

void Button::paint()
{
	// top light
	glColor3ub(46, 139, 87);
	DrawingUtilNG::drawRectangle(x, y, xSize, ySize, true);

	// bottom shadow
	glColor3ub(0, 200, 0);
	glBegin(GL_QUADS);
	glVertex2i(x, y + ySize);
	glVertex2i(x + ySize / 2, y + ySize / 2);
	glVertex2i(x + xSize, y + ySize / 2);
	glVertex2i(x + xSize, y + ySize);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2i(x + xSize, y);
	glVertex2i(x + xSize, y + ySize);
	glVertex2i(x + xSize - ySize / 2, y + ySize / 2);
	glEnd();

	// flat
	glColor3ub(0, 200, 0);
	int width = 3;
	DrawingUtilNG::drawRectangle(x + width, y + width, xSize - width * 2, ySize - width * 2, true);

	if (enabled)
		theFont->setColorRGB(0, 0, 0);
	else
		theFont->setColorRGB(.4, .4, .4);

	int hei = theFont->getLetterHeight();
	theFont->drawText(label, x + xSize / 2, y + ySize / 2, (float)(ySize - 8) / hei, 0, true);
}

void Button::paintHover(int locX, int locY)
{
}




void ButtonCollection::add(int locX, int locY, int wid, int hei, int val, std::string text, GraphicFont* aFont, std::string description)
{
	theButtons.push_back(Button(locX, locY, wid, hei, val, text, aFont, description));
}

void ButtonCollection::remove(int val)
{

}

void ButtonCollection::disableButton(int val)
{
	int wantedIndex = getIndex(val);
	if (wantedIndex >= 0)
		theButtons.at(wantedIndex).disable();
}

void ButtonCollection::enableButton(int val)
{
	int wantedIndex = getIndex(val);
	if (wantedIndex >= 0)
		theButtons.at(wantedIndex).enable();
}

void ButtonCollection::paint()
{	//glLoadIdentity();

	for (auto& currButton : theButtons) {
		currButton.paint();
	}
}

int ButtonCollection::checkClick(int locX, int locY)
{
	int buttonValue;
	for (auto& currButton : theButtons) {
		buttonValue = currButton.getVal(locX, locY);
		if (buttonValue != FSKEY_NULL)
			return buttonValue;
	}
	return FSKEY_NULL;
}

void ButtonCollection::checkHover(int locX, int locY)
{
	for (auto& currButton : theButtons) {
		currButton.paintHover(locX, locY);
	}
}

void ButtonCollection::showImg(int x, int y, int width, int height, const char png[])
{


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


int ButtonCollection::getIndex(int val)
{
	int i = 0;
	for (auto& currButton : theButtons) {
		if (currButton.getVal() == val)
			return i;  // possible exit from function
		i++;
	}
	return -1;
}
