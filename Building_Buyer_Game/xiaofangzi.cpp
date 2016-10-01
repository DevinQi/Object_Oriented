//
//  xiaofangzi.cpp
//  bb7k
//
//  Created by Devin Qi on 2015-07-20.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#include "xiaofangzi.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>
#include <ctime>
using namespace std;

// gyms
Gyms::Gyms(string s):Building(s){}
Gyms::~Gyms(){}
void Gyms::getpay(Player *p){
    if ((p->gettname() == getowner()->gettname()) && (!getmort())) return;
    double t = p->rollingdice(); // rolling dice
    double pcost; // save the usage fee
    if (getnn() < 1) pcost = t * 4; 
    // If the owner of this Gyms has only one Gyms, the fee is 4 times the sum of the dice.
    else pcost = t * 10;
    // If the owner of this Gyms has only two Gyms, the fee is 4 times the sum of the dice.
    p->changemoney(-pcost);
    p->settc(-pcost);
    if (!getmort()) { // check whethe the property is mortgaged
        getowner()->changemoney(pcost); // pay to the owner
        getowner()->settc(pcost); // change the total worth of the owner
        cout << p->gettname() << " pays $" << pcost << " to " << getowner()->gettname() << endl;
    } else { // if the property is mortgage, the owner cannot get the usage fees
        cout << p->gettname() << " pays $" << pcost << "." << endl;
    }
}
void Gyms::imlvl(string s){
    cout << "You cannot improve a Gyms." << endl;
}
void Gyms::leveldown(string s) {
    cout << "You cannot sell an improvement of Gyms." << endl;
}
void Gyms::mortgage() {
    if (getmort()) { // check whethe the property is mortgaged
        cout << "Sorry! " << getname() << " is already mortgaged!" << endl;
        cout << "You cannot mortgages it twice!" << endl;
        return;
    }
    setmort(true); // update ismort
    Player *p = getowner(); // find the owner
    double pcost = getp(); // how much money the owner cost to but the building
    double pget = pcost/2; // the owner can just get half of the cost of the property
    p->changemoney(pget); // change the owner's money
    cout << getowner()->gettname() << " gets " << pget << " after he/she mortgages the " << getname() << endl;
}
void Gyms::unmortgage() {
    if (getmort()) { // check whether the property is mortgaged
        cout << "You didn't mortgage " << getname() << "." << endl;
        cout << "You do not need to unmortgage it." << endl; 
    }
    // To unmortgage a property, the player must pay half of the cost of the property plus 10%.
    char t;
    Player *p = getowner();
    double pcost = getp()*0.5; // how much the new owner should pay to the bank
    p->changemoney(-(pcost*0.1)); // the owner should pay 10% of the purchase cost of the property to bank
    p->settc(-(pcost*0.1)); // the owner's total worth will lose 10% of the purchase cost of the property
    cout << "Do you want to unmortgage the property? y/n" << endl;
    cin >> t;
    if (t == 'y') {
        cout << p->gettname() << " wants to unmortgage the property." << endl;
        cout << p->gettname() << " pays " << pcost << " to the bank." << endl;
        pcost = getp()*0.5; // how much the new owner should pay to the bank
        p->changemoney(-pcost); // the new owner pay half of the property to bank
        setmort(false); // set the mortgage is false
        cout << p->gettname() << " pays " << pcost << " to the bank to unmortgage" << getname() << "." << endl;
    }
}

// residence
Residence::Residence(string s):Building(s){}
Residence::~Residence(){}
void Residence::getpay(Player *p) {
    if ((p->gettname() == getowner()->gettname()) && (!getmort())) return;
    double pcost = 0.0;
    if (getnn() == 0) pcost = 25;
    else if (getnn() == 1) pcost = 50;
    else if (getnn() == 2) pcost = 100;
    else if (getnn() == 3) pcost = 200;
    p->changemoney(-pcost);
    p->settc(-pcost);
    if (!getmort()) {
        getowner()->changemoney(pcost); // pay to the owner
        getowner()->settc(pcost);
        cout << p->gettname() << " pays $" << pcost << " to " << getowner()->gettname() << endl;
    } else {
        cout << p->gettname() << " pays $" << pcost << "." << endl;
    }
}

