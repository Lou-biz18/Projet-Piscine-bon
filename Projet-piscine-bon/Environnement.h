#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <iostream>
#include "Graphe.h"

class Environnement
{
    private:
        Graphe* m_graphe;
    public:
        Environnement();
        ~Environnement();
        void createGraphe(std::string nomFichier);
        Graphe* get_graphe();

};
#endif
