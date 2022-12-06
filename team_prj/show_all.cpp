#include "show_all.h"
/*
* full name: Chuang Ma
* date: Dec. 5, 2022
* andrew ID: chuangm
* course: 24780 B
*/
void set_texture_new(YsRawPngDecoder& pngTemp, const char pngname[], GLuint& png_texture) {
    pngTemp.Decode(pngname);
    glGenTextures(1, &png_texture);
    glBindTexture(GL_TEXTURE_2D, png_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,
        0,// Level of detail
        GL_RGBA,// the "A" in RGBA will include the transparency
        pngTemp.wid,// the hippos width and height
        pngTemp.hei,
        0,// Border width, but not supported and needs to be 0.
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        pngTemp.rgba);
}
void Show::setup()
{
    YsRawPngDecoder pngTemp;
    ;
    set_texture_new(pngTemp, "tower1.2.png", tower1_2);
    set_texture_new(pngTemp, "tower1.3.png", tower1_3);
    set_texture_new(pngTemp, "tower2.2.png", tower2_2);
    set_texture_new(pngTemp, "tower2.3.png", tower2_3);
    set_texture_new(pngTemp, "tower3.2.png", tower3_2);
    set_texture_new(pngTemp, "tower3.3.png", tower3_3);

    set_texture_new(pngTemp, "enemy1.1.png", e1);
    set_texture_new(pngTemp, "enemy2.png", e2);
    set_texture_new(pngTemp, "enemy3.png", e3);
}

void Show::show_pic()
{
    float to_x = 100;
    float to_y = 100;
    addPic(texture_tower1,tower1_2, tower1_3, to_x, to_y);
    addS("Arrow Tower: ", to_x, to_y);
    addS("Can only attack one nearest enemy.", to_x, to_y);
    addS("Can't attack wizards with shells. ", to_x, to_y);
    addPic(texture_tower2, tower2_2, tower2_3, to_x, to_y);
    addS("Gun tower: ", to_x, to_y);
    addS("Can attack all enemies in range", to_x, to_y);
    addS("at a lower speed.", to_x, to_y);
    addS("Can attack wizards with shells", to_x, to_y);
    addPic(texture_tower3, tower3_2, tower3_3, to_x, to_y);
    addS("Ice Tower: ", to_x, to_y);
    addS("Can make all enemies in range", to_x, to_y);
    addS("move lower.", to_x, to_y);
    to_y += 100;
    addS("All towers can be upgraded and removed.", to_x, to_y);

    to_x = 600;
    to_y = 100;
    addPic(e1, to_x, to_y);
    addS("Wizard: ", to_x, to_y);
    addS("when its health is below 1/4, it will get ", to_x, to_y);
    addS("a shell, then Arrow Tower won't attack it, but", to_x, to_y);
    addS("the Gun Tower can attack it.", to_x, to_y);
    addPic(e2, to_x, to_y);
    addS("Orcs: ", to_x, to_y);
    addS("when its health is less than 1/2 and larger ", to_x, to_y);
    addS("than 1/4, it will run and move faster.", to_x, to_y);
    
    addPic(e3, to_x, to_y);
    addS("Summoner: ", to_x, to_y);
    addS("When it¡¯s dead, it will summon two ", to_x, to_y);
    addS("Orcs in the place where it¡¯s dead.", to_x, to_y);
    to_y += 100;
    addS("After killing enemies, they will become ", to_x, to_y);
    addS("the gold coin and players can get money.", to_x, to_y);
}
