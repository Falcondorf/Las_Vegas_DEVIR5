#include "casino.h"
#include <sstream>

void Casino::initBetList(unsigned nbP){
    for (unsigned i=0; i< nbP; i++){
        betList_.push_back(0);
    }
}

unsigned Casino::debitHigherTicket(){
    std::pair<unsigned, unsigned> highestTicket(0,0); //first: position/ second: la val

    for (unsigned i=0; i<ticketList_.size();i++){
        if (ticketList_[i] > highestTicket.second){
            highestTicket.first = i;
            highestTicket.second = ticketList_[i];
        }
    }
    ticketList_.erase(ticketList_.begin()+highestTicket.first);
    return highestTicket.second;
}

unsigned Casino::getHighestBet() const {
    std::pair<unsigned, unsigned> highestBet(0,0); //first: position/ second: la val

    for (unsigned i=0; i<betList_.size();i++){
        if (betList_[i] > highestBet.second){
            highestBet.first = i;
            highestBet.second = betList_[i];
        }
    }
    return highestBet.first;
}

void Casino::resetCasino(){
    ticketList_.clear();
    betList_.clear();
}

std::string Casino::makeStringTickets(){
    std::string laChaine ="";
    for (unsigned val : ticketList_){
        std::stringstream ss;
        ss << val;
        laChaine+="\n"+ss.str();
    }
    return laChaine;
}

std::string Casino::makeStringBets(){
    std::string laChaine ="";
    int cpt = 1;
    for (unsigned val : betList_){
        std::stringstream ss;
        ss << cpt << ": " << val;
        laChaine+="\n"+ss.str();
        cpt++;
    }
    return laChaine;
}

void Casino::checkDraw(){
    unsigned i=0, j=betList_.size()-1;
    bool wasDoubled;
    while (i<j){
        wasDoubled = false;
        while (j>i){
            if (betList_.at(i) == betList_.at(j)){
                betList_[j] = 0;
                wasDoubled = true;
            }
            j--;
        }
        if (wasDoubled){
            betList_.at(i) = 0;
        }
        i++;
    }
}
