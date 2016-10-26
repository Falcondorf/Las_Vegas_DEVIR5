#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "subject.h"
/*!
 * \brief Classe représentant un joueur de Las Vegas.
 */
class Player{
    int num_;
    bool bigDiceExtension_;
    std::pair<bool, unsigned> bigDice_;
    unsigned diceStock_;
    unsigned sumAccount_;
    std::vector<unsigned>dices_;

public:
    /*!
     * \brief Constructeur de la classe joueur.
     * \param no Le numéro du joueur.
     * \param ext Si on joue avec des gros dés.
     * \param dices Le nombre de dés de départ.
     * \param bank La somme d'argent de départ.
     */
    inline Player (int no, bool ext = false, unsigned dices = 8, unsigned bank = 0);
    /*!
     * \brief Accède au numéro du joueur.
     * \return Le numéro du joueur.
     */
    inline unsigned getNum() const;
    /*!
     * \brief Crédite le joueur avec le montant d'argent passé en paramètre.
     * \param value Le montant d'argent.
     */
    inline void creditP (unsigned value);
    /*!
     * \brief Accède à la somme d'argent du joueur.
     * \return La somme d'argent du joueur.
     */
    inline unsigned getSumAccount() const;
    /*!
     * \brief Accède au nombre de dés restant au joueur.
     * \return Le nombre de dés restant.
     */
    inline unsigned getDiceStock() const;
    /*!
     * \brief Retire des dés du stock de dés. Si il y a le gros dé,
     *  on met la valeur booléenne du gros dé à faux.
     * \param num Le nombre de dés à retirer.
     * \param putBig Booléen si on dépose un gros dé ou non.
     */
    inline void putDice(unsigned num, bool putBig);
    /*!
     * \brief Rend au joueur tous ses dés.
     */
    inline void getDiceBack();
    /*!
     * \brief Lance les dés du joueurs.
     */
    void rollDices();
    /*!
     * \brief Accède à la valeur d'un dé à la position donnée.
     * \param pos La position dans la liste de dés.
     * \return La valeur du dé.
     */
    inline unsigned getDiceAt(unsigned pos)const;
    /*!
     * \brief Calcul la valeur des dés (leur occurence) d'une
     * valeur. Si un gros dé est compté, il vaut double.
     * \param val La valeur du dé à compter.
     * \return Combien de fois le dé est décompter
     *  (si gros dé, il compte double).
     */
    unsigned valueOccurency(unsigned val)const;
    /*!
     * \brief Retourne qu'on joue ou non en extension gros dé.
     * \return Vrai si on joue avec l'extension des gros dés.
     */
    inline bool getBigDiceExt() const;
    /*!
     * \brief Retourne si le joueur possède encore son gros dé.
     * \return Vrai lorsque le joueur a encore son gros dé.
     */
    inline bool getHasBigDice() const;
    /*!
     * \brief Accède à la valeur du gros dé.
     * \return La valeur du gros dé.
     */
    inline unsigned getBigDiceVal() const;
};

Player::Player(int no, bool ext, unsigned dices, unsigned bank)
    :num_(no), bigDiceExtension_(ext), diceStock_(dices), sumAccount_(bank){
    if (bigDiceExtension_){
        bigDice_.first = true;
        bigDice_.second = 1;
    } else {
        bigDice_.first = false;
        bigDice_.second = 0;
    }
    for (unsigned i=0; i<diceStock_; i++){
        dices_.push_back(1);
    }
}

unsigned Player::getNum() const{
    return num_;
}

bool Player::getBigDiceExt() const{
    return bigDiceExtension_;
}

bool Player::getHasBigDice() const{
    return bigDice_.first;
}

unsigned Player::getBigDiceVal() const{
    return bigDice_.second;
}

void Player::creditP(unsigned value){
    sumAccount_ += value;
}

unsigned Player::getSumAccount()const{
    return sumAccount_;
}

unsigned Player::getDiceStock()const{
    if (bigDiceExtension_){
        if(bigDice_.first){
            return diceStock_+1;
        }else {
            return diceStock_;
        }
    }else {
        return diceStock_;
    }

}

void Player::putDice(unsigned num, bool putBig){
    diceStock_ -= num;
    if (putBig){
        bigDice_.first = false;
    }
}

void Player::getDiceBack(){
    if (bigDiceExtension_){
        diceStock_ = 7;
        bigDice_.first = true;
    }else {
        diceStock_ = 8;
    }
}

unsigned Player::getDiceAt(unsigned pos) const{
    return dices_[pos];
}

#endif // PLAYER_H
