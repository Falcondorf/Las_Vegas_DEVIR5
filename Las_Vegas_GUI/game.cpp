#include "game.h"

Game::Game(unsigned nbJ, bool bigTickets, bool bigDices):nbPlayer_(nbJ), bigDiceExt_(bigDices){//casinoList, playerList, pile à init
    //Init pile et mélange
    if (bigTickets){
        pile_.extensionBigTickets();
    }
    pile_.shuffleDeck();
    //init Joueurs
    for (unsigned i=0; i<nbJ; i++){
        playerList_.push_back(Player(i,bigDices));
    }
    //init Casinos
    for (unsigned i=0; i<6; i++){
        casinoList_.push_back(Casino(i));
    }
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
    if (currRound_>0){
        isOver = true;
    }
    return isOver;
}

void Game::initCasinos(){
    for (unsigned i=0; i<6; i++){
        //casinoList_.push_back(Casino(i));
        while (casinoList_[i].totalMoney() < 50000){
            casinoList_[i].creditTicket(pile_.pickLastTicket());
        }
        casinoList_.at(i).initBetList(nbPlayer_);
    }
}

void Game::distributeTickets(){
    for (Casino c : casinoList_){
        while (c.getnbTicket() > 0 && c.isEmptyBet()){
            //trouvé le plus gros pari puis donné le premier ticket
            playerList_.at(c.getHighestBet()).creditP(c.debitHigherTicket());
            c.clearBet(c.getHighestBet());
        }
    }
}

void Game::nextRound(){
    //Vérif égalité et Distrib billets...
    for (auto i=0;i<6;i++){
        casinoList_[i].checkDraw();
    }
//    for (Casino c : casinoList_){
//        c.checkDraw();//A vérifier si il supprimme bien
//    }
    distributeTickets();

    for (unsigned i=0; i<6; i++){
        casinoList_.at(i).resetCasino();
    }
    initCasinos();
    for (unsigned i=0; i<nbPlayer_;i++){
        playerList_[i].getDiceBack();
    }
//    for (Player p : playerList_){
//        p.getDiceBack();
//    }

    currRound_++;

    notifyObservers();
}
