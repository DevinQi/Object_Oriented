//
//  GraphicDisplay.cpp
//  a4q2
//
//  Created by Devin Qi on 2015-07-12.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#include "graphicdisplay.h"

GraphicDisplay::GraphicDisplay(int n):View(n){
    xw = new Xwindow;
}

void GraphicDisplay::notify(int r, int c, char ch){
    int tn = 500 / gridSize;
    xw->fillRectangle(r*tn, c*tn, tn, tn,ch-'0');
}

void GraphicDisplay::print(std::ostream &out){
}

GraphicDisplay::~GraphicDisplay(){
    delete xw;
}



