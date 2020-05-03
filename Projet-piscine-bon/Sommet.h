#ifndef SOMMET_H
#define SOMMET_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Graphe.h"
#include "Svgfile.h"

class Arete;

class Sommet//dans chaque somme il y a un tableaux d'aretes
{
    public:
        Sommet();//constructeur
        Sommet(const Sommet &sommetACopier);// constructeur de copie
        Sommet(int idSommet, std::string nom, double x, double y);
        ~Sommet(); // destructeur

        void afficher() const;
        int get_idSommet() const;
        std::string get_nom() const;
        double get_coordx() const;//pour dessiner
        double get_coordy() const;
        std::string get_couleurS() const;

        // get pour les diff�rents indices
        float get_indiceDegreNorm() const;
        float get_indiceDegre() const;
        int get_longueurDeChemin() const;
        float get_indiceProximite() const;
        float get_indiceProximiteNorm() const;
        float get_sommeIVPVoisins() const;
        float get_indiceVecteurPropre()const;
        std::vector<Arete*> get_tabArete() const;
        std::string get_couleurIDN() const;
        std::string get_couleurIVPN() const;
        std::string get_couleurIPN() const;


        // les diff�rents set
        void set_indiceProximite(float indicePr);
        void set_indiceProximiteNorm(float indicePrNrm);
        void set_indiceVecteurPropre(float m_indiceVecteurPropre);
        void set_sommeIVPVoisins();
        void set_calculICouleur(float couleurI);
        void set_couleurIDN(std::string couleurIDN);
        void set_couleurIVP(std::string couleurIVP);
        void set_couleurIPN(std::string couleurIPN);

        // les m�thodes
        void ajoutArete(Arete* newArete);
        void dessiner(Svgfile&svgout, double x, double y);
        void afficherTextId(Svgfile&svgout, double x, double y);

        void calculeIndiceCentraliteDegres(int m_ordre);
        std::string calcCouleurSommet();
        void enleveA(Arete* arete);
        void deployerDijkstra();
        void set_longueurDeChemin(int longueur);
        bool get_connexite();
        bool set_connexite(bool conn);



    private:

        int m_idSommet;
        int m_nbArete;
        float m_indiceDegre;
        float m_indiceDegreNorm;
        float m_indiceVecteurPropre;
        float m_sommeIVPVoisins;
        int m_longueurDeChemin;
        float m_indiceProximite;
        float m_indiceProximiteNorm;
        bool m_connexite;



        std::string m_nom;
        std::pair<double,double> m_coords;
        std::vector<Arete*> m_tabAreteSo;//il possede des aretes
        std::string m_couleurS;

        std::string m_couleurIDN;
        std::string m_couleurIVP;
        std::string m_couleurIPN;





};
#endif
