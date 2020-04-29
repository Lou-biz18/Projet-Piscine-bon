#include "Arete.h"
#include "Sommet.h"

Arete::Arete()
{
    //ctor
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
int Arete::get_ex1()
{
    return m_arete.first->get_idSommet();
}
int Arete::get_ex2()
{
    return m_arete.second->get_idSommet();
}
