/// aide TP�5 de Mme Dridi
#ifndef ARETE_H
#define ARETE_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Graphe.h"
#include "Sommet.h"


class Sommet;
class Arete
{
   public:
        Arete(int idArete, Sommet*s1, Sommet*s2); //constructeur
        Arete(const Arete &areteACopier, Sommet* sommet1, Sommet* sommet2); // constrtucteur de copie
        ~Arete(); // destructeur

        void afficher();
        void set_poids(int poids);
        int get_idArete() const;
        int get_idS1() const;
        int get_idS2() const;
        Sommet* get_s1() const;
        Sommet* get_s2() const;
        int get_poids() const;
        std::string get_couleurA() const;
        Sommet* get_autreSommet (Sommet* premierSommet)const;


    private:
        int m_idArete;
        int m_poids;
        std::pair<Sommet*,Sommet*> m_sommets;// les extremites de l'aretes
        std::string m_couleurA;

};

#endif // ARETE_H
