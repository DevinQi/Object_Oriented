// created by Lihua Chen and Haoran Qi
//
//  Controller.cpp
//  bb7k
//

#include "Controller.h"
#include "textdisplay.h"
#include <string>
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

Controller::Controller(): M(NULL), t(NULL) {                //constructor
    loadfileoption = false;
    filename = "";
    test = false;
}

void Controller::cleangame(){                               //cleangame memroy and set all feild to initial value
    for (int i = 0; i < numplayer;++i){
        delete pl[i];
        pl[i] = NULL;
    }
    delete M;
    delete t;
    numplayer = 0;
    M = NULL;
    t = NULL;
}

Controller::~Controller(){                          //destructor
    cleangame();
}

void Controller::newgame(){                         //allocate memory for all fields
    if(M != NULL){                              //if there has a game, delete it
        cleangame();
    }
    if(loadfileoption){                         // The load file option
        M = new Map;
        M->initial();
        t = new textdisplay;
        ifstream myfile;
        myfile.open (filename.c_str());                 //open the file
        string getliner;
        int maxnum = 0;
        while(getline(myfile, getliner)){               //loop has 2 exits
            stringstream ss1(getliner);
            stringstream s(getliner);
            int helpnum;
            if (ss1 >> helpnum) {                   //set the number of players
                numplayer = helpnum;
                continue;
            }
            ++maxnum;
            string s1;
            s >> s1;
            char c2;
            if (maxnum <= numplayer) {        //first loading condition
                s >> c2;
                int i1,i2,i3;
                s >> i1;
                s >> i2;
                s >> i3;
                //int numberp = numplayer;
                Player* p = new Player(c2,s1,M);
                p->changemoney(i2-1500);                //set the cash
                p->changep(i3);                         //set position
                t->notifyplayer(p->getp(),p->getname()); //notify textdisplay
                p->settc(i2-1500);                      //set totalcost
                p->changeRURC(3);                       //set the Roll Up the Rim Cup
                pl[maxnum-1] = p;
                if(i3 == 10){                   //particular condition on dc timeline
                    double i4,i5;
                    s >> i4;
                    if(i4 == 0){
                        p->sendtims = false;           //set whether player was send to dc time line
                    }else{
                        p->sendtims =true;
                        s >> i5;
                        p->numtims = i5;
                    }
                    
                }
            }else{                          //second loading condition
                string s2;
                int i6;
                s >> s2;
                s >> i6;
                Building * tempadf = NULL;
                int bpasd;                      //find the building position
                for(int i =0;i < 40;++i){
                    if( M->playmap[i]->getname() == s1){
                        tempadf = M->playmap[i];
                        bpasd = i;
                        break;
                    }
                }
                Player * tempads = NULL;                   //find the player pointer
                for(int i = 0; i < numplayer;++i){
                    if(pl[i]->gettname() == s2){
                        tempads = pl[i];
                        break;
                    }
                }
                if (tempads == NULL) continue;
                tempadf->setowner(tempads);                     //set owner
                tempadf->setlvl(i6);                               //set level
                tempads->b[bpasd] = tempadf;
                tempads->settc(tempadf->getp());                    //set total cost
                tempads->checkneigh(bpasd);
                t->notifybuilding(bpasd, tempads->getname(),tempadf->getlvl());
                //tempads = NULL;                                 //reset to NULL
                //tempadf = NULL;                                 //reset to NULL
            }
        }
        myfile.close();
    }else{                                  //regular new game commend;
        M = new Map;
        M->initial();
        t = new textdisplay;
        cout << "Enter the number of Players,Maximum is 8"<<endl;
        int numberp;
        cin >> numberp;                                         //read in the number of players
        numplayer = numberp;
        while(numberp > 0){
            cout << "Enter the name of the player." << endl;
            string tempname;
            cin >> tempname;                            //read in player name
            cout << "Enter a character as your symbol" << endl;
            char temc;
            cin >> temc;
            pl[numplayer - numberp] = new Player(temc,tempname,M);
            t->notifyplayer(0,temc);                        //notify the textdisplay
            --numberp;
        }
        t->printgame(cout);
    }
}
void Controller::auction(Building * b,int ap){          //Auction
    
    int paimai[numplayer];                      //player array
    for (int i = 0;i < numplayer ; ++i){
        paimai[i] = 1;                          //set initial value, 1 indicate that player have ability in auction
    }
    int n = numplayer;
    int mm = 0;                       //maximum money
    int whos = 0;                     //who gives the largest price
    while (n > 1){              //auction loop
        for (int i = 0; i < numplayer ; ++i){
            if(paimai[i] == 1){
                cout << "The current bid price is " << mm<< endl;
                cout << "Do "<<pl[i]->gettname() <<" want give a price (Y),or just quit(Q)" << endl;
                char t;
                cin >> t;
                if(t == 'Y'){
                    cout << "Enter a price(integer), reuqire the price is large than current price"<< endl;
                    int t1;
                    cin >> t1;
                    if(t1 > mm){
                        mm = t1;
                        whos = i ;
                    }else{
                        cout << "invilid input,please try again" << endl;
                        --i;
                        continue;
                    }
                }else if (t == 'Q'){                //player quit the auction
                    n -= 1;
                    paimai[i] = 0;
                }else{                      //invaild input
                    cout << "invilid input, please try again" << endl;
                    --i;
                    continue;
                }
            }
        }
    }
    if(n == 1){             //auction is over and exist a winner
        cout << pl[whos]->getname() << " gets the " << b->getname()<< " with "<< mm<< "$." << endl;
        pl[whos]->buyb(ap,-mm);
        t->notifybuilding(ap,pl[whos]->getname(),0);
    }else if(n == 0){               //auction over without a winner
        cout << "No player wants to buy it" << endl;
    }else{
        cout << "Progream has abug here" << endl;
    }
}

