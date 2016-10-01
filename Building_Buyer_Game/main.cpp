//
//  main.cpp
//  bb7k
//
//  Created by Devin Qi on 2015-07-20.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#include <iostream>
#include "Controller.h"

int main(int amao,char * agou[]) {
    Controller * c = new Controller;
    //c->newgame();
    if (amao == 3) {
        std::string s = agou[1];
        std::string filename = agou[2];
        if(s == "-load"){
            c->loadfileoption = true;
            c->filename = filename;
        }
    }else if(amao == 2){
        std::string s = agou[1];
        cout << "pass"<<" "<<s  <<endl;
        if(s == "-testing"){
            c->test = true;
        }
    }
    c->play();
    delete c;
}
