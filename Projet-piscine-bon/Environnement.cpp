#include "Environnement.h"
#include "Sommet.h"


Environnement::Environnement(){
    //ctor
}

Environnement::~Environnement(){
    delete m_graphe;
}

void Environnement::createGraphe(std::string nomFichier){
    m_graphe = new Graphe(nomFichier);
};

Graphe* Environnement::get_graphe(){
    return m_graphe;
}
