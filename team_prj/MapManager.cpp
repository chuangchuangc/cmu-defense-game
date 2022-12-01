//
//  MapManager.cpp
//
//  Created by Valen Hsu on 11/21/22.
//


#include "MapManager.h"

void MenuManager::GLSetup(const char menufn[], const char coinfn[], const char tower1fn[], const char tower2fn[],
    const char tower3fn[]) {
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

    pngTemp.Decode(tower3fn);
    glGenTextures(1, &texture_tower3);
    glBindTexture(GL_TEXTURE_2D, texture_tower3);
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

void MenuManager::managemouse() {
    FsPollDevice();
    int mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, screenX, screenY);
    loc click_loc = { screenX * 1.f, screenY * 1.f };
    if (mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && isLegal(click_loc)) {
        if (isLegal(click_loc) && !inPlaceMode) {
            selected_tower = getTower(click_loc);
        }
        //mouseEvent = 0;
    }
    return;
}

ToKind  MenuManager::getTower(loc click_loc) {
    if (!isLegal(click_loc)) {
        cout << "unable to place tower here" << endl;
        return NONE;
    }
    
    if (abs(click_loc.x - tower1_loc.x) > 0 && abs(click_loc.x - tower1_loc.x) < tower_wid && abs(click_loc.y - tower1_loc.y) > 0 && abs(click_loc.y - tower1_loc.y) < tower_hei) {
        if (gold >= tower1_gold) {
            cout << "ARROW is chosen" << endl;
            inPlaceMode = true;
            return ARROW;
        } else {
            cout << "not enought money for ARROW!" << endl;
            inPlaceMode = false;
            return NONE;
        }
    } else if (abs(click_loc.x - tower2_loc.x) > 0 && abs(click_loc.x - tower2_loc.x) < tower_wid && abs(click_loc.y - tower2_loc.y) > 0 && abs(click_loc.y - tower2_loc.y) < tower_hei) {
        if (gold >= tower2_gold) {
            cout << "GUN is chosen" << endl;
            inPlaceMode = true;
            return GUN;
        } else {
            cout << "not enought money for GUN!" << endl;
            inPlaceMode = false;
            return NONE;
        }
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
    drawPng(texture_coin, { 880, 240 }, coin_wid/2, coin_hei/2);
    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2i(920, 265);
    YsGlDrawFontBitmap12x16(to_string(tower1_gold).c_str());


    glColor3d(1.0, 1.0, 1.0);
    drawPng(texture_tower2, tower2_loc, tower_wid, tower_hei);
    drawPng(texture_coin, { 1030, 240 }, coin_wid/2, coin_hei/2);
    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2i(1070, 265);
    YsGlDrawFontBitmap12x16(to_string(tower2_gold).c_str());

    glColor3d(1.0, 1.0, 1.0);
    drawPng(texture_tower3, tower3_loc, tower_wid, tower_hei);
    drawPng(texture_coin, { 880, 390 }, coin_wid / 2, coin_hei / 2);
    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2i(920, 415);
    YsGlDrawFontBitmap12x16(to_string(tower1_gold).c_str());

    glColor3d(1.0, 1.0, 1.0);
    drawPng(texture_coin, { 950, 80 }, coin_wid, coin_hei);

    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2i(1010, 120);  // sets position
    YsGlDrawFontBitmap20x32(to_string(gold).c_str()); // there are other font sizes

    if (selected_tower == ARROW) {
        glColor3d(0.0, 0.0, 1.0);
        glRasterPos2i(860, 600);  // sets position
        YsGlDrawFontBitmap20x32("Arrow is chosen"); // there are other font sizes
    }else if (selected_tower == GUN) {
        glColor3d(0.0, 0.0, 1.0);
        glRasterPos2i(860, 600);  // sets position
        YsGlDrawFontBitmap20x32("Gun is chosen"); // there are other font sizes
    }
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
    if (inEditMode) {
        if (key == FSKEY_U) {
            if (menu->gold < menu->upgrade_gold) {
                cout << "not enough money to upgrade!" << endl;
            } else {
                game->upgradeTower(getTowerPos(click_loc));
                menu->gold -= menu->upgrade_gold;
                cout << "tower upgrade!" << endl;
            }
            inEditMode = false;
        } else if (key == FSKEY_D) {
            int x, y;
            tie(x, y) = getTowerIdx(click_loc);
            existtower[x][y] = false;
            game->removeTower(getTowerPos(click_loc));
            menu->gold += menu->remove_gold;
            cout << "tower removed!" << endl;
            inEditMode = false;

        }
    }
    return true;
}

void MapManager::manageMouse() {

    FsPollDevice();
    mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, screenX, screenY);
    click_loc = { screenX * 1.f, screenY * 1.f };
    if (mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && isLegal(click_loc)) {
        int x, y;
        tie(x, y) = getTowerIdx(click_loc);
        if (existtower[x][y]) {
            inEditMode = true;
            cout << "\tChoose:" << endl;
            cout << "\t\tUpgrade Tower: U" << endl;
            cout << "\t\tRemove Tower: D" << endl;
        } else if (isLegal(click_loc) && !existtower[x][y] && menu->inPlaceMode) {
            existtower[x][y] = true;
            inPlaceMode = true;
            menu->inPlaceMode = false;
        }
        //mouseEvent = 0;
    }
    return;
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

//void MapManager::editTower(loc click_loc) {
//    
//
//
//    if (existtower[x_index][y_index]) {
//        
//
//        FsPollDevice();
//        int key = FsInkey();
//        if (key == FSKEY_U) {
//            game->upgradeTower(tower_pos);
//            return;
//        } else if (key == FSKEY_D) {
//            existtower[x_index][y_index] = false;
//            game->removeTower(tower_pos);
//
//            return;
//        }
//        key = FSKEY_NULL;
//
//        return;
//    }
//
//
//}
//
//loc MapManager::placeTower(loc click_loc) {
//    if (!isLegal(click_loc)) {
//        cout << "unable to place tower here" << endl;
//        return { -INFINITY, -INFINITY };
//    }
//
//    float grid_size = 800.0 / 12;
//
//    int x_index = click_loc.x / grid_size;
//    int y_index = click_loc.y / grid_size;
//
//    if (existtower[x_index][y_index]) {
//        cout << "there is already a tower here" << endl;
//        return { -INFINITY, -INFINITY };
//    }
//
//    existtower[x_index][y_index] = true;
//    return { x_index * grid_size + grid_size / 2, y_index * grid_size + grid_size / 2 };
//    
//}

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
}
