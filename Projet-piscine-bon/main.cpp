#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "utile.h"
#include "Environnement.h"

/// Phrases de sorties du programme
std::string demandeMenu = "Bonjour! que voulez-vous faire? (Entrez le numero correspondant) \n1: Charger un graphe\n2: Choisir un fichier de ponderations\n3: Calculer/Afficher/Sauvegarder les differents indices de centralite\n4: Faire des tests de vulnerabilite en supprimant des aretes\n5 : Quitter";
std::string mauvaiseEntree = "Veuillez entrer un nombre entier.";
std::string mauvaiseOption = "L'option demandée n'existe pas";

/*
void demandeSuppressionAretes(){
    // boucle de demande suppression arette(s) (par index et quitter fait sortir de cette fonction)
        env->get_graphemodifie()->supprimerArrete(arretechoisie)
        Svgfile svg;
        env->get_graphemodifie()->dessiner(svg);
}
*/
///CHOIX SUPP ARETE
void demandeSuppA(Environnement * env)
{
    int choixU;
    std::string choixUstr = "";

    while(1)
    {
        std::cout<<"Veuillez donner l'identifiant de l'arête que vous souhaitez supprimer" << std::endl;
        std::cin >> choixU;
        if(std::cin.fail())
        {
            std::cin.clear();// recup un flux pur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
            std::cout << mauvaiseEntree << std::endl;
            std::cin >> choixU;
        }
        else if(!(env->get_grapheModif()->supprimerArete(choixU)))//si bool = false
        {
            std::cout <<"l'arete choisie n'existe pas, veuillez entrer une arete qui existe"<<std::endl;
            std::cin >> choixU;
        }
        else
            std::cout << "Tout c'est bien passé." << std::endl;
        while(choixUstr.compare("non") != 0 && choixUstr.compare("oui") != 0 )
        {
            std::cout << "Voulez-vous continuer? (oui/non)" << std::endl;
            std::cin >> choixUstr;
        }
        if(choixUstr.compare("non") == 0)
        {
            break;
        }
    }
}

//Choix de l'utilisateur
bool lancementDuService(int choix, Environnement* env)
{
    std::string nomFichier;
    std::string nomFichierSauv = "sauv.txt";
    std::string ligneSauv;
    switch(choix)
    {
        case 6:
            std::cout << "Quitter" << std::endl;
            return true;
        case 5:
            std::cout <<"que souhaitez vous ecrire dans le fichier sauv.txt ? " <<std::endl;
            std::cin>> ligneSauv;
            sauvegardeDansFichier(nomFichierSauv,ligneSauv);
            break;
        case 4:
            std::cout << "Etude de vulnerabilite" << std::endl;
            env->creationGrapheAModifer();//ca marche pas sa mereé
            env->get_grapheModif()->afficher();
            demandeSuppA(env);
            if (env->get_grapheModif()->test_connexite(env->get_grapheModif()->get_tabSommet()[0]) == false)
                std::cout << "Le graphe n'est plus connexe." << std::endl;
                env->get_grapheModif()->commencerIndiceDeProximite();
            else
                std::cout << "Le graphe est toujours connexe." << std::endl;
            env->get_grapheModif()->commencerIndiceDeCentralite();
            env->get_grapheModif()->commencerVecteurPropre();
            env->get_grapheModif()->reinitialiseConnexite();
            env->get_grapheModif()->dessiner("outputVulnerability.svg"); //dessine le graphe
            /*demandeSuppressionAretes();FAIT
            relancer les methodes de calcul d'indices FAIT
             sauvegarder/afficher les indices dans un fichier different de celui du graph normal
             comparer les indices => afficher pour chaque sommet: indiceAvantSuppression => indiceApresSuppression
            */
            break;
        case 3:
            std::cout << "Calcul des indices de degre normalise et non-normalise" << std::endl;
            env->get_graphe()->commencerIndiceDeCentralite();
            env->get_graphe()->commencerVecteurPropre();
            env->get_graphe()->commencerIndiceDeProximite();
            break;
        case 2:
            std::cout << "Ajout d'une ponderation" << std::endl;
            nomFichier = demandeNomFichier(); // on creer le fichier avec des arete ponde
            if (nomFichier.compare("") != 0) // Si le fichier existe, alors on lance la suite
            {
                env->get_graphe()->chargePonderation(nomFichier);//pas sure de le modif
                env->get_graphe()->afficher();
            }
            break;
        case 1:
            std::cout << "Création du graphe..." << std::endl;
            //nomFichier = demandeNomFichier();//si je fais quitter --> retourne string vide
            nomFichier = "graphe_cycle5_topo.txt"; // !! a enlever
            if (nomFichier.compare("")!= 0) // Si le fichier existe, alors on lance la suite
            {
                env->createGraphe(nomFichier);
                env->get_graphe()->afficher();
                if (env->get_graphe()->test_connexite(env->get_graphe()->get_tabSommet()[0]) == false)
                    std::cout << "Le graphe n'est pas connexe." << std::endl;
                else
                    std::cout << "Le graphe est connexe." << std::endl;
                env->get_graphe()->reinitialiseConnexite();
                env->get_graphe()->dessiner("output.svg"); //dessine le graphe
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
