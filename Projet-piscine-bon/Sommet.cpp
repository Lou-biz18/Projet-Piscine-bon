#include "Sommet.h"
#include "Arete.h"

Sommet::Sommet(int idSommet, std::string nom, double x, double y)//constructeur de arete
{
    m_idSommet = idSommet;
    m_nom = nom;
    m_coords.first = x;
    m_coords.second = y;
    m_nbArete = 0;
    m_couleurS = "black";//couleur par default
}

Sommet(const Sommet &sommetACopier)
{
    m_idSommet = sommetACopier.get_idSommet();
    m_nbArete = 0;
    m_nom = sommetACopier.get_nom();
    m_coords.first = sommetACopier.get_coordx();
    m_coords.second = sommetACopier.get_coordy();
}

Sommet::~Sommet()
{
    //dtor
}

int Sommet::get_idSommet()
{
    return m_idSommet;
}
std::string Sommet::get_nom()
{
    return m_nom;
}
double Sommet::get_coordx()
{
    return m_coords.first;
}
double Sommet::get_coordy()
{
    return m_coords.second;
}
std::string Sommet::get_couleurS()
{
    return m_couleurS;
}

 float  Sommet::get_indiceDegre()
 {
     return m_indiceDegre;
 }

float Sommet::get_indiceDegreNorm()
{
    return m_indiceDegreNorm;
}

void Sommet::afficher() const///afficher les donn�es d'un bloc pour debug
{
    std::cout <<"Sommet --> "<<m_idSommet
              <<":x= "<<m_coords.first
              <<";y= "<<m_coords.second<<std::endl;

}

void Sommet::ajoutArete(Arete* newArete)
{
    m_tabAreteSo.push_back(newArete);
    m_nbArete++;
}

/*
void Sommet::enleveArete(Arete* arete){
    supprimer arrete de m_tabAreteSo => supprimer element d'un vector
    m_nbArete--;
}
*/

// faire une fonction dans graphe qui lance celle la pour tout les sommets du graphe
void Sommet::calculeIndiceCentraliteDegres(int ordre)
{
    int n = ordre-1;
    // somme des aretes d'un sommet = cds
    m_indiceDegre = m_nbArete;
    m_indiceDegreNorm = m_indiceDegre/ n;
    std::cout << "indice : " << m_indiceDegre << std::endl;
    std::cout << "indice normalise : " << m_indiceDegreNorm << std::endl;

}
