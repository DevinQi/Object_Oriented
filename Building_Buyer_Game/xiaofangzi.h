//
//  xiaofangzi.h
//  bb7k
//
//  Created by Devin Qi on 2015-07-20.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#ifndef __bb7k__xiaofangzi__
#define __bb7k__xiaofangzi__

#include <stdio.h>
#include "Building.h"
#include "Player.h"
using namespace std;

// gyms
class Gyms:public Building {
public:
    Gyms(string);
    ~Gyms();
    void getpay(Player*); // how much usage fee the player will pay to the owner
    void mortgage(); // mortgage the property
    void unmortgage(); // unmorgage the property
    // the following two functions are useless in Gyms, they just be used in Academic
    void imlvl(string);
    void leveldown(string);
};

// residence
class Residence:public Building {
public:
    Residence(string);
    ~Residence();
    void getpay(Player*); // how much rent the player will pay to the owner
    void mortgage(); // mortgage the property
    void unmortgage(); // unmorgage the property
    // the following two functions are useless in Gyms, they just be used in Academic
    void imlvl(string);
    void leveldown(string);
};

// OSAP
class OSAP:public Building {
public:
    OSAP(string);
    ~OSAP();
    // the following functions are useless in OSAP
    void getpay(Player*);
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};

// DC Tims Line
class DCtimsline:public Building {
public:
    DCtimsline(string);
    ~DCtimsline();
    void getpay(Player*); // how much tuition the player should pay when he/she lands on DC Tims Line
    // the following functions are useless in DCtimsline
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};
//Go to Tims
class Gototims:public Building{
public:
    Gototims(string);
    ~Gototims();
    void getpay(Player*); // the player should go to DC Tims Line
    // the following functions are useless in Gototims
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};

//Goosenesting
class Goosenesting:public Building{
public:
    Goosenesting(string);
    ~Goosenesting();
    void getpay(Player*); // there is nothing happend in Goosenesting
    // the following functions are useless in Goosenesting
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};

//Tuition
class Tuition:public Building{
public:
    Tuition(string);
    ~Tuition();
    void getpay(Player*); // how much tuition the player should pay
    // the following functions are useless in Tuition
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};

//Coop fee
class Coopfee:public Building{
public:
    Coopfee(string);
    ~Coopfee();
    void getpay(Player*); // how much tuition the player should pay
    // the following functions are useless in Coopfee
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};

//SLC
class SLC:public Building{
public:
    SLC(string);
    ~SLC();
    void getpay(Player*); // how much tuition the player should pay
    // the following functions are useless in SLC
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};

//Needles Hall
class Needleshall:public Building{
public:
    Needleshall(string);
    ~Needleshall();
    void getpay(Player*); // how much tuition the player should Needles Hall
    // the following functions are useless in Needles Hall
    void imlvl(string);
    void leveldown(string);
    void mortgage();
    void unmortgage();
};


#endif /* defined(__bb7k__xiaofangzi__) */
