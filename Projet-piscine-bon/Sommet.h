#ifndef SOMMET_H
#define SOMMET_H
#include "Fichier_h.h"

class Sommet//dans chaque somme ya un tableaux darretes
{
    public:
        Sommet();//constructeur
        virtual ~Sommet();

        virtual void afficher() const;
        int get_idSommet();
// dans graphe oriente : ext  le depart ext destination
    //protected:

    private:

        int m_idSommet;
        std::string m_nom;
        std::pair<int,int> m_coords;

        ///svg
        //std::string m_couleur;
        //float m_rayon;
};
#endif
