#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <iostream>
#include "Graphe.h"

class Environnement
{
    private:
        Graphe* m_graphe;
        Graphe* m_grapheModifie;
    public:
        Environnement();
        ~Environnement();
        void createGraphe(std::string nomFichier);
        void creationGrapheAModifer();
        Graphe* get_graphe();
};
#endif