#ifndef GRAPHE_H
#define GRAPHE_H


class graphe
{
    public:
        graphe();

        virtual ~graphe();

    private:
        int m_ordre;
        bool m_orientation;
        int m_taille;

};

#endif // GRAPHE_H
