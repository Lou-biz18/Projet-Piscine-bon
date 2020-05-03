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



void Environnement::comparaisonIndiceSommet ()
{
    std::vector<Sommet*> tabSommetModifie = m_grapheModifie->get_tabSommet();
    std::vector<Sommet*> tabSommet = m_graphe->get_tabSommet();
    std::cout<<"test"<<std::endl;
    for ( int i= 0; i < m_graphe->get_ordre(); i++ )
    {
        std::cout<<tabSommet[i]->get_sommeIVPVoisins() - tabSommetModifie[i]->get_sommeIVPVoisins()<<std::endl;
        std::cout<<tabSommet[i]->get_indiceVecteurPropre() - tabSommetModifie[i]->get_indiceVecteurPropre()<<std::endl;
        std::cout<<tabSommet[i]->get_indiceProximite() - tabSommetModifie[i]->get_indiceProximite()<<std::endl;
        std::cout<<tabSommet[i]->get_indiceProximiteNorm() - tabSommetModifie[i]->get_indiceProximiteNorm()<<std::endl;
        std::cout<<tabSommet[i]->get_indiceDegre() - tabSommetModifie[i]->get_indiceDegre()<<std::endl;
        std::cout<<tabSommet[i]->get_indiceDegreNorm() - tabSommetModifie[i]->get_indiceDegreNorm()<<std::endl;
    }


}
