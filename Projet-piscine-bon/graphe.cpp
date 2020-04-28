#include "Graphe.h"
#include <iostream>
#include <vector>
/*
Graphe::Graphe()
{
    //ctor
}*/

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

void Graphe::afficher() const///afficher les données d'un bloc pour debug
{
    std::cout<<std::endl<<"graphe ";
            if(m_orient) std::cout<<"oriente"<<std::endl<<"  ";
            else std::cout<<"non oriente"<<std::endl<<"  ";
    std::cout<<m_orient<<std::endl
             << m_ordre<<std::endl;// nb sommets

}

std::string recupFichier (std::istringstream& iss)///ssprgm de tri du flux reçu en paramètre
{

    std::string orient, ordre;

    ///on récupère les variables
    iss>>orient;
    iss>>ordre;

    return orient+" "+ordre;

}
///TJ dans constructeur
Graphe::graphe(std::string nomFichier)
{
    chargeGraphe(nomFichier)
}
///Méthode de parsing de type Graphe
void Graphe::chargeGraphe(std::string nomFichier)
{
    try
    {
        std::vector<std::string> tabLigne;//tab dynamique constitué des lignes de données du le fichier
        std::ifstream fichier{nomFichier};//ouverture du fichier

        if(!fichier)//TEST ouverture de fichier
        {
            std::cout<<"Erreur ouverture du fichier"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else//le fichier s'est bien chargé et peut etre lu
        {
            std::cout<<"Chargement fichier: OK"<<std::endl;
            while(std::getline(fichier, tabLigne))
            {
                get_orient(tabLigne[0]);
                get_ordre(tabLigne[1]);
                /*for(int i=2;i<1+m_ordre;i++)
                {
                    ajoutArete(tabLigne[i]);//créer le nombre d'arete (n-1)

                }
                get_taille(tabLigne[2+m_ordre])
                for(int i=2+m_ordre;i<)
                {

                }
                */

            }
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }

}/*
Graphe::chargeGraphe(std::string fileName){
    getOriented(ligne 0) // une methode de graph
    getOrder(ligne 1),   // pareil
    Pour chaque ligne de sommet (ligne n = 2 à 1 + graph.m_order):
      addArrete(ligne n) // methode de graph qui cree une arrete en appelant son constructeur et la met dans le tableau d'arrete
    graph.getTaille(line 2 + graph.m_order) // bon c'est parlant
    Pour chaque ligne de arete (ligne n = 3 à 2 + graph.m_taille):
      addSommet(ligne n) // pareil que pour Sommet
}

Graphe::addArrete(std::string){
    on coupe la ligne en 3 variables, index, indexSommet1 et indexSommet2
    Arrete newArrete(index, m_tabArrete[indexSommet1], m_tabArrete[indexSommet2]);
    m_tabArette = m_tabArette + newArrete; //si la syntaxe est pas bonne c'est normal XD c'est un peu du pseudocode
}*/
/*void Graphe::chargeGraphe(std::string&f)//parsing lou testsx
{
    std::string monFichier=f;
    try
    {
        std::string ligne;//chaque ligne lue
        std::ifstream fichier{monFichier};//ouverture du fichier

        if(!fichier)//si le fichier a un problème
        {
            std::cout<<"Erreur ouverture du fichier"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            std::cout<<"Chargement fichier: OK"<<std::endl;
            while(std::getline(fichier, ligne))//tant qu'il y a une ligne à lire dans le fichier
            {//tester sur quelle ligne je suis
                std::istringstream iss(ligne);//on crée flux avec toutes les données lues sur une ligne du fichier par ligne
                std::istringstream tempo(recupFichier(iss));//autre flux créé avec string des données triées par fonction triFichier

            }
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }

}
*/

//0 non orienté
//1 orienté

/*
Graphe::Graphe(std::istringstream iss)//recup des données du flux
{
    iss >>m_ordre
        >>m_orientation
        >>m_taille
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
    Pour chaque ligne d'arrete (ligne n = 2 à 1 + graph.m_order):
      addArrete(ligne n) // methode de graph qui cree une arrete en appelant son constructeur et la met dans le tableau d'arrete
    graph.getTaille(line 2 + graph.m_order) // bon c'est parlant
    Pour chaque ligne de sommet (ligne n = 3 à 2 + graph.m_taille):
      addSommet(ligne n) // pareil que pour Sommet
}

Graphe::addArrete(std::string){
    on coupe la ligne en 3 variables, index, indexSommet1 et indexSommet2
    Arrete newArrete(index, m_tabArrete[indexSommet1], m_tabArrete[indexSommet2]);
    m_tabArette = m_tabArette + newArrete; //si la syntaxe est pas bonne c'est normal XD c'est un peu du pseudocode
}
*/
