#include "Arete.h"
#include "Sommet.h"

Arete::Arete(int idArete, Sommet*s1, Sommet*s2)//constructeur de arete
{
    m_idArete = idArete;
    m_arete.first = s1;
    m_arete.second = s2;
}

Arete::~Arete()
{
    //dtor
}

int Arete::get_idArete()const
{
    return m_idArete;
}
//chope la premiere extremité de l'arete
int Arete::get_s1()
{
    return m_arete.first->get_idSommet();
}
int Arete::get_s2()
{
    return m_arete.second->get_idSommet();
}
