#include "Sommet.h"
#include "Arete.h"

Sommet::Sommet(int idSommet, std::string nom, int x, int y)//constructeur de arete
{
    m_idSommet = idSommet;
    m_nom = nom;
    m_coords.first = x;
    m_coords.second = y;
    m_nbArete = 0;
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

void Sommet::afficher() const///afficher les donn�es d'un bloc pour debug
{
    std::cout <<"Sommet --> "<<m_idSommet
              <<":x= "<<m_coords.first
              <<";y= "<<m_coords.second<<std::endl;

}

void Sommet::ajoutArrete(Arete* newArete)
{
    m_tabAreteSo.push_back(newArete);
    m_nbArete++;
}


// faire une fonction dans graphe qui lance celle la pour tout les sommets du graphe
void Sommet::calculeIndiceCentraliteDegres(int m_ordre)
{
 int ordre = m_ordre-1;
        // somme des aretes d'un sommet = cds
int m_indiceDegre = m_tabAreteSo.size();
int m_indiceDegreNorm= m_indiceDegre/ordre;
 std::cout << "indice : " << m_indiceDegre << std::endl;
 std::cout << "indice normalisé : " << m_indiceDegreNorm << std::endl;


}










