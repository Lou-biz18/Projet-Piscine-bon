#include "Fichier_h.h"

Sommet::Sommet()
{
    //ctor
}

Sommet::~Sommet()
{
    //dtor
}

int Sommet::get_idSommet()
{
    return m_idSommet;
}

std::string Sommet::get_nom()
{
    return m_nom;
}

void Sommet::afficher() const///afficher les données d'un bloc pour debug
{
    std::cout<<m_idSommet<<std::endl
             <<m_nom<<std::endl
             << m_coords.first << ", " << m_coords.second<<std::endl;

}
