#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include "formulaireWindow.h"
/*!
 * \brief titleWindow Classe qui a pour rôle de créer et afficher d'ouverture.
 *
 */
class titleWindow : public QWidget
{

    Q_OBJECT
private:
    /*!
     * \brief root_ La fenetre regroupant tous les autre composant de la fenetre
     */
    QVBoxLayout *root_;
    /*!
     * \brief start_ Bouton chargé de lancer la fenetre de configuration du plateau     */
    QPushButton *start_;
    /*!
     * \brief img_ Image de présentation de Quoridor
     */
    QLabel *img_;
    /*!
     * \brief formW Le formulaire a remplir avec les caractéristique du plateau.
     */
    formulaireWindow *formW;
public:
    /*!
     * \brief titleWindow Le constructeur de la fenetre d'ouverture
     * \param parent
     */
    explicit titleWindow(QWidget *parent = 0);
signals:


public slots:

    /*!
     * \brief startForm Methode lançant le formulaire et fermant la fenetre courante.
     */
    void startForm();




};

#endif // TITLEWINDOW_H