void Controller::play(){            //play fuction
    if(M == NULL ){                 //there exist a game before
        cout << "Using new commend start a new game" << endl;
        while(1){
            string sign;
            cin >> sign;
            if(sign == "new"){
                newgame();              //call new game commend
                break;
            }else{
                cout << "Please enter new to start game."<<endl;
            }
        }
    }
    bool cantmove = false;                  //indicate player can move or not
    int whosturn = 0;                   //indicate whosturn
    string cmd;                             //commend string
    while (numplayer > 1){
        cout << "Now, " << pl[whosturn]->getname()<< "'s turn"<<endl;
        int pp = pl[whosturn]->getp();      //get the player's position
        if(M->playmap[pp]->getprop()){
            M->playmap[pp]->M = M;
            if(M->playmap[pp]->getowner() == NULL){    //if the building does't have a owner
                if(pl[whosturn]->getmoney() < 0){
                    cout <<"You dont have any cash,you must selet following choice to get some cash to make this game continue"<<endl;
                    cout <<"1. Trade buidling"<<endl;
                    cout <<"2. Sell inprovement" <<endl;
                    cout <<"3. mortgage building " <<endl;
                    cout <<"4. bankrupt" << endl;
                    if(M->playmap[pp]->getowner() != NULL){
                        M->playmap[pp]->getowner()->changemoney(pl[whosturn]->getmoney());
                    }
                    cantmove = true;
                }else{
                cout<< "Do you want to buy " << M->playmap[pp]->getname() << " ?" <<"Endter Y or N"<<endl;
                char t123;
                cin >> t123;
                if(t123 == 'Y'){                           //player wnats to buy this building
                    pl[whosturn]->buyb(pp,0);       // 0 is the default which indicate there is no auction
                    t->notifybuilding(pp,pl[whosturn]->getname(),0);
                    cout << pl[whosturn]->gettname() << " buys the " <<M->playmap[pp]->getname()<<endl;
                    t->printgame(cout);
                }else if(t123 == 'N'){                     //player doesnt wants to buy this building
                    cout << "Player dont want buy this building , start to auction" << endl;
                    auction(M->playmap[pp],pp);
                }else{
                    cout << "invild input,you have no chance to buy it" << endl;
                    auction(M->playmap[pp],pp);
                }
                }
            }else{
                M->playmap[pp]->getpay(pl[whosturn]);
                t->notifyplayer(pl[whosturn]->getp(),pl[whosturn]->getname());
                t->printgame(cout);
                if(pl[whosturn]->getmoney() < 0){
                    cout <<"You dont have any cash,you must selet following choice to get some cash to make this game continue"<<endl;
                    cout <<"1. Trade buidling"<<endl;
                    cout <<"2. Sell inprovement" <<endl;
                    cout <<"3. mortgage building " <<endl;
                    cout <<"4. bankrupt" << endl;
                    if(M->playmap[pp]->getowner() != NULL){
                        M->playmap[pp]->getowner()->changemoney(pl[whosturn]->getmoney());       //set the money
                    }
                    cantmove = true;
                }
            }
        } else {
            M->playmap[pp]->M = M;
            t->notifyplayer(pl[whosturn]->getp(),pl[whosturn]->getname());       //notify textdisplay
            t->printgame(cout);
            M->playmap[pp]->getpay(pl[whosturn]);
            if (((M->playmap[pp]->getname() == "SLC") || (M->playmap[pp]->getname() == "Gototims")) && (pl[whosturn]->getp() != pp)) {
                pp = pl[whosturn]->getp();
                M->playmap[pp]->getpay(pl[whosturn]);
                t->notifyplayer(pl[whosturn]->getp(),pl[whosturn]->getname());
                t->printgame(cout);
            }
            if(pl[whosturn]->getmoney() < 0){
                cout <<"You dont have any cash,you must selet following choice to get some cash to make this game continue"<<endl;
                cout <<"1. Trade buidling"<<endl;
                cout <<"2. Sell inprovement" <<endl;
                cout <<"3. mortgage building " <<endl;
                cout <<"4. bankrupt" << endl;
                if(M->playmap[pp]->getowner() != NULL){
                    M->playmap[pp]->getowner()->changemoney(pl[whosturn]->getmoney());
                }
                cantmove = true;
            }
        }
        while (cin >> cmd){                 //commend loop
            cout << "input a commend"<<endl;
            if (cmd == "new"){                      //if commend is new
                newgame();
            }else if(cmd == "roll"){                //if commend is roll
                if(cantmove&&pl[whosturn]->getmoney() < 0){  //dont gave ability to roll
                    cout << "you cannot roll a dice unless you get some cash"<<endl;
                }else{                                  //else
                    if(pl[whosturn]->abilroll){
                        string checktest;
                        getline(cin,checktest);
                        if(test == true && checktest != ""){            //using -testing commend line option
                            stringstream si(checktest);
                            int dice1;
                            int dice2;
                            si >> dice1;
                            si >> dice2;
                            cout << "moving " << dice1 + dice2<< " steps." << endl;
                            pl[whosturn]->changep(dice1 + dice2);
                        }else{                          //rolling dice without commend line option
                            int step =pl[whosturn]->rollingdice();
                            pl[whosturn]->changep(step);
                        }
                        pl[whosturn]->abilroll = false;
                        t->notifyplayer(pl[whosturn]->getp(),pl[whosturn]->getname());  //notify the textdisplay
                        t->printgame(cout);                             //notify the textdisplay
                    }else{
                        cout << "You dont have chance to roll dice"<<endl;
                    }
                }
            }else if(cmd == "next"){            //next option
                if(pl[whosturn]->abilroll){
                    cout << "You are is eligible to roll,please roll the dices first."<<endl;
                    continue;
                    //int step =pl[whosturn]->rollingdice();          //get the step
                   // pl[whosturn]->changep(step);                    //change position
                   // t->notifyplayer(pl[whosturn]->getp(),pl[whosturn]->getname());      //notify textdisplay
                    //t->printgame(cout);
                    //if(whosturn == numplayer-1){
                    //    whosturn = 0;
                    //}else{
                    //    ++whosturn;                 //next player's turn
                   // }
                    //break;
                }else{                      //already roll the dices
                    pl[whosturn]->abilroll = true;
                    (whosturn == numplayer-1)? whosturn = 0:++whosturn;
                    break;
                }
            }else if (cmd == "trade"){                  //trade option
                bool checkallowner = true;                      //check whether all bulding has a owner
                for(int i =0;i < 40;++i){
                    if(M->playmap[i]->getprop()&&M->playmap[i]->getowner() == NULL){
                        checkallowner = false;
                        break;
                    }
                }
                if(checkallowner){                      //if all buidlings has a owner
                    string cin123;
                    getline(cin,cin123);
                    stringstream cin1(cin123);
                    stringstream cin2(cin123);
                    stringstream cin3(cin123);
                    string s1;                //s1 is the name of the
                    string s2;
                    string s3;
                    int i1;
                    cin1 >> s1;
                    Player * trader;
                    for(int i = 0 ;i < numplayer;++i){              //find the player
                        if(pl[i]->gettname() == s1){
                            trader = pl[i];
                            break;
                        }
                    }
                    if(cin1 >> i1){                            //Frist trade mothed
                        cin1 >> s3;
                        cout <<pl[whosturn]->gettname()<<" is willing to give "<<s1 << " "<<i1<<" in exchange for the "<<s3<<" building ."<<endl;
                        if(pl[whosturn]->getmoney() < i1){
                            cout << "you dont have enough money to afford this trade"<<endl;
                        }else{
                            int ppp = -1;
                            for(int i = 0; i < 40 ; ++i){                   //get the position of building
                                if(M->playmap[i]->getname() == s3){
                                    ppp = i;
                                    break;
                                }
                            }
                            bool linjushengjile = false;
                            for (int i = 0; i < M->playmap[ppp]->getnn(); ++i){
                                if(M->playmap[ppp]->getneigh(i)->getlvl() != 0){
                                    linjushengjile = true;
                                    break;
                                }
                            }
                            if (ppp == -1) {
                                cout << "You haven't building called " << s3 << "." << endl;
                                cout << "You cannot trade it." << endl;
                            } else if(trader->b[ppp] == NULL){
                                cout<<trader->gettname() <<" dont have the buidling"<<endl;
                            }else if(M->playmap[ppp]->getlvl() != 0 ){
                                cout << "Cannot trade building with level not 0. " << endl;
                                continue;
                            }else if(linjushengjile){
                                cout << "You cannot trade property if a property in its monopoly has improvements"<<endl;
                                continue;
                            }else{                                     //trading fuction
                                cout << "Do you want to accept this trade(y/n), "<<s1<< " ?"<<endl;
                                char jiebujieshou;
                                cin >> jiebujieshou;
                                if(jiebujieshou == 'n'){
                                    cout << "trade rejected"<<endl;
                                    continue;
                                }
                                pl[whosturn]->changemoney(-i1);
                                trader->changemoney(i1);                //set money
                                pl[whosturn]->b[ppp] = trader->b[ppp];
                                trader->b[ppp]->setowner(pl[whosturn]);          //change the buiding owner
                                t->notifybuilding(ppp,pl[whosturn]->getname() ,0);
                                trader->b[ppp] = NULL;
                                pl[whosturn]->settc(M->playmap[ppp]->getp() - i1);
                                trader->settc(i1-M->playmap[ppp]->getp());  //change rhe total cost
                                cout << "Trade compeleted"<<endl;
                                t->printgame(cout);
                            }
                        }
                    }else{
                        cin2>> s1;
                        cin2 >> s2;
                        int ppp1 = -1;
                        for(int i = 0; i < 40 ; ++i){                   //get the position of building
                            if(M->playmap[i]->getname() == s2){
                                ppp1 = i;
                                break;
                            }
                        }
                        bool linjushengjile = false;
                        for (int i = 0; i < M->playmap[ppp1]->getnn(); ++i){
                            if(M->playmap[ppp1]->getneigh(i)->getlvl() != 0){
                                linjushengjile = true;
                                break;
                            }
                        }
                        if (ppp1 == -1) {
                            cout << "There is no player called " << s2 << endl;
                            cout << "You cannot trade." << endl;
                        }
                        else if(M->playmap[ppp1]->getlvl() !=0){
                            cout << "Cannot trade this building with level not 0"<<endl;
                        }
                        else if(cin2 >> i1){                          //second trade mothed
                            cout <<pl[whosturn]->gettname()<<" is willing to give "<<trader->gettname()<<" "<<s2<<" in exchange for "<<i1<<endl;
                            if(trader->getmoney() < i1){
                                cout <<trader->getmoney()<<" dont have enough money to afford this trade"<< endl;
                            }else if(M->playmap[ppp1]->getlvl() != 0 ){
                                cout << "Cannot trade building with level not 0. " << endl;
                                continue;
                            }else if(linjushengjile){
                                cout << "You cannot trade property if a property in its monopoly has improvements"<<endl;
                                continue;
                            }else{
                                if(pl[whosturn]->b[ppp1] == NULL){
                                    cout << "You dont have this building";
                                }else{                                      //trae fuction
                                    cout << "Do you want to accept this trade(y/n), "<<s1<< " ?"<<endl;
                                    char jiebujieshou;
                                    cin >> jiebujieshou;
                                    if(jiebujieshou == 'n'){
                                        cout << "trade rejected"<<endl;
                                        continue;
                                    }
                                    pl[whosturn]->changemoney(i1);
                                    trader->changemoney(-i1);               //change money
                                    trader->b[ppp1] = pl[whosturn]->b[ppp1];
                                    trader->b[ppp1]->setowner(trader);          //change owner
                                    t->notifybuilding(ppp1,trader->getname() ,0);
                                    pl[whosturn]->b[ppp1] = NULL;
                                    pl[whosturn]->settc(M->playmap[ppp1]->getp() -i1);
                                    trader->settc(i1-M->playmap[ppp1]->getp());         //set total cost
                                    cout <<"Trade compeleted"<<endl;
                                    t->printgame(cout);
                                }
                            }
                        }else{                //third trade mothed;
                            cin3 >> s1;
                            cin3 >> s2;
                            cin3 >> s3;
                            cout << pl[whosturn]->gettname() <<" is willing to give "<<trader->gettname() << s2<<" in exchange for "<<s3<<endl;
                            int ppp2 = -1;
                            for(int i = 0; i < 40 ; ++i){                   //get the position of building
                                if(M->playmap[i]->getname() == s3){
                                    ppp2 = i;
                                    break;
                                }
                            }
                            bool linjushengjile = false;
                            for (int i = 0; i < M->playmap[ppp2]->getnn(); ++i){
                                if(M->playmap[ppp1]->getneigh(i)->getlvl() != 0){
                                    linjushengjile = true;
                                    break;
                                }
                            }
                            if (ppp2 == -1) {
                                cout << "There is no player called " << s2 << endl;
                                cout << "You cannot trade." << endl;
                            } else if(M->playmap[ppp2]->getlvl() !=0){
                                cout << "Cannot trade this building with level not 0"<<endl;
                            }else if(linjushengjile){
                                cout << "You cannot trade property if a property in its monopoly has improvements"<<endl;
                                continue;
                            } else if(trader->b[ppp2] == NULL || pl[whosturn]->b[ppp1] == NULL){
                                cout << "Trade can not compeleted"<<endl;
                            }else{
                                cout << "Do you want to accept this trade(y/n), "<<s1<< " ?"<<endl;
                                char jiebujieshou;
                                cin >> jiebujieshou;
                                if(jiebujieshou == 'n'){
                                    cout << "trade rejected"<<endl;
                                    continue;
                                }
                                t->notifybuilding(ppp1,trader->getname() ,0);
                                t->notifybuilding(ppp2,pl[whosturn]->getname() ,0);         //notify textdispaly
                                trader->b[ppp1] = pl[whosturn]->b[ppp1];
                                trader->b[ppp1]->setowner(trader);              //set owner
                                pl[whosturn]->b[ppp1] = NULL;
                                pl[whosturn]->b[ppp2]=trader->b[ppp2];
                                trader->b[ppp2]->setowner(pl[whosturn]);                //set owner
                                trader->b[ppp2] = NULL;
                                pl[whosturn]->settc(M->playmap[ppp2]->getp()-M->playmap[ppp1]->getp());
                                trader->settc(M->playmap[ppp1]->getp() - M->playmap[ppp2]->getp());  //set totalcost
                                cout << "Trade completed"<<endl;
                                t->printgame(cout);
                            }
                        }
                    }
                }else{
                    cout << "You can not trade at this time"<<endl;
                }
            }else if(cmd == "improve"){                 //improve commend
                string ib;
                cin >> ib;
                int ppp;
                for(int i = 0; i < 40 ; ++i){                   //get the position of building
                    if(M->playmap[i]->getname() == ib){
                        ppp = i;
                        break;
                    }
                }
                string cmbs;
                cin >> cmbs;
                if(cmbs == "buy"){                                  //buy improve
                    Building * b1 = M->playmap[ppp];
                    b1->imlvl(pl[whosturn]->gettname());
                    t->notifybuilding(ppp,pl[whosturn]->getname(),b1->getlvl());
                    t->printgame(cout);
                }else if(cmbs == "sell"){           //sell improve
                    Building * b1 = M->playmap[ppp];
                    b1->leveldown(pl[whosturn]->gettname());
                    t->notifybuilding(ppp,pl[whosturn]->getname(),b1->getlvl());  //notify textdisplay
                    t->printgame(cout);                     //notify textdisplay
                }
            }else if(cmd == "mortgage"){        //mortagage commend
                string buildingname;
                cin >> buildingname;
                bool check = M->mortgage(buildingname, pl[whosturn]->gettname());
                if (check) {
                    int ppp = 0;               //find the building position
                    for (; ppp < 40; ++ppp) {
                      if(M->playmap[ppp]->getname() == buildingname) break;
                    }
                    Building * b1 = M->playmap[ppp];
                    t->notifybuilding(ppp,pl[whosturn]->getname(),b1->getlvl());    //notify textdisplay
                    t->printgame(cout);                         //notify textdisplay
                }
            }else if(cmd == "unmortgage"){          //unmortgage  commend
                string buildingname;
                cin >> buildingname;
                bool check = M->unmortgage(buildingname, pl[whosturn]->gettname());
                if (check) {                //
                    int ppp = 0;                  //find teh building position
                    for (; ppp < 40; ++ppp) {
                        if(M->playmap[ppp]->getname() == buildingname) break;
                    }
                    Building * b1 = M->playmap[ppp];
                    t->notifybuilding(ppp,pl[whosturn]->getname(),b1->getlvl()); //notify textdisplay
                    t->printgame(cout);             //notify textdisplay
                }
            }else if(cmd == "bankrupt"){            //bankrupt commend
                if(pl[whosturn]->getmoney() >0){            //player cannot bankrupt
                    cout << "You cannot branrupt"<<endl;
                }else{
                    Player * brankrp = pl[whosturn];        //player who wants bankrupt
                    --numplayer;
                    for(int i = whosturn;i < numplayer; ++i){
                        pl[i] = pl[i+1];
                    }
                    if(M->playmap[pp]->getowner() == NULL){         //romving the player
                        for(int i = 0; i < 40 ; ++i){
                            if(brankrp->b[i] != NULL){
                                brankrp->b[i]->setowner(NULL);
                                auction(brankrp->b[i], i);          //conduce the auction
                            }
                        }
                        cout <<brankrp->gettname() <<" leave this game"<<endl;
                        delete brankrp;      //romving the brankrupt player
                        break;
                    }else{                                  //giving all building to other player
                        for(int i = 0; i < 40 ; ++i){
                            if(brankrp->b[i] != NULL){
                                M->playmap[i]->setowner(M->playmap[pp]->getowner());
                                M->playmap[pp]->getowner()->b[i] = M->playmap[i];
                                t->notifydelete(brankrp->getp(), brankrp->getname());
                                t->notifybuilding(i,pl[whosturn]->getname(),M->playmap[pp]->getlvl());
                                //t->printgame(cout);
                                if(M->playmap[i]->getmort()){
                                    cout << "This building is mortgage"<<endl;
                                    M->unmortgage(M->playmap[i]->getname(),pl[whosturn]->gettname());
                                }
                            }
                        }
                        t->printgame(cout);                 //notify textdisplay
                        cout << brankrp->gettname()<<" leave this game"<<endl;
                        delete  brankrp;
                        break;
                    }
                }
            }else if(cmd == "assets"){          //assets commend
                if(pp == 4){
                    cout <<"You are at Tuition,cannot get all assets printed"<<endl;
                }else{
                    cout << "Your Total property is "<<pl[whosturn]->gettc()<<"."<<endl;
                    cout << "Your current cash is " <<pl[whosturn]->getmoney() << "." <<endl;
                    for (int i = 0; i < 40;++i){
                        if(pl[whosturn]->b[i] != NULL){
                            cout << pl[whosturn]->gettname() << " own "<<pl[whosturn]->b[i]->getname()<<endl;
                        }
                    }
                }
            }else if(cmd == "save"){        //save commend
                ofstream myfile;
                string filename;
                cin >> filename;
                myfile.open(filename.c_str());
                myfile << numplayer<<endl;
                for(int i = 0; i < numplayer; ++i){
                    if(pl[i]->getp() == 10){
                        if(pl[i]->sendtims){
                            myfile << pl[i]->gettname()<< " "<<pl[i]->getname()<<" "<<pl[i]->getRURC() << " "<<pl[i]->getmoney()<<" 10 1"<<pl[i]->numtims<<endl;
                        }else{
                            myfile << pl[i]->gettname()<< " "<<pl[i]->getname()<<" "<<pl[i]->getRURC() << " "<<pl[i]->getmoney()<<" 10 0"<<endl;
                        }
                    }else{
                        myfile << pl[i]->gettname()<< " "<<pl[i]->getname()<<" "<<pl[i]->getRURC() << " "<<pl[i]->getmoney()<<" "<<pl[i]->getp()<<endl;
                    }
                }
                for (int i = 0; i < 40 ;++i){
                    if (M->playmap[i]->getprop()){
                        if (M->playmap[i]->getowner() == NULL){
                            myfile << M->playmap[i]->getname()<< " "<<"NULL"<< " "<< "0"<<endl;
                        }else{
                            myfile << M->playmap[i]->getname()<< " "<< M->playmap[i]->getowner()->gettname()<< " "<<  M->playmap[i]->getlvl()<<endl;
                        }
                    }
                }
                myfile.close();
            } else if (cmd == "Quit") {         //Quit commend
                char c;
                cout << "Do you save the game?? y/n"<< endl;
                cin >> c;
                if (c == 'n') {
                    cout << "Do you want to save the game? y/n" << endl;
                    cin >> c;
                    if (c == 'y') continue;
                }
                cout << "Do you really want to end the Game?? y/n" << endl;
                cin >> c;
                if (c == 'y') {
                    numplayer = 0;
                    break;
                } else {
                    cout << "The game continue." << endl;
                }
            }else{
                cout << "Wrong commend" <<endl;
            }
        }                                                      //clear memory
    }
    if (numplayer == 1) {                                   //game has a winner
        cout << "The end." << endl;
        cout << "Winner: " << pl[0]->gettname() << endl;
    } else {
        cout << "The end." << endl;
        cout << "There is no winner." << endl;
    }
    cleangame();                                                            //clean memory
}

