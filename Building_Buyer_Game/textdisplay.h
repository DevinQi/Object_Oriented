//
// Create by Lihua Chen
//
//  textdisplay.cpp
//  bb7k
//

#ifndef __bb7k__textdisplay__
#define __bb7k__textdisplay__
#include <iostream>
#include <sstream>
#include "View.h"
using namespace std;

class textdisplay: public View {
	char ownername[40]; // save the owner of the properties
	int buildinglevel[40]; // save the improvement of the properties
	string playermap[40]; // where the player is
	string getlevel(int); // get the improvement of the properties
	string getplayer(int); // find the player in the map
	char getowner(int); // get the owner of the properties
	void replace(int, int); // replace the player's previous position
	void checkdouble(int); // when the player didn't move
public:
	textdisplay();
	~textdisplay();
	void printgame(ostream &out); // print the whole game
	void notifybuilding(int, char, int); // update the information of the building
	void notifyplayer(int, char); // update the information of the player
    void notifydelete(int, char); // there is a player quit game
};

#endif
