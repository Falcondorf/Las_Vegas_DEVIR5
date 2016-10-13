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

void Casino::resetCasino(){
    ticketList_.clear();
    betList_.clear();
    notifyObservers();
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
