#include "tDeck.h"
#include <algorithm>

TDeck::TDeck(){
    for(unsigned i=0; i<5; i++){
        bank_.push_back(60000);
        bank_.push_back(70000);
        bank_.push_back(80000);
        bank_.push_back(90000);
    }
     for(unsigned i=0; i<6; i++){
         bank_.push_back(10000);
         bank_.push_back(40000);
         bank_.push_back(50000);
     }
     for(unsigned i=0; i<8; i++){
         bank_.push_back(20000);
         bank_.push_back(30000);
     }
}

void TDeck::shuffleDeck()const {

}
