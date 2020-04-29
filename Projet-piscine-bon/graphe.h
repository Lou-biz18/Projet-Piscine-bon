#ifndef GRAPHE_H
#define GRAPHE_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"

class Graphe
{
    public:
        Graphe(std::string nomFichier);//prototyper le constructeur
        ~Graphe();

        void chargeGraphe(std::string nomFichier);
        void ajoutSommet(std::string ligne);
        void ajoutArete(std::string ligne);
        void afficher() const;
        bool get_orient() const;
        int get_ordre() const;
        int get_taille() const;
        void set_orient(bool m_orient);
        void set_ordre(int m_ordre);
        void set_taille(int m_taille);


 //void chargeGraphe(std::string&fichier);

    private:
        int m_ordre;
        bool m_orient;
        int m_taille;
        std::vector<Sommet*> m_tabSommet;
};
#endif
