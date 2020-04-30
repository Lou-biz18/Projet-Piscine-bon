#include "Arete.h"
#include "Sommet.h"

Arete::Arete(int idArete, Sommet*s1, Sommet*s2)//constructeur de arete
{
    m_idArete = idArete;
    m_sommets.first = s1;
    m_sommets.second = s2;
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
    return m_sommets.first->get_idSommet();
}
int Arete::get_s2()
{
    return m_sommets.second->get_idSommet();
}
void Arete::afficher()
{ //"Arrete 5: A-B"
    std::cout <<"Arrete --> "<<m_idArete
              <<": "<<m_sommets.first->get_nom()
              <<"-"<<m_sommets.second->get_nom()<<std::endl;
}

void Arete::set_poids(int poids)
{
    m_poids= poids;
}
