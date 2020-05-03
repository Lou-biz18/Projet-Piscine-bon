#include "Environnement.h"
#include "Sommet.h"

///CONSTRUCTEUR
Environnement::Environnement(){
    //ctor
}
///DESTRUCTEUR
Environnement::~Environnement(){
    delete m_graphe;
}
///CREATION DUN GRAPHE
void Environnement::createGraphe(std::string nomFichier){
    m_graphe = new Graphe(nomFichier);
};

void Environnement::creationGrapheAModifer()
{
    Graphe* tmp = new Graphe(*(m_graphe));
    m_grapheModifie = tmp;
}

Graphe* Environnement::get_graphe(){
    return m_graphe;
}
Graphe* Environnement::get_grapheModif(){
    return m_grapheModifie;
}
