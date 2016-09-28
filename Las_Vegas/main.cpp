#include <iostream>
#include <iomanip>
#include "tDeck.h"

using namespace std;

int main()
{
    TDeck pile ;

    for(unsigned i=1;i<=54;i++){
        std::cout << std::setw(3) << i << ".  " << pile.getTicket(i) << "   ";
        if (i%5==0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    pile.shuffleDeck();

    for(unsigned i=1;i<=54;i++){
        std::cout << std::setw(3) << i << ".  " << pile.getTicket(i) << "   ";
        if (i%5==0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}

