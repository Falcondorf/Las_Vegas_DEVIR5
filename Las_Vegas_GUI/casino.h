#ifndef CASINO_H
#define CASINO_H

#include <vector>
#include <string>

#include "subject.h"

class Casino{
    unsigned num_;
    std::vector<unsigned> ticketList_;
    std::vector<unsigned> betList_;


public:
    inline Casino(unsigned n);
    inline unsigned getNum() const;
    inline unsigned getnbTicket() const;
    unsigned getHighestBet() const;
    void initBetList(unsigned nbP);
    inline void creditTicket(unsigned value);
    unsigned debitHigherTicket();
    inline unsigned totalMoney();
    inline void insertBet(unsigned valAdd, int numPlayer);
    void resetCasino();
    std::string makeStringTickets();
    std::string makeStringBets();
    void checkDraw();
    inline void clearBet(unsigned numP);
    inline bool isEmptyBet();

};

Casino::Casino(unsigned n):num_(n){}

unsigned Casino::getNum()const{
    return num_;
}

void Casino::creditTicket(unsigned value){
    ticketList_.push_back(value);
}

void Casino::insertBet(unsigned valAdd, int numPlayer){
    betList_[numPlayer] += valAdd;
}

unsigned Casino::getnbTicket() const {
    return ticketList_.size();
}

bool Casino::isEmptyBet(){
    bool isEmpty = false;
    for (unsigned val : betList_){
        if (val != 0){
            isEmpty = true;
        }
    }
    return isEmpty;
}

unsigned Casino::totalMoney(){
    unsigned total=0;
    for(unsigned val : ticketList_){
        total += val;
    }
    return total;
}

void Casino::clearBet(unsigned numP){
    betList_[numP] = 0;
}

#endif // CASINO_H
