

#ifndef __a3q4__scoreboard__
#define __a3q4__scoreboard__

#include <stdio.h>
#include <string>
#include<iostream>
#include<cstdlib>
class ScoreBoard{
    static ScoreBoard *pb;
    static void cleanup();
public:
    int XS;
    int OS;
    int step;
    ScoreBoard();
    int pg[9];
    bool end;
    static ScoreBoard * getpb();
    void presult(const int who);
    void next_step(const int who,const std::string&move);
};
#endif
