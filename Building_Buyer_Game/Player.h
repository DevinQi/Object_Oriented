//
//  Player.h
//  bb7k
//
//  Created by Devin Qi on 2015-07-20.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#ifndef __bb7k__Player__
#define __bb7k__Player__

#include <string>
//#include "Building.h"
//#include "xiaofangzi.h"
//#include "Academic.h"
#include "Map.h"
using namespace std;

class Building;
//class Map;

class Player{
    int p; // the current position of player
    double money;
    Map* M;
    char name;
    string truename;
    double totalcost;
    int RURC;
public:
    int numtims;             //the number of times that player has been send to dc timeline
    bool sendtims;          //whether player be sent to tims
    bool abilroll;          //ability to roll a dice
    Player(char,string,Map*);
    ~Player();
    Building * b[40];   // this Building array is the Building player owned
    int Numb;           //number of building
    void settc(double);   //set total cost
    double gettc();        //get totalcost
    char getname();     // get the name
    void changemoney(double); // change money
    double getmoney();   //get the amount of money
    int rollingdice();    //roll two dice
    void buyb(int,int);        //buy building
    void setM(Map *);        //set Map
    int getp(); // get the current position of player
    void changep(int);     //change position
    void gotot();         //go to tims
    void goosap();         //go to osap
    void changeRURC(int); //change the number of RURC
    int getRURC();
    void checkneigh(int); // check the monorpoly
    string gettname();
};


#endif /* defined(__bb7k__Player__) */
