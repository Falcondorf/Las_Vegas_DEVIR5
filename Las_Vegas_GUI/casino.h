#ifndef CASINO_H
#define CASINO_H

#include <vector>
#include <string>

#include "subject.h"
/*!
 * \brief Classe représentant un casino dans le jeu Las Vegas
 */
class Casino{
    unsigned num_;
    std::vector<unsigned> ticketList_;
    std::vector<unsigned> betList_;


public:
    /*!
     * \brief Constructeur de la classe casino.
     * \param n Le numéro du casino.
     */
    inline Casino(unsigned n);
    /*!
     * \brief Accède à la variable qui définit le numéro du casino.
     * \return le numéro du casino.
     */
    inline unsigned getNum() const;
    /*!
     * \brief Donne le nombre de ticket que le casino possède
     * \return La nombre de billet que possède la casino.
     */
    inline unsigned getnbTicket() const;
    /*!
     * \brief Retourne la position du billet avec la plus grande valeur dans la liste des billets.
     * \return La position du plus gros billet.
     */
    unsigned getHighestBet() const;
    /*!
     * \brief Initialise une liste de pari pour chaques joueurs.
     * \param nbP Le nombre de joueur total.
     */
    void initBetList(unsigned nbP);
    /*!
     * \brief Crédite le casino avec un nouveau billet dont la valeur est passée en paramètre.
     * \param value Le montant du billet ajouté.
     */
    inline void creditTicket(unsigned value);
    /*!
     * \brief Débite le casino de son plus gros billet.
     * \return La valeur du plus gros billet.
     */
    unsigned debitHigherTicket();
    /*!
     * \brief Donne le montant total d'argent que le casino possède.
     * \return Le total d'argent que possède le casino.
     */
    inline unsigned totalMoney();
    /*!
     * \brief Place un pari (un nombre de dés) pour un joueur dans la liste de ses paris sur le casino.
     * \param valAdd Le nombre de dé à ajouter.
     * \param numPlayer Le numéro du joueur placant le pari.
     */
    inline void insertBet(unsigned valAdd, int numPlayer);
    /*!
     * \brief Vide complètement la liste de billets et la liste de paris.
     */
    void resetCasino();
    /*!
     * \brief Crée une représentation sous forme de chaîne de caractère pour afficher les billets.
     * \return La chaîne représantant les billets.
     */
    std::string makeStringTickets();
    /*!
     * \brief Crée une représentation sous forme de chaîne de caractère pour afficher les paris des joueurs.
     * \return La chaîne représantant les paris de joueurs.
     */
    std::string makeStringBets();
    /*!
     * \brief Vérifie s'il y a des paris de montant identique et les supprime.
     */
    void checkDraw();
    /*!
     * \brief Remet les paris d'un joueur à zéro.
     * \param numP Le numéro du joueur.
     */
    inline void clearBet(unsigned numP);
    /*!
     * \brief Vérifie si le casino n'a aucun paris.
     * \return Vrai lorsque le casino n'a aucun paris.
     */
    inline bool isEmptyBet();

};

Casino::Casino(unsigned n):num_(n){}

unsigned Casino::getNum()const{
    return num_;
}

void Casino::creditTicket(unsigned value){
    ticketList_.push_back(value);
}

void Casino::insertBet(unsigned valAdd, int numPlayer){
    betList_[numPlayer] += valAdd;
}

unsigned Casino::getnbTicket() const {
    return ticketList_.size();
}

bool Casino::isEmptyBet(){
    bool isEmpty = false;
    for (unsigned val : betList_){
        if (val != 0){
            isEmpty = true;
        }
    }
    return isEmpty;
}

unsigned Casino::totalMoney(){
    unsigned total=0;
    for(unsigned val : ticketList_){
        total += val;
    }
    return total;
}

void Casino::clearBet(unsigned numP){
    betList_[numP] = 0;
}

#endif // CASINO_H
