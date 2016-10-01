//
// Create by Lihua Chen
//
//  Map.cpp
//  bb7k
//
#include "Map.h"

Map::Map():numRURC(4),C(NULL) {
	for (int i = 0; i < 40; ++i) { // initialize the array of pointer of Building
		playmap[i] = NULL; 
	}
}
Map::~Map() {
	for (int i = 0; i < 40; ++i) { // delete all of the Building in Map
		delete playmap[i];
	}
}

int Map::getRURC() {
	return numRURC;
}
void Map::setRURC(int i) {
	numRURC += i; // change the number of RURC
}

Building* Map::getpm(int i) {
	return playmap[i]; // find a building
}

void Map::initial() {
	// create a new OSAP, the start point of the game
	Building *osap = new OSAP("OSAP");
    playmap[0] = osap; // create the first step
	// the second step, AL, Academic
    Building *al = new Academic("AL");
	al->setprop(true); // the Al can be bought by player
    al->settuit(2); // the initial tuition of AL
	al->setpay(40); // how much the player should pay, if he/she want to buy AL
    playmap[1] = al;
	// step 3, SLC
	Building *slc1 = new SLC("SLC");
	slc1->setprop(false); // SLC cannot be sold
	playmap[2] = slc1;
	// step 4, ML, Academic
	Building *ml = new Academic("ML");
	ml->setprop(true); // ML can be bought by player
	ml->settuit(4); // the initial tuition of ML
	ml->setpay(60); // how much the player should pay, if he/she want to buy ML
    playmap[3] = ml;
	// step 5, Tuition
	Building *tuition = new Tuition("Tuition");
	tuition->setprop(false); // Tuition cannot be sold
	playmap[4] = tuition;
	//6, MKV, Residence
	Building *mkv = new Residence("MKV");
    mkv->setprop(true); // MKV can be bought by player
    // Rather than paying Tuition visitors will pay Rent to the residence owner. 
    // Rent is calculated based on the number of residences a player owns.
	mkv->setpay(200); // how much the player should pay, if he/she want to buy MKV
    playmap[5] = mkv; 
	//7, ECH, Academic
	Building *ech = new Academic("ECH");
	ech->setprop(true); // ECH can be bought by player
	ech->settuit(6); // the initial tuition of ECH
	ech->setpay(100); // how much the player should pay, if he/she want to buy ECH
	playmap[6] = ech;
	//8, Needles Hall
	Building *nh1 = new Needleshall("Needles Hall");
	nh1->setprop(false); // Needles Hall cannot be sold
    playmap[7] = nh1;
	//9, PAS, Academic
	Building *pas = new Academic("PAS");
	pas->setprop(true); // PAS can be bought by player
	pas->settuit(6); // the initial tuition of PAS
	pas->setpay(100); // how much the player should pay, if he/she want to buy PAS
	playmap[8] = pas;
	//10, HH, Academic
	Building *hh = new Academic("HH");
    hh->setprop(true); // HH can be bought by player
    hh->settuit(8); // the initial tuition of HH
    hh->setpay(120); // how much the player should pay, if he/she want to buy HH
	playmap[9] = hh;
	//11, DC Tims Line
	Building *dctl = new DCtimsline("DC Tims Line");
	dctl->setprop(false); // DC Tims Line cannot be sold
    playmap[10] = dctl;
	//12, RCH, Academic
	Building *rch = new Academic("RCH");
	rch->setprop(true); // RCH can be bought by player
    rch->settuit(10); // the initial tuition of RCH
	rch->setpay(140); // how much the player should pay, if he/she want to buy RCH
	playmap[11] = rch;
	//13, PAC, Gyms
	Building *pac = new Gyms("PAC");
    pac->setprop(true); // PAC can be bought by player
    // Usage fees are calculated by rolling two dice3. 
    // If one Gym is owned by a player, the fee is 4 times the sum of the dice.
	pac->setpay(150); // how much the player should pay, if he/she want to buy PAC
	playmap[12] = pac;
	//14, DWE, Academic
	Building *dwe = new Academic("DWE");
	dwe->setprop(true); // DWE can be bought by player
    dwe->settuit(10); // the initial tuition of DWE
	dwe->setpay(140); // how much the player should pay, if he/she want to buy DWE
	playmap[13] = dwe;
	//15, CPH, Academic
    Building *cph = new Academic("CPH");
	cph->setprop(true); // CPH can be bought by player
	cph->settuit(12); // the initial tuition of CPH
	cph->setpay(160); // how much the player should pay, if he/she want to buy CPH
    playmap[14] = cph;
	//16, UWP, Residences
	Building *uwp = new Residence("UWP");
    uwp->setprop(true); // UWP can be bought by player
    // Rather than paying Tuition visitors will pay Rent to the residence owner. 
    // Rent is calculated based on the number of residences a player owns.
	uwp->setpay(200); // how much the player should pay, if he/she want to buy UWP
	playmap[15] = uwp;
	//17, LHI, Academic
    Building *lhi = new Academic("LHI");
	lhi->setprop(true); // LHI can be bought by player
	lhi->settuit(14); // the initial tuition of LHI
	lhi->setpay(180); // how much the player should pay, if he/she want to buy LHI
	playmap[16] = lhi;
	//18, SLC
	Building *slc2 = new SLC("SLC");
	slc2->setprop(false); // SLC cannot be sold
	playmap[17] = slc2;
	//19, BMH, Academic
	Building *bmh = new Academic("BMH");
	bmh->setprop(true); // BMH can be bought by player
	bmh->settuit(14); // the initial tuition of BMH
	bmh->setpay(180); // how much the player should pay, if he/she want to buy BMH
	playmap[18] = bmh;
	//20, OPT, Academic
	Building *opt = new Academic("OPT");
	opt->setprop(true); // OPT can be bought by player
	opt->settuit(16); // the initial tuition of OPT
	opt->setpay(200); // how much the player should pay, if he/she want to buy OPT
	playmap[19] = opt;
	//21, Goose Nesting
	Building *gn = new Goosenesting("Goose Nesting");
	gn->setprop(false); // Goose Nesting cannot be sold
	playmap[20] = gn;
	//22, EV1, Academic
	Building *ev1 = new Academic("EV1");
	ev1->setprop(true); // EV1 can be bought by player
	ev1->settuit(18); // the initial tuition of EV1
	ev1->setpay(220); // how much the player should pay, if he/she want to buy EV1
	playmap[21] = ev1;
	//23, Needles Hall
	Building *nh2 = new Needleshall("Needles Hall");
	nh2->setprop(false); // Needles Hall cannot be sold
    playmap[22] = nh2;
	//24, EV2, Academic
	Building *ev2 = new Academic("EV2");
	ev2->setprop(true); // EV2 can be bought by player
	ev2->settuit(18); // the initial tuition of EV2
	ev2->setpay(220); // how much the player should pay, if he/she want to buy EV2
	playmap[23] = ev2;
	//25, EV3, Academic
	Building *ev3 = new Academic("EV3");
	ev3->setprop(true); // EV3 can be bought by player
	ev3->settuit(20); // the initial tuition of EV3
	ev3->setpay(240); // how much the player should pay, if he/she want to buy EV3
    playmap[24] = ev3;
	//26, V1, Residence
	Building *v1 = new Residence("V1");
	v1->setprop(true); // V1 can be bought by player
	// Rather than paying Tuition visitors will pay Rent to the residence owner. 
	// Rent is calculated based on the number of residences a player owns.
	v1->setpay(200); // how much the player should pay, if he/she want to buy V1
	playmap[25] = v1;
	//27 PHYS, Academic
	Building *phys = new Academic("PHYS");
	phys->setprop(true); // PHYS can be bought by player
	phys->settuit(22); // the initial tuition of PHYS
    phys->setpay(260); // how much the player should pay, if he/she want to buy PHYS
	playmap[26] = phys;
	//28, B1, Academic
	Building *b1 = new Academic("B1");
	b1->setprop(true); // B1 can be bought by player
	b1->settuit(22); // the initial tuition of B1
    b1->setpay(260); // how much the player should pay, if he/she want to buy B1
	playmap[27] = b1;
	//29, CIF, Gyms
	Building *cif = new Gyms("CIF");
	cif->setprop(true); // CIF can be bought by player
	// Usage fees are calculated by rolling two dice3. 
	// If one Gym is owned by a player, the fee is 4 times the sum of the dice.
	cif->setpay(150); // how much the player should pay, if he/she want to buy CIF
	playmap[28] = cif;
	//30, B2, Academic
	Building *b2 = new Academic("B2");
	b2->setprop(true); // B2 can be bought by player
	b2->settuit(24); // the initial tuition of B2
	b2->setpay(280); // how much the player should pay, if he/she want to buy B2
	playmap[29] = b2;
	//31, Go To Times
	Building *gtt = new Gototims("Go To Times");
	gtt->setprop(false); // Go To Tims cannot be sold
    playmap[30] = gtt;
	//32, EIT, Academic
	Building *eit = new Academic("EIT");
	eit->setprop(true); // EIT can be bought by player
	eit->settuit(26); // the initial tuition of EIT
	eit->setpay(300); // how much the player should pay, if he/she want to buy EIT
	playmap[31] = eit;
	//33, ESC, Academic
	Building *esc = new Academic("ESC");
	esc->setprop(true); // ESC can be bought by player
	esc->settuit(26); // the initial tuition of ESC
    esc->setpay(300); // how much the player should pay, if he/she want to buy ESC
	playmap[32] = esc;
	//34, SLC
	Building *slc3 = new SLC("SLC");
	slc3->setprop(false); // SLC cannot be sold
	playmap[33] = slc3;
	//35, C2, Academic
	Building *c2 = new Academic("C2");
	c2->setprop(true); // C2 can be bought by player
	c2->settuit(28); // the initial tuition of C2
	c2->setpay(320); // how much the player should pay, if he/she want to buy C2
	playmap[34] = c2;
	//36, REV, Residence
	Building *rev = new Residence("REV");
    rev->setprop(true); // REV can be bought by player
    // Rather than paying Tuition visitors will pay Rent to the residence owner. 
    // Rent is calculated based on the number of residences a player owns.
	rev->setpay(200); // how much the player should pay, if he/she want to buy REV
	playmap[35] = rev;
	//37, Needles Hall
	Building *nh3 = new Needleshall("Needles Hall");
	nh3->setprop(false); // Needles Hall cannot be sold
	playmap[36] = nh3;
	//38, MC, Academic
	Building *mc = new Academic("MC");
	mc->setprop(true); // MC can be bought by player
	mc->settuit(35); // the initial tuition of MC
    mc->setpay(350); // how much the player should pay, if he/she want to buy MC
	playmap[37] = mc;
	//39, Coop Fee
	Building *cf = new Coopfee("Coop Fee");
	cf->setprop(false); // Coop Fee can be bought by player
	playmap[38] = cf;
	//40, DC, Academic
	Building *dc = new Academic("DC");
	dc->setprop(true); // DC can be bought by player
	dc->settuit(50); // the initial tuition of DC
	dc->setpay(400); // how much the player should pay, if he/she want to buy DC
	playmap[39] = dc;
}

