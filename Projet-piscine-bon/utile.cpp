#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<std::string> split(const std::string &ligne, char delimiteur)
{
    std::vector<std::string> recup;
    std::stringstream ss(ligne);
    std::string temp; //chaine tampon
    while (getline(ss, temp, delimiteur))
    {
        recup.push_back(temp);
    }

    return recup;
}

std::string demandeNomFichier()
{
    std::string fichier = "";
    bool sortie = false; // booleen de condition pour sortir de la boucle.
    while (sortie == false)//tq on ne sort pas
    {
        std::cout << "Veuilez entrer le nom du fichier (ou 'quitter' pour quitter)" << std::endl;
        std::cin >> fichier;
        std::ifstream flux(fichier);
        // si le nom exite dans le fichier on retourne le nom du fichier
        if (flux)
        {
            sortie = true;
        } else if (fichier.compare("quitter") == 0)  {
            fichier = "";
            sortie == true;
        } else {
            std::cout << "Le fichier renseigné n'existe pas." << std::endl;
        }
    }
    return fichier;
}
