#include "Sommet.h"
#include "Arete.h"

Sommet::Sommet(int idSommet, std::string nom, int x, int y)//constructeur de arete
{
    m_idSommet = idSommet;
    m_nom = nom;
    m_coords.first = x;
    m_coords.second = y;
    m_nbArete = 0;
}

Sommet(const Sommet &sommetACopier)
{
    m_idSommet = sommetACopier.get_idSommet();
    m_nbArete = 0;
    m_nom = sommetACopier.get_nom();
    m_coords.first = sommetACopier.get_coordx();
    m_coords.second = sommetACopier.get_coordy();
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