void Residence::imlvl(string s){
    cout << "You cannot improve a Residence." << endl;
}
void Residence::leveldown(string s){
    cout << "You cannot sell an improvement of Residence." << endl;
}
void Residence::mortgage() {
    if (getmort()) { // check whether the property is mortgaged
        cout << "Sorry! " << getname() << " is already mortgaged!" << endl;
        cout << "You cannot mortgages it twice!" << endl;
        return;
    }
    setmort(true); // update ismort
    Player *p = getowner(); // find the owner
    double pcost = getp(); // how much money the owner cost to but the building
    double pget = pcost/2; // the owner can just get half of the cost of the property
    p->changemoney(pget); // change the owner's money
    cout << getowner()->gettname() << " gets " << pget << " after he/she mortgages the " << getname() << endl;
}
void Residence::unmortgage() {
    if (getmort()) { // check whether the property is mortgaged
        cout << "You didn't mortgage " << getname() << "." << endl;
        cout << "You do not need to unmortgage it." << endl; 
    }
    // To unmortgage a property, the player must pay half of the cost of the property plus 10%.
    char t;
    Player *p = getowner();
    double pcost = getp()*0.5; // how much the new owner should pay to the bank
    p->changemoney(-(pcost*0.1)); // the owner should pay 10% of the purchase cost of the property to bank
    p->settc(-(pcost*0.1)); // the owner's total worth will lose 10% of the purchase cost of the property
    cout << "Do you want to unmortgage the property? y/n" << endl;
    cin >> t;
    if (t == 'y') {
        cout << p->gettname() << " wants to unmortgage the property." << endl;
        cout << p->gettname() << " pays " << pcost << " to the bank." << endl;
        pcost = getp()*0.5; // how much the new owner should pay to the bank
        p->changemoney(-pcost); // the new owner pay half of the property to bank
        setmort(false); // set the mortgage is false
        cout << p->gettname() << " pays " << pcost << " to the bank to unmortgage" << getname() << "." << endl;
    }
}

// OSAP
OSAP::OSAP(string s):Building(s){}
void OSAP::getpay(Player *p) {}
OSAP::~OSAP(){}
void OSAP::imlvl(string s){}
void OSAP::leveldown(string s){}
void OSAP::mortgage() {}
void OSAP::unmortgage() {}

// DC Tims Line
DCtimsline::DCtimsline(string s):Building(s) {}
DCtimsline::~DCtimsline(){}
void DCtimsline::getpay(Player* p){
    if (!p->sendtims) return; // check whether the player is sent to DC Tims Line, 
                              // if not, there is nothing happened
    cout << p->gettname() << " lands on the DC Tims Line. You are not allowed to move." << endl; 
    p->abilroll = false; // the player cannot move
    char c;
    if (p->getRURC() > 0) { // check whether the player have Roll Up the Rim cup
        cout << "Do you want to use a Roll Up the Rim cup? y/n" << endl;
        cin >> c;
        cout << p->gettname() << " :" << c << endl;
        if (c == 'y') {
            p->changeRURC(-1); // delete one Roll Up the Rim cup of the player hold
            p->abilroll = true; // the player can move now
            M->setRURC(1); // there is one more Roll Up the Rim cup free to players win
            return;
        }
    }
    if (p->numtims < 2) {
        cout << "Do you want to try to roll doubles? y/n" << endl;
        cin >> c;
        if (c == 'y') {
            cout << p->gettname() << " want to try to roll doubles" << c << endl;
            int dice1;
            int dice2;
            srand((unsigned int) time (NULL));
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            // try to roll doubles
            if (dice1 == dice2) {
                cout << "Congratulation! You roll doubles!! You are allowed to move." << endl;
                p->abilroll = true; // if the player roll doubles, he/she can move now
                return;
            } else {
                cout << "Unfortunately, you didn't roll doubles, you are not allowed to move." << endl;
                return;
            }
        }
        // if the player haven't Roll Up the Rim cup or didn't use the Roll Up the Rim cup
        // and the player cannot or refuses to roll doubles
        // he/she should pay 50 to move
        cout << "Do you want to pay $50 to leave? y/n" << endl;
        cin >> c;
        if (c == 'n') {
            cout << "You cannot move in this term." << endl;
            return;
        }
        p->changemoney(-50); // pay 50
        p->settc(-50); // the total worth decreased 50
        p->abilroll = true; // the player can move
        cout << p->gettname() << " pays $50." << endl;
    } else {
        cout << "Do you want to try to roll doubles? y/n" << endl;
        cin >> c;
        int playermove = 0; // save the sum of the dice from their last attempt to leave
        if (c == 'y') {
            cout << p->gettname() << " want to try to roll doubles" << endl;
            int dice1;
            int dice2;
            srand((unsigned int) time (NULL));
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            // try to roll doubles
            if (dice1 == dice2) {
                cout << "Congratulation! You roll doubles!! You are allowed to move." << endl;
                p->abilroll = true; // if the player roll doubles, he/she can move now
                return;
            } else {
                playermove = dice1 + dice2;
                cout << "Unfortunately, you didn't roll doubles, you are not allowed to move." << endl;
            }
        }
        p->changemoney(-50); // pay 50
        p->settc(-50); // the total worth decreased 50
        p->abilroll = false; // the player can move
        cout << p->gettname() << " pays $50." << endl;
        cout << p->gettname() << " move " << playermove << " steps." << endl;
        p->changep(playermove); // the player move the sum of the dice from their last attempt to leave
    }
    
}
void DCtimsline::imlvl(string s){}
void DCtimsline::leveldown(string s){}
void DCtimsline::mortgage() {}
void DCtimsline::unmortgage() {}

