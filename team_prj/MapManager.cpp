//
//  MapManager.cpp
//
//  Created by Valen Hsu on 11/21/22.
//

#include "MapManager.h"

void MenuManager::GLSetup(const char menufn[], const char coinfn[], const char tower1fn[], const char tower2fn[], const char upgradefn[], const char removefn[], const char backfn[]) {
    YsRawPngDecoder pngTemp;

    pngTemp.Decode(menufn);
    glGenTextures(1, &texture_menu);
    glBindTexture(GL_TEXTURE_2D, texture_menu);
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

    pngTemp.Decode(coinfn);
    glGenTextures(1, &texture_coin);
    glBindTexture(GL_TEXTURE_2D, texture_coin);
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

    coin_wid = pngTemp.wid; coin_hei = pngTemp.hei;

    pngTemp.Decode(tower1fn);
    glGenTextures(1, &texture_tower1);
    glBindTexture(GL_TEXTURE_2D, texture_tower1);
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

    tower_wid = pngTemp.wid; tower_hei = pngTemp.hei;

    pngTemp.Decode(tower2fn);
    glGenTextures(1, &texture_tower2);
    glBindTexture(GL_TEXTURE_2D, texture_tower2);
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

    pngTemp.Decode(upgradefn);
    glGenTextures(1, &texture_upgrade);
    glBindTexture(GL_TEXTURE_2D, texture_upgrade);
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

    pngTemp.Decode(removefn);
    glGenTextures(1, &texture_remove);
    glBindTexture(GL_TEXTURE_2D, texture_remove);
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

    pngTemp.Decode(backfn);
    glGenTextures(1, &texture_back);
    glBindTexture(GL_TEXTURE_2D, texture_back);
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

void drawPng(GLuint texture, loc l, int width, int height) {
    int x = l.x; int y = l.y;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture); // imageSample (a bird)

    glBegin(GL_QUADS); // For each vertex, assign texture coordinate before vertex coordinate.
    glTexCoord2d(0.0, 0.0); // these are "percentage" of the image
    glVertex2i(x, y); // these are actual pixel coordinates on screen

    glTexCoord2d(1.0, 0.0);
    glVertex2i(x + width, y);

    glTexCoord2d(1.0, 1.0);
    glVertex2i(x + width, y + height); // kept xSize and ySize for this purpose

    glTexCoord2d(0.0, 1.0);
    glVertex2i(x, y + height);
    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}

void MenuManager::setIndicator(string content) {
    indicator = content;

}

void MenuManager::managemouse() {
    FsPollDevice();
    int mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, screenX, screenY);
    loc click_loc = { screenX * 1.f, screenY * 1.f };
    if (mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && isLegal(click_loc)) {
        cout << "inPlaceMode: " << inPlaceMode << endl;
        if (isLegal(click_loc) && !inPlaceMode) {
            selected_tower = getTower(click_loc);
        }
        if (isLegal(click_loc) && success && click_loc.x - back_loc.x > 0 && click_loc.x - back_loc.x < button_wid && click_loc.y - back_loc.y > 0 && click_loc.y - back_loc.y < button_hei) {
            exit = TRUE;
        }
        //mouseEvent = 0;
    }
    return;
}

