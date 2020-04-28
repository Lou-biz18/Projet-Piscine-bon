#ifndef GRAPHE_H
#define GRAPHE_H
#include <fstream>
#include <sstream>


class Graphe
{
    public:
        Graphe();
        ~Graphe();

        Graphe(int ordre, bool orientation, int taille);

        void chargeGraphe(std::string&fichier);
        void afficher() const;


    //protected:

    private:
        int m_ordre;
        bool m_orientation;
        int m_taille;
};

#endif // GRAPHE_H
