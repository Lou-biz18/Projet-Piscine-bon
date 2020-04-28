#ifndef FICHIER_H_H_INCLUDED
#define FICHIER_H_H_INCLUDED

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"

std::vector<std::string> split(const std::string &ligne, char delimiteur);

#endif // FICHIER_H_H_INCLUDED
