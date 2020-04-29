#ifndef UTILE_H_INCLUDED
#define UTILE_H_INCLUDED
# include <iostream>
# include <vector>

std::vector<std::string>    split(const std::string &ligne, char delimiteur);
std::string                 demandeNomFichier();
void                        entete();

#endif // UTILE_H_INCLUDED
