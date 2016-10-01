//
// Created by Lihua Chen
//
//  Map.h
//  bb7k
//

#ifndef __bb7k__Map__
#define __bb7k__Map__

#include <stdio.h>
#include <iostream>
#include "Building.h"
#include "xiaofangzi.h"
#include "Academic.h"

using namespace std;
class Mapnotify{}; // the base class of Controller to avoid include too much file with multiple times

class Map{
    int numRURC; // the number of RURC is free to give player
public:
    Map();
    ~Map();
    Building * playmap[40];
    Mapnotify *C;
    int getRURC(); 
    void setRURC(int); // change the number of RURC
    Building * getpm(int);   // find a building which is the ith step in the map
    void initial(); // create a new game map
    bool mortgage(string, string); // mortgage a property
    bool unmortgage(string, string); // unmortgage a property
};

#endif /* defined(__bb7k__Map__) */
