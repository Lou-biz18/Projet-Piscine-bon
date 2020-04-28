/// aide TP�5 de Mme Dridi
#ifndef ARETE_H
#define ARETE_H
#include "Fichier_h.h"

class Arete
{
    public:
        Arete();
        virtual ~Arete();

        int get_idArete()const;
        int get_ex1();
        int get_ex2();


    private:
        int m_idArete;
        //double m_poids;
        std::pair<Sommet*,Sommet*> m_arete;// extremites de laretes
};

#endif // ARETE_H
