#include "Environnement.h"

Environnement::Environnement(){
    //ctor
}

Environnement::~Environnement(){
    delete m_graphe;
}

void Environnement::createGraphe(std::string nomFichier){
    m_graphe = new Graphe(nomFichier);
};

void Environnement::creationGrapheAModifer()
{
    Graphe tmp = m_graphe;
    m_grapheModifie = tmp;
}

Graphe* Environnement::get_graphe(){
    return m_graphe;
}
