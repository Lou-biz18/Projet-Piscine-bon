#include "Graphe.h"
#include <iostream>

Graphe::Graphe()
{
    //ctor
}

Graphe::~Graphe()
{
    //dtor
}

void Graphe::afficher() const///afficher les donn�es d'un bloc pour debug
{
    std::cout<<m_ordre<<std::endl
             <<m_orientation<<std::endl
             << m_taille<<std::endl;

}
