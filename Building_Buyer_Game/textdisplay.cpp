//
// Create by Lihua Chen
//
//  textdisplay.cpp
//  bb7k
//

#include "textdisplay.h"
#include "Building.h"
#include "Player.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string textdisplay::getlevel(int bp) {
	string level = "";
	char addl = 'I';
	int lvl = buildinglevel[bp];
	for (int i = 0; i < 8; ++i) {
		// Each improvement is represented by an I in the top row of the property it belongs to in the text display.
		if (i < lvl) level += addl; 
		else level += " ";
	}
	return level;
}

string textdisplay::getplayer(int bp) {
	string playerp = "";
	string p = playermap[bp];
	int len = (unsigned int)p.length();
	for (int i = 0; i < 8; ++i) {
		// print the pieces, which the player chose in the beginning of the game,  to represent players on the board
		if (i < len) playerp += p[i];
		else playerp += " ";
	}
	return playerp;
}

char textdisplay::getowner(int bp) {
	return ownername[bp]; // find the owner of the building
}

void textdisplay::replace(int cp, int pp) {
	int len = (unsigned int)playermap[pp].length(); // count the number of the player lands on this building
	                                                // before a player move
	string s;
	for (int i = 0; i < len; ++i) {
        if (cp == i) continue; // there is a player moving
        s += playermap[pp][i];
	}
    playermap[pp] = s; // the other players lands on the building
}

void textdisplay::checkdouble(int pp) {
	string s = playermap[pp];
	int len = (unsigned int)s.length(); // count the number of the player lands on this building
	                                    // before a player move
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < i; ++j) {
			if (s[j] == s[i]) replace(j, pp); // a player didn't move
		}
	}
}

textdisplay::textdisplay() {
	for (int i = 0; i < 40; ++i) {
		ownername[i] = ' '; // there is no owner of properties at first
		buildinglevel[i] = 0; // the initial improvement of properties are 0
		playermap[i] = ""; // there is no player lands on any building
	}
}

textdisplay::~textdisplay(){}

