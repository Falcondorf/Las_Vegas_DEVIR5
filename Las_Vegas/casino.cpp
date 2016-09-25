#include "casino.h"

unsigned Casino::debitHigherTicket(){
    std::pair<unsigned, unsigned> highestTicket(0,0);

    for (unsigned i=0; i<=ticketList_.size();i++){
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
