//
// Created by Lihua Chen
//  xiaofangzi.cpp
//  bb7k
// 

#include "Academic.h"
#include <iostream>
using namespace std;

Academic::Academic(string b):Building(b) {}

Academic::~Academic() {}

void Academic::getpay(Player* p){
    if ((p->gettname() == getowner()->gettname()) && (!getmort())) return;
    double pcost = gettuit(); // how much should the player pay to the owner
    if ((ismono) && (getlvl() == 0)) {
        pcost *= 2; // whether the property is monopoly
    }
    p->changemoney(-pcost); // the player pay
    p->settc(-pcost); // the total worth of the player
    if (!getmort()) {
        getowner()->changemoney(pcost); // pay to the owner
        getowner()->settc(pcost); // the total worth of the owner
        cout << p->gettname() << " pays $" << pcost << " to " << getowner()->gettname() << endl;
    } else {
        cout << p->gettname() << " pays $" << pcost << "." << endl;
    }
}

void Academic::imlvl(string s){
    if (getowner()->gettname() != s) {
        cout << "Don't joke!! You are not the owner, you cannot improve the property!!!" << endl;
    }
    cout << getowner()->gettname() << " tries to improve the property." << endl;
    cout << "The current level is " << getlvl() << endl;
    if (getmort()) { // if the property is mortgaged, the owner cannot improve the academic building
        cout << "Sorry! " << getname() << " is already mortgaged!" << endl;
        cout << "You cannot improve it." << endl;
    }
     else if(ismono) { // if and only if the owner is monopoly the type of the building,
                 // the owner can improve the building
        if(getlvl() == 5){ // level 5 is the maximum improvement
            cout << "Sorry! The level of " << getname() << "is fifth, you cannot improve it." << endl;
            return;
        }
        Player* p = getowner(); // find the owner
        if (getname() == "AL") {
            if (p->getmoney() < 50) { // check whether the owner have enough money to improve AL
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-50);
            cout << p->getname() << " spends " << 50 << endl;
            if (getlvl() == 1) {
                settuit(10);  // the tuition with improvement// the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(30);  // the tuition with improvement// the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(90);  // the tuition with improvement// the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(160); // the tuition with improvement // the tuition with improvement
            } else {
                settuit(250); // the tuition with improvement // the tuition with improvement
            }
        }else if (getname() == "ML"){
            if (p->getmoney() < 50) { // check whether the owner have enough money to improve ML
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-50);
            cout << p->getname() << " spends " << 50 << endl;
            if (getlvl() == 1) {
                settuit(20); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(60); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(180); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(320); // the tuition with improvement
            } else {
                settuit(450); // the tuition with improvement
            }
        }else if (getname() == "ECH"){
            if (p->getmoney() < 50) { // check whether the owner have enough money to improve ECH
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-50);
            cout << p->getname() << " spends " << 50 << endl;
            if (getlvl() == 1) {
                settuit(30); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(90); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(270); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(400); // the tuition with improvement
            } else {
                settuit(550); // the tuition with improvement
            }
        }else if (getname() == "PAS"){
            if (p->getmoney() < 50) { // check whether the owner have enough money to improve PAS
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-50);
            cout << p->getname() << " spends " << 50 << endl;
            if (getlvl() == 1) {
                settuit(30); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(90); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(270); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(400); // the tuition with improvement
            } else {
                settuit(550); // the tuition with improvement
            }
        }else if (getname() == "HH"){
            if (p->getmoney() < 50) {  // check whether the owner have enough money to improve HH
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-50);
            cout << p->getname() << " spends " << 50 << endl;
            if (getlvl() == 1) {
                settuit(40); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(100); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(300); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(450); // the tuition with improvement
            } else {
                settuit(600); // the tuition with improvement
            }
        }else if (getname() == "RCH"){
            if (p->getmoney() < 100) {  // check whether the owner have enough money to improve RCH
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-100);
            cout << p->getname() << " spends " << 100 << endl;
            if (getlvl() == 1) {
                settuit(50); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(150); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(450); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(625); // the tuition with improvement
            } else {
                settuit(750); // the tuition with improvement
            }
        }else if (getname() == "DWE"){
            if (p->getmoney() < 100) {  // check whether the owner have enough money to improve DWE
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-100);
            cout << p->getname() << " spends " << 100 << endl;
            if (getlvl() == 1) {
                settuit(50); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(150); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(450); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(625); // the tuition with improvement
            } else {
                settuit(750); // the tuition with improvement
            }
        }else if (getname() == "CPH"){
            if (p->getmoney() < 100) {  // check whether the owner have enough money to improve CPH
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-100);
            cout << p->getname() << " spends " << 100 << endl;
            if (getlvl() == 1) {
                settuit(60); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(180); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(500); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(700); // the tuition with improvement
            } else {
                settuit(900); // the tuition with improvement
            }
        }else if (getname() == "LHI"){
            if (p->getmoney() < 100) {  // check whether the owner have enough money to improve LHI
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-100);
            cout << p->getname() << " spends " << 100 << endl;
            if (getlvl() == 1) {
                settuit(70); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(200); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(550); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(750); // the tuition with improvement
            } else {
                settuit(950); // the tuition with improvement
            }
        }else if (getname() == "BMH"){
            if (p->getmoney() < 100) {  // check whether the owner have enough money to improve BMH
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-100);
            cout << p->getname() << " spends " << 100 << endl;
            if (getlvl() == 1) {
                settuit(70); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(200); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(550); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(750); // the tuition with improvement
            } else {
                settuit(950); // the tuition with improvement
            }
        }else if (getname() == "OPT"){
            if (p->getmoney() < 100) {  // check whether the owner have enough money to improve OPT
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-100);
            cout << p->getname() << " spends " << 100 << endl;
            if (getlvl() == 1) {
                settuit(80); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(220); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(600); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(800); // the tuition with improvement
            } else {
                settuit(1000); // the tuition with improvement
            }
        }else if (getname() == "EV1"){
            if (p->getmoney() < 150) {  // check whether the owner have enough money to improve EV1
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-150);
            cout << p->getname() << " spends " <<150 << endl;
            if (getlvl() == 1) {
                settuit(90); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(250); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(700); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(875); // the tuition with improvement
            } else {
                settuit(1050); // the tuition with improvement
            }
        }else if (getname() == "EV2"){
            if (p->getmoney() < 150) {  // check whether the owner have enough money to improve EV2
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-150);
            cout << p->getname() << " spends " << 150 << endl;
            if (getlvl() == 1) {
                settuit(90); // the tuition with improvement            
            } else if (getlvl() == 2) {
                settuit(250); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(700); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(875); // the tuition with improvement
            } else {
                settuit(1050); // the tuition with improvement
            }
        }else if (getname() == "EV3"){
            if (p->getmoney() < 150) {  // check whether the owner have enough money to improve EV3
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-150);
            cout << p->getname() << " spends " << 150 << endl;
            if (getlvl() == 1) {
                settuit(100); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(300); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(750); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(925); // the tuition with improvement
            } else {
                settuit(1100); // the tuition with improvement
            }
        }else if (getname() == "PHYS"){
            if (p->getmoney() < 150) {  // check whether the owner have enough money to improve PHYS
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-150);
            cout << p->getname() << " spends " << 150 << endl;
            if (getlvl() == 1) {
                settuit(110); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(330); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(800); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(975); // the tuition with improvement
            } else {
                settuit(1150); // the tuition with improvement
            }
        }else if (getname() == "B1"){
            if (p->getmoney() < 150) {  // check whether the owner have enough money to improve B1
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-150);
            cout << p->getname() << " spends " << 150 << endl;
            if (getlvl() == 1) {
                settuit(110); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(330); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(800); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(975); // the tuition with improvement
            } else {
                settuit(1150); // the tuition with improvement
            }
        }else if (getname() == "B2"){
            if (p->getmoney() < 150) {  // check whether the owner have enough money to improve B2
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-150);
            cout << p->getname() << " spends " << 150 << endl;
            if (getlvl() == 1) {
                settuit(120); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(360); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(850); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(1025); // the tuition with improvement
            } else {
                settuit(1200); // the tuition with improvement
            }
        }else if (getname() == "EIT"){
            if (p->getmoney() < 200) {  // check whether the owner have enough money to improve EIT
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-200);
            cout << p->getname() << " spends " << 200 << endl;
            if (getlvl() == 1) {
                settuit(130); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(390); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(900); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(1100); // the tuition with improvement
            } else {
                settuit(1275); // the tuition with improvement
            }
        }else if (getname() == "ESC"){
            if (p->getmoney() < 200) {  // check whether the owner have enough money to improve ESC
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-200);
            cout << p->getname() << " spends " << 200 << endl;
            if (getlvl() == 1) {
                settuit(130); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(390); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(900); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(1100); // the tuition with improvement
            } else {
                settuit(1275); // the tuition with improvement
            }
        }else if (getname() == "C2"){
            if (p->getmoney() < 200) {  // check whether the owner have enough money to improve C2
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-200);
            cout << p->getname() << " spends " << 200 << endl;
            if (getlvl() == 1) {
                settuit(150); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(450); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(1000); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(1200); // the tuition with improvement
            } else {
                settuit(1400); // the tuition with improvement
            }
        }else if (getname() == "MC"){
            if (p->getmoney() < 200) {  // check whether the owner have enough money to improve MC
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-200);
            cout << p->getname() << " spends " << 200 << endl;
            if (getlvl() == 1) {
                settuit(175); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(500); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(1100); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(1300); // the tuition with improvement
            } else {
                settuit(1500); // the tuition with improvement
            }
        }else if (getname() == "DC"){
            if (p->getmoney() < 200) {  // check whether the owner have enough money to improve DC
                cout << "Sorry! You haven't enough money, you cannot improve " << getname() << "." << endl;
                return;
            }
            uplvl(getlvl()+1); // improve the level
            p->changemoney(-200);
            cout << p->getname() << " spends " << 200 << endl;
            if (getlvl() == 1) {
                settuit(200); // the tuition with improvement
            } else if (getlvl() == 2) {
                settuit(600); // the tuition with improvement
            } else if (getlvl() == 3) {
                settuit(1400); // the tuition with improvement
            } else if (getlvl() == 4) {
                settuit(1700); // the tuition with improvement
            } else {
                settuit(2000); // the tuition with improvement
            }
        }
        cout<< "Level Up! " << getname() << " is LV " << getlvl();
        if (getlvl() == 5) cout << " called a wireless access podouble (WAP)";
        cout << "!" << endl;
        cout<< "Current charge is " << gettuit() <<"!"<< endl;
    } else {
        cout << "Sorry! You didn't monopoly this block, you cannot improve " << getname() << "." << endl;
    }
}

