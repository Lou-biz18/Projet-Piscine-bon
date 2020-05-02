#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>//pour to_string

#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
#include "utile.h"

///CONSTRUCTEUR
Graphe::Graphe(std::string nomFichier)
{
    chargeGraphe(nomFichier);
}

Graphe::Graphe(const Graphe &grapheACopier)
{
    m_ordre = grapheACopier.get_ordre();
    m_orient = grapheACopier.get_orient();
    m_taille = grapheACopier.get_taille();

    std::vector<Sommet*> tmpS(m_ordre);// taille m_ordre pour tabSommet
    m_tabSommet = tmpS;
    std::vector<Sommet*> tabSomACopier = grapheACopier.get_tabSommet();
    for(int i = 0; i <= m_ordre; i++)
    {
        Sommet newSommet = *(tabSomACopier[i]); // Sommet newSomme = *monSommet
        m_tabSommet[i] = &newSommet;
    }
    std::vector<Arete*> tmpA(m_taille);// taille m_ordre pour tabSommet
    m_tabArete = tmpA;
    std::vector<Arete*> tabAreteACopier = grapheACopier.get_tabArete();
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
///GET
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

///PARSING
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
///AJOUT D'OBJETS
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

///DESSIN
void Graphe::dessiner(Svgfile&svgout)
{
    for(int i=0;i<m_taille;i++)
    {
        Arete* a = m_tabArete[i];
        double x1 = a->get_s1()->get_coordx();
        double x2 = a->get_s2()->get_coordx();
        double y1 = a->get_s1()->get_coordy();
        double y2 = a->get_s2()->get_coordy();

        svgout.addLine(x1 *100, y1 *100,x2 *100, y2*100, "rgb(255,200,200)"/*a->get_color()*/);
        svgout.addId(((x1 + x2 )/2)*100, ((y1 + y2 )/2) *100,std::to_string(a->get_idArete()),a->get_couleurA());//attention int converti en string par to_string
        // on ecrit l'idArete au milieu de l'arete
    }
    for(int i=0;i<m_ordre;i++)
    {
        Sommet* s = m_tabSommet[i];
        svgout.addDisk(s->get_coordx() * 100,s->get_coordy() *100, 30, s->get_couleurS());
        svgout.addId(s->get_coordx() *100, s->get_coordy() *100,s->get_nom(),"pink");
        std::cout<<"on arrive jusquici"<<std::endl;
    }
    svgout.addDisk(1000,800,20,"blue");
}

void Graphe::commencerIndiceDeCentralite()
{
    for (auto s : m_tabSommet)
    {
        s->calculeIndiceCentraliteDegres(m_ordre);
    }
}

void Graphe::commencerIndiceDeProximite()
{
    
}

bool Graphe::supprimerArete(int areteChoisie)
{
    Arete* arete;//besoin d'un d'un pointeur/ d'une addresse sur arrete pour le supp
    for(int i=0; i<m_taille;i++)// ! mettre des i
    {
        if(m_tabArete[i]->get_idArete()==areteChoisie)
        {
            arete = m_tabArete[i];//on attribue à arete cette refereence i precise
            std::cout <<"l'arete ";
            m_tabArete[i]->afficher();
            std::cout<<"existe"<<std::endl;

            m_tabArete.erase(m_tabArete.begin()+i);//efface les ref de arete car tableau d'adresse d'aretes

            m_taille = m_taille - 1 ;//mise a jour de la taille du tableau

            //m_tabArete[i]->get_s1();
            Sommet* s1 = m_tabArete[i]->get_s1();
            Sommet* s2 = m_tabArete[i]->get_s2();
            s1->enleveA(m_tabArete[i]);//on efface les ref de Arete dans sommet
            s2->enleveA(m_tabArete[i]);//car tabAreteSo dans Sommet

            delete(arete);// destruction finale de l'objet arete i
            std::cout<<"l'arete";
            m_tabArete[i]->afficher();
            std::cout<<" a bien été suprimée"<<std::endl;
            return true;
       }
       else
        return false;
    }
}
/* bool Graphe::supprimerArrete(int arretechoisie) {
    chercher dans tabArrete si elle existe
    si l'arrete existe
       1: supprimer arrete de m_tabArete => => supprimer element d'un vector
        Sommet* s1 = arete.get_s1();
        Sommet* s2 = arete.get_s2();
       2: s1->enleveArete(arete);
       3: s2->enleveArete(arete);
       4: delete arete;
}
*/





/*
void Graphe::calcCouleurG()
{
    for(int i=0;i<nb_arete;i++)
    {
       // nb_arete[i].m_couleur = set_couleurA(couleurCac);//grosse merde
       //pour chaque sommet de degre diff, on set la couelur calculée
    }
}
*/
