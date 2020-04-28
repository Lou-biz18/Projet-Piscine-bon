#ifndef GRAPHE_H
#define GRAPHE_H
#include "Fichier_h.h"

class Graphe
{
    public:
        Graphe(std::string nomFichier);//prototyper le constructeur
        ~Graphe();

        void ajoutArete(std::string ligne);
        void chargeGraphe(std::string nomFichier);
        //void chargeGraphe(std::string&fichier);
        void afficher() const;
        bool get_orient() const;
        int get_ordre() const;
        int get_taille() const;



    //protected:

    private:
        int m_ordre;
        bool m_orient;
        int m_taille;
};
#endif
