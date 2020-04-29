#ifndef SOMMET_H
#define SOMMET_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Graphe.h"

class Arete;

class Sommet//dans chaque somme ya un tableaux darretes
{
    public:
        Sommet();//constructeur
        virtual ~Sommet();

        virtual void afficher() const;
        int get_idSommet();
        std::string get_nom();
// dans graphe oriente : ext  le depart ext destination
    //protected:

    private:

        int m_idSommet;
        std::string m_nom;
        std::pair<int,int> m_coords;
        std::vector<Arete*> m_tabArete;

        ///svg
        //std::string m_couleur;
        //float m_rayon;
};
#endif
