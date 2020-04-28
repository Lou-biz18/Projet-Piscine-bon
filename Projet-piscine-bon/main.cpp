#include "Fichier_h.h"

/// Phrases de sorties du programme
std::string demandeMenu = "Bonjour! que voulez-vous faire? (Entrez le numero correspondant) \n1: Charger un graphe\n2: Choisir un fichier de ponderations\n3: Calculer/Afficher/Sauvegarder les differents indices de centralite\n4: Faire des tests de vulnerabilite\n5 : Quitter";
std::string mauvaiseEntree = "Veuillez entrer un nombre entier.";
std::string mauvaiseOption = "L'option demandée n'existe pas";
std::string queFaire = "L'option demandée n'existe pas";

//Choix de l'utilisateur
bool lancementDuService(int choix)
{
    const char* nomFichier;
    switch(choix)
    {
        case 5:
            std::cout << "exit" << std::endl;
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
            nomFichier = demandeNomFichier();
            // A exporter dans une fonction
            Graphe graphe(nomFichier);
            break;
    }
    return false;
}

bool menu()
{
    int choixUtilisateur;
    std::cout << "Bienvenue sur notre support de gestion de graphes" <<std::endl << std::endl
              << demandeMenu << std::endl;

    std::cin >> choixUtilisateur;

    while(1)
    {
        if(cin.fail())
        {
            cin.clear();// recup un flux pur
            cin.ignore(numeric_limits<streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
            std::cout << mauvaiseEntree <<std::endl;
            std::cin >> choixUtilisateur
        }
        else if(choixUtilisateur<1 || choixUtilisateur >5)
        {
            std::cout << mauvaiseOption << endl;
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
    while (!quitter)   /// On relance le menu tant que l'utilisateur n'a pas demandé la sortie du programme
    {
        quitter = menu();
        if (!quitter) {
            std::cout << queFaire << std::endl << demandeMenu << std::endl;
        }
    }
    return 0;
}