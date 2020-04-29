#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>

#include "Graphe.h"
#include "utile.h"

/// Phrases de sorties du programme
std::string demandeMenu = "Bonjour! que voulez-vous faire? (Entrez le numero correspondant) \n1: Charger un graphe\n2: Choisir un fichier de ponderations\n3: Calculer/Afficher/Sauvegarder les differents indices de centralite\n4: Faire des tests de vulnerabilite\n5 : Quitter";
std::string mauvaiseEntree = "Veuillez entrer un nombre entier.";
std::string mauvaiseOption = "L'option demandée n'existe pas";

//Choix de l'utilisateur
bool lancementDuService(int choix)
{
    std::string nomFichier;
    switch(choix)
    {
        case 5:
            std::cout << "Quitter" << std::endl;
            return true;
        case 4:
            std::cout << "menu4" << std::endl;
            break;
        case 3:
            std::cout << "menu3" << std::endl;
            break;
        case 2:
            std::cout << "menu2" << std::endl;
            break;
        case 1:
            std::cout << "Création du graphe..." << std::endl;
            //nomFichier = demandeNomFichier();
            Graphe graphe("test.txt");
            graphe.afficher();

/*             if (nomFichier.compare("") == 0) // Si le fichier existe, alors on lance la suite
            {
                Graphe graphe(nomFichier);
            } */
            break;
    }
    return false;
}

bool menu()
{
    int choixUtilisateur;
    std::cout << std::endl << demandeMenu << std::endl;
    std::cin >> choixUtilisateur;

    while(1)
    {
        if(std::cin.fail())
        {
            std::cin.clear();// recup un flux pur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
            std::cout << mauvaiseEntree << std::endl;
            std::cin >> choixUtilisateur;
        }
        else if(choixUtilisateur < 1 || choixUtilisateur > 5)
        {
            std::cout << mauvaiseOption << std::endl;
            std::cin >> choixUtilisateur;
        }
        else
        {
            break;
        }

    }
    return lancementDuService(choixUtilisateur);
}

int main() {
    bool quitter = false; // bool pour tester si l'utilisateur veut quitter
    std::cout << "Bienvenue sur notre support de gestion de graphes" << std::endl;
    while (!quitter)   /// On relance le menu tant que l'utilisateur n'a pas demandé la sortie du programme
    {
        quitter = menu();
    }
    return 0;
}
