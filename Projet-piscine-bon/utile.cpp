#include "utile.h"
#include <iostream>
#include <windows.h>


std::vector<std::string> split(const std::string &ligne, char delimiteur)
{
    std::vector<std::string> recup;
    std::stringstream ss(ligne);
    std::string temp; //chaine tampon
    while (getline(ss, temp, delimiteur))
    {
        recup.push_back(temp);
    }

    return recup; // retourne un tableau du tableau de base coupé
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
            sortie = true;
        } else {
            std::cout << "Le fichier renseigne n'existe pas." << std::endl;
        }
    }
    return fichier;
}

bool sauvegardeDansFichier(std::string nomFichierSauv, std::string ligneSauv) // a changer pour faire en sorte que meme si le fichier existe pas, ca le cree
{
    std::ofstream fichier;//flux de fichier de sortie et ouverture du fichier
    fichier.open(nomFichierSauv);//creer un fichier nommé nomFichier
    if(fichier)// si l'ouverture a réussie
    {
        fichier << ligneSauv;//operateur du flux de sortie
        fichier.close();  // on ferme le fichier
        return true;
    }
    else//sinon
    {
        std::cerr << "Impossible d'ouvrir le fichier !" <<nomFichierSauv<< std::endl;
        return false;
    }

}
// renvoie la taille du plus court chemin. On utilise un parcours en largeur 
int dijkstra(Sommet* sommetDepart, Sommet* sommetArrivee, Graphe* graphe)
{
    std::vector<Sommet*> tabSommet = graphe->get_tabSommet();
    int i = 1;

    for(auto s: tabSommet)
    {
        s->set_longueurDeChemin(0);
    }  // on set une longueur de 0 sur tous les sommets
    sommetDepart->set_longueurDeChemin(1);
    while(sommetArrivee->get_longueurDeChemin() == 0) // tant que le point d'arrivee n; est pas atteint
    {
        for(auto s: tabSommet)  // pour chaque sommet
        {
            if (s->get_longueurDeChemin() == i) // si notre index est le mem que la longueur du sommet 
            {
                s->deployerDijkstra(); // on deploie sur les sommets voisins
            }
        }
        i++;
    }
    return(sommetArrivee->get_longueurDeChemin() - 1);
}
//entete de notre menu
void entete(){
    using namespace std;
    HANDLE console;   // Souce : youtube.com/watch?v=zujRdlaCef4
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 1);

    std::cout <<"     ________  __                                      __              "<<endl;
    std::cout <<"    |        \\|  \\                                    |  \\             "<<endl;
    std::cout <<"     \\$$$$$$$$| $$____    ______    ______    ______   \\$$  ______     "<<endl;
    std::cout <<"       | $$   | $$    \\  /      \\  /      \\  /      \\ |  \\ /      \\    "<<endl;
    std::cout <<"       | $$   | $$$$$$$\\|  $$$$$$\\|  $$$$$$\\|  $$$$$$\\| $$|  $$$$$$\\   "<<endl;
    std::cout <<"       | $$   | $$  | $$| $$    $$| $$  | $$| $$   \\$$| $$| $$    $$   "<<endl;
    std::cout <<"       | $$   | $$  | $$| $$$$$$$$| $$__/ $$| $$      | $$| $$$$$$$$   "<<endl;
    std::cout <<"       | $$   | $$  | $$ \\$$     \\ \\$$    $$| $$      | $$ \\$$     \\   "<<endl;
    std::cout <<"        \\$$    \\$$   \\$$  \\$$$$$$$  \\$$$$$$  \\$$       \\$$  \\$$$$$$$   "<<endl;
    std::cout <<"                                                                  "<<endl;

    SetConsoleTextAttribute(console, 15);
    std::cout <<"                             __                      "<<endl;
    std::cout <<"                            |  \\                     "<<endl;
    std::cout <<"                        ____| $$  ______    _______  "<<endl;
    std::cout <<"                       /      $$ /      \\  /       \\ "<<endl;
    std::cout <<"                      |  $$$$$$$|  $$$$$$\\|  $$$$$$$ "<<endl;
    std::cout <<"                      | $$  | $$| $$    $$ \\$$    \\  "<<endl;
    std::cout <<"                      | $$__| $$| $$$$$$$$ _\\$$$$$$\\ "<<endl;
    std::cout <<"                       \\$$    $$ \\$$     \\|       $$ "<<endl;
    std::cout <<"                        \\$$$$$$$  \\$$$$$$$ \\$$$$$$$  "<<endl;

    SetConsoleTextAttribute(console, 12);
    std::cout <<"     ______                                 __                           "<<endl;
    std::cout <<"    /      \\                               /  |                          "<<endl;
    std::cout <<"   /$$$$$$  |  ______    ______    ______  $$ |____    ______    _______ "<<endl;
    std::cout <<"   $$ | _$$/  /      \\  /      \\  /      \\ $$      \\  /      \\  /       |"<<endl;
    std::cout <<"   $$ |/    |/$$$$$$  | $$$$$$  |/$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$$/ "<<endl;
    std::cout <<"   $$ |$$$$ |$$ |  $$/  /    $$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$      \\ "<<endl;
    std::cout <<"   $$ \\__$$ |$$ |      /$$$$$$$ |$$ |__$$ |$$ |  $$ |$$$$$$$$/  $$$$$$  |"<<endl;
    std::cout <<"   $$    $$/ $$ |      $$    $$ |$$    $$/ $$ |  $$ |$$       |/     $$/ "<<endl;
    std::cout <<"    $$$$$$/  $$/        $$$$$$$/ $$$$$$$/  $$/   $$/  $$$$$$$/ $$$$$$$/  "<<endl;
    std::cout <<"                                 $$ |                                    "<<endl;
    std::cout <<"                                 $$ |                                    "<<endl;
    std::cout <<"                                 $$/                                     "<<endl;

    SetConsoleTextAttribute(console, 15);
}
