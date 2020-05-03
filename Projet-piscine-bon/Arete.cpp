#include "Arete.h"
#include "Sommet.h"

///CONSTRUCTEUR
Arete::Arete(int idArete, Sommet*s1, Sommet*s2)//constructeur d'arete
{
    m_idArete = idArete;
    m_sommets.first = s1;
    m_sommets.second = s2;
    m_poids = 1;//Arete de poids 1 par default pour graphe non orienté
    s1->ajoutArete(this);
    s2->ajoutArete(this);
    m_couleurA = "black";
}

Arete::Arete(const Arete &areteACopier, Sommet* sommet1, Sommet* sommet2)// constructeur de la copie
{
    m_idArete = areteACopier.get_idArete();
    m_poids = areteACopier.get_poids();
    m_sommets.first = sommet1;
    m_sommets.second = sommet2;
    m_sommets.first->ajoutArete(this);
    m_sommets.second->ajoutArete(this);
    m_couleurA = "black";
}

Arete::~Arete() // destructeur
{

}
///GET

int Arete::get_idArete()const // id de l'arete
{
    return m_idArete;
}


// donne les coordonnées des extremités de l'arete

int Arete::get_idS1() const// premiere extremité
{
    return m_sommets.first->get_idSommet();
}
int Arete::get_idS2() const // deuxieme extremité
{
    return m_sommets.second->get_idSommet();
}

Sommet* Arete::get_autreSommet (Sommet* premierSommet) const
{
    if (premierSommet == m_sommets.first)
    {
        return m_sommets.second;
    }
    else
    {
        return m_sommets.first;
    }
}
// donne l'extremité de l'arete voulu

Sommet* Arete::get_s1() const // le premier sommet
{
    return m_sommets.first;
}
Sommet* Arete::get_s2() const //le deuxieme sommet
{
    return m_sommets.second;
}

int Arete::get_poids() const // donne le poid des aretes
{
    return m_poids;
}

std::string Arete::get_couleurA() const // donne la couleur
{
    return m_couleurA;
}

    ///SET
void Arete::set_poids(int poids)
{
    m_poids= poids;
}


    ///AFFICHAGE
void Arete::afficher()
{
    std::cout <<"Arrete --> "<<m_idArete
              <<": "<<m_sommets.first->get_nom()
              <<"-"<<m_sommets.second->get_nom()
              <<" poids:"<<m_poids;
}
