#include "View.h"

View::View() {}
View::~View() {}

void View::printgame(std::ostream &out) {} // print the game
void View::notifybuilding(int, char, int){} // update the information of the building
void View::notifyplayer(int, char){} // update the information of players
void View::notifydelete(int, char){} // there is a player quit game

