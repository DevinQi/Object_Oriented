//
//  Player.cpp
//  bb7k
//
//  Created by Devin Qi on 2015-07-20.
//  Copyright (c) 2015 Devin Qi. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Player::Player(char s,string s1,Map * m):p(0),money(1500),M(m),name(s),truename(s1),totalcost(1500),RURC(0),Numb(0){
    for(int i = 0; i < 40; ++i){
        b[i] = NULL;
    }                                                       //constructor
    numtims = 0;
    sendtims = false;
    abilroll = true;
}
Player::~Player(){
}
void Player::settc(double b){                  //set total cost
    totalcost += b;
}
double Player::gettc(){
    return totalcost;
}

string Player::gettname(){                          //get the player's full name
    return truename;
}
char Player::getname(){                         //get the player's symbol
    return name;
}
void Player::changemoney(double b){                         //change money
    money += b;
}
double Player::getmoney(){           //get money
    return money;
}
void Player::buyb(int l,int np){                    //buy building
    Building * temp = M->playmap[l];
    temp->setowner(this);
    if(np == 0){
        changemoney(- temp->getp());
    }else{
        changemoney(np);
    }
    b[l] = M->playmap[l];
    checkneigh(l);
    
}
void Player::setM(Map * M1){
    M = M1;
}
int Player::getp() {
    return p;
}
void Player::changep(int b){
    if(p + b >= 40){
        cout << "OSAP gives you 200$"<<endl;
        p = p+b -40;
        changemoney(200);
    } else if (p + b < 0) {
        cout << "OSAP gives you $200" << endl;
        p = 40 + p + b;
    }else{
        p += b;
    }
}
void Player::gotot(){                       //get the number of  RURC
    sendtims = true;
    ++numtims;
    p = 10;
}
void Player::goosap(){
    p = 0;
}
void Player::changeRURC(int b){                     //change number of RURC
    RURC +=b;
}
int Player::getRURC(){
    return RURC;
}
int Player::rollingdice(){        //player rolling the dice
    int n =0;
    int dice1 = 0;
    int dice2 = 0;
    while(1){
        srand((unsigned int)time(NULL));
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        if(dice1 != dice2){
            break;
        }
        if(n == 3){
            cout << "Rolling three times of double, moving to DC Timeline" << endl;
            gotot();
            return 0;
        }
        cout << "Two dices result are the same,rolling again" << endl;
        ++n;
    }
    cout << "The Rolling results are " << dice1 << " and " <<dice2<< ". Sum is " << dice1+dice2<< endl;
    return (dice1 + dice2);
}

