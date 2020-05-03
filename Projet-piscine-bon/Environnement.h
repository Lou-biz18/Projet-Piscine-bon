#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <iostream>
#include "Graphe.h"

// Classe nous permettant de stocker nos graphes et de faire des appels de fonctions dans le main (on pensait qu'il serait plus rempli au depart)
class Environnement
{
    private:
        Graphe* m_graphe;
        Graphe* m_grapheModifie;
    public:
        Environnement(); // cr�ateur
        ~Environnement(); //destructeur
        void createGraphe(std::string nomFichier);
        void creationGrapheAModifer();
        Graphe* get_graphe();
        Graphe* get_grapheModif();

        void comparaisonIndiceSommet(); // methode de l'analyse de la vulnérabilité

};
#endif