bool Map::mortgage(string s, string name) {
    for (int i = 0; i < 40; ++i) { // check all of the step, to find the property named s
        if (s == playmap[i]->getname()) {
            int nn = playmap[i]->getnn();
            if (nn > 0) {
                for (int j = 0; j < nn; ++j) {
                    if (playmap[i]->getneigh(j)->getlvl() > 0) {
                        cout << "You cannot mortgage this property if a property in its monopoly has improvements." << endl;
                        return false;
                        
                    }
                }
            }
        	if ((playmap[i]->getowner() == NULL) || (playmap[i]->getowner()->gettname() != name)) {
        		// check whether the player who call mortgage is the owner of the property
        		cout << "Don't joke!! You are not the owner, you cannot mortgage the property!!!" << endl;
        		return false;
        	}
            playmap[i]->mortgage();
            return true;
        }
    }
    return false;
}

bool Map::unmortgage(string s, string name) {
    for (int i =0 ; i < 40; ++i) { // check all of the step, to find the property named s
        if (s == playmap[i]->getname()) {
        	if ((playmap[i]->getowner() == NULL) || (playmap[i]->getowner()->gettname() != name)) {
        		// check whether the player who call mortgage is the owner of the property
        		cout << "Don't joke!! You are not the owner, you cannot unmortgage the property!!!" << endl;
        		return false;
        	}
            playmap[i]->unmortgage();
            return true;
        }
    }
    return false;
}


