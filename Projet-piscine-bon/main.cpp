#include <iostream>
#include "graphe.h"
#include "Sommet.h"
#include "Arete.h"

void setup(Graphe&graphe);
int main()
{
    Graphe graphe;
    setup(graphe);
    return 0;
}
void setup(Graphe&graphe)//muscle
{
    std::string monFichier="test.txt";
    graphe.chargeGraphe(monFichier);
    graphe.afficher();
    std::cout << "il y a tous les fichiers !!! Carla tu les vois ? lol" << std::endl;
}
