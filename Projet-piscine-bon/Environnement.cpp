#include "Environnement.h"

Environnement::Environnement(){
    //ctor
}

Environnement::~Environnement(){
    //dtor
}

void Environnement::createGraphe(std::string nomFichier){
    m_graphe = new Graphe(nomFichier);
};

Graphe* Environnement::get_graphe(){
    return m_graphe;
}