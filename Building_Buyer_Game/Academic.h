//
//  xiaofangzi.h
//  bb7k
//
//  Created by Devin Qi on 2015-07-20.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#ifndef __bb7k__Academic__
#define __bb7k__Academic__

#include <stdio.h>
#include "Building.h"
#include "Player.h"
using namespace std;

class Academic: public Building {
public:
    Academic(string);
    ~Academic();
    void getpay(Player*); // how much tuition the player will pay to the owner
    void imlvl(string); // level up the academic building
    void leveldown(string); // level down the academic building
    void mortgage(); // mortgage the property
    void unmortgage(); // unmorgage the property
};

#endif /* defined(__bb7k__xiaofangzi__) */
