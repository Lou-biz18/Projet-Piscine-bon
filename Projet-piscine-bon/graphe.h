#ifndef GRAPHE_H
#define GRAPHE_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Sommet.h"
#include "Arete.h"
#include "Svgfile.h"

class Graphe
{
    public:
        Graphe(std::string nomFichier);//prototyper le constructeur
        Graphe(const Graphe &grapheACopier);// constructeur de copie
        ~Graphe(); // destructeur

        void chargeGraphe(std::string nomFichier);
        void chargePonderation(std::string fichierPonderation);
        void ajoutSommet(std::string ligne);
        void ajoutArete(std::string ligne);
        void ajouterPonderation(std::string fichierPond);
        void afficherTabA();
        void afficherTabS();
        void afficher();
        bool get_orient() const;
        int get_ordre() const;
        int get_taille() const;
        std::vector<Arete*> get_tabArete() const;
        std::vector<Sommet*> get_tabSommet() const;
        void dessiner(Svgfile&svgout);
        void commencerIndiceDeCentralite();
        void commencerIndiceDeProximite();
        bool supprimerArete(int areteChoisie);
        void calcCouleurG();
        void commencerVecteurPropre();

    private:
        int m_ordre;
        bool m_orient;
        int m_taille;
        std::vector<Sommet*> m_tabSommet;
        std::vector<Arete*> m_tabArete;

};
#endif
