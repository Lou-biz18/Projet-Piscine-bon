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
        virtual ~Arete();

        void afficher();
        int get_idArete()const;
        int get_s1();
        int get_s2();


    private:
        int m_idArete;
        int m_ponderation;
        //double m_poids;
        std::pair<Sommet*,Sommet*> m_sommets;// extremites de laretes

};

#endif // ARETE_H
