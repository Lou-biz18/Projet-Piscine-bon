#ifndef GRAPHE_H
#define GRAPHE_H


class Graphe
{
    public:
        Graphe();
        virtual ~Graphe();

        Graphe(int ordre, bool orientation, int taille);
        virtual void afficher() const;

    //protected:

    private:
        int m_ordre;
        bool m_orientation;
        int m_taille;
};

#endif // GRAPHE_H
