//
//  textdisplay.cpp
//  a4q2
//
//  Created by Devin Qi on 2015-07-11.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#include "textdisplay.h"

TextDisplay::TextDisplay(int n):View(n){
    theDisplay = new char *[n];
    for(int i = 0;i<n;++i){
        theDisplay[i] = new char[n];
        for(int j = 0; j < n;++j){
            theDisplay[i][j] = '0';
        }
    }
}

void TextDisplay::notify(int r, int c, char ch){
    theDisplay[r][c] = ch;
}

void TextDisplay::print(std::ostream &out){
    for(int i = 0;i<gridSize;++i){
        for(int j = 0; j < gridSize;++j){
            out<<theDisplay[i][j];
        }
        out<<std::endl;
    }
}

TextDisplay::~TextDisplay(){
    for(int i = 0;i < gridSize;++i){
        delete[] theDisplay[i];
    }
    delete [] theDisplay;
}

