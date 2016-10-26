#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "tDeck.h"
#include "casino.h"

#include "subject.h"
/*!
 * \brief La classe qui gère le fonctionnement et le moteur du
 * jeu Las Vegas.
 */
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
    /*!
     * \brief Constructeur de la classe de jeu.
     * \param nbJ Le nombre de joueur.
     * \param bigTickets Extension des gros billets de 100.000$
     * \param bigDices Extension des gros dés.
     */
    Game (unsigned nbJ, bool bigTickets, bool bigDices);
    /*!
     * \brief Méthode passant le joueur courant au suivant.
     */
    void nextPlayer();
    /*!
     * \brief Accède à un joueur.
     * \param nbP Le numéro du joueur.
     * \return Retourne le joueur sélectionné.
     */
    inline Player &getPlayer(unsigned nbP);
    /*!
     * \brief Accède à un casino.
     * \param nbC Le numéro du casino.
     * \return Retourne le casino sélectionné.
     */
    inline Casino &getCasino(unsigned nbC);
    /*!
     * \brief Donne le numéro du joueur courant.
     * \return Le numéro du joueur courant.
     */
    inline unsigned getCurrPlay() const;
    /*!
     * \brief Donne le numéro du round courant.
     * \return Le numéro du round courant.
     */
    inline unsigned getCurrRound() const;
    /*!
     * \brief Passe au round suivant. Distribue les billets aux joueurs
     * et réinitialise les casinos.
     */
    void nextRound();
    /*!
     * \brief Vérifie que tous les joueurs ont placé leurs dés, c'est-
     * à-dire que le round est terminé.
     * \return Vrai lorsque tout les dés sont placé.
     */
    bool roundOver();//Round terminé lorsque plus aucun joueur n'a de dé
    /*!
     * \brief Vérifie que tous les rounds sont terminé et ainsi que le
     * jeu est fini.
     * \return Vrai lorsque le dernier round est terminé.
     */
    bool isOver();   //Jeu terminé quand le round 4 est fini
    /*!
     * \brief Retrouve le joueur ayant la plus grosse somme d'argent.
     * C'est lui qui gagne la partie.
     * \return La pair donne en first le numéro du joueur et le second
     * la somme d'argent.
     */
    inline std::pair<unsigned, unsigned> getWinner();
    /*!
     * \brief Insères tous les dés de la valeur en paramètre du joueur courant.
     * \param val La valeur du dé à placer.
     */
    inline void insertBet (unsigned val);
    /*!
     * \brief Lance les dés du joueurs courant.
     */
    inline void rollDices();
    /*!
     * \brief Informe si on joue avec l'extension gros dés.
     * \return Vrai si on joue avec les gros dé.
     */
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
    if (playerList_[currPlayer_].valueOccurency(val) == 0){
        throw std::exception();
    }
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
