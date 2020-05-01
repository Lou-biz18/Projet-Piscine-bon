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
        Arete(int idArete, Sommet*s1, Sommet*s2);
        ~Arete();

        void afficher();
        void set_poids( int poids);
        int get_idArete()const;
        int get_idS1();
        int get_idS2();
        Sommet* get_s1();
        Sommet* get_s2();
        int get_poids();
        std::string get_couleurA();


    private:
        int m_idArete;
        int m_poids;
        std::pair<Sommet*,Sommet*> m_sommets;// extremites de laretes
        std::string m_couleurA;

};

#endif // ARETE_H