//Go to tims
Gototims::Gototims(string s):Building(s){}
Gototims::~Gototims(){}
void Gototims::getpay(Player* p){
    cout << "You lands on the Go To Tims square!" << endl;
    cout << p->gettname() << " is sent to DC Tims Line!" << endl;
    p->sendtims = true; // the player is sent to DC Tims Line
    p->gotot(); // the players should be sent to DC Tims Line
}
void Gototims::imlvl(string s){}
void Gototims::leveldown(string s){}
void Gototims::mortgage() {}
void Gototims::unmortgage() {}

//Goosenesting
Goosenesting::Goosenesting(string s):Building(s) {}
Goosenesting::~Goosenesting(){}
void Goosenesting::getpay(Player* p){
    cout << "THe Gooses are nesting. They did not notice you passing by!" << endl;
    cout << "Nothing happened." << endl;
}
void Goosenesting::imlvl(string s){}
void Goosenesting::leveldown(string s){}
void Goosenesting::mortgage() {}
void Goosenesting::unmortgage() {}

//Tuition
Tuition::Tuition(string s):Building(s){}
Tuition::~Tuition(){}
void Tuition::getpay(Player* p){
    cout << p->gettname() << " lands on the Tuition." << endl; 
    cout << "Choosing paying $300 or the 10% of the total worth"<< endl;
    cout << "Enter a for paying 300, b for paying 10% of the total worth"<<endl;
    char c;
    cin >> c;
    double t;
    if (c == 'a') t = 300; // pay 300
    else t = (p->gettc() / 10); // pay 10% of the player's total worth
    p->changemoney(-t); // the player's cash change
    p->settc(-t); // the total worth change
    cout << p->gettname() << " pays $" << t << endl;
}
void Tuition::imlvl(string s){}
void Tuition::leveldown(string s){}
void Tuition::mortgage() {}
void Tuition::unmortgage() {}

//Coop fee
Coopfee::Coopfee(string s):Building(s){};
Coopfee::~Coopfee(){}
void Coopfee::getpay(Player* p){
    cout << p->gettname() << " lands on the Coop Fee." << endl; 
    p->changemoney(-150); // the player's cash change
    p->settc(-150); // the total worth change
    cout << p->gettname() << " pays $150" << endl;
}
void Coopfee::imlvl(string s){}
void Coopfee::leveldown(string s){}
void Coopfee::mortgage() {}
void Coopfee::unmortgage() {}

