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
        Sommet(int idSommet, std::string nom, int x, int y);
        Sommet(const Sommet &sommetACopier);// constructeur de copie
        ~Sommet();

        void afficher() const;
        int get_idSommet();
        std::string get_nom();
        void ajoutArete(Arete* newArete);
// dans graphe oriente : ext  le depart ext destination
    //protected:

    private:

        int m_idSommet;
        int m_nbArete;
        std::string m_nom;
        std::pair<int,int> m_coords;
        std::vector<Arete*> m_tabAreteSo;//il possede des aretes


        ///svg
        //std::string m_couleur;
        //float m_rayon;
};
#endif
