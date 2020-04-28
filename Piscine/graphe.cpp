#include "Graphe.h"
#include <iostream>

Graphe::Graphe()
{
    //ctor
}

Graphe::~Graphe()
{
    //dtor
}

void Graphe::afficher() const///afficher les données d'un bloc pour debug
{
    std::cout<<std::endl<<"graphe ";
            if(m_orientation) std::cout<<"oriente"<<std::endl<<"  ";
            else std::cout<<"non oriente"<<std::endl<<"  ";
    std::cout<<m_orientation<<std::endl
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
void Graphe::chargeGraphe(std::string&f)
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
            {
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
//0 non orienté
//1 orienté

/*
Graphe::Graphe(std::istringstream iss)//recup des données du flux
{
    iss >>m_ordre
        >>m_orientation
        >>m_taille
}*/

/// Surcharge de l'opérateur d'insertion vers un flot de sortie
/// c'est la "méthode d'affichage" des objets de type Station
/*friend std::ostream& Graphe:: operator<<(std::ostream& out, const   Graphe& g)
{
    out << "id=" << std::setw(2) << g.m_ordre << " orientation=" << g.orientation << "  taille=" << g.m_taille;
    out << std::endl;
    return out;
}*/
/*Graphe(std::string nomFichier)
        {
            std::ifstream ifs{nomFichier};
            if (!ifs)
                throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
            ifs >> m_orientation;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture orientation du graphe");
            int ordre;
            ifs >> ordre;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture ordre du graphe");
            int taille;
            ifs >> taille;
            if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture taille du graphe");
            for (int i=0; i<ordre; ++i)
                m_sommets.push_back( new Sommet{i} );
            int num1,num2;
            for (int i=0;i<taille;++i){
                ifs>>num1>>num2;
                if ( ifs.fail() )
                throw std::runtime_error("Probleme lecture arc");
                m_sommets[num1]->ajouterSucc(m_sommets[num2]);
                ///si le graphe n'est pas orienté
                ///si num2 est successeur de num1, num1 est successeur de num2
                if(!m_orientation) m_sommets[num2]->ajouterSucc(m_sommets[num1]);
            }
        }*/
/*Bloc::Bloc(std::istringstream& iss, Bloc*parent) ///constructeur avec flux
{
    double x=0.0,y=0.0;

    iss>>m_id
       >>m_idparent
       >>m_couleur
       >>x
       >>y
       >>m_width
       >>m_height;
    m_parent=parent;
    m_position= {x,y};

}*/
//Graphe(int ordre, bool orientation, int taille);
/*
Graphe::Graphe(std::istringstream iss)
{
    iss >>m_ordre
        >>m_orientation
        >>m_taille
}*/
