#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>


class Sommet
{
    public:
        Sommet();//constructeur
        virtual ~Sommet();

        Sommet(int idSommet, std::string nom, std::pair<int,int> coords);
        virtual void afficher() const;


    //protected:

    private:

        int m_idSommet;
        std::string m_nom;
        std::pair<int,int> m_coords;

        ///svg
        //std::string m_couleur;
        //float m_rayon;
};

#endif // SOMMET_H