void Player::checkneigh(int bp) {                           //check the neighbour and set neighbour
    if ((bp == 1) && (b[3] != NULL)) {
        b[1]->addneigh(b[3]);
        b[3]->addneigh(b[1]);
        b[1]->ismono = true;
        b[3]->ismono = true;
    } else if ((bp == 3) && (b[1] != NULL)) {
        b[1]->addneigh(b[3]);
        b[3]->addneigh(b[1]);
        b[1]->ismono = true;
        b[3]->ismono = true;
    } else if (bp == 6) {
        if ((b[8] != NULL) && (b[9] != NULL)) {
            b[6]->addneigh(b[8]);
            b[6]->addneigh(b[9]);
            b[8]->addneigh(b[6]);
            b[8]->addneigh(b[9]);
            b[9]->addneigh(b[8]);
            b[9]->addneigh(b[6]);
            b[6]->ismono = true;
            b[8]->ismono = true;
            b[9]->ismono = true;
        } else if (b[8] != NULL) {
            b[6]->addneigh(b[8]);
            b[8]->addneigh(b[6]);
        } else if (b[9] != NULL) {
            b[6]->addneigh(b[9]);
            b[9]->addneigh(b[6]);
        }
    } else if (bp == 8) {
        if ((b[6] != NULL) && (b[9] != NULL)) {
            b[6]->addneigh(b[8]);
            b[6]->addneigh(b[9]);
            b[8]->addneigh(b[6]);
            b[8]->addneigh(b[9]);
            b[9]->addneigh(b[8]);
            b[9]->addneigh(b[6]);
            b[6]->ismono = true;
            b[8]->ismono = true;
            b[9]->ismono = true;
        } else if (b[6] != NULL) {
            b[6]->addneigh(b[8]);
            b[8]->addneigh(b[6]);
        } else if (b[9] != NULL) {
            b[8]->addneigh(b[9]);
            b[9]->addneigh(b[8]);
        }
    } else if (bp == 9) {
        if ((b[6] != NULL) && (b[8] != NULL)) {
            b[6]->addneigh(b[8]);
            b[6]->addneigh(b[9]);
            b[8]->addneigh(b[6]);
            b[8]->addneigh(b[9]);
            b[9]->addneigh(b[8]);
            b[9]->addneigh(b[6]);
            b[6]->ismono = true;
            b[8]->ismono = true;
            b[9]->ismono = true;
        } else if (b[6] != NULL) {
            b[6]->addneigh(b[9]);
            b[9]->addneigh(b[6]);
        } else if (b[8] != NULL) {
            b[8]->addneigh(b[9]);
            b[9]->addneigh(b[8]);
        }
    } else if (bp == 11) {
        if ((b[13] != NULL) && (b[14] != NULL)) {
            b[11]->addneigh(b[13]);
            b[11]->addneigh(b[14]);
            b[13]->addneigh(b[11]);
            b[13]->addneigh(b[14]);
            b[14]->addneigh(b[11]);
            b[14]->addneigh(b[13]);
            b[11]->ismono = true;
            b[13]->ismono = true;
            b[14]->ismono = true;
        } else if (b[13] != NULL) {
            b[11]->addneigh(b[13]);
            b[13]->addneigh(b[11]);
        } else if (b[14] != NULL) {
            b[11]->addneigh(b[14]);
            b[14]->addneigh(b[11]);
        }
    } else if (bp == 13) {
        if ((b[11] != NULL) && (b[14] != NULL)) {
            b[11]->addneigh(b[13]);
            b[11]->addneigh(b[14]);
            b[13]->addneigh(b[11]);
            b[13]->addneigh(b[14]);
            b[14]->addneigh(b[11]);
            b[14]->addneigh(b[13]);
            b[11]->ismono = true;
            b[13]->ismono = true;
            b[14]->ismono = true;
        } else if (b[11] != NULL) {
            b[11]->addneigh(b[13]);
            b[13]->addneigh(b[11]);
        } else if (b[14] != NULL) {
            b[13]->addneigh(b[14]);
            b[14]->addneigh(b[13]);
        }
    } else if (bp == 14) {
        if ((b[11] != NULL) && (b[13] != NULL)) {
            b[11]->addneigh(b[13]);
            b[11]->addneigh(b[14]);
            b[13]->addneigh(b[11]);
            b[13]->addneigh(b[14]);
            b[14]->addneigh(b[11]);
            b[14]->addneigh(b[13]);
            b[11]->ismono = true;
            b[13]->ismono = true;
            b[14]->ismono = true;
        } else if (b[11] != NULL) {
            b[11]->addneigh(b[14]);
            b[14]->addneigh(b[11]);
        } else if (b[13] != NULL) {
            b[13]->addneigh(b[14]);
            b[14]->addneigh(b[13]);
        }
    } else if (bp == 16) {
        if ((b[18] != NULL) && (b[19] != NULL)) {
            b[16]->addneigh(b[18]);
            b[16]->addneigh(b[19]);
            b[18]->addneigh(b[16]);
            b[18]->addneigh(b[19]);
            b[19]->addneigh(b[16]);
            b[19]->addneigh(b[18]);
            b[16]->ismono = true;
            b[18]->ismono = true;
            b[19]->ismono = true;
        } else if (b[18] != NULL) {
            b[16]->addneigh(b[18]);
            b[18]->addneigh(b[16]);
        } else if (b[19] != NULL) {
            b[16]->addneigh(b[19]);
            b[19]->addneigh(b[16]);
        }
    } else if (bp == 18) {
        if ((b[16] != NULL) && (b[19] != NULL)) {
            b[16]->addneigh(b[18]);
            b[16]->addneigh(b[19]);
            b[18]->addneigh(b[16]);
            b[18]->addneigh(b[19]);
            b[19]->addneigh(b[16]);
            b[19]->addneigh(b[18]);
            b[16]->ismono = true;
            b[18]->ismono = true;
            b[19]->ismono = true;
        } else if (b[16] != NULL) {
            b[16]->addneigh(b[18]);
            b[18]->addneigh(b[16]);
        } else if (b[19] != NULL) {
            b[18]->addneigh(b[19]);
            b[19]->addneigh(b[18]);
        }
    } else if (bp == 19) {
        if ((b[18] != NULL) && (b[16] != NULL)) {
            b[16]->addneigh(b[18]);
            b[16]->addneigh(b[19]);
            b[18]->addneigh(b[16]);
            b[18]->addneigh(b[19]);
            b[19]->addneigh(b[16]);
            b[19]->addneigh(b[18]);
            b[16]->ismono = true;
            b[18]->ismono = true;
            b[19]->ismono = true;
        } else if (b[18] != NULL) {
            b[19]->addneigh(b[18]);
            b[18]->addneigh(b[19]);
        } else if (b[16] != NULL) {
            b[16]->addneigh(b[19]);
            b[19]->addneigh(b[16]);
        }
    } else if (bp == 21) {
        if ((b[23] != NULL) && (b[24] != NULL)) {
            b[21]->addneigh(b[23]);
            b[21]->addneigh(b[24]);
            b[23]->addneigh(b[21]);
            b[23]->addneigh(b[24]);
            b[24]->addneigh(b[21]);
            b[24]->addneigh(b[23]);
            b[21]->ismono = true;
            b[23]->ismono = true;
            b[24]->ismono = true;
        } else if (b[23] != NULL) {
            b[21]->addneigh(b[23]);
            b[23]->addneigh(b[21]);
        } else if (b[24] != NULL) {
            b[21]->addneigh(b[24]);
            b[24]->addneigh(b[21]);
        }
    } else if (bp == 23) {
        if ((b[21] != NULL) && (b[24] != NULL)) {
            b[21]->addneigh(b[23]);
            b[21]->addneigh(b[24]);
            b[23]->addneigh(b[21]);
            b[23]->addneigh(b[24]);
            b[24]->addneigh(b[21]);
            b[24]->addneigh(b[23]);
            b[21]->ismono = true;
            b[23]->ismono = true;
            b[24]->ismono = true;
        } else if (b[21] != NULL) {
            b[21]->addneigh(b[23]);
            b[23]->addneigh(b[21]);
        } else if (b[24] != NULL) {
            b[23]->addneigh(b[24]);
            b[24]->addneigh(b[23]);
        }
    } else if (bp == 24) {
        if ((b[23] != NULL) && (b[21] != NULL)) {
            b[21]->addneigh(b[23]);
            b[21]->addneigh(b[24]);
            b[23]->addneigh(b[21]);
            b[23]->addneigh(b[24]);
            b[24]->addneigh(b[21]);
            b[24]->addneigh(b[23]);
            b[21]->ismono = true;
            b[23]->ismono = true;
            b[24]->ismono = true;
        } else if (b[23] != NULL) {
            b[24]->addneigh(b[23]);
            b[23]->addneigh(b[24]);
        } else if (b[21] != NULL) {
            b[21]->addneigh(b[24]);
            b[24]->addneigh(b[21]);
        }
    } else if (bp == 26) {
        if ((b[27] != NULL) && (b[29] != NULL)) {
            b[26]->addneigh(b[27]);
            b[26]->addneigh(b[29]);
            b[27]->addneigh(b[26]);
            b[27]->addneigh(b[29]);
            b[29]->addneigh(b[26]);
            b[29]->addneigh(b[27]);
            b[26]->ismono = true;
            b[27]->ismono = true;
            b[29]->ismono = true;
        } else if (b[27] != NULL) {
            b[26]->addneigh(b[27]);
            b[27]->addneigh(b[26]);
        } else if (b[29] != NULL) {
            b[26]->addneigh(b[29]);
            b[29]->addneigh(b[26]);
        }
    } else if (bp == 27) {
        if ((b[26] != NULL) && (b[29] != NULL)) {
            b[26]->addneigh(b[27]);
            b[26]->addneigh(b[29]);
            b[27]->addneigh(b[26]);
            b[27]->addneigh(b[29]);
            b[29]->addneigh(b[26]);
            b[29]->addneigh(b[27]);
            b[26]->ismono = true;
            b[27]->ismono = true;
            b[29]->ismono = true;
        } else if (b[26] != NULL) {
            b[26]->addneigh(b[27]);
            b[27]->addneigh(b[26]);
        } else if (b[29] != NULL) {
            b[27]->addneigh(b[29]);
            b[29]->addneigh(b[27]);
        }
    } else if (bp == 29) {
        if ((b[27] != NULL) && (b[26] != NULL)) {
            b[26]->addneigh(b[27]);
            b[26]->addneigh(b[29]);
            b[27]->addneigh(b[26]);
            b[27]->addneigh(b[29]);
            b[29]->addneigh(b[26]);
            b[29]->addneigh(b[27]);
            b[26]->ismono = true;
            b[27]->ismono = true;
            b[29]->ismono = true;
        } else if (b[26] != NULL) {
            b[26]->addneigh(b[29]);
            b[29]->addneigh(b[26]);
        } else if (b[27] != NULL) {
            b[27]->addneigh(b[29]);
            b[29]->addneigh(b[27]);
        }
    } else if (bp == 31) {
        if ((b[32] != NULL) && (b[34] != NULL)) {
            b[31]->addneigh(b[32]);
            b[31]->addneigh(b[34]);
            b[32]->addneigh(b[31]);
            b[32]->addneigh(b[34]);
            b[34]->addneigh(b[31]);
            b[34]->addneigh(b[32]);
            b[31]->ismono = true;
            b[32]->ismono = true;
            b[34]->ismono = true;
        } else if (b[32] != NULL) {
            b[31]->addneigh(b[32]);
            b[32]->addneigh(b[31]);
        } else if (b[34] != NULL) {
            b[31]->addneigh(b[34]);
            b[34]->addneigh(b[31]);
        }
    } else if (bp == 32) {
        if ((b[31] != NULL) && (b[34] != NULL)) {
            b[31]->addneigh(b[32]);
            b[31]->addneigh(b[34]);
            b[32]->addneigh(b[31]);
            b[32]->addneigh(b[34]);
            b[34]->addneigh(b[31]);
            b[34]->addneigh(b[32]);
            b[31]->ismono = true;
            b[32]->ismono = true;
            b[34]->ismono = true;
        } else if (b[31] != NULL) {
            b[31]->addneigh(b[32]);
            b[32]->addneigh(b[31]);
        } else if (b[34] != NULL) {
            b[32]->addneigh(b[34]);
            b[34]->addneigh(b[32]);
        }
    } else if (bp == 34) {
        if ((b[32] != NULL) && (b[31] != NULL)) {
            b[31]->addneigh(b[32]);
            b[31]->addneigh(b[34]);
            b[32]->addneigh(b[31]);
            b[32]->addneigh(b[34]);
            b[34]->addneigh(b[31]);
            b[34]->addneigh(b[32]);
            b[31]->ismono = true;
            b[32]->ismono = true;
            b[34]->ismono = true;
        } else if (b[32] != NULL) {
            b[31]->addneigh(b[34]);
            b[34]->addneigh(b[31]);
        } else if (b[31] != NULL) {
            b[31]->addneigh(b[34]);
            b[34]->addneigh(b[31]);
        }
    } else if (bp == 37) {
        if (b[39] != NULL) {
            b[39]->addneigh(b[37]);
            b[37]->addneigh(b[39]);
            b[39]->ismono = true;
            b[37]->ismono = true;
        }
    } else if (bp == 39) {
        if (b[37] != NULL) {
            b[37]->addneigh(b[39]);
            b[39]->addneigh(b[37]);
            b[37]->ismono = true;
            b[39]->ismono = true;
        }
    } else if (bp == 5) {
        if (b[15] != NULL) {
            b[5]->addneigh(b[15]);
            b[15]->addneigh(b[5]);
        } 
        if (b[25] != NULL) {
            b[5]->addneigh(b[25]);
            b[25]->addneigh(b[5]);
        }
        if (b[35] != NULL) {
            b[5]->addneigh(b[35]);
            b[35]->addneigh(b[5]);
        }
    } else if (bp == 15) {
        if (b[5] != NULL) {
            b[5]->addneigh(b[15]);
            b[15]->addneigh(b[5]);
        } 
        if (b[25] != NULL) {
            b[15]->addneigh(b[25]);
            b[25]->addneigh(b[15]);
        }
        if (b[35] != NULL) {
            b[15]->addneigh(b[35]);
            b[35]->addneigh(b[15]);
        }
    } else if (bp == 25) {
        if (b[15] != NULL) {
            b[25]->addneigh(b[15]);
            b[15]->addneigh(b[25]);
        } 
        if (b[5] != NULL) {
            b[5]->addneigh(b[25]);
            b[25]->addneigh(b[5]);
        }
        if (b[35] != NULL) {
            b[25]->addneigh(b[35]);
            b[35]->addneigh(b[25]);
        }
    } else if (bp == 35) {
        if (b[15] != NULL) {
            b[35]->addneigh(b[15]);
            b[15]->addneigh(b[35]);
        } 
        if (b[25] != NULL) {
            b[35]->addneigh(b[25]);
            b[25]->addneigh(b[35]);
        }
        if (b[5] != NULL) {
            b[5]->addneigh(b[35]);
            b[35]->addneigh(b[5]);
        }
    } else if (bp == 12) {
        if (b[28] != NULL) {
            b[12]->addneigh(b[28]);
            b[28]->addneigh(b[12]);
        }
    } else if (bp == 28) {
        if (b[12] != NULL) {
            b[12]->addneigh(b[28]);
            b[28]->addneigh(b[12]);
        }
    }
}
