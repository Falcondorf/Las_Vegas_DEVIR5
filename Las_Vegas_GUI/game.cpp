#include "game.h"

Game::Game(unsigned nbJ):nbPlayer_(nbJ){//casinoList, playerList, pile à init
    //Init pile et mélange
    pile_.shuffleDeck();
    //init Joueurs
    for (unsigned i=0; i<nbJ; i++){
        playerList_.push_back(Player(i));
    }
    //init Casinos
    initCasinos();
}

void Game::nextPlayer(){
    currPlayer_++;
    if (currPlayer_==nbPlayer_){
        currPlayer_=0;
    }
    if (playerList_[currPlayer_].getDiceStock() == 0 && !roundOver()){
        nextPlayer();
    }

    notifyObservers();
}

bool Game::roundOver(){
    for (Player p: playerList_){
        if (p.getDiceStock()>0){
            return false;
        }
    }
    return true;
}

bool Game::isOver(){
    bool isOver = false;
    if (currRound_>4){
        isOver = true;
    }
    return isOver;
}

void Game::initCasinos(){
    for (unsigned i=0; i<6; i++){
        casinoList_.push_back(Casino(i));
        while (casinoList_[i].totalMoney() < 50000){
            casinoList_[i].creditTicket(pile_.pickLastTicket());
        }
        casinoList_.at(i).initBetList(nbPlayer_);
    }
}

void Game::checkDraw(){
    //suppression des égalités dans les betList
}

void Game::nextRound(){
    //Distrib billets et vérif égalité...

    for (unsigned i=0; i<6; i++){
        casinoList_.at(i).resetCasino();
    }
    initCasinos();
    for (Player p : playerList_){
        p.getDiceBack();
    }
    currRound_++;
}
