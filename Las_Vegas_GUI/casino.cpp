#include "casino.h"
#include <sstream>

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
    for (unsigned val : betList_){
        std::stringstream ss;
        ss << val;
        laChaine+=ss.str()+"\n";
    }
    return laChaine;
}
