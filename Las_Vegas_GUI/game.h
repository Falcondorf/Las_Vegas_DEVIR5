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
    bool bigDiceExt_;
    std::vector<Player> playerList_;
    std::vector<Casino> casinoList_;
    TDeck pile_;

    void initCasinos();
    void distributeTickets();

public:
    Game (unsigned nbJ, bool bigTickets, bool bigDices);
    void nextPlayer();
    inline Player &getPlayer(unsigned nbP);
    inline Casino &getCasino(unsigned nbC);
    inline unsigned getCurrPlay() const;
    inline unsigned getCurrRound() const;
    void nextRound();
    bool roundOver();//Round terminé lorsque plus aucun joueur n'a de dé
    bool isOver();   //Jeu terminé quand le round 4 est fini    
    inline std::pair<unsigned, unsigned> getWinner();

    inline void insertBet (unsigned val);
    inline void rollDices();

    inline bool playingBigDice() const;
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

unsigned Game::getCurrRound() const{
    return currRound_;
}

void Game::insertBet(unsigned val){
    casinoList_[val-1].insertBet(playerList_[currPlayer_].valueOccurency(val), playerList_[currPlayer_].getNum());
    if (bigDiceExt_ && playerList_[currPlayer_].getHasBigDice()
                    && playerList_[currPlayer_].getBigDiceVal() == val){
        playerList_[currPlayer_].putDice(playerList_[currPlayer_].valueOccurency(val)-1,true);
//    } else if (bigDiceExt_ && playerList_[currPlayer_].getBigDiceVal() != val){
//        playerList_[currPlayer_].putDice(playerList_[currPlayer_].valueOccurency(val)-1,false);
    }else {
        playerList_[currPlayer_].putDice(playerList_[currPlayer_].valueOccurency(val),false);
    }
}

void Game::rollDices(){
    playerList_[currPlayer_].rollDices();
    notifyObservers();
}

std::pair<unsigned, unsigned> Game::getWinner(){
    //first: numéro joueur / second: somme totale
    std::pair<unsigned, unsigned> winner(0,0);
    for(Player p : playerList_){
        if (p.getSumAccount()>winner.second){
            winner.first = p.getNum();
            winner.second = p.getSumAccount();
        }
    }
    return winner;
}

bool Game::playingBigDice() const{
    return bigDiceExt_;
}

#endif // GAME_H
