//
//  Controller.h
//  bb7k
//
//  Created by Devin Qi on 2015-07-22.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#ifndef __bb7k__Controller__
#define __bb7k__Controller__

#include <stdio.h>
#include "Map.h"
#include "Player.h"
#include "View.h"

class Controller:public Mapnotify{
    Player * pl[8];
    Map * M;
    View * t;
    int numplayer;
public:
    bool test;
    bool loadfileoption;
    string filename;
    void newgame();
    void play();
    Controller();
    ~Controller();
    //void notify(int bp,string on);
    void cleangame();
    void auction(Building *,int);   // auction
};

#endif /* defined(__bb7k__Controller__) */
