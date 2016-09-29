#include <iostream>
#include <iomanip>
#include "tDeck.h"
#include "casino.h"

using namespace std;

int main()
{
    TDeck pile ;

    for(unsigned i=1;i<=pile.sizeDeck();i++){
        std::cout << std::setw(3) << i << ".  " << pile.getTicket(i) << "   ";
        if (i%5==0){
            std::cout << std::endl;
        }
    }
    std::cout << "\n/*-------------------------------------------*/" << std::endl;

    pile.shuffleDeck();

    for(unsigned i=1;i<=pile.sizeDeck();i++){
        std::cout << std::setw(3) << i << ".  " << pile.getTicket(i) << "   ";
        if (i%5==0){
            std::cout << std::endl;
        }
    }
    std::cout << "\n/*-------------------------------------------*/" << std::endl;

    unsigned lastTicket = pile.pickLastTicket();

    std::cout << "La valeur : " << lastTicket << " a ete piochee...\n" << std::endl;

    for(unsigned i=1;i<=pile.sizeDeck();i++){
        std::cout << std::setw(3) << i << ".  " << pile.getTicket(i) << "   ";
        if (i%5==0){
            std::cout << std::endl;
        }
    }
    std::cout << "\n/*-------------------------------------------*/" << std::endl;

    Casino casino1(1);

    casino1.creditTicket(lastTicket);
    casino1.creditTicket(pile.pickLastTicket());

    std::cout << casino1.totalMoney() << "$ en banque pour Casino:" << casino1.getNum() << std::endl;

    Casino casino2(2);

    while (casino2.totalMoney() < 50000){
        std::cout << pile.getTicket(pile.sizeDeck()) << std::endl;
        casino2.creditTicket(pile.pickLastTicket());
    }

    std::cout << casino2.totalMoney() << "$ en banque pour Casino:" << casino2.getNum() << std::endl;

    std::cout << "\nPlus gros billet = " << casino2.debitHigherTicket();
    std::cout << "Et il reste " << casino2.totalMoney() << std::endl;

    return 0;
}

