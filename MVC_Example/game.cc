//
//  game.cpp
//  a4q2
//
//  Created by Devin Qi on 2015-07-11.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//
#include "game.h"

Game::Game():gridSize(0),notification(0),theGrid(0){}
Game::~Game(){
    clearGame();
}

void Game::clearGame(){
    for(int i = 0; i < gridSize; ++i){
        delete[] theGrid[i];
    }
    delete[] theGrid;
}

void Game::notify(int r, int c, unsigned int oldState, unsigned int newState){
    notification->notify(r, c, newState);
    --colours[oldState];
    ++colours[newState];
}

bool Game::isWon(){
    int t = gridSize * gridSize;
    if(colours[0] == t || colours[1] == t ||colours[2] == t ||colours[3] == t ||colours[4] == t){
        return 1;
    }else{
        return 0;
    }
}

void Game::init(int n, GameNotification *gameNotification){
    notification = gameNotification;
    if(theGrid != NULL){
        clearGame();
    }
    gridSize = n;
    theGrid = new Cell *[gridSize];
    for (int i = 0;i<gridSize;++i){
        theGrid[i] = new Cell[gridSize];
    }
    for(int i = 0; i < gridSize;++i){
        for(int j = 0; j < gridSize;++j){
            theGrid[i][j].setGame(this);
            theGrid[i][j].setState(0);
            theGrid[i][j].setCoords(i,j);
        }
    }
    for(int i = 0; i< gridSize;++i){
        for(int j = 0; j < gridSize;++j){
            if(i-1 >= 0) theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
            if(j-1 >= 0) theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
            if(i+1 < gridSize) theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
            if(j+1 < gridSize) theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
        }
    }
    colours[0] = gridSize * gridSize;
    colours[1] = 0;
    colours[2] = 0;
    colours[3] = 0;
    colours[4] = 0;
}

void Game::change(const int & c){
    theGrid[0][0].notify(c);
}

void Game::init(int r, int c, int change){
    if(r >= gridSize || c >=gridSize){
        return;
    }
    if(r < 0||c <0){
        return;
    }
    theGrid[r][c].setState(change);
    notification->notify(r, c, change);
    --colours[theGrid[r][c].getState()];
    ++colours[change];
}




