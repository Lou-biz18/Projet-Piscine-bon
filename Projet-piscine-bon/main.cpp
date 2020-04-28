#include "Fichier_h.h"// acces aux librairies

/// strings de sorties du prgm
std::string demandeMenu = "Bonjour! que voulez-vous faire? (Entrez le num ro correspondant) \n1: Charger un graphe\n2: Choisir un fichier de pond rations\n3: Calculer/Afficher/Sauvegarder les diff rentss indices de centralit \n4: Faire des tests de vuln rabilit \n5 : Quitter";
std::string stringFail = "Please enter an integer";
std::string stringTooBig = "Number entered is too big";

//Choix de l'utilisateur
bool affichageMenu(int choix)
{
    switch(choix)
    {
    case 1:
        std::cout << "Creer un graphe" << std::endl;//charge le fichier et recup données
        Graphe graphe("test.txt");//creation du graphe du fichier text.txt
        break;
    case 2:
        std::cout << "option 2" << std::endl;
        break;
    case 3:
        std::cout << "option 3" << std::endl;
        break;
    case 4:
        std::cout << "option 4" << std::endl;
        break;
    case 5:
        std::cout << "Partir" << std::endl;
        return true;
    }
    return false;
}
bool menu()
{
    int choixUtilisateur;
    std::cout << "Bienvenue sur notre support de gestion de graphes" <<std::endl << std ::endl
              << demandeMenu << std::endl
              << " Creer un graphe : 1 " << std::endl
              << "option2 : 2" << std::endl
              << "option3 : 3" << std::endl
              << "option4 : 4" << std::endl
              << "Quitter : 5" << std::endl;

              std::cin >> choixUtilisateur ;

    while(1)
    {
        if(cin.fail())
        {
            cin.clear();// recup un flux pur
            cin.ignore(numeric_limits<streamsize>::max(),'\n');//permet d'ignorer que le tampon du flux contient
            std::cout << "snifff c est pas un int" <<std::endl;
            std::cin >> choixUtilisateur
        }
        else if(choixUtilisateur<1 || choixUtilisateur >5)
        {
            std::cout << "chiffre trop eleve" << endl;
            std::cin >> choixUtilisateur;
        }
        else
        {
            break;
        }

    }
    return affichageMenu(choixUtilisateur);
}

int main() {
    bool quitter = false; // bool pour tester si lútilisateur veut quitter
    while (!quitter) {   ///On fait tourner la boucle pour utiliser le menu
        quitter = menu();
    }
    return 0;
}

