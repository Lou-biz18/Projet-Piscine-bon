#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
#include "utile.h"

///TJ dans constructeur
Graphe::Graphe(std::string nomFichier)
{
    chargeGraphe(nomFichier);
}

Graphe::~Graphe()
{
    //dtor
}

bool Graphe::get_orient()const
{
    return m_orient;
}

int Graphe::get_ordre()const
{
    return m_ordre;
}

int Graphe::get_taille()const
{
    return m_taille;
}

void Graphe::afficher() const///afficher les donn�es d'un bloc pour debug
{
    std::cout<<std::endl<<"graphe ";
    if(m_orient)
        std::cout<<"oriente"<<std::endl<<"  ";
    else
        std::cout<<"non oriente"<<std::endl<<"  ";
    std::cout<<m_orient<<std::endl
             << m_ordre<<std::endl;// nb sommets
    for(int i=0;i<m_tabSommet.size();i++)
    {
        std::cout<< m_tabSommet[i] << " ";
    }
    std::cout<<m_taille<<std::endl;
    for(int i=0;i<m_tabArete.size();i++)
    {
        std::cout<< m_tabArete[i] << " "<<std::endl;
    }

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
void Graphe::chargeGraphe(std::string nomFichier)
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
            std::string tmpStr;
            while(std::getline(fichier, tmpStr))//recup info du fichier ligne par ligne
            {
                tabLigne.push_back(tmpStr);//recup infos dans tabline
            }
            m_orient = std::stoi(tabLigne[0]);// stoi pour transformer le string to int
            m_ordre = std::stoi(tabLigne[1]);
            // m_tabArette = new vector(m_ordre);
            std::vector<Sommet*> tmp(m_ordre);// taille m_ordre pour tabSommet
            m_tabSommet = tmp;
            for(int i=2;i<1+m_ordre;i++)//ajoute les sommets dans tabSommet
            {
                ajoutSommet(tabLigne[i]);//cr�er le nombre d'arete (n-1)
            }
            m_taille = std::stoi(tabLigne[2+m_ordre]);// recup taille pour tabArete
            std::vector<Arete*> temp(m_taille);
            m_tabArete = temp;
            for(int i=3+m_ordre;i<3+m_ordre+m_taille;i++)//ajoute les arretes dans tabArete
            {
                ajoutArete(tabLigne[i]);
            }
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }

}
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
}
*/
void Graphe::ajoutArete(std::string ligne)
{
    //split
    std::vector<std::string> recupLigneSplit=split(ligne, ' ');
    int index = std::stoi(recupLigneSplit[0]);//on transforme une string en int grace a stoi (string to int)
    int indexSom1 = std::stoi(recupLigneSplit[1]);
    int indexSom2 = std::stoi(recupLigneSplit[2]);


    Arete newArete(index, m_tabSommet[indexSom1],m_tabSommet[indexSom2]);
    //pour etre propre -> 3 variables pour recup bien les données ( lindex bien etc)
    //m_tabArete[index] = newArete;
    m_tabArete[index] = &newArete;//tableau de Arete* (pointeur sur aretes)
}

void Graphe::ajoutSommet(std::string ligne)
{
    //split
    std::vector<std::string> recupLigneSplit=split(ligne, ' ');
    //4 var pour les 4 attributs du constructeurs
    int index = std::stoi(recupLigneSplit[0]);
    std::string indexNom = recupLigneSplit[1];
    int coord_x = std::stoi(recupLigneSplit[2]);
    int coord_y = std::stoi(recupLigneSplit[3]);

    Sommet newSommet(index, indexNom ,coord_x,coord_y);
    m_tabSommet[index] = &newSommet;//car tab de som *

}

