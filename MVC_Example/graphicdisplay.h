//
//  GraphicDisplay.h
//  a4q2
//
//  Created by Devin Qi on 2015-07-12.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#ifndef __a4q2__GraphicDisplay__
#define __a4q2__GraphicDisplay__

#include <iostream>
#include <sstream>
#include "view.h"
#include "window.h"

class GraphicDisplay : public View {
    char **theDisplay;          //the n x n display
    Xwindow * xw;
    
public:
    GraphicDisplay(int n); //one arg constructor where the parameter is the gridSize
    
    ~GraphicDisplay(); //dtor
    
    /*
     * The Controller calls notify to
     * update the (r,c) location to be ch
     */
    virtual void notify(int r, int c, char ch);
    
    /*
     * Prints the grid as specified in the assignment specification.
     */
    virtual void print(std::ostream &out);
};
#endif /* defined(__a4q2__GraphicDisplay__) */
