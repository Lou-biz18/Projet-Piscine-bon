#include "Arete.h"
#include "Sommet.h"

Arete::Arete(int idArete, Sommet*s1, Sommet*s2)//constructeur de arete
{
    m_idArete = idArete;
    m_sommets.first = s1;
    m_sommets.second = s2;
    m_poids = 1;
    s1->ajoutArete(this);
    s2->ajoutArete(this);
}

Arete::Arete(const Arete &areteACopier)
{
    m_idArete = areteACopier.get_idArete();
    m_poids = areteACopier.getPoids();
    m_sommets.first = areteACopier.get_s1();
    m_sommets.second = areteACopier.get_s2();
    m_sommets.first->ajoutArete(this);
    m_sommets.second->ajoutArete(this);
}

Arete::~Arete()
{
    //dtor
}

int Arete::get_idArete()const
{
    return m_idArete;
}
//chope la premiere extremit� de l'arete
int Arete::get_s1()
{
    return m_sommets.first->get_idSommet();
}

int Arete::get_s2()
{
    return m_sommets.second->get_idSommet();
}

int Arete::get_poids()
{
    return m_poids;
}

void Arete::afficher()
{
    std::cout <<"Arrete --> "<<m_idArete
              <<": "<<m_sommets.first->get_nom()
              <<"-"<<m_sommets.second->get_nom()
              <<" poids:"<<m_poids<<std::endl;
}

void Arete::set_poids(int poids)
{
    m_poids= poids;
}
