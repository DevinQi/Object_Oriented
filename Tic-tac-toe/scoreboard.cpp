

#include "scoreboard.h"
ScoreBoard * ScoreBoard::pb = NULL;
ScoreBoard::ScoreBoard(){
    step = 0;
    XS = 0;
    OS = 0;
    for (int i = 0;i < 9;++i){
        pg[i]= 0;
    }
    end = false;
}

ScoreBoard * ScoreBoard::getpb(){
    if(!pb){
        pb = new ScoreBoard;
        atexit(cleanup);
    }
    return pb;
}

void ScoreBoard::presult(const int who){
    if (who == 1){
        ++XS;
        std::cout << "X wins" << std::endl;
        std::cout << "Score is" << std::endl;
        std::cout << 'X' << " "<< XS<< std::endl;
        std::cout << 'O' << " "<< OS<< std::endl;
    }else if(who == 2){
        ++OS;
        std::cout << "O wins" << std::endl;
        std::cout << "Score is" << std::endl;
        std::cout << 'X' << " "<< XS<< std::endl;
        std::cout << 'O' << " "<< OS<< std::endl;
    }else{
        std::cout << "Draw" << std::endl;
        std::cout << "Score is" << std::endl;
        std::cout << 'X' << " "<< XS<< std::endl;
        std::cout << 'O' << " "<< OS<< std::endl;
    }
}

void ScoreBoard::next_step(const int who,const std::string&move){
    ++step;
    if(move == "NW")pg[0]= who;
    else if(move == "N") pg[1] = who;
    else if(move == "NE") pg[2] = who;
    else if(move == "W") pg[3] = who;
    else if(move == "C") pg[4] = who;
    else if(move == "E") pg[5] = who;
    else if(move == "SW") pg[6] = who;
    else if(move == "S") pg[7] = who;
    else if(move == "SE") pg[8] = who;
    if((pg[0] == pg[1] &&pg[1] == pg[2]&&pg[0] == pg[2] && pg[0] != 0)||
       (pg[3] == pg[4] &&pg[4] == pg[5]&&pg[3] == pg[5] && pg[3] != 0)||
       (pg[6] == pg[7] &&pg[7] == pg[8]&&pg[6] == pg[8] && pg[6] != 0)||
       (pg[0] == pg[4] &&pg[4] == pg[8]&&pg[0] == pg[8] && pg[4] != 0)||
       (pg[2] == pg[4] &&pg[4] == pg[6]&&pg[2] == pg[6] && pg[4] != 0)||
       (pg[0] == pg[3] &&pg[3] == pg[6]&&pg[0] == pg[6] && pg[3] != 0)||
       (pg[1] == pg[4] &&pg[4] == pg[7]&&pg[1] == pg[7] && pg[4] != 0)||
       (pg[2] == pg[5] &&pg[5] == pg[8]&&pg[2] == pg[8] && pg[2] != 0)){
        end = true;
        presult(who);
    }
    if(step == 9){
        end =true;
        presult(0);
    }
}

void ScoreBoard::cleanup(){
    delete pb;
}



