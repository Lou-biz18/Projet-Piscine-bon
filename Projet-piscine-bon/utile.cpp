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
            sortie = true;
        } else {
            std::cout << "Le fichier renseigné n'existe pas." << std::endl;
        }
    }
    return fichier;
}

void entete(){
    using namespace std;
    std::string rouge = "\033[31m";
    std::string vert = "\033[32m";
    std::string jaune = "\033[33m";
    std::string bleu = "\033[34m";
    std::string magenta = "\033[35m";
    std::string cian = "\033[36m";
    std::string blanc = "\033[37m";
    std::string normal = "\033[0m";

    std::cout << bleu;
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

    std::cout << blanc;
    std::cout <<"                             __                      "<<endl;
    std::cout <<"                            |  \\                     "<<endl;
    std::cout <<"                        ____| $$  ______    _______  "<<endl;
    std::cout <<"                       /      $$ /      \\  /       \\ "<<endl;
    std::cout <<"                      |  $$$$$$$|  $$$$$$\\|  $$$$$$$ "<<endl;
    std::cout <<"                      | $$  | $$| $$    $$ \\$$    \\  "<<endl;
    std::cout <<"                      | $$__| $$| $$$$$$$$ _\\$$$$$$\\ "<<endl;
    std::cout <<"                       \\$$    $$ \\$$     \\|       $$ "<<endl;
    std::cout <<"                        \\$$$$$$$  \\$$$$$$$ \\$$$$$$$  "<<endl;

    std::cout << rouge;
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

    std::cout << normal;
}
