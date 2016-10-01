#include "controller.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * TODO: update main function to take argument "-graphics" for part b. 
 * If -graphics argument is provided, forward this to the controller
 */
int main (int amao,char * agou[]) {
    Controller c;
    if (amao == 2) {
        std::string s = agou[1];
        if(s == "-graphics"){
            c.sett(1);
        }
    }
    c.play();
}
