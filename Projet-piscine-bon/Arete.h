/// aide TP�5 de Mme Dridi
#ifndef ARETE_H
#define ARETE_H
#include "Fichier_h.h"

class Arete
{
    public:
        Arete();
        virtual ~Arete();

        Arete(double poids, std::pair<Sommet*,Sommet*> arete);
    //protected:

    private:
        double m_poids;
        std::pair<Sommet*,Sommet*> m_arete;// extremites de laretes
};

#endif // ARETE_H