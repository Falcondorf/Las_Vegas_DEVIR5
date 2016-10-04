#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "tDeck.h"
#include "casino.h"

class Game{
    unsigned currPlayer_=0;
    unsigned currRound_=1;
    unsigned nbPlayer_;
    std::vector<Player> playerList_;
    std::vector<Casino> casinoList_;
    TDeck pile_;    

public:
    Game (unsigned nbJ);
    void nextPlayer();
    inline Player &getPlayer(unsigned nbP);
    inline Casino &getCasino(unsigned nbC);
    void nextRound();
    bool roundOver();//Round terminé lorsque plus aucun joueur n'a de dé
    bool isOver();   //Jeu terminé quand le round 4 est fini

};

Casino &Game::getCasino(unsigned nbC){
    return casinoList_[nbC];
}

Player &Game::getPlayer(unsigned nbP){
    return playerList_[nbP];
}

#endif // GAME_H
