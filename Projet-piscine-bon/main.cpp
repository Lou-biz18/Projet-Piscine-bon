// Auteurs:
// Lou Bizet
// Léo Valet
// Carla Gaignard
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include <windows.h>
#include "utile.h"
#include "Environnement.h"


/// Phrases de sorties du programme

std::string mauvaiseEntree = "Veuillez entrer un nombre entier.";
std::string mauvaiseOption = "L'option demandee n'existe pas";

bool grapheChargey = false;
bool indiceCalculey = false;
///CHOIX SUPP ARETE
void demandeSuppA(Environnement * env)
{
    int choixU;
    std::string choixUstr;

    while(1)
    {
        choixUstr = "";
        std::cout<<"Veuillez donner l'identifiant de l'arete que vous souhaitez supprimer" << std::endl;
        std::cin >> choixU;
        if(std::cin.fail())
        {
            std::cout << mauvaiseEntree << std::endl;
            std::cin.clear();// recup un flux pur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
        }
        else if(!(env->get_grapheModif()->supprimerArete(choixU)))//si bool = false
        {
            std::cout <<"l'arete choisie n'existe pas, veuillez entrer une arete qui existe"<<std::endl;
            std::cin.clear();// recup un flux pur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
        }
        else
            std::cout << "Tout c'est bien passe" << std::endl;
        while(choixUstr.compare("non") != 0 && choixUstr.compare("oui") != 0 ) // On demande si l'utilisateur veut encore faire des suppressions
        {
            std::cout << "Voulez-vous continuer? (oui/non)" << std::endl;
            std::cin >> choixUstr;
        }
        if(choixUstr.compare("non") == 0)
        {
            break;
        }
        std::cin.clear();// recup un flux pur
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
    }
}

//Choix de l'utilisateur
bool lancementDuService(int choix, Environnement* env)
{
    HANDLE console;  // Souce : youtube.com/watch?v=zujRdlaCef4
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    std::string nomFichier;
    std::string nomFichierSauv = "sauv.txt";
    std::string nomFichierSvg;
    std::string ligneSauv;

    if (choix != 1 && choix != 5 && grapheChargey != true) // Nous permet de proteger les choix dependant des autres
    {
        std::cout << "Il faut d'abord charger un graphe..." << std::endl;
        lancementDuService(1, env);
    }
    if (choix == 4 && indiceCalculey != true) {
        std::cout << "Il faut d'abord calculer les indices de centralite..." << std::endl;
        lancementDuService(3, env);
    }
    switch(choix) 
    {
        case 5:
            SetConsoleTextAttribute(console, 12);
            std::cout << "Quitter" << std::endl;
            return true;
        case 4:  // On copie notre graphe grace aux copy constructor, puis on supprime des arretes, calcule les indices, puis compare le tout
            SetConsoleTextAttribute(console, 1);
            std::cout << "Etude de vulnerabilite" << std::endl;
            env->creationGrapheAModifer();
            demandeSuppA(env);
            if (env->get_grapheModif()->test_connexite(env->get_grapheModif()->get_tabSommet()[0]) == false)
                std::cout << "Le graphe n'est plus connexe." << std::endl;
            else
            {
                std::cout << "Le graphe est toujours connexe." << std::endl;
                env->get_grapheModif()->commencerIndiceDeProximite();
            }
            env->get_grapheModif()->commencerIndiceDeCentralite();
            env->get_grapheModif()->commencerVecteurPropre();

            env->get_grapheModif()->reinitialiseConnexite();
            env->get_grapheModif()->dessiner("outputVulnerability.svg"); //dessine le graphe
            env->get_graphe()->commencerVecteurPropre();
            env->get_graphe()->commencerIndiceDeProximite();
            env->get_graphe()->commencerIndiceDeCentralite();
            env->comparaisonIndiceSommet ();
            break;
        case 3: // on calclule, affiche et sauvegarde les indices
            SetConsoleTextAttribute(console, 11);
            std::cout << "Calcul des indices de degre normalise et non-normalise" << std::endl;
            env->get_graphe()->lancerLesIndices(nomFichierSauv);
            indiceCalculey = true;
            env->get_graphe()->calcCouleurG();
            env->get_graphe()->dessinerGICDN("fichierD.svg");
            env->get_graphe()->dessinerGIVPN("fichierVP.svg");
            env->get_graphe()->dessinerGIPN("fichierP.svg");
            break;
        case 2: //on peut charger un fichier de ponderation
            SetConsoleTextAttribute(console, 10);
            std::cout << "Ajout d'une ponderation" << std::endl;
            nomFichier = demandeNomFichier(); // on creer le fichier avec des arete ponde
            if (nomFichier.compare("") != 0) // Si le fichier existe, alors on lance la suite
            {
                env->get_graphe()->chargePonderation(nomFichier);
                env->get_graphe()->afficher();
            }
            break;
        case 1: // on charge un graphe
            SetConsoleTextAttribute(console, 13);
            std::cout << "Creation du graphe..." << std::endl;
            nomFichier = demandeNomFichier();//si je fais quitter --> retourne string vide
            if (nomFichier.compare("")!= 0) // Si le fichier existe, alors on lance la suite
            {
                env->createGraphe(nomFichier);
                env->get_graphe()->afficher();
                if (env->get_graphe()->test_connexite(env->get_graphe()->get_tabSommet()[0]) == false)
                    std::cout << "Le graphe n'est pas connexe." << std::endl;
                else
                    std::cout << "Le graphe est connexe." << std::endl;
                env->get_graphe()->reinitialiseConnexite();
                env->get_graphe()->dessiner("outputNormal.svg"); //dessine le graphe
                grapheChargey = true;
            }
            break;
    }
    return false;
}

bool menu(Environnement* env)
{
    int choixUtilisateur;
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 15);

    std::cout << "Bonjour! que voulez-vous faire? (Entrez le numero correspondant)" << std::endl;
    SetConsoleTextAttribute(console, 13);
    std::cout << "1: Charger un graphe" << std::endl;
    SetConsoleTextAttribute(console, 10);
    std::cout << "2: Choisir un fichier de ponderations" << std::endl;
    SetConsoleTextAttribute(console, 11);
    std::cout << "3: Calculer/Afficher/Sauvegarder les differents indices de centralite" << std::endl;
    SetConsoleTextAttribute(console, 1);
    std::cout << "4: Faire des tests de vulnerabilite en supprimant des aretes" << std::endl;
    SetConsoleTextAttribute(console, 14);
    std::cout << "5 : Quitter" << std::endl;
    SetConsoleTextAttribute(console, 15);
    std::cin >> choixUtilisateur;
    system("cls");

    while(1)
    {
        if(std::cin.fail())
        {
            std::cin.clear();// recup un flux pur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
            std::cout << mauvaiseEntree << std::endl;
            std::cin >> choixUtilisateur;
        }
        else if(choixUtilisateur < 1 || choixUtilisateur > 6)
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
       while (!quitter)   /// On relance le menu tant que l'utilisateur n'a pas demandé la sortie du programme
    {
        quitter = menu(env);
    }
    return 0;
}