void Academic::leveldown(string s) {
    if (getowner()->gettname() != s) {
        cout << "Don't joke!! You are not the owner, you cannot improve the property!!!" << endl;
    }
    if (getlvl() == 0) return;
    Player* p = getowner();
    uplvl(getlvl()-1); // improve the level
    if (getname() == "AL") {
        p->changemoney(25);
        p->settc(-25); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 25 << endl;
        if (getlvl() == 0) {
            settuit(2); // the tuition with improvement       
        }else if (getlvl() == 1) {
            settuit(10); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(30); // the tuition with improvement        
        } else if (getlvl() == 3) {
            settuit(90); // the tuition with improvement        
        } else{
            settuit(160); // the tuition with improvement
        }
    }else if (getname() == "ML"){
        p->changemoney(25);
        p->settc(-25); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 25 << endl;
        if (getlvl() == 0) {
            settuit(4); // the tuition with improvement       
        }else if (getlvl() == 1) {
            settuit(20); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(60); // the tuition with improvement        
        } else if (getlvl() == 3) {
            settuit(180); // the tuition with improvement
        } else {
            settuit(320); // the tuition with improvement
        }
    }else if (getname() == "ECH"){
        p->changemoney(25);
        p->settc(-25); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 25 << endl;
        if (getlvl() == 0) {
            settuit(6); // the tuition with improvement       
        }else if (getlvl() == 1) {
            settuit(30); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(90); // the tuition with improvement        
        } else if (getlvl() == 3) {
            settuit(270); // the tuition with improvement
        } else {
            settuit(400); // the tuition with improvement
        }
    }else if (getname() == "PAS"){
        p->changemoney(25);
        p->settc(-25); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 25 << endl;
        if (getlvl() == 0) {
            settuit(6); // the tuition with improvement       
        }else if (getlvl() == 1) {
            settuit(30); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(90); // the tuition with improvement        
        } else if (getlvl() == 3) {
            settuit(270); // the tuition with improvement
        } else {
            settuit(400); // the tuition with improvement
        }
    }else if (getname() == "HH"){
        p->changemoney(25);
        p->settc(-25); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 25 << endl;
        if (getlvl() == 0) {
            settuit(8); // the tuition with improvement       
        }else if (getlvl() == 1) {
            settuit(40); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(100); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(300); // the tuition with improvement
        } else{
            settuit(450); // the tuition with improvement
        }
    }else if (getname() == "RCH"){
        p->changemoney(50);
        p->settc(-50); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 50 << endl;
        if (getlvl() == 0) {
            settuit(10); // the tuition with improvement        
        }else if (getlvl() == 1) {
            settuit(50); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(150); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(450); // the tuition with improvement
        } else{
            settuit(625); // the tuition with improvement
        }
    }else if (getname() == "DWE"){
        p->changemoney(50);
        p->settc(-50); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 50 << endl;
        if (getlvl() == 0) {
            settuit(10); // the tuition with improvement        
        }else if (getlvl() == 1) {
            settuit(50); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(150); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(450); // the tuition with improvement
        } else {
            settuit(625); // the tuition with improvement
        }
    }else if (getname() == "CPH"){
        p->changemoney(50);
        p->settc(-50); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 50 << endl;
        if (getlvl() == 0) {
            settuit(12); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(60); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(180); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(500); // the tuition with improvement
        } else {
            settuit(700); // the tuition with improvement
        }
    }else if (getname() == "LHI"){
        p->changemoney(50);
        p->settc(-50); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 50 << endl;
        if (getlvl() == 0) {
            settuit(14); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(70); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(200); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(550); // the tuition with improvement
        } else {
            settuit(750); // the tuition with improvement
        }
    }else if (getname() == "BMH"){
        p->changemoney(50);
        p->settc(-50); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 50 << endl;
        if (getlvl() == 0) {
            settuit(14); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(70); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(200); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(550); // the tuition with improvement
        } else {
            settuit(750); // the tuition with improvement
        }
    }else if (getname() == "OPT"){
        p->changemoney(50);
        p->settc(-50); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 50 << endl;
        if (getlvl() == 0) {
            settuit(16); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(80); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(220); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(600); // the tuition with improvement
        } else {
            settuit(800); // the tuition with improvement
        }
    }else if (getname() == "EV1"){
        p->changemoney(75);
        p->settc(-75); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 75 << endl;
        if (getlvl() == 0) {
            settuit(18); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(90); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(250); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(700); // the tuition with improvement
        } else {
            settuit(875); // the tuition with improvement
        }
    }else if (getname() == "EV2"){
        p->changemoney(75);
        p->settc(-75); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 75 << endl;
        if (getlvl() == 0) {
            settuit(18); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(90); // the tuition with improvement        
        } else if (getlvl() == 2) {
            settuit(250); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(700); // the tuition with improvement
        } else {
            settuit(875); // the tuition with improvement
        }
    }else if (getname() == "EV3"){
        p->changemoney(75);
        p->settc(-75); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 75 << endl;
        if (getlvl() == 0) {
            settuit(20); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(100); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(300); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(750); // the tuition with improvement
        } else {
            settuit(925); // the tuition with improvement
        }
    }else if (getname() == "PHYS"){
        p->changemoney(75);
        p->settc(-75); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 75 << endl;
        if (getlvl() == 0) {
            settuit(22); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(110); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(330); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(800); // the tuition with improvement
        } else {
            settuit(975); // the tuition with improvement
        }
    }else if (getname() == "B1"){
        p->changemoney(75);
        p->settc(-75); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 75 << endl;
        if (getlvl() == 0) {
            settuit(22); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(110); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(330); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(800); // the tuition with improvement
        } else {
            settuit(975); // the tuition with improvement
        }
    }else if (getname() == "B2"){
        p->changemoney(75);
        p->settc(-75); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 75 << endl;
        if (getlvl() == 0) {
            settuit(24); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(120); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(360); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(850); // the tuition with improvement
        } else {
            settuit(1025); // the tuition with improvement
        }
    }else if (getname() == "EIT"){
        p->changemoney(100);
        p->settc(-100); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 100 << endl;
        if (getlvl() == 0) {
            settuit(26); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(130); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(390); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(900); // the tuition with improvement
        } else {
            settuit(1100); // the tuition with improvement
        }
    }else if (getname() == "ESC"){
        p->changemoney(100);
        p->settc(-100); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 100 << endl;
        if (getlvl() == 0) {
            settuit(26); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(130); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(390); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(900); // the tuition with improvement
        } else {
            settuit(1100); // the tuition with improvement
        }
    }else if (getname() == "C2"){
        p->changemoney(100);
        p->settc(-100); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 100 << endl;
        if (getlvl() == 0) {
            settuit(28); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(150); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(450); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(1000); // the tuition with improvement
        } else {
            settuit(1200); // the tuition with improvement
        }
    }else if (getname() == "MC"){
        p->changemoney(100);
        p->settc(-100); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 100 << endl;
        if (getlvl() == 0) {
            settuit(35); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(175); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(500); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(1100); // the tuition with improvement
        } else {
            settuit(1300); // the tuition with improvement
        }
    }else if (getname() == "DC"){
        p->changemoney(100);
        p->settc(-100); // the owner's total worth will lose half of the improvement cost if he/she sell the improvement
        cout << p->getname() << " gets " << 100 << endl;
        if (getlvl() == 0) {
            settuit(50); // the tuition with improvement        
        } else if (getlvl() == 1) {
            settuit(200); // the tuition with improvement
        } else if (getlvl() == 2) {
            settuit(600); // the tuition with improvement
        } else if (getlvl() == 3) {
            settuit(1400); // the tuition with improvement
        } else {
            settuit(1700); // the tuition with improvement
        }
        cout<< "Level Down! " << getname() << " is LV " << getlvl() << "!" <<endl;
        cout<< "Current charge is " << gettuit() << "!" << endl;
    }
}

