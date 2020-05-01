#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "utile.h"
#include "Environnement.h"

/// Phrases de sorties du programme
std::string demandeMenu = "Bonjour! que voulez-vous faire? (Entrez le numero correspondant) \n1: Charger un graphe\n2: Choisir un fichier de ponderations\n3: Calculer/Afficher/Sauvegarder les differents indices de centralite\n4: Faire des tests de vulnerabilite\n5 : Quitter";
std::string mauvaiseEntree = "Veuillez entrer un nombre entier.";
std::string mauvaiseOption = "L'option demandée n'existe pas";

//Choix de l'utilisateur
bool lancementDuService(int choix, Environnement* env)
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
            std::cout << "calcule des indices de degre normalise et non-normalise" << std::endl;
            commencerIndiceDeCentralite();
            break;
        case 2:
            std::cout << "Ajout d'une ponderation" << std::endl;
            //nomFichier = demandeNomFichier(); // on creer le fichier avec des arete ponde
            nomFichier = "testPond.txt"; // !! a enlever
            if (nomFichier.compare("")!= 0) // Si le fichier existe, alors on lance la suite
            {
                env->get_graphe()->chargePonderation(nomFichier);//pas sure de le modif
                env->get_graphe()->afficher();
            }
            break;
        case 1:
            std::cout << "Création du graphe..." << std::endl;
            //nomFichier = demandeNomFichier();//si je fais quitter --> retourne string vide
            nomFichier = "test.txt"; // !! a enlever
            if (nomFichier.compare("")!= 0) // Si le fichier existe, alors on lance la suite
            {
                env->createGraphe(nomFichier);
                env->get_graphe()->afficher();
                Svgfile svg;
                //Graphe graphe;

                env->get_graphe()->dessiner(svg);//dessine le graphe

            }
            break;
    }
    return false;
}

bool menu(Environnement* env)
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
    return lancementDuService(choixUtilisateur, env);
}


int main() {
    bool quitter = false; // bool pour tester si l'utilisateur veut quitter
    Environnement* env = new Environnement;
    entete();
    g.commencerIndiceDeCentralite();
    while (!quitter)   /// On relance le menu tant que l'utilisateur n'a pas demandé la sortie du programme
    {
        quitter = menu(env);
    }
    return 0;
}
