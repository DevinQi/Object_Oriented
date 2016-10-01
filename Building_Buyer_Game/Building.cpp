//
// Create by Lihua Chen
//
//  Building.cpp
//  bb7k
//

#include "Building.h"

Building::Building(string b):name(b),owner(NULL),Numneight(0),tuit(0),pay(0),ismort(false),isprop(false),lvl(0),M(NULL),ismono(false) {}
Building::~Building(){
    
}
Player * Building::getowner(){
    return owner;
}
void Building::setowner(Player *p) {
    owner = p;
}
void Building::addneigh(Building *b){
    Neighbour[Numneight] = b;
    ++Numneight; // add the number of neighbour that the property has
}
Building * Building::getneigh(int b){
    return Neighbour[b];
}
int Building::getnn(){
    return Numneight;
}

double Building::gettuit(){
    return tuit;
}
void Building::settuit(double b){
    tuit = b;
}
void Building::setpay(double b){
    pay = b;
}
double Building::getp(){
    return pay;
}
bool Building::getmort(){
    return ismort;
}
void Building::setmort(bool b){
    ismort = b;
}
bool Building::getprop(){
    return isprop;
}
void Building::setprop(bool b) {
    isprop = b;
}
string Building::getname(){
    return name;
}

int Building::getlvl() {
    return lvl;
}
void Building::uplvl (int newlvl) {
    lvl = newlvl;
}
void Building::setlvl(int newlvl) {
    lvl = newlvl; // set the new level
    if (name == "AL") {
        if (lvl == 1) {
            settuit(10);  // the tuition with improvement// the tuition with improvement
        } else if (lvl == 2) {
            settuit(30);  // the tuition with improvement// the tuition with improvement
        } else if (lvl == 3) {
            settuit(90);  // the tuition with improvement// the tuition with improvement
        } else if (lvl == 4) {
            settuit(160); // the tuition with improvement // the tuition with improvement
        } else if (lvl == 5) {
            settuit(250); // the tuition with improvement // the tuition with improvement
        }
    }else if (name == "ML"){
        if (lvl == 1) {
            settuit(20); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(60); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(180); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(320); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(450); // the tuition with improvement
        }
    }else if (name == "ECH"){
        if (lvl == 1) {
            settuit(30); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(90); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(270); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(400); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(550); // the tuition with improvement
        }
    }else if (name == "PAS"){
        if (lvl == 1) {
            settuit(30); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(90); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(270); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(400); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(550); // the tuition with improvement
        }
    }else if (name == "HH"){
        if (lvl == 1) {
            settuit(40); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(100); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(300); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(450); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(600); // the tuition with improvement
        }
    }else if (name == "RCH"){
        if (lvl == 1) {
            settuit(50); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(150); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(450); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(625); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(750); // the tuition with improvement
        }
    }else if (name == "DWE"){
        if (lvl == 1) {
            settuit(50); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(150); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(450); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(625); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(750); // the tuition with improvement
        }
    }else if (name == "CPH"){
        if (lvl == 1) {
            settuit(60); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(180); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(500); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(700); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(900); // the tuition with improvement
        }
    }else if (name == "LHI"){
        if (lvl == 1) {
            settuit(70); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(200); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(550); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(750); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(950); // the tuition with improvement
        }
    }else if (name == "BMH"){
        if (lvl == 1) {
            settuit(70); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(200); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(550); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(750); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(950); // the tuition with improvement
        }
    }else if (name == "OPT"){
        if (lvl == 1) {
            settuit(80); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(220); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(600); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(800); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1000); // the tuition with improvement
        }
    }else if (name == "EV1"){
        if (lvl == 1) {
            settuit(90); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(250); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(700); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(875); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1050); // the tuition with improvement
        }
    }else if (name == "EV2"){
        if (lvl == 1) {
            settuit(90); // the tuition with improvement            
        } else if (lvl == 2) {
            settuit(250); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(700); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(875); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1050); // the tuition with improvement
        }
    }else if (name == "EV3"){
        if (lvl == 1) {
            settuit(100); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(300); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(750); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(925); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1100); // the tuition with improvement
        }
    }else if (name == "PHYS"){
        if (lvl == 1) {
            settuit(110); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(330); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(800); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(975); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1150); // the tuition with improvement
        }
    }else if (name == "B1"){
        if (lvl == 1) {
            settuit(110); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(330); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(800); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(975); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1150); // the tuition with improvement
        }
    }else if (name == "B2"){
        if (lvl == 1) {
            settuit(120); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(360); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(850); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(1025); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1200); // the tuition with improvement
        }
    }else if (name == "EIT"){
        if (lvl == 1) {
            settuit(130); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(390); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(900); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(1100); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1275); // the tuition with improvement
        }
    }else if (name == "ESC"){
        if (lvl == 1) {
            settuit(130); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(390); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(900); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(1100); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1275); // the tuition with improvement
        }
    }else if (name == "C2"){
        if (lvl == 1) {
            settuit(150); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(450); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(1000); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(1200); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1400); // the tuition with improvement
        }
    }else if (name == "MC"){
        if (lvl == 1) {
            settuit(175); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(500); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(1100); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(1300); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(1500); // the tuition with improvement
        }
    }else if (name == "DC"){
        if (lvl == 1) {
            settuit(200); // the tuition with improvement
        } else if (lvl == 2) {
            settuit(600); // the tuition with improvement
        } else if (lvl == 3) {
            settuit(1400); // the tuition with improvement
        } else if (lvl == 4) {
            settuit(1700); // the tuition with improvement
        } else if (lvl == 5) {
            settuit(2000); // the tuition with improvement
        }
    }
}