//SLC
SLC::SLC(string s): Building(s){}
SLC::~SLC() {}
void SLC::getpay(Player* p){
    cout << p->gettname() << " lands on the SLC." << endl; 
    srand((unsigned int) time(NULL));
    int t = rand() % 24 + 1;
    if(t <= 3){
        p->changep(-3); // 1/8 probability back 3
        cout << p->gettname() << " should go back 3 step." << endl;
    }else if (t <=7){
        p->changep(-2); // 1/6 probability back 2
        cout << p->gettname() << " should go back 2 step." << endl;
    }else if (t <= 11){
        p->changep(-1); // 1/6 probability back 1
        cout << p->gettname() << " should go back 1 step." << endl;
    }else if (t <=14){
        p->changep(1); // 1/8 probability forward 1
        cout << p->gettname() << " should go forward 1 step." << endl;
    }else if ( t <= 18){
        p->changep(2); // 1/6 probability forward 2
        cout << p->gettname() << " should go forward 2 step." << endl;
    }else if (t <= 22){
        p-> changep(3); // 1/6 probability forward 3
        cout << p->gettname() << " should go forward 3 step." << endl;
    }else if (t < 23){
        // 1/24 probability go to DC Tims Line
        cout << p->gettname() << " is sent to DC Tims Line!" << endl;
        p->sendtims = true;
        p->gotot(); // send the player to DC Tims Line
    }else{
        // 1/24 probability advance to Collect OSAP
        p->changemoney(200);
        p->settc(200);
        cout << p->gettname() << " advances to Collect OSAP!" << endl;
        cout << p->gettname() << " gets $200!!" << endl;
        p->goosap(); // send the player to Collect OSAP
    }
    // there is a rare chance (1%) that instead of the normal effect of visiting 
    // that building the player receives a winning Roll Up the Rim cup. 
    srand((unsigned int)time(NULL));
    t = rand() % 100 + 1;
    if(t == 1){
        if (M->getRURC() == 0) {
            cout << "Sorry! There is no chance to win Roll Up the Rim Up." << endl;
        } else {
            p->changeRURC(1);
            M->setRURC(-1);
            cout << p->gettname() << " wins a Roll Up the Rim cup!" << endl;
        }
    }
}
void SLC::imlvl(string s){}
void SLC::leveldown(string s){}
void SLC::mortgage() {}
void SLC::unmortgage() {}

//Needles Hall
Needleshall::Needleshall(string s):Building(s) {}
Needleshall::~Needleshall() {}
void Needleshall::getpay(Player* p){
    cout << p->gettname() << " lands on the Needles Hall." << endl; 
    srand((unsigned int) time(NULL));
    int t = rand() % 18 + 1;
    if (t == 1){
        // 1/18 probability lose 200
        p->changemoney(-200);
        p->settc(-200);
        cout << p->gettname() << " pays $200." << endl;
    }else if (t <= 3){
        // 1/9 probability lose 100
        p->changemoney(-100);
        p->settc(-100);
        cout << p->gettname() << " pays $100." << endl;
    }else if (t <= 6){
        // 1/6 probability lose 50
        p->changemoney(-50);
        p->settc(-50);
        cout << p->gettname() << " pays $50." << endl;
    }else if (t <= 12){
        // 1/3 probability get 25
        p->changemoney(25);
        p->settc(25);
        cout << p->gettname() << " gets $25." << endl;
    }else if (t <= 15){
        // 1/6 probability get 50
        p->changemoney(50);
        p->settc(50);
        cout << p->gettname() << " gets $50." << endl;
    }else if (t <= 17){
        // 1/9 probability get 100
        p->changemoney(100);
        p->settc(100);
        cout << p->gettname() << " gets $100." << endl;
    }else{
        // 1/18 probability get 200
        p->changemoney(200);
        p->settc(200);
        cout << p->gettname() << " gets $200." << endl;
    }
    // there is a rare chance (1%) that instead of the normal effect of visiting 
    // that building the player receives a winning Roll Up the Rim cup. 
    srand((unsigned int)time(NULL));
    t = rand() % 100 + 1;
    if(t == 1){
        if (M->getRURC() == 0) {
            cout << "Sorry! There is no chance to win Roll Up the Rim Up." << endl;
        } else {
            p->changeRURC(1);
            M->setRURC(-1);
            cout << p->gettname() << " wins a Roll Up the Rim cup!" << endl;
        }
    }
}
void Needleshall::imlvl(string s){}
void Needleshall::leveldown(string s){}
void Needleshall::mortgage() {}
void Needleshall::unmortgage() {}