void Academic::mortgage() {
    if (getmort()) {
        cout << "Sorry! " << getname() << " is already mortgaged!" << endl;
        cout << "You cannot mortgages it twice!" << endl;
        return;
    }
    if (getlvl() > 0) { // all improvement should be sold before mortgage
        char t;
        cout << "Sorry! You cannot mortgages this property until you should sell all of the improvement(s)." << endl;
        cout << "The current level is " << getlvl() << "." << endl;
        cout << "Do you still want to mortgages this building? y/n" << endl;
        cin >> t;
        if (t == 'n') return;
        cout << "Start to sell your improvement(s)." << endl;
        while (getlvl() > 0) leveldown(getowner()->gettname());
        cout << "Now, you sold all of the improvement(s), and you can mortgages the property." << endl;
    }
    setmort(true); // update ismort
    Player *p = getowner();
    double pcost = getp(); // how much money the owner cost to but the building
    double pget = pcost/2; // the owner can just get half of the cost of the property
    p->changemoney(pget);
    p->settc(pget); // the owner's total worth will get half of the purchase cost of the property
    cout << getowner()->gettname() << " gets " << pget << " after he/she mortgages the " << getname() << endl;
}

void Academic::unmortgage() {
    if (!getmort()) { // check whether the property is mortgaged
        cout << "You didn't mortgage " << getname() << "." << endl;
        cout << "You do not need to unmortgage it." << endl;
        return;
    }
    // To unmortgage a property, the player must pay half of the cost of the property plus 10%.
    char t;
    Player *p = getowner();
    double pcost = getp()*0.1;
    p->changemoney(-pcost); // the owner should pay 10% of the purchase cost of the property to bank
    p->settc(-pcost); // the owner's total worth will lose 10% of the purchase cost of the property
    cout << "Do you want to unmortgage the property(y/n), "<< p->gettname() << " ?" << endl;
    cin >> t;
    if (t == 'y') {
        cout << p->gettname() << " wants to unmortgage the property." << endl;
        int pcost = getp()*0.5; // how much the new owner should pay to the bank
        p->changemoney(-pcost); // the new owner pay half of the property to bank
        setmort(false); // set the mortgage is false
    }
}
