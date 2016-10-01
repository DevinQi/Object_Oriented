
#include<iostream>
#include<string>
#include "player.h"

Player::Player(std::string input,ScoreBoard *temp):input(input),temp(temp){}

bool Player::move_dup(std::string &move){
    if(move == "NW"){
        if(temp->pg[0] != 0) return false;
        else return true;
    }
     else if(move == "N"){
        if(temp->pg[1] != 0) return true;
        else return false;
    }
    else if(move == "NE"){
        if(temp->pg[2] != 0) return true;
        else return false;
    }else if(move == "W"){
        if(temp->pg[3] != 0) return true;
        else return false;
    }else if(move == "C"){
        if(temp->pg[4] != 0) return true;
        else return false;
    }else if(move == "E"){
        if(temp->pg[5] != 0) return true;
        else return false;
    }else if(move == "SW"){
        if(temp->pg[6] != 0) return true;
        else return false;
    }else if(move == "S"){
        if(temp->pg[7] != 0) return true;
        else return false;
    }else{
        if(temp->pg[8] != 0) return true;
        else return false;
    }
}

void Player::print_move(const int who,std::ifstream &in){
    std::string s;
    if (input == "stdin"){
        std::cin>>s;
    }else{
        in >> s;
        while(move_dup(s)) in >>s;
    }
    if(who == 1){
        std::cout << "X's move"<<std::endl;
    }
    else std::cout << "O's move"<<std::endl;
    if(input != "stdin"){
        std::cout<<"("<<"plays"<<s<<")"<<std::endl;
    }
    temp->next_step(who,s);
}












