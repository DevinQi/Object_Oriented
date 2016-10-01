#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <sstream>

class View { // the base class of textdisplay
public:
	View();
	virtual ~View();
	virtual void printgame(std::ostream &out);
	virtual void notifybuilding(int, char, int);
	virtual void notifyplayer(int, char);
    virtual void notifydelete(int, char);
};

#endif
