#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

# include <iostream>
# include "Graphe.h"

class Environnement
{
    public:
        Graphe graphe;
        void createGraphe(std::string nomFichier);
}
#endif