
#ifndef __a3q4__player__
#define __a3q4__player__

#include <stdio.h>
#include "scoreboard.h"
#include <iostream>
#include <fstream>

class Player{
    ScoreBoard * temp;
    std::string input;
public:
    Player(std::string input,ScoreBoard *temp);
    bool move_dup(std::string &move);
    void print_move(const int who,std::ifstream &in);
};


#endif
