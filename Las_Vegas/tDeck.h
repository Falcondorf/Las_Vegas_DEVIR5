#ifndef TDECK_H
#define TDECK_H

#include <vector>

class TDeck{
    std::vector <unsigned> bank_;

public:
    TDeck();
    inline unsigned getTicket(int pos) const;
    void shuffleDeck();
};

unsigned TDeck::getTicket(int pos) const{
    return bank_[pos-1];
}

#endif // TDECK_H
