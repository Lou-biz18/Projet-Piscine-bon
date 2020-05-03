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

Sommet::Sommet(const Sommet &sommetACopier)// copier du sommet
{
    m_idSommet = sommetACopier.get_idSommet();
    m_nbArete = 0;
    m_nom = sommetACopier.get_nom();
    m_coords.first = sommetACopier.get_coordx();
    m_coords.second = sommetACopier.get_coordy();
}

Sommet::~Sommet()  // destructeur
{

}


            /// GET

int Sommet::get_idSommet() const // donne l'id du sommet
{
    return m_idSommet;
}

std::string Sommet::get_nom() const // donne le nom du sommet
{
    return m_nom;
}

double Sommet::get_coordx() const // la coordonnée en x
{
    return m_coords.first;
}

double Sommet::get_coordy() const // la coordonnée en y
{
    return m_coords.second;
}

std::string Sommet::get_couleurS() const // donne la couleur
{
    return m_couleurS;
}

float  Sommet::get_indiceDegre() const // donne l'indice de degrés non normalisé
{
    return m_indiceDegre;
}

float Sommet::get_indiceDegreNorm() const // donne l'indice de degrés normalisé
{
    return m_indiceDegreNorm;
}

int Sommet::get_longueurDeChemin() const // la longeur du chemin
{
    return m_longueurDeChemin;
}

float Sommet::get_indiceVecteurPropre() const // donne l'indice de vecteur propre
{
    return m_indiceVecteurPropre;
}

float Sommet::get_sommeIVPVoisins() const  // donne la somme des indice des voisins
{
    return m_sommeIVPVoisins;
}

float Sommet::get_indiceProximite() const  // donne l'indice de proximité
{
    return m_indiceProximite;
}

float Sommet::get_indiceProximiteNorm() const // donne l'indice proximité normalisé
{
    return m_indiceProximiteNorm;
}



                /// SET


void Sommet::set_indiceVecteurPropre(float indiceVecteurPropre)
{
    m_indiceVecteurPropre = indiceVecteurPropre;
}


void Sommet::set_sommeIVPVoisins()  // on fait la somme des indices des voisins et on met ans m_sommeIVOVoisins
{
    m_sommeIVPVoisins = 0;
    for (auto a: m_tabAreteSo)
    {
        m_sommeIVPVoisins += a->get_autreSommet(this)->get_indiceVecteurPropre();
    }
}

void Sommet::set_longueurDeChemin(int longueur)
{
    m_longueurDeChemin = longueur;
}

void Sommet::set_indiceProximite(float indicePr)
{
    m_indiceProximite = indicePr;
}



void Sommet::set_indiceProximiteNorm(float indicePrNrm)
{
    m_indiceProximiteNorm = indicePrNrm;
}




                /// METHODE



void Sommet::afficher() const///afficher les donn�es d'un bloc pour debug
{
    std::cout <<"Sommet --> "<<m_idSommet
              <<":x= "<<m_coords.first
              <<";y= "<<m_coords.second;

}

void Sommet::ajoutArete(Arete* newArete)  // permet d'ajouter une arete
{
    m_tabAreteSo.push_back(newArete);
    m_nbArete++;
}

void Sommet::enleveA(Arete* arete) // enleve une arete
{
    for(int i=0;i<m_nbArete;i++)
    {
        if(m_tabAreteSo[i]==arete)
        {
            m_tabAreteSo.erase(m_tabAreteSo.begin()+ i);
        //vect.erase(std::remove(vect.beging(),vetc.end(),vect[aretesup]),vetc.end())
            m_nbArete = m_nbArete - 1;
        }
    }
}

void Sommet::calculeIndiceCentraliteDegres(int ordre)
{
    int n = ordre-1;
    // somme des aretes d'un sommet = cds
    m_indiceDegre = m_nbArete; // l'indice correspond au nombres d'arete
    m_indiceDegreNorm = m_indiceDegre/ n;  //on divise par l'ordre -1

}

void Sommet::deployerDijkstra()   // algo dijkstra
{
    int longueurDeCheminTest;
    int longueurDeCheminSommetSuivant;
    for (auto a: m_tabAreteSo)
    {
        longueurDeCheminTest = m_longueurDeChemin + a->get_poids();
        longueurDeCheminSommetSuivant = a->get_autreSommet(this)->get_longueurDeChemin();
        if (longueurDeCheminSommetSuivant > longueurDeCheminTest || longueurDeCheminSommetSuivant == 0)
        {
            a->get_autreSommet(this)->set_longueurDeChemin(longueurDeCheminTest);
        }
    }
}





