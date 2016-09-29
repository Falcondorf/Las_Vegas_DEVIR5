#ifndef TDECK_H
#define TDECK_H

#include <vector>

class TDeck{
    std::vector <unsigned> bank_;

public:
    TDeck();
    inline unsigned getTicket(int pos) const;
    inline unsigned pickLastTicket();
    inline void underDeck(unsigned val);
    inline unsigned sizeDeck();
    void shuffleDeck();
};

unsigned TDeck::getTicket(int pos) const{
    return bank_[pos-1];
}

unsigned TDeck::pickLastTicket(){
    unsigned ticket = bank_.back();
    bank_.pop_back();
    return ticket;
}

void TDeck::underDeck(unsigned val){
    bank_.insert(bank_.begin() ,val);
}

unsigned TDeck::sizeDeck(){
    return bank_.size();
}

#endif // TDECK_H
