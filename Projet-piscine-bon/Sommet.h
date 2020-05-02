#ifndef SOMMET_H
#define SOMMET_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Graphe.h"
#include "Svgfile.h"

class Arete;

class Sommet//dans chaque somme ya un tableaux darretes
{
    public:
        Sommet();//constructeur
        Sommet(const Sommet &sommetACopier);// constructeur de copie
        Sommet(int idSommet, std::string nom, double x, double y);
        ~Sommet();

        void afficher() const;
        int get_idSommet() const;
        std::string get_nom() const;
        double get_coordx() const;//pour dessiner
        double get_coordy() const;
        std::string get_couleurS() const;
        float get_indiceDegreNorm() const;
        float get_indiceDegre() const;

        void ajoutArete(Arete* newArete);
        void dessiner(Svgfile&svgout, double x, double y);
        void afficherTextId(Svgfile&svgout, double x, double y);
        void calculeIndiceCentraliteDegres(int m_ordre);
        void enleveA(Arete* arete);
        void deployerDijkstra();


    private:

        int m_idSommet;
        int m_nbArete;
        float m_indiceDegre;
        float m_indiceDegreNorm;

        std::string m_nom;
        std::pair<double,double> m_coords;
        std::vector<Arete*> m_tabAreteSo;//il possede des aretes
        std::string m_couleurS;


        ///svg
        //std::string m_couleur;
        //float m_rayon;
};
#endif
