
#include <iostream>
#include<string>
#include "scoreboard.h"
#include "player.h"
using namespace std;

int main() {
    string s1;
    string s2;    //initial 3 string to store cin value
    string s3;
    ScoreBoard *t = ScoreBoard::getpb();   //create scoreboard
    int turn = 1;           //indicate whose turn
    while(1){    //loop has 1 exit
        t->end =false;     //set end false
        t->step = 0;       //set step to 0
        for(int i  =0 ;i< 9;++i){ //loop has 2 exit
            t->pg[i] = 0;
        }
        cin >> s1;  //read in string
        if(cin.eof())break;     //break when cannot read in
        if(s1 == "quit") break;    //quit the game
        cin >> s2 >> s3;  //read in the input style
        Player X(s2,t);   //construct 2 player
        Player O(s3,t);
        ifstream X1;
        ifstream O1;
        if(s2 != "stdin") X1.open(s2.c_str());
        if(s3 != "stdin") O1.open(s3.c_str());
        if(turn == 1){    //check whose turn
            while(t->end == false){   //loop has 1 exit
                X.print_move(1, X1);
                if(t->end == false){
                    O.print_move(2, O1);
                }
            }
        }else{
            while(t->end == false){
                O.print_move(2, O1);
                if(t->end == false){
                    X.print_move(1, X1);
                }
            }//exit
            if(turn == 1)turn = 2;
            if(turn == 2)turn = 1;
        }//fi
    }//exit
}
