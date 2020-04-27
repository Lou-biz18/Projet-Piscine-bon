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
             << m_taille<<std::endl;


}
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
