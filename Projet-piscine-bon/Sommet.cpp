#include "Sommet.h"
#include "Arete.h"

Sommet::Sommet(int idSommet, std::string nom, int x, int y)//constructeur de arete
{
    m_idSommet = idSommet;
    m_nom = nom;
    m_coords.first = x;
    m_coords.second = y;
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
