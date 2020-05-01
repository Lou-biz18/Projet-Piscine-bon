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
        int get_idSommet();
        std::string get_nom();
        double get_coordx();//pour dessiner
        double get_coordy();
        std::string get_couleurS();

        void ajoutArete(Arete* newArete);
        void dessiner(Svgfile&svgout, double x, double y);
        void afficherTextId(Svgfile&svgout, double x, double y);
        void calculeIndiceCentraliteDegres(int m_ordre);
        float get_indiceDegre();
        float get_indiceDegreNorm();


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
