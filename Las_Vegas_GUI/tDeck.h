#ifndef TDECK_H
#define TDECK_H

#include <vector>
/*!
 * \brief Classe représentant une pile de billets dans le
 * jeu Las Vegas.
 */
class TDeck{
    std::vector <unsigned> bank_;

public:
    /*!
     * \brief Constructeur d'une pile de billets.
     */
    TDeck();
    /*!
     * \brief Accède à la valeur du ticket à une position donnée.
     * \param pos La position dans la pile de billets.
     * \return La valeur du billet à la position donnée.
     */
    inline unsigned getTicket(int pos) const;
    /*!
     * \brief Retourne le dernier billet et le retire de la pile.
     * \return La valeur du dernier billet.
     */
    inline unsigned pickLastTicket();
    /*!
     * \brief Replace un billet sur le dessous de la pile.
     * \param val La valeur à placer au dessous de la pile.
     */
    inline void underDeck(unsigned val);
    /*!
     * \brief Donne la taille de la pile.
     * \return La taille de la pile.
     */
    inline unsigned sizeDeck();
    /*!
     * \brief Ajoute les GROS billets à la pile.
     */
    void extensionBigTickets();
    /*!
     * \brief Mélange les billets dans la pile.
     */
    void shuffleDeck();
};

unsigned TDeck::getTicket(int pos) const{
    return bank_[pos-1];
}

unsigned TDeck::pickLastTicket(){
    unsigned ticket = bank_.back();
    bank_.pop_back();
    return ticket;
}

void TDeck::underDeck(unsigned val){
    bank_.insert(bank_.begin() ,val);
}

unsigned TDeck::sizeDeck(){
    return bank_.size();
}

#endif // TDECK_H
