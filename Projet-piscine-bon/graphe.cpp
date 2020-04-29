#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
#include "utile.h"

///TJ dans constructeur
Graphe::Graphe(std::string nomFichier)
{
    //chargeGraphe(nomFichier);^!
}

Graphe::~Graphe()
{
    //dtor
}

bool Graphe::get_orient()const
{
    return m_orient;
}

void Graphe::set_orient(bool  m_orient)
{
    m_orient= orient;
}

int Graphe::get_ordre()const
{
    return m_ordre;
}

void Graphe::set_ordre (int m_ordre)
{
   m_ordre= ordre;
}

int Graphe::get_taille()const
{
    return m_taille;
}
void Graphe::set_taille(int m_taille)
{
    m_taille=taille;
}

void Graphe::afficher() const///afficher les donn�es d'un bloc pour debug
{
    std::cout<<std::endl<<"graphe ";
            if(m_orient) std::cout<<"oriente"<<std::endl<<"  ";
            else std::cout<<"non oriente"<<std::endl<<"  ";
    std::cout<<m_orient<<std::endl
             << m_ordre<<std::endl;// nb sommets

}

std::string recupFichier (std::istringstream& iss)///ssprgm de tri du flux re�u en param�tre
{

    std::string orient, ordre;

    ///on r�cup�re les variables
    iss>>orient;
    iss>>ordre;

    return orient+" "+ordre;

}
///M�thode de parsing de type Graphe
/*void Graphe::chargeGraphe(std::string nomFichier)
{
    try
    {
        std::vector<std::string> tabLigne;//tab dynamique constitu� des lignes de donn�es du le fichier
        std::ifstream fichier(nomFichier);//ouverture du fichier

        if(!fichier)//TEST ouverture de fichier
        {
            std::cout<<"Erreur ouverture du fichier"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else//le fichier s'est bien charg� et peut etre lu
        {
            std::cout<<"Chargement fichier: OK"<<std::endl;
            while(std::getline(fichier, tabLigne))
            {
                get_orient(tabLigne[0]);
                get_ordre(tabLigne[1]);
                for(int i=2;i<1+m_ordre;i++)
                {
                    ajoutArete(tabLigne[i]);//cr�er le nombre d'arete (n-1)

                }
                get_taille(tabLigne[2+m_ordre])
                for(int i=2+m_ordre;i<)
                {

                }


            }
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }

}*/
/*
Graphe::chargeGraphe(std::string fileName){
    getOriented(ligne 0) // une methode de graph
    getOrder(ligne 1),   // pareil
    Pour chaque ligne de sommet (ligne n = 2 � 1 + graph.m_order):
      addArrete(ligne n) // methode de graph qui cree une arrete en appelant son constructeur et la met dans le tableau d'arrete
    graph.getTaille(line 2 + graph.m_order) // bon c'est parlant
    Pour chaque ligne de arete (ligne n = 3 � 2 + graph.m_taille):
      addSommet(ligne n) // pareil que pour Sommet
}

Graphe::addArrete(std::string){
    on coupe la ligne en 3 variables, index, indexSommet1 et indexSommet2
    Arrete newArrete(index, m_tabArrete[indexSommet1], m_tabArrete[indexSommet2]);
    m_tabArette = m_tabArette + newArrete; //si la syntaxe est pas bonne c'est normal XD c'est un peu du pseudocode
}*/

/*
DataField::constructGraph(fileName){
    Graphe m_graph(fileName);
}
// et vu que:
Graphe::graphe(std::string fileName){
    chargeGraphe(fileName)
}
// et ensuite dans chargeGraphe si tu fais ma technique de parsing:
Graphe::chargeGraphe(std::string fileName){
    getOriented(ligne 0) // une methode de graph
    getOrder(ligne 1),   // pareil
    Pour chaque ligne d'arrete (ligne n = 2 � 1 + graph.m_order):
      addArrete(ligne n) // methode de graph qui cree une arrete en appelant son constructeur et la met dans le tableau d'arrete
    graph.getTaille(line 2 + graph.m_order) // bon c'est parlant
    Pour chaque ligne de sommet (ligne n = 3 � 2 + graph.m_taille):
      addSommet(ligne n) // pareil que pour Sommet
}

Graphe::addArrete(std::string){
    on coupe la ligne en 3 variables, index, indexSommet1 et indexSommet2
    Arrete newArrete(index, m_tabArrete[indexSommet1], m_tabArrete[indexSommet2]);
    m_tabArette = m_tabArette + newArrete; //si la syntaxe est pas bonne c'est normal XD c'est un peu du pseudocode
}
*/
void Graphe::ajoutArete(std::string ligne)
{
    //split
    std::vector<std::string> recupLigneSplit=split(ligne, ' ');

    Arete newArete(recupLigneSplit[0], m_tabArete[recupLigneSplit[1]],m_tabArete[recupLigneSplit[2]]);
    //pour etre propre -> 3 variables pour recup bien les données ( lindex bien etc)
}

void Graphe::ajoutSommet(std::string ligne)
{
    //split
    std::vector<std::string> recupLigneSplit=split(ligne, ' ');

    Sommet newSommet(recupLigneSplit[0], m_tabSommet[recupLigneSplit[1]],m_tabSommet[recupLigneSplit[2]]);
    //pour etre propre -> 3 variables pour recup bien les données ( lindex bien etc)
}

