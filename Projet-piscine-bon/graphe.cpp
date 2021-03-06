#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>//pour to_string
#include <tgmath.h>
#include <math.h>
#include <windows.h>

#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
#include "utile.h"
#include "Svgfile.h"

///CONSTRUCTEUR
///
Graphe::Graphe(std::string nomFichier)
{
    chargeGraphe(nomFichier);
}

Graphe::Graphe(const Graphe &grapheACopier)
{
    m_ordre = grapheACopier.get_ordre();
    m_orient = grapheACopier.get_orient();
    m_taille = grapheACopier.get_taille();

    std::vector<Sommet*> tmpS(m_ordre);// taille m_ordre pour tabSommet
    m_tabSommet = tmpS;
    std::vector<Sommet*> tabSomACopier = grapheACopier.get_tabSommet();
    for(int i = 0; i < m_ordre; i++)
    {
        Sommet* newSommet = new Sommet(*(tabSomACopier[i])); // Sommet newSomme = *monSommet
        m_tabSommet[i] = newSommet;
    }
    std::vector<Arete*> tmpA(m_taille);// taille m_ordre pour tabSommet
    m_tabArete = tmpA;
    std::vector<Arete*> tabAreteACopier = grapheACopier.get_tabArete();
    for(int i = 0; i < m_taille; i++)
    {
        Sommet* sommet1;
        Sommet* sommet2;
        for(auto s: m_tabSommet)
        {
            if (s->get_idSommet() == tabAreteACopier[i]->get_idS1())
                sommet1 = s;
            else if (s->get_idSommet() == tabAreteACopier[i]->get_idS2())
                sommet2 = s;
        }
        Arete* newArete = new Arete(*(tabAreteACopier[i]), sommet1, sommet2);
        m_tabArete[i] = newArete;
    }
}

Graphe::~Graphe()
{
    for (auto a : m_tabArete)
        delete a;
    for (auto s : m_tabSommet)
        delete s;
}
///GET
bool Graphe::get_orient()const
{
    return m_orient;
}

int Graphe::get_ordre()const
{
    return m_ordre;
}

int Graphe::get_taille()const
{
    return m_taille;
}

std::vector<Arete*> Graphe::get_tabArete()const
{
    return m_tabArete;
}

std::vector<Sommet*> Graphe::get_tabSommet()const
{
    return m_tabSommet;
}

void Graphe::afficherTabS()
{
    for(auto elem: m_tabSommet){
        elem->afficher();
        std::cout << std::endl;
    }
}
void Graphe::afficherTabA()
{
    for(auto elem: m_tabArete){
        elem->afficher();
        std::cout << std::endl;
    }
}

void Graphe::afficher()///afficher les donn�es d'un bloc pour debug
{
    std::cout<<"Graphe ";
    if(m_orient)
        std::cout<<"oriente"<<std::endl;
    else
        std::cout<< "non oriente"<<std::endl;
    std::cout<< "ordre = " <<m_ordre<<std::endl;// nb sommets
    afficherTabS();
    std::cout<< "taille =" <<m_taille<<std::endl;
    afficherTabA();

}

