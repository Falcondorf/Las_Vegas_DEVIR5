#ifndef FORMULAIREWINDOW_H
#define FORMULAIREWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include "game.h"
#include "gamewindow.h"

/*!
 * \brief formulaireWindow La classe qui gère la fenetre de configuration du jeu.
 */
class formulaireWindow : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief formulaireWindow constructeur de la fenetre de configuration du jeu.
     * \param parent la fenetre d'ouverture du jeu.
     */
    explicit formulaireWindow(QWidget *parent = 0);
signals:

public slots:
    /*!
     * \brief startGame Lance la fenetre de jeu et ferme le formulaire.
     */
    void startGame();
    /*!
     * \brief fourPlayerGame Affiche ou cache la possibilité d'entrer le nom
     *  des 4 joueurs au lieu de deux.
     */
    void hideShowExt();
private:
    /*!
     * \brief theGameWindow_ la fenetre de jeu.
     */
    gameWindow *theGameWindow_;
    /*!
     * \brief theGame_ le jeu lancé.
     */
    Game *theGame_;
    /*!
     * \brief superRoot_ VBox Possède tout les composant de la fenetre ainsi que le bouton.
     */
    QVBoxLayout *superRoot_;
    /*!
     * \brief root_  Possède tout les composant de la fenetre sauf le bouton de lancement.
     */
    QVBoxLayout *vbExtensionForRadio_;
    QHBoxLayout *hbLayoutNbJ_;
    QCheckBox *cbExtension_;
    QGroupBox *gbRadioExtension_;
    QLabel *lNbJ_;
    QSpinBox *sbNbJ_;
    QRadioButton *rNoExtension_;
    QRadioButton *rExtension1_;
    QRadioButton *rExtension2_;
    QPushButton *buttonStart_;

};

#endif // FORMULAIREWINDOW_H
