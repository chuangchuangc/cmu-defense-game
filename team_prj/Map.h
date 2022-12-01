//
//  Map.hpp
//  Group_projcet
//
//  Created by Zhenguan You on 11/10/22.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <math.h>
#include <vector>
#include "DrawingUtilNG.h"
#include "yssimplesound.h"
#include "ysglfontdata.h"
#include "yspng.h"
#include "fssimplewindow.h"


#endif /* Map_hpp */
using namespace DrawingUtilNG;


class Map {
protected:
    float BLOCK_SIZE = 800/12;
    int NUM_PER_LINE = 12;
    bool* blocks;
private:
    int getIndex(int x, int y) {
        return y * NUM_PER_LINE + x;
    }
    int getY(int index) {
        return index / NUM_PER_LINE;
    }
    int getX(int index) {
        return index - index / NUM_PER_LINE;
    }
public:
    Map(std::vector<int> avail_list) {
        for (int j = 0; j < NUM_PER_LINE * NUM_PER_LINE; j++) {
            blocks[j] = false;
        }
        for (auto i : avail_list) {
            blocks[avail_list[i]] = true;
        }
    }
    int getBlock(float x, float y) {
        int divX = x/BLOCK_SIZE;
        int divY = y/BLOCK_SIZE;
        return getIndex(divX, divY);
    }
    void drawBlock(int index) {
        int x = index / NUM_PER_LINE;
        int y = index - x * NUM_PER_LINE;
        glColor3ub(255, 0, 0);  // red
        drawRectangle(x * BLOCK_SIZE, y * BLOCK_SIZE,
            BLOCK_SIZE, BLOCK_SIZE, true);
    }
};
