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

Graphe(const Graphe &grapheACopier)
{
    m_ordre = grapheACopier.get_ordre();
    m_orient = grapheACopier.get_orient();
    m_taille = grapheACopier.get_taille();

    std::vector<Sommet*> tmpS(m_ordre);// taille m_ordre pour tabSommet
    m_tabSommet = tmpS;
    std::vector<Sommet*> tabSomACopier = graheACopier.get_tabSommet() // A CODER getTabSommet
    for(int i = 0; i <= m_ordre; i++)
    {
        Sommet newSommet = *(tabSomACopier[i]); // Sommet newSomme = *monSommet
        m_tabSommet[i] = &newSommet;
    }
    std::vector<Arete*> tmpA(m_taille);// taille m_ordre pour tabSommet
    m_tabArete = tmpA;
    std::vector<Arete*> tabAreteACopier = graheACopier.get_tabArete() // A CODER getTabArete
    for(int i = 0; i <= m_ordre; i++)
    {
        Arete newArete = *(tabAreteACopier[i]);
        m_tabArete[i] = &newArete;
    }
}

Graphe::~Graphe()
{
    for (auto a : m_tabArete)
        delete a;
    for (auto s : m_tabSommet)
        delete s;
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

std::vector<Arete*> Graphe::get_tabArete()const
{
    return m_tabArete;
}

std::vector<Sommet*> Graphe::get_tabSommet()const
{
    return m_tabSommet;
}

void Graphe::afficherTabS()
{
    for(auto elem: m_tabSommet){
        elem->afficher();
    }
}
void Graphe::afficherTabA()
{
    for(auto elem: m_tabArete){
        elem->afficher();
    }
}

void Graphe::afficher()///afficher les donn�es d'un bloc pour debug
{
    std::cout<<std::endl<<"Graphe ";
    if(m_orient)
        std::cout<<"oriente"<<std::endl;
    else
        std::cout<< "non oriente"<<std::endl;
    std::cout<< "ordre = " <<m_ordre<<std::endl;// nb sommets
    afficherTabS();
    std::cout<< "taille =" <<m_taille<<std::endl;
    afficherTabA();

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
            std::vector<Sommet*> tmp(m_ordre);// taille m_ordre pour tabSommet
            m_tabSommet = tmp;
            for(int i = 2; i <= 1 + m_ordre; i++)//ajoute les sommets dans tabSommet
            {
                ajoutSommet(tabLigne[i]);//cr�er le nombre d'arete (n-1)
            }
            m_taille = std::stoi(tabLigne[2+m_ordre]);// recup taille pour tabArete
            std::vector<Arete*> temp(m_taille);
            m_tabArete = temp;
            for(int i=3+m_ordre;i<=2+m_ordre+m_taille;i++)//ajoute les arretes dans tabArete
            {
                std::cout<<"line = "<< tabLigne[i] <<std::endl;
                std::cout << std::stoi(split(tabLigne[i], ' ')[1]) << std::endl;
                ajoutArete(tabLigne[i]);
            }
            std::cout<< "Graphe terminé"<< std::endl;
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }

}
void Graphe::chargePonderation(std::string fichierPonderation)
{
    try
    {
        std::vector<std::string> tabLigne;//tab dynamique constitu� des lignes de donn�es du le fichier
        std::ifstream fichier(fichierPonderation);//ouverture du fichier
        int taille;

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
            taille = std::stoi(tabLigne[0]);// recup taille pour tabArete
            if(taille!=m_taille)
            {
                 std::cout<<"PB : tailles differentes"<<std::endl;
                 return;
            }
            for(int i=1;i<=m_taille;i++)//ajoute les arretes dans tabArete
            {
                ajouterPonderation(tabLigne[i]);
            }
            std::cout<< "Ponderation terminee"<< std::endl;
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }
}

void Graphe::ajoutArete(std::string ligne)
{
    //split
    std::vector<std::string> recupLigneSplit=split(ligne, ' ');
    int index = std::stoi(recupLigneSplit[0]);//on transforme une string en int grace a stoi (string to int)
    int indexSom1 = std::stoi(recupLigneSplit[1]);
    int indexSom2 = std::stoi(recupLigneSplit[2]);

    std::cout << index << " "<< indexSom1<< " "<< indexSom2 << " "<<std::endl;
    m_tabSommet[indexSom1]->afficher();
    m_tabSommet[indexSom2]->afficher();
    Arete* newArete = new Arete(index, m_tabSommet[indexSom1],m_tabSommet[indexSom2]);
    //pour etre propre -> 3 variables pour recup bien les données ( lindex bien etc)
    //m_tabArete[index] = newArete;

    m_tabArete[index] = newArete;//tableau de Arete* (pointeur sur aretes)
}

void Graphe::ajoutSommet(std::string ligne)
{
    std::vector<std::string> recupLigneSplit = split(ligne, ' ');
    //4 var pour les 4 attributs du constructeurs
    int index = std::stoi(recupLigneSplit[0]);
    std::string nom = recupLigneSplit[1];
    int coord_x = std::stoi(recupLigneSplit[2]);
    int coord_y = std::stoi(recupLigneSplit[3]);

    Sommet* newSommet = new Sommet(index, nom ,coord_x,coord_y);
    m_tabSommet[index] = newSommet;//car tab de som
}
void Graphe::ajouterPonderation(std::string lignePond)
{
    std::vector<std::string> recupLigneSplit=split(lignePond, ' ');
    int index = std::stoi(recupLigneSplit[0]);
    int poids = std::stoi(recupLigneSplit[1]);

    m_tabArete[index]->set_poids(poids);
}