///PARSING
void Graphe::chargeGraphe(std::string nomFichier)
{
    try
    {
        std::vector<std::string> tabLigne;//tab dynamique constitu� des lignes de donn�es du le fichier
        std::ifstream fichier(nomFichier);//ouverture du fichier

        if(!fichier)//TEST ouverture de fichier
        {
            std::cout<<"Erreur ouverture du fichier"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else//le fichier s'est bien charge et peut etre lu
        {
            std::cout<<"Chargement fichier: OK"<<std::endl;
            std::string tmpStr;
            while(std::getline(fichier, tmpStr))//recup info du fichier ligne par ligne
            {
                tabLigne.push_back(tmpStr);//recup infos dans tabline
            }
            m_orient = std::stoi(tabLigne[0]);// stoi pour transformer le string to int
            m_ordre = std::stoi(tabLigne[1]);
            for(int i = 2; i <= 1 + m_ordre; i++)//ajoute les sommets dans tabSommet
            {
                ajoutSommet(tabLigne[i]);//cr�er le nombre d'arete (n-1)
            }
            m_taille = std::stoi(tabLigne[2+m_ordre]);// recup taille pour tabArete
            //std::vector<Arete*> temp(m_taille);
            //m_tabArete = temp;
            for(int i=3+m_ordre;i<=2+m_ordre+m_taille;i++)//ajoute les arretes dans tabArete
            {
                ajoutArete(tabLigne[i]);
            }
            std::cout<< "Graphe termine"<< std::endl;
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }

}
void Graphe::chargePonderation(std::string fichierPonderation)
{
    try
    {
        std::vector<std::string> tabLigne;//tab dynamique constitu� des lignes de donn�es du le fichier
        std::ifstream fichier(fichierPonderation);//ouverture du fichier
        int taille;

        if(!fichier)//TEST ouverture de fichier
        {
            std::cout<<"Erreur ouverture du fichier"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else//le fichier s'est bien charg� et peut etre lu
        {
            std::cout<<"Chargement fichier: OK"<<std::endl;
            std::string tmpStr;
            while(std::getline(fichier, tmpStr))//recup info du fichier ligne par ligne
            {
                tabLigne.push_back(tmpStr);//recup infos dans tabline
            }
            taille = std::stoi(tabLigne[0]);// recup taille pour tabArete
            if(taille!=m_taille)
            {
                 std::cout<<"Erreur : La taille est differente. Fichier non charge"<<std::endl;
                 return;
            }
            for(int i=1;i<=m_taille;i++)//ajoute les arretes dans tabArete
            {
                ajouterPonderation(tabLigne[i]);
            }
            std::cout<< "Ponderation terminee"<< std::endl;
        }

    }
    catch(const std::exception&e)
    {
            std::cerr<<"Attention: "<<e.what()<<std::endl;
    }
}
///AJOUT D'OBJETS
void Graphe::ajoutArete(std::string ligne)
{
    //split
    std::vector<std::string> recupLigneSplit=split(ligne, ' ');
    int index = std::stoi(recupLigneSplit[0]);//on transforme une string en int grace a stoi (string to int)
    int indexSom1 = std::stoi(recupLigneSplit[1]);
    int indexSom2 = std::stoi(recupLigneSplit[2]);
    Sommet* sommet1;
    Sommet* sommet2;
    for(auto s: m_tabSommet)
    {
        if (s->get_idSommet() == indexSom1)
            sommet1 = s;
        else if (s->get_idSommet() == indexSom2)
            sommet2 = s;
    }

    Arete* newArete = new Arete(index, sommet1, sommet2);
    m_tabArete.push_back(newArete);//tableau de Arete* (pointeur sur aretes)
}

void Graphe::ajoutSommet(std::string ligne)
{
    std::vector<std::string> recupLigneSplit = split(ligne, ' ');
    //4 var pour les 4 attributs du constructeurs
    int index = std::stoi(recupLigneSplit[0]);
    std::string nom = recupLigneSplit[1];
    int coord_x = std::stoi(recupLigneSplit[2]);
    int coord_y = std::stoi(recupLigneSplit[3]);

    Sommet* newSommet = new Sommet(index, nom ,coord_x,coord_y);
    m_tabSommet.push_back(newSommet);//car tab de som
}
void Graphe::ajouterPonderation(std::string lignePond)
{
    std::vector<std::string> recupLigneSplit=split(lignePond, ' ');
    int index = std::stoi(recupLigneSplit[0]);
    int poids = std::stoi(recupLigneSplit[1]);

    for(auto a: m_tabArete)
    {
        if (a->get_idArete() == index)
        {
            a->set_poids(poids);
            break;
        }
    }
}

///DESSIN
void Graphe::dessiner(std::string fileName)
{
    Svgfile svgout(fileName);
    for(int i=0;i<m_taille;i++)
    {
        Arete* a = m_tabArete[i];
        double x1 = a->get_s1()->get_coordx();
        double x2 = a->get_s2()->get_coordx();
        double y1 = a->get_s1()->get_coordy();
        double y2 = a->get_s2()->get_coordy();

        svgout.addLine(x1 *100, y1 *100,x2 *100, y2*100, "rgb(255,200,200)"/*a->get_color()*/);
        svgout.addId(((x1 + x2 )/2)*100, ((y1 + y2 )/2) *100,std::to_string(a->get_idArete()),a->get_couleurA());//attention int converti en string par to_string
        // on ecrit l'idArete au milieu de l'arete
    }
    for(int i=0;i<m_ordre;i++)
    {
        Sommet* s = m_tabSommet[i];
        svgout.addDisk(s->get_coordx() *100,s->get_coordy() *100, 20, s->get_couleurS());
        svgout.addId(s->get_coordx() *100, s->get_coordy() *100,s->get_nom(),"pink");
    }
    std::cout << "Creation du graphe au format svg (" << svgout.get_filename() << ") termine" << std::endl;
}

void Graphe::dessinerGICDN(std::string fileName)
{
    Svgfile svgout(fileName);
    for(int i=0;i<m_taille;i++)
    {
        Arete* a = m_tabArete[i];
        double x1 = a->get_s1()->get_coordx();
        double x2 = a->get_s2()->get_coordx();
        double y1 = a->get_s1()->get_coordy();
        double y2 = a->get_s2()->get_coordy();

        svgout.addLine(x1 *100, y1 *100,x2 *100, y2*100, "rgb(255,200,200)"/*a->get_color()*/);
        svgout.addId(((x1 + x2 )/2)*100, ((y1 + y2 )/2) *100,std::to_string(a->get_idArete()),a->get_couleurA());//attention int converti en string par to_string

    }
    for(int i=0;i<m_ordre;i++)
    {
        Sommet* s = m_tabSommet[i];
        std::ostringstream oss;//creation d'un flux de transfert pour mettre float dans string
        std::string indiceC;
        oss<<s->get_indiceDegreNorm();
        indiceC = oss.str();

        svgout.addDisk(s->get_coordx() *100,s->get_coordy() *100, 20, s->get_couleurIDN());//sommet degrade
        svgout.addId(s->get_coordx() *105, s->get_coordy() *105,indiceC,"purple");
        //valeurs de centralité affichées à coté des Sommets
    }
    std::cout << " Dessin du graphe avec centralite de degre apparente "<<std::endl;
    std::cout << "Creation du graphe au format svg (" << svgout.get_filename() << ") terminee" << std::endl;
}
void Graphe::dessinerGIVPN(std::string fileName)
{

    Svgfile svgout(fileName);
    for(int i=0;i<m_taille;i++)
    {
        Arete* a = m_tabArete[i];
        double x1 = a->get_s1()->get_coordx();
        double x2 = a->get_s2()->get_coordx();
        double y1 = a->get_s1()->get_coordy();
        double y2 = a->get_s2()->get_coordy();

        svgout.addLine(x1 *100, y1 *100,x2 *100, y2*100, "rgb(255,200,200)"/*a->get_color()*/);
        svgout.addId(((x1 + x2 )/2)*100, ((y1 + y2 )/2) *100,std::to_string(a->get_idArete()),a->get_couleurA());
        // on ecrit l'idArete au milieu de l'arete
    }
    for(int i=0;i<m_ordre;i++)
    {
        Sommet* s = m_tabSommet[i];
        svgout.addDisk(s->get_coordx() *100,s->get_coordy() *100, 20, s->get_couleurIVPN());//sommet degrade
        std::cout <<s->get_couleurIVPN()<<std::endl;
        svgout.addId(s->get_coordx() *100, s->get_coordy() *100,s->get_nom(),"pink");
    }
    std::cout << " Dessin du graphe avec vecteurs propres apparents normalises "<<std::endl;
    std::cout << "Creation du graphe au format svg (" << svgout.get_filename() << ") terminee" << std::endl;
}

void Graphe::dessinerGIPN(std::string fileName)
{
    Svgfile svgout(fileName);
    for(int i=0;i<m_taille;i++)
    {
        Arete* a = m_tabArete[i];
        double x1 = a->get_s1()->get_coordx();
        double x2 = a->get_s2()->get_coordx();
        double y1 = a->get_s1()->get_coordy();
        double y2 = a->get_s2()->get_coordy();

        svgout.addLine(x1 *100, y1 *100,x2 *100, y2*100, "rgb(255,200,200)");
        svgout.addId(((x1 + x2 )/2)*100, ((y1 + y2 )/2) *100,std::to_string(a->get_idArete()),a->get_couleurA());
    }
    for(int i=0;i<m_ordre;i++)
    {
        Sommet* s = m_tabSommet[i];
        svgout.addDisk(s->get_coordx() *100,s->get_coordy() *100, 20, s->get_couleurIPN());//sommet degradé
        std::cout <<s->get_couleurIDN()<<std::endl;
        svgout.addId(s->get_coordx() *100, s->get_coordy() *100,s->get_nom(),"pink");
    }
    std::cout << " Dessin du graphe avec indices de proximite normalises "<<std::endl;
    std::cout << "Creation du graphe au format svg (" << svgout.get_filename() << ") terminee" << std::endl;
}

void Graphe::commencerIndiceDeCentralite()
{
    for (auto s : m_tabSommet)
    {
        s->calculeIndiceCentraliteDegres(m_ordre);
    }
}

void Graphe::commencerIndiceDeProximite()
{
    float sommeLongueurPCC;
    for (auto sDebut : m_tabSommet)
    {
        sommeLongueurPCC = 0;
        for (auto sFin: m_tabSommet)
        {
            if(sFin != sDebut)
                sommeLongueurPCC += (float)dijkstra(sDebut, sFin, this);
        }
        sDebut->set_indiceProximite(1 / sommeLongueurPCC);
        sDebut->set_indiceProximiteNorm( (m_ordre - 1) / sommeLongueurPCC);

    }
}

bool Graphe::supprimerArete(int areteChoisie)
{
    Arete* arete;
    for(int i=0; i<m_taille;i++)
    {
        if(m_tabArete[i]->get_idArete() == areteChoisie)
        {
            arete = m_tabArete[i];//on attribue à arete cette reference i precise


            m_tabArete.erase(m_tabArete.begin()+i);//efface les ref de arete car tableau d'adresse d'aretes

            m_taille = m_taille - 1 ;//mise a jour de la taille du tableau
            Sommet* s1 = m_tabArete[i]->get_s1();
            Sommet* s2 = m_tabArete[i]->get_s2();
            s1->enleveA(m_tabArete[i]);//on efface les ref de Arete dans sommet
            s2->enleveA(m_tabArete[i]);//car tabAreteSo dans Sommet

            delete(arete);// destruction finale de l'objet arete i
            std::cout<<"L'arete ";
            m_tabArete[i]->afficher();
            std::cout<<" a bien ete suprimee"<<std::endl;
            return true;
        }
    }
    return false;
}
// permet de lancer le caclul du vecteur propre dans le main
void Graphe::commencerVecteurPropre()  // non normalisé divisé non divisé par lambda
{
    float lambda = 0;
    float lambda_avant = 0; // pour calculer le delta lambda
    for (auto s: m_tabSommet)
        s->set_indiceVecteurPropre(1); // on initilialise à 1
    do
    {
        for (auto s : m_tabSommet)
            s->set_sommeIVPVoisins();// somme des indices des des voisins

        lambda_avant = lambda;
        lambda= 0;

        for (auto s : m_tabSommet)
        {
            lambda += s->get_sommeIVPVoisins() * s->get_sommeIVPVoisins(); // on calcule le lambda
        }
        lambda = std::sqrt(lambda); // on calcule la racine

        for(auto s : m_tabSommet)
            s->set_indiceVecteurPropre(s->get_sommeIVPVoisins()/ lambda); //on obtient le nouvel indice pour recommencer la branche

    } while(std::abs(lambda_avant - lambda) > 0.01); // on regarde la variation ( delta ) du lambda tant qu elle ne varie paq trop

   }


void Graphe::lancerLesIndices(std::string nomFichier) // permet de lancer l'affichage simultané de tous les indices dans le main pour chaque sommet et de sauvegarder dans un fichier
{
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE); // couleur

    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;

    // on lance les methodes
    commencerIndiceDeProximite();
    commencerVecteurPropre();
    commencerIndiceDeCentralite();
    // données pour la sauvegarde des indices dans un fichier
    std::string indiceSauv;
    std::ostringstream oss; //flux


    // boucle pour etudier tout les sommets
    for(auto s : m_tabSommet)
    {
        SetConsoleTextAttribute(console, 15);// couleurs

        std::cout << "Sommet " <<s->get_nom() << ": "<< std::endl; // affiche le nom du sommet
        std::cout<<""<<std::endl;
        SetConsoleTextAttribute(console, 13);// couleur
        std::cout<< "Indice vecteur Propre non-normalise "<< s->get_sommeIVPVoisins () <<std::endl;  // indice vecteur propre non-normalise
        SetConsoleTextAttribute(console, 10);// couleur
        std::cout <<"Indice Vecteur Propre normalise "<< s->get_indiceVecteurPropre() << std::endl; // indice vecteur  propre normalise
        SetConsoleTextAttribute(console, 11); // couleur
        std::cout << "Indice de proximite non-normalise"  << ": " << s->get_indiceProximite() <<std::endl // indice de proximite non normalise
        SetConsoleTextAttribute(console, 1); // couleur
        std::cout<< "Indice de proximite Normalise " << s->get_indiceProximiteNorm() << std::endl;// indice de proximite normalise
        SetConsoleTextAttribute(console, 14);// couleur
        std::cout << "Indice de centralite non-normalise: " << s->get_indiceDegre() << std::endl;// indice de centralite non normalise
        SetConsoleTextAttribute(console, 12); //couleur
        std::cout << "Indice de centralite normalise : " << s->get_indiceDegreNorm() << std::endl; // indice de centralite normalise
        SetConsoleTextAttribute(console, 15); //couleur

        std::cout<<""<<std::endl;
        std::cout<<""<<std::endl;

        // sauvegarde des indices dans le fichier

       oss<< s->get_nom() <<" "<< s->get_sommeIVPVoisins()<< " " << s->get_indiceVecteurPropre()<< s->get_indiceProximite()<<" "<<s->get_indiceProximiteNorm()<<" "<<s->get_indiceDegre()<<" "<<s->get_indiceDegreNorm()<<std::endl;

    }

    indiceSauv = oss.str();
    sauvegardeDansFichier(nomFichier, indiceSauv);
}

bool Graphe::test_connexite(Sommet* sommetActuel) //valeur par defaut lorsqu'on lance le test
{
    sommetActuel->afficher();

    if (sommetActuel->get_connexite()) //true si sommet deja visite
        return false;
    sommetActuel->set_connexite(true);
    for(auto a: sommetActuel->get_tabArete())
    {
        test_connexite(a->get_autreSommet(sommetActuel));
    }
    if (sommetActuel != m_tabSommet[0])
        return true;
    for (auto s: m_tabSommet)
    {
        if (s->get_connexite() == false) //si il n'a pas ete visite
        {
            return false;
        }
    }
    return true;
}

void Graphe::reinitialiseConnexite()
{
    for(auto s: m_tabSommet)
    {
        s->set_connexite(false);
    }
}

void Graphe::calcCouleurG()
{
// calcul couleur du sommet pour l'indice de centralité degré (prend le normalisé c'est plus simple)
    float iDNMax =0;
    float iVPMax = 0;
    float proxMax = 0;
    float calcIDN;
    float calcIVP;
    float calcIPN;

    for(auto s: m_tabSommet) //on obtient le min et le max
    {
        if(s->get_indiceDegreNorm()> iDNMax)
        {
            iDNMax = s->get_indiceDegreNorm();
        }
        if(s->get_indiceVecteurPropre()> iVPMax)
        {
            iVPMax = s->get_indiceVecteurPropre();
        }
        if(s->get_indiceProximiteNorm()> proxMax)
        {
            proxMax = s->get_indiceProximiteNorm();
        }

    }
    for(auto s: m_tabSommet)
    {
        //calcul des couleurs des indices
        calcIDN = (s->get_indiceDegreNorm() *255)/iDNMax;
        calcIVP = (s->get_indiceVecteurPropre() *255)/iVPMax;
        calcIPN = (s->get_indiceProximiteNorm() *255)/proxMax;

        //recup des valeurs calc et mis dans une string pour chaque type d'affichage de comparaison d'indices
        std::ostringstream oss;
        std::string couleurIDN;
        std::cout << calcIDN<< std::endl;
        oss<<"rgb("<<calcIDN<<",0,0)";
        couleurIDN = oss.str();

        s->set_couleurIDN(couleurIDN);
        oss.str("");
        oss.clear();//on vide le flux pour pouvoir le remplir a nouveau

        std::string couleurIVP;
        oss<<"rgb(0,"<<calcIVP<<",0)";
        couleurIVP = oss.str();

        s->set_couleurIVP(couleurIVP);
        oss.str("");
        oss.clear();

        std::string couleurIPN;
        oss<<"rgb(0,0,"<<calcIPN<<")";
        couleurIPN = oss.str();

        s->set_couleurIPN(couleurIPN);
        oss.str("");
        oss.clear();
    }
}
