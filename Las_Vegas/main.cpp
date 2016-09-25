#include <iostream>
#include "tDeck.h"

using namespace std;

int main()
{
    TDeck pile ;

    for(unsigned i=1;i<=54;i++){
        std::cout << i << ".  " << pile.getTicket(i) << "   ";
        if (i%5==0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}

