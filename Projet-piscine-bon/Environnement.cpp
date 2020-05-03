#include "Environnement.h"
#include "Sommet.h"
#include <windows.h>

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
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<Sommet*> tabSommetModifie = m_grapheModifie->get_tabSommet();
    std::vector<Sommet*> tabSommet = m_graphe->get_tabSommet();
    std::cout<<" difference des indices "<<std::endl;

    for ( int i= 0; i < m_graphe->get_ordre(); i++ )
    {

// on calcule la difference entre le premiere indice et le nouveau modifié, puis on calcule le pourcentage de variation en l'affichant dans la conso

        SetConsoleTextAttribute(console, 15);
        std::cout<<"    Sommet : "<< tabSommet[i]->get_nom()<<std::endl;
        std::cout<<" "<<std::endl;
        SetConsoleTextAttribute(console, 13);
        std::cout<<"La difference des vecteurs propres non normalise est: "    <<tabSommet[i]->get_sommeIVPVoisins() - tabSommetModifie[i]->get_sommeIVPVoisins()         <<" soit: " <<((tabSommetModifie[i]->get_sommeIVPVoisins() - tabSommet[i]->get_sommeIVPVoisins())/ tabSommet[i]->get_sommeIVPVoisins())*100              <<"%"<<std::endl;
        SetConsoleTextAttribute(console, 10);
        std::cout<<"La difference des vecteurs propre normalise est :"         <<tabSommet[i]->get_indiceVecteurPropre() - tabSommetModifie[i]->get_indiceVecteurPropre() <<" soit: " <<((tabSommetModifie[i]->get_indiceVecteurPropre() - tabSommet[i]->get_indiceVecteurPropre())/tabSommet[i]->get_indiceVecteurPropre()) * 100 <<"%"<<std::endl;
        SetConsoleTextAttribute(console, 11);
        std::cout<<"La difference des indices de proximite non normalise est: "<<tabSommet[i]->get_indiceProximite() - tabSommetModifie[i]->get_indiceProximite()         <<" soit: " <<((tabSommetModifie[i]->get_indiceProximite() - tabSommet[i]->get_indiceProximite())/tabSommet[i]->get_indiceProximite()) * 100             <<"%"<<std::endl;
        SetConsoleTextAttribute(console, 1);
        std::cout<<"La difference des indices de proximite normalise est: "    <<tabSommet[i]->get_indiceProximiteNorm() - tabSommetModifie[i]->get_indiceProximiteNorm() <<" soit: " <<((tabSommetModifie[i]->get_indiceProximiteNorm()- tabSommet[i]->get_indiceProximiteNorm())/tabSommet[i]->get_indiceProximiteNorm()) * 100  <<"%"<<std::endl;
        SetConsoleTextAttribute(console, 14);
        std::cout<<"La difference des indices de degre non normalise est: "    <<tabSommet[i]->get_indiceDegre()-tabSommetModifie[i]->get_indiceDegre()                   <<" soit: " <<((tabSommetModifie[i]->get_indiceDegre()- tabSommet[i]->get_indiceDegre())/ tabSommet[i]->get_indiceDegre()) * 100                         <<"%"<<std::endl;
        SetConsoleTextAttribute(console, 12);
        std::cout<<"La difference des indices de degre normalise est: "        <<tabSommet[i]->get_indiceDegreNorm()-tabSommetModifie[i]->get_indiceDegreNorm()           <<" soit: " <<((tabSommetModifie[i]->get_indiceDegreNorm() -  tabSommet[i]->get_indiceDegreNorm()) / tabSommet[i]->get_indiceDegreNorm()) *100           <<"%"<<std::endl;
        SetConsoleTextAttribute(console, 15);
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;

    }


}
