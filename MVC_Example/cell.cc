//
//  cell.cpp
//  a4q2
//
//  Created by Devin Qi on 2015-07-11.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//
#include "cell.h"
#include "game.h"

Cell::Cell():state(0),numNeighbours(0),r(0),c(0),game(0){}

char Cell::getState(){
    return prevState;
}
void Cell::setState(const int& change){
    prevState = state;
    state = change;
}

void Cell::setCoords(const int r, const int c){
    this->r = r;
    this->c = c;
}

void Cell::setGame(Game * game){
    this->game = game;
}

void Cell::addNeighbour(Cell *neighbour){
    if(numNeighbours > 4){
        std::cerr << "Cannot add neighbour to it"<<std::endl;
    }
    neighbours[numNeighbours] = neighbour;
    ++numNeighbours;
}

void Cell::notify( const int & change){
    setState(change);
    notifyGame();
    notifyNeighbours();
}

void Cell::notify( const int & current, const int & previous){
    for(int i=0;i<numNeighbours;++i){
        if(neighbours[i]->state==previous){
            neighbours[i]->setState(current);
            neighbours[i]->notifyGame();
            neighbours[i]->notify(current,previous);
        }
    }
}

void Cell::notifyGame(){
    game->notify(r,c, prevState,state);
}

void Cell::notifyNeighbours(){
    notify(state,prevState);
}


