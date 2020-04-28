#include "Fichier_h.h"

Sommet::Sommet()
{
    //ctor
}

Sommet::~Sommet()
{
    //dtor
}
void Sommet::afficher() const///afficher les données d'un bloc pour debug
{
    std::cout<<m_idSommet<<std::endl
             <<m_nom<<std::endl
             << m_coords.first << ", " << m_coords.second<<std::endl;

}
