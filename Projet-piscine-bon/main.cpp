#include "Fichier_h.h"

bool launchAssets(int uInput) {    //Menu
    switch (uInput) {
    case 1:
        cout << "creating Graph" << endl;
        Graphe graphe("test.txt");
        break;
    case 2:
        cout << "menu2" << endl;
        break;
    case 3:
        cout << "menu3" << endl;
        break;
    case 4:
        cout << "menu4" << endl;
        break;
    case 5:
        cout << "exit" << endl;
        return true;
    }
    return false;
}

bool menu() {
    int x;
    cout << demandeMenu << endl;  //Appele du menu
    cin >> x;

    while (1) {
        if (cin.fail()) {
            cin.clear();   //Remet le flux d entree dans un etat apte � fournir la valeur a extraire
            cin.ignore(numeric_limits<streamsize>::max(),'\n');  //Permet d ignorer ces donn�es que le tzmpon du flux contient
            cout << stringFail << endl;
            cin >> x;
        } else if (x < 1 || x > 5) {
            cout << stringTooBig << endl;
            cin >> x;
        } else {
            break;
        }
    }
    return launchAssets(x);
}

int main() {
    bool userAbort = false; // bool pour tester si lútilisateur veut quitter
    while (!userAbort) {   ///On fait tourner la boucle pour utiliser le menu
        userAbort = menu();
    }
    return 0;
}
