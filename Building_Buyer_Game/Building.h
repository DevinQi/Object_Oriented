//
// Create by Lihua Chen
//
//  Building.h
//  bb7k
//

#ifndef __bb7k__Building__
#define __bb7k__Building__
#include <stdio.h>
#include <string>
using namespace std;

class Player;
class Map;

class Building{
    string name; // the name of the building
    Player *owner; // the owner of a property, if the building is non-property, then the owner will be NULL
    Building *Neighbour[4];
    int Numneight; // the number of property in the same block have the same owner
    double tuit; // how much the player should pay to the owner
    double pay; // how much money a player should pay when the player want to buy this building
    double ismort; // whether the building is mortgage
    bool isprop; // can the player buy the building
    double lvl; // level of the Building
public:
    Building(string);
    virtual ~Building();
    Map *M;
    bool ismono; // check monopoly
    Player* getowner(); // find the owner
    void setowner(Player *); // define the owner
    void addneigh(Building*b);
    Building *getneigh(int); // get the neightbour
    int getnn(); // get the number of the neightbour
    double gettuit(); // find the tuition the player should pay
    void settuit(double); // update the tuition
    void setpay(double); // define how much the player should pay, if he/she want to buy the property
    double getp();       //get the pay
    bool getmort(); // check whether the property is mortgaged
    void setmort(bool); // update the ismort
    bool getprop(); // check whether the property can be bought by player
    void setprop(bool); // define whether the building is property
    string getname(); // get the name of the Building
    int getlvl(); // get the level of the property
    void setlvl(int); // set the new level (for load file)
    void uplvl(int); // update the level (for improve level)
    virtual void getpay(Player*)=0;   //pay the tuition
    virtual void imlvl(string)=0; // improve the level
    virtual void leveldown(string)=0; // sell a level
    virtual void mortgage()=0; // mortgage the property
    virtual void unmortgage()=0; // unmortgage the property
};

#endif /* defined(__bb7k__Building__) */