void textdisplay::printgame(ostream &out){
	out << "____________________________________________________________________________________________________" << endl;
	out << "|Goose   |" << getlevel(21)<< "|NEEDLES |" << getlevel(23) << "|" << getlevel(24) <<"|V1      |" << getlevel(26) << "|" << getlevel(27) << "|CIF     |" << getlevel(29) << "|GO TO   |" << endl;
	out << "|Nesting |--------|HALL    |--------|--------|owner: " << getowner(25) << "|--------|--------|owner: " << getowner(28) << "|--------|TIMS    |" << endl;
	out << "|        |EV1     |        |EV2     |EV3     |        |PHYS    |B1      |        |B2      |        |" << endl;
	out << "|        |owner: " << getowner(21) << "|        |owner: " << getowner(23) << "|owner: " << getowner(24) << "|        |owner: " << getowner(26) << "|owner: " << getowner(27) << "|        |owner: " << getowner(29) << "|        |" << endl;
	out << "|" << getplayer(20) << "|" << getplayer(21) << "|" << getplayer(22) << "|" << getplayer(23) << "|" << getplayer(24) << "|" << getplayer(25) << "|" << getplayer(26) << "|" << getplayer(27) << "|" << getplayer(28) << "|" << getplayer(29) << "|" << getplayer(30) << "|" << endl;
	out << "|________|________|________|________|________|________|________|________|________|________|________|" << endl;
	out << "|" << getlevel(19) << "|                                                                                |" << getlevel(31) << "|" << endl;
	out << "|--------|                                                                                |--------|" << endl;
	out << "|OPT     |                                                                                |EIT     |" << endl;
	out << "|owner: " << getowner(19) << "|                                                                                |owner: " << getowner(31) << "|" << endl;
	out << "|" << getplayer(19) << "|                                                                                |" << getplayer(31) << "|" << endl;
	out << "|________|                                                                                |________|" << endl;
	out << "|" << getlevel(18) << "|                                                                                |" << getlevel(32) << "|" << endl;
	out << "|--------|                                                                                |--------|" << endl;
	out << "|BMH     |                                                                                |ESC     |" << endl;
	out << "|owner: " << getowner(18) << "|                                                                                |owner: " << getowner(32) << "|" << endl;
	out << "|" << getplayer(18) << "|                                                                                |" << getplayer(32) << "|" << endl;
	out << "|________|                                                                                |________|" << endl;
	out << "|SLC     |                                                                                |SLC     |" << endl;
	out << "|        |                                                                                |        |" << endl;
	out << "|        |                                                                                |        |" << endl;
	out << "|        |                                                                                |        |" << endl;
	out << "|" << getplayer(17) << "|                                                                                |" << getplayer(33) << "|" << endl;
	out << "|________|                                                                                |________|" << endl;
	out << "|" << getlevel(16) << "|                                                                                |" << getlevel(34) << "|" << endl;
	out << "|--------|                                                                                |--------|" << endl;
	out << "|LHI     |                                                                                |C2      |" << endl;
	out << "|owner: " << getowner(16) << "|                                                                                |owner: " << getowner(34) << "|" << endl;
	out << "|" << getplayer(16) << "|                   __________________________________________                   |" << getplayer(34) << "|" << endl;
	out << "|________|                   |                                        |                   |________|" << endl;
	out << "|UWP     |                   |  ###   ###    #####  ###   ###   ###   |                   |REV     |" << endl;
	out << "|owner: " << getowner(15) << "|                   |  #  #  #  #      #  #   # #   # #   #  |                   |owner: " << getowner(35) << "|" << endl;
	out << "|        |                   |  ####  ####     #   #   # #   # #   #  |                   |        |" << endl;
	out << "|        |                   |  #   # #   #   #    #   # #   # #   #  |                   |        |" << endl;
	out << "|" << getplayer(15) << "|                   |  ####  ####   #      ###   ###   ###   |                   |" << getplayer(35) << "|" << endl;
	out << "|________|                   |________________________________________|                   |________|" << endl;
	out << "|" << getlevel(14) << "|                                                                                |NEEDLES |" << endl;
	out << "|--------|                                                                                |HALL    |" << endl;
	out << "|CPH     |                                                                                |        |" << endl;
	out << "|owner: " << getowner(14) << "|                                                                                |        |" << endl;
	out << "|" << getplayer(14) << "|                                                                                |" << getplayer(36) << "|" << endl;
	out << "|________|                                                                                |________|" << endl;
	out << "|" << getlevel(13) << "|                                                                                |" << getlevel(37) << "|" << endl;
	out << "|--------|                                                                                |--------|" << endl;
	out << "|DWE     |                                                                                |MC      |" << endl;
	out << "|owner: " << getowner(13) << "|                                                                                |owner: " << getowner(37) << "|" << endl;
	out << "|" << getplayer(13) << "|                                                                                |" << getplayer(37) << "|" << endl;
	out << "|________| 			                                                          |________|" << endl;
	out << "|PAC     |          		                                                          |COOP    |" << endl;
	out << "|owner: " << getowner(12) << "|                                                                                |FEE     |" << endl;
	out << "|        |                                                                                |        |" << endl;
	out << "|        |                                                                                |        |" << endl;
	out << "|" << getplayer(12) << "|                                                                                |" << getplayer(38) << "|" << endl;
	out << "|________|                                                                                |________|" << endl;
	out << "|" << getlevel(11) << "|                                                                                |" << getlevel(39) << "|" << endl;
	out << "|--------|                                                                                |--------|" << endl;
	out << "|RCH     |                                                                                |DC      |" << endl;
	out << "|owner: " << getowner(11) << "|                                                                                |owner: " << getowner(39) << "|" << endl;
	out << "|" << getplayer(11) << "|                                                                                |" << getplayer(39) << "|" << endl;
	out << "|________|________________________________________________________________________________|________|" << endl;
	out << "|DC Tims |" << getlevel(9) << "|" << getlevel(8) << "|NEEDLES |" << getlevel(6) << "|MKV     |TUITION |" << getlevel(3) << "|SLC     |" << getlevel(1) << "|COLLECT |" << endl;
	out << "|Line    |--------|--------|HALL    |--------|owner: " << getowner(5) << "|        |--------|        |--------|OSAP    |" << endl;
	out << "|        |HH      |PAS     |        |ECH     |        |        |ML      |        |AL      |        |" << endl;
	out << "|        |owner: " << getowner(9) << "|owner: " << getowner(8) << "|        |owner: " << getowner(6) << "|        |        |owner: " << getowner(3) << "|        |owner: " << getowner(1) << "|        |" << endl;
	out << "|" << getplayer(10) << "|" << getplayer(9) << "|" << getplayer(8) << "|" << getplayer(7) << "|" << getplayer(6) << "|" << getplayer(5) << "|" << getplayer(4) << "|" << getplayer(3) << "|" << getplayer(2) << "|" << getplayer(1) << "|" << getplayer(0) << "|" << endl;
	out << "|________|________|________|________|________|________|________|________|________|________|________|" << endl;
}

void textdisplay::notifybuilding(int bp, char o, int lvl) {
	ownername[bp] = o; // set owner
	buildinglevel[bp] = lvl; // update improvements
}

void textdisplay::notifyplayer(int pp, char pc) {
	playermap[pp] += pc;
	for (int i = 0; i < 40; ++i) {
        if (i == pp) { // when the player did not move
        	checkdouble(i);
        	continue;
        }
        // if the player is move
		string h = playermap[i];
		int len = (unsigned int)h.length();
		if (len > 0) {
			for (int j = 0; j < len; ++j) {
				if (pc == h[j]) { // find the piece the player chose to represent hiself/herself in the beginning of the game
					replace(j, i); // move the player
					return;
				}
			}
		}
	}
}

void textdisplay::notifydelete(int pp, char pc) {
    string h = playermap[pp];
    int len = (unsigned int)h.length();
    for (int j = 0; j < len; ++j) {
        if (pc == h[j]) { // find the piece the player chose to represent hiself/herself in the beginning of the game
            replace(j, pp); // move the player
            return;
        }
    }
}



