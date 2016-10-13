#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "tDeck.h"
#include "casino.h"

#include "subject.h"

class Game : public nvs::Subject{
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
    inline unsigned getCurrPlay() const;
    void nextRound();
    bool roundOver();//Round terminé lorsque plus aucun joueur n'a de dé
    bool isOver();   //Jeu terminé quand le round 4 est fini

    inline void insertBet (unsigned val);
    inline void rollDices();

};

Casino & Game::getCasino(unsigned nbC){
    return casinoList_[nbC];
}

Player & Game::getPlayer(unsigned nbP){
    return playerList_[nbP];
}

unsigned Game::getCurrPlay() const{
    return currPlayer_;
}

void Game::insertBet(unsigned val){
    casinoList_[val-1].insertBet(playerList_[currPlayer_].valueOccurency(val), playerList_[currPlayer_].getNum());
    playerList_[currPlayer_].putDice(playerList_[currPlayer_].valueOccurency(val));
    notifyObservers();
}

void Game::rollDices(){
    playerList_[currPlayer_].rollDices();
    notifyObservers();
}

#endif // GAME_H
