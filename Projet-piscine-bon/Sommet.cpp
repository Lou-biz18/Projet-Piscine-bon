#include "Sommet.h"
#include "Arete.h"

Sommet::Sommet(int idSommet, std::string nom, double x, double y)//constructeur de arete
{
    m_idSommet = idSommet;
    m_nom = nom;
    m_coords.first = x;
    m_coords.second = y;
    m_nbArete = 0;
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
double Sommet::get_coordx()
{
    return m_coords.first;
}
double Sommet::get_coordy()
{
    return m_coords.second;
}

void Sommet::afficher() const///afficher les donn�es d'un bloc pour debug
{
    std::cout <<"Sommet --> "<<m_idSommet
              <<":x= "<<m_coords.first
              <<";y= "<<m_coords.second<<std::endl;

}

void Sommet::ajoutArete(Arete* newArete)
{
    m_tabAreteSo.push_back(newArete);
    m_nbArete++;
}