ToKind  MenuManager::getTower(loc click_loc) {

    if (click_loc.x - tower1_loc.x > 0 && click_loc.x - tower1_loc.x < tower_wid && click_loc.y - tower1_loc.y > 0 && click_loc.y - tower1_loc.y < tower_hei) {
        if (gold >= tower1_gold) {
            cout << "Arrow is chosen" << endl;
            inPlaceMode = true;
            indicator = CHOOSE_ARROW;
            return ARROW;
        }
        else {
            cout << "Not enought money for ARROW!" << endl;
            indicator = NOT_ENOUGH_ARROW;
            inPlaceMode = false;
            return NONE;
        }
    }
    else if (click_loc.x - tower2_loc.x > 0 && click_loc.x - tower2_loc.x < tower_wid && click_loc.y - tower2_loc.y > 0 && click_loc.y - tower2_loc.y < tower_hei) {
        if (gold >= tower2_gold) {
            cout << "GUN is chosen" << endl;
            indicator = CHOOSE_GUN;
            inPlaceMode = true;
            indicator = CHOOSE_GUN;
            return GUN;
        }
        else {
            cout << "Not enought money for GUN!" << endl;
            indicator = NOT_ENOUGH_GUN;
            inPlaceMode = false;
            return NONE;
        }
    }
    else if (click_loc.x - upgrade_loc.x > 0 && click_loc.x - upgrade_loc.x < button_wid && click_loc.y - upgrade_loc.y > 0 && click_loc.y - upgrade_loc.y < button_hei) {
        indicator = CHOOSE_UPGRADE;
        mode = UPGRADE;
    }
    else if (click_loc.x - tower2_loc.x > 0 && click_loc.x - remove_loc.x < button_wid && click_loc.y - remove_loc.y > 0 && click_loc.y - remove_loc.y < button_hei) {
        indicator = CHOOSE_REMOVE;
        mode = REMOVE;
    }
    return NONE;
}

void MenuManager::showMenu() {
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

    drawPng(texture_menu, { 800, 0 }, 400, 800);

    glColor3d(1.0, 1.0, 1.0);
    drawPng(texture_tower1, tower1_loc, tower_wid, tower_hei);
    drawPng(texture_coin, { 880, 240 }, coin_wid / 2, coin_hei / 2);
    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2i(920, 265);
    YsGlDrawFontBitmap12x16(to_string(tower1_gold).c_str());

    glColor3d(1.0, 1.0, 1.0);
    drawPng(texture_tower2, tower2_loc, tower_wid, tower_hei);
    drawPng(texture_coin, { 1030, 240 }, coin_wid / 2, coin_hei / 2);
    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2i(1070, 265);
    YsGlDrawFontBitmap12x16(to_string(tower2_gold).c_str());

    glColor3d(1.0, 1.0, 1.0);
    drawPng(texture_coin, { 950, 80 }, coin_wid, coin_hei);

    if (!success) {
        glColor3d(1.0, 1.0, 1.0);
        drawPng(texture_upgrade, upgrade_loc, button_wid, button_hei);

        glColor3d(1.0, 1.0, 1.0);
        drawPng(texture_remove, remove_loc, button_wid, button_hei);
    }
    else {
        glColor3d(1.0, 1.0, 1.0);
        drawPng(texture_back, back_loc, button_wid, button_hei);
    }
    

    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2i(1010, 120);  // sets position
    YsGlDrawFontBitmap20x32(to_string(gold).c_str()); // there are other font sizes

    if (success) {
        indicator = YOU_WIN;
    }

    glColor3d(0.0, 0.0, 1.0);
    glRasterPos2i(860, 600);  // sets position
    YsGlDrawFontBitmap12x16(indicator.c_str()); // there are other font sizes

}

void MenuManager::accrue(time_t game_time) {
    if (abs(game_time - prev_time - 1.0) < 0.1) {
        gold += goldpersec;
        prev_time = game_time;
    }

    return;
}

void MapManager::GLSetup(const char mapfn[]) {
    YsRawPngDecoder pngTemp;
    pngTemp.Decode(mapfn);
    glGenTextures(1, &texture_map);
    glBindTexture(GL_TEXTURE_2D, texture_map);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,
        0,// Level of detail
        GL_RGBA,// the "A" in RGBA will include the transparency
        pngTemp.wid,// the hippos width and height
        pngTemp.hei,
        0,// Border width, but not supported and needs to be 0
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        pngTemp.rgba);
}

bool MapManager::manage() {
    FsPollDevice();
    success = game->success();
    menu->success = success;
    key = FsInkey();
    menu->managemouse();
    manageMouse();

    if (inPlaceMode && menu->selected_tower != NONE) {
        if (menu->selected_tower == ARROW) {
            menu->gold -= menu->tower1_gold;
        }
        else if (menu->selected_tower == GUN) {
            menu->gold -= menu->tower2_gold;
        }
        game->getTower(menu->selected_tower, getTowerPos(click_loc));
        loc tmploc = getTowerPos(click_loc);
        cout << "tower placed at " << tmploc.x << " " << tmploc.y << endl;

        menu->selected_tower = NONE;
        inPlaceMode = false;
    }
    if (menu->exit == true) {
        return false;
    }
    return true;
}

