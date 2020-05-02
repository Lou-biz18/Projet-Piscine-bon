#ifndef UTILE_H_INCLUDED
#define UTILE_H_INCLUDED
# include <iostream>
# include <vector>

std::vector<std::string>    split(const std::string &ligne, char delimiteur);
std::string                 demandeNomFichier();
void                        entete();
int                         dijkstra(Sommet* sommetDepart, Sommet* sommetArrivee);
bool                        sauvegardeDansFichier(std::string nomFichierSauv, std::string ligneSauv);

#endif // UTILE_H_INCLUDED