void MapManager::manageMouse() {

    FsPollDevice();
    mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, screenX, screenY);
    click_loc = { screenX * 1.f, screenY * 1.f };
    if (menu->mode == UPGRADE && mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && isLegal(click_loc)) {
        int x, y;
        tie(x, y) = getTowerIdx(click_loc);
        if (areas[x][y] > 0) {

            if (menu->gold < menu->upgrade_gold) {
                cout << "not enough money to upgrade!" << endl;
                menu->indicator = menu->NOT_ENOUGH_UPGRADE;
            }
            else {
                if (areas[x][y] == 3) {
                    cout << "The tower is of the highest level!" << endl;
                    menu->indicator = menu->HIGHEST_LEVEL;
                }
                else {
                    areas[x][y] += 1;
                    game->upgradeTower(getTowerPos(click_loc));
                    menu->gold -= menu->upgrade_gold;
                    menu->indicator = menu->TOWER_UPGRADED;
                    cout << "tower upgrade!" << endl;
                }
            }
            menu->mode = DEFAULT;
        }
    }
    else if (menu->mode == REMOVE && mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && isLegal(click_loc)) {
        int x, y;
        tie(x, y) = getTowerIdx(click_loc);
        if (areas[x][y] > 0) {
            areas[x][y] = 0;
            game->removeTower(getTowerPos(click_loc));
            menu->gold += menu->remove_gold;
            cout << "tower removed!" << endl;
            menu->indicator = menu->TOWER_REMOVED;
            menu->mode = DEFAULT;
        }
    }

    if (menu->inPlaceMode && mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && isLegal(click_loc)) {
        int x, y;
        tie(x, y) = getTowerIdx(click_loc);
        if (areas[x][y] == 0) {
            areas[x][y] = 1;
            inPlaceMode = true;
            menu->inPlaceMode = false;
            menu->indicator = menu->BUILD_SUCCESS;
        }

    }
}

tuple<int, int> MapManager::getTowerIdx(loc input_loc) {
    if (!isLegal(input_loc)) {
        cout << "illegal input" << endl;
        return make_tuple<int, int>(-INT_MAX, -INT_MAX);
    }

    int x_index = input_loc.x / grid_size;
    int y_index = input_loc.y / grid_size;
    return tie(x_index, y_index);
}

loc MapManager::getTowerPos(loc input_loc) {
    int x, y;
    tie(x, y) = getTowerIdx(input_loc);
    return { x * grid_size + grid_size / 2, y * grid_size + grid_size / 2 };
}

void MapManager::showMap() {
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

    drawPng(texture_map, { 0, 0 }, 800, 800);
    if (menu->inPlaceMode) {
        paintAvailableArea();
    }
    else if (menu->mode == UPGRADE) {
        paintUpgradeArea();
    }
    else if (menu->mode == REMOVE) {
        paintRemoveArea();
    }
}
void MapManager::paintAvailableArea() {
    using namespace DrawingUtilNG;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (areas[i][j] == 0) {
                glColor3ub(240, 0, 240);
                drawRectangle(i * grid_size, j * grid_size,
                    grid_size, grid_size, true);
            }
        }
    }
}

void MapManager::paintUpgradeArea() {
    using namespace DrawingUtilNG;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (areas[i][j] > 0 && areas[i][j] < 3) {
                glColor3ub(240, 0, 240);
                drawRectangle(i * grid_size, j * grid_size,
                    grid_size, grid_size, true);
            }
        }
    }
}

void MapManager::paintRemoveArea() {
    using namespace DrawingUtilNG;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (areas[i][j] > 0) {
                glColor3ub(240, 0, 240);
                drawRectangle(i * grid_size, j * grid_size,
                    grid_size, grid_size, true);
            }
        }
    }
}