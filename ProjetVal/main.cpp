/* HALILA Nada - HU Lucas - ROY Jules */

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "headers/Station.hpp"
#include "headers/Rame.hpp"
#include "headers/Route.hpp"
#include "headers/fonctions_rames.hpp"
#include "headers/visible.hpp"
#include <iomanip>
#include <map>

#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define WHITE   "\033[37m"


using namespace std;
using namespace sf;

constexpr auto WINDOW_X = 1900; //largeur de la fenetre
constexpr auto WINDOW_Y = 900; //hauteur de la fenetre
constexpr auto WINDOW_NAME = "VAL"; //nom de la fenetre
constexpr auto FONT = "merienda.ttf"; //police d'ecriture
constexpr auto ICON = "icon.png"; //icone de la fenetre
constexpr auto DIST_STATIONS = 70;
const Color GREY(119, 136, 153);

//Clock clock1;


void affichage_joli(const string& titre, const map<string, int>& myMap) {
    // Affichage du titre
    cout <<string(30, '*') << RESET << endl;
    cout << setw(20) << titre << RESET << endl;
    cout <<string(30, '*') << RESET << endl << endl;

    // Affichage de la carte (map)
    for (const auto& entry : myMap) {
        string couleur = WHITE;  // Par défaut, couleur blanche

        // Vérifier si la ligne contient "ligne 1" ou "ligne 2"
        if (entry.first.find("Ligne 1") != string::npos) {
            couleur = YELLOW;  // Ligne 1 en jaune
        }
        else if (entry.first.find("Ligne 2") != string::npos) {
            couleur = RED;  // Ligne 2 en rouge
        }

        cout << couleur << setw(20) << entry.first << " : " << entry.second << RESET << endl;
    }
}

int main()
{
    //importation de l'icone
    Image icon;
    if (!icon.loadFromFile(ICON)) {
        return EXIT_FAILURE;
    }

    //importation de la police
    Font font;
    if (!font.loadFromFile(FONT)) {
        return -1;
    }

    //definition des carré de textes qui contiendront le nombre de passager dans les rames
    Text text;
    text.setFont(font);
    text.setCharacterSize(17); // Definir la taille du texte
    text.setFillColor(Color::White); // Definir la couleur du texte
    Text text2;
    text2.setFont(font);// Definir la police
    text2.setCharacterSize(17); // Definir la taille du texte
    text2.setFillColor(Color::White); // Definir la couleur du texte

    //definition des boutons (rectangles) qui permettent de repasser au mode de vue de toutes les rames
    RectangleShape affiche1(Vector2f(150, 50));
    affiche1.setPosition(50.0f, 150.0f);
    affiche1.setFillColor(Color::Yellow);
    RectangleShape affiche2(Vector2f(150, 50));
    affiche2.setPosition(600.0f, 150.0f);
    affiche2.setFillColor(Color::Red);
    string reset = "Reset";
    Text re1;
    Text re2;
    re1.setFont(font);
    re1.setCharacterSize(25);
    re1.setFillColor(Color::Black);
    re1.setPosition(95.0f, 160.0f);
    re1.setString(reset);
    re2.setFont(font);
    re2.setCharacterSize(25);
    re2.setFillColor(Color::Black);
    re2.setPosition(645.0f, 160.0f);
    re2.setString(reset);

    //definition des boutons (cercles) qui permettent d'avoir la vue sur une rame en particulier sur la L1
    CircleShape Rame1L1;
    Rame1L1.setRadius(10);
    Rame1L1.setPosition(280, 2);
    Rame1L1.setFillColor(Color::Yellow);
    CircleShape Rame2L1;
    Rame2L1.setRadius(10);
    Rame2L1.setPosition(280, 25);
    Rame2L1.setFillColor(Color::Yellow);
    CircleShape Rame3L1;
    Rame3L1.setRadius(10);
    Rame3L1.setPosition(280, 50);
    Rame3L1.setFillColor(Color::Yellow);
    CircleShape Rame4L1;
    Rame4L1.setRadius(10);
    Rame4L1.setPosition(280, 75);
    Rame4L1.setFillColor(Color::Yellow);
    CircleShape Rame5L1;
    Rame5L1.setRadius(10);
    Rame5L1.setPosition(280, 100);
    Rame5L1.setFillColor(Color::Yellow);
    CircleShape Rame6L1;
    Rame6L1.setRadius(10);
    Rame6L1.setPosition(280, 125);
    Rame6L1.setFillColor(Color::Yellow);

    //definition des boutons (cercles) qui permettent d'avoir la vue sur une rame en particulier sur la L2
    CircleShape Rame1L2;
    Rame1L2.setRadius(10);
    Rame1L2.setPosition(790, 2);
    Rame1L2.setFillColor(Color::Red);
    CircleShape Rame2L2;
    Rame2L2.setRadius(10);
    Rame2L2.setPosition(790, 25);
    Rame2L2.setFillColor(Color::Red);
    CircleShape Rame3L2;
    Rame3L2.setRadius(10);
    Rame3L2.setPosition(790, 50);
    Rame3L2.setFillColor(Color::Red);
    CircleShape Rame4L2;
    Rame4L2.setRadius(10);
    Rame4L2.setPosition(790, 75);
    Rame4L2.setFillColor(Color::Red);
    CircleShape Rame5L2;
    Rame5L2.setRadius(10);
    Rame5L2.setPosition(790, 100);
    Rame5L2.setFillColor(Color::Red);
    CircleShape Rame6L2;
    Rame6L2.setRadius(10);
    Rame6L2.setPosition(790, 125);
    Rame6L2.setFillColor(Color::Red);

    //definition des stations des lignes
    //L1
    int departL1X = 325; //coordonnees de la premiere station
    int departL1Y = 570; //coordonnees de la premiere station
    Station station1_begin(0, "Station Debut", departL1X += DIST_STATIONS, departL1Y, 0, Color::White, false, false);
    Station station1_1(1, "Station1", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, true, false);
    Station station1_2(2, "Station2", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_3(3, "Station3", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_4(4, "Station4", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_5(5, "Station5", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_6(6, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_7(7, "Station7", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_8(8, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_9(9, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_10(10, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_11(11, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_12(12, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_13(13, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_14(14, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_15(15, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_16(16, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_17(17, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, false, false);
    Station station1_18(18, "Station6", departL1X += DIST_STATIONS, departL1Y, 10, Color::Yellow, true, false);
    Station station1_end(8, "Station Fin", departL1X += DIST_STATIONS, departL1Y, 0, Color::White, false, false);

    //L2
    int departL2X = -25; //coordonnees de la premiere station
    int departL2Y = 500; //coordonnees de la premiere station
    Station station2_begin(0, "Station Debut", departL2X += DIST_STATIONS, departL2Y, 0, Color::White, false, false);
    Station station2_1(1, "Station1", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, true, false);
    Station station2_2(2, "Station2", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_3(3, "Station3", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_4(4, "Station4", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_5(5, "Station5", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_9(9, "Station9", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_10(10, "Station10", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_11(3, "Station3", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, true);
    Station station2_12(4, "Station3", departL2X, departL2Y += DIST_STATIONS, 10, Color::Red, false, false);
    Station station2_13(5, "Station6", departL2X, departL2Y += DIST_STATIONS, 10, Color::Red, false, true);
    Station station2_14(6, "Station7", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_15(7, "Station8", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_16(8, "Station9", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_17(1, "Station1", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, true);
    Station station2_18(2, "Station2", departL2X += DIST_STATIONS, departL2Y , 10, Color::Red, false, false);
    Station station2_19(3, "Station3", departL2X, departL2Y -= DIST_STATIONS, 10, Color::Red, false, true);
    Station station2_20(4, "Station4", departL2X , departL2Y -= DIST_STATIONS, 10, Color::Red, false, false);
    Station station2_21(5, "Station5", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_22(6, "Station6", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_23(7, "Station7", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_24(8, "Station8", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_25(9, "Station9", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, true);
    Station station2_26(1, "Station1", departL2X, departL2Y -= DIST_STATIONS, 10, Color::Red, false, false);
    Station station2_27(3, "Station3", departL2X, departL2Y -= DIST_STATIONS, 10, Color::Red, false, true);
    Station station2_28(4, "Station3", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_29(5, "Station6", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_30(6, "Station7", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_31(7, "Station8", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_32(8, "Station9", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_33(1, "Station1", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_34(2, "Station2", departL2X += DIST_STATIONS, departL2Y, 10, Color::Red, false, false);
    Station station2_end(45, "Station Fin", departL2X += DIST_STATIONS, departL2Y, 0, Color::White, false, false);

    //on regroupe les stations des lignes dans des tableau, chaque tableau vaut une ligne

    vector<Station> listeStationsL1 = { station1_begin, station1_1, station1_2, station1_3, station1_4, station1_5, station1_6, station1_7, station1_8, station1_9,station1_10, station1_11, station1_12, station1_13, station1_14,station1_15, station1_16, station1_17, station1_18,station1_end };
    vector<Station> listeRStationsL1 = listeStationsL1; //liste des stations de retour
    reverse(listeRStationsL1.begin(), listeRStationsL1.end()); //on inverse l'ordre des stations pour avoir les stations de retour

    vector<Station> listeStationsL2 = { station2_begin, station2_1, station2_2, station2_3, station2_4, station2_5, station2_9, station2_10, station2_11, station2_12, station2_13, station2_14, station2_15, station2_16, station2_17, station2_18, station2_19, station2_20, station2_21, station2_22, station2_23, station2_24, station2_25, station2_26, station2_27, station2_28, station2_29, station2_30, station2_31, station2_32, station2_33, station2_34, station2_end };
    vector<Station> listeRStationsL2 = listeStationsL2; //liste des stations de retour
    reverse(listeRStationsL2.begin(), listeRStationsL2.end()); //on inverse l'ordre des stations pour avoir les stations de retour

    vector<string> nom_station_L2 = { " ","lomme St Philibert","Bourg","Maison des Enfant","Pont Superieur","Lomme_Lambersant","Canteleu","Cormontainge","Montebello","Porte des Postes","Porte d'Arras","Porte de Douai","Porte de Valenciennes","Lille-Grand Palais","Bois Blancs","Mairie de Lille","Gare Lille Flandre" ,"Gare Lille Europe","ST-Maurcie Pellevoisin","Mons Sarts" ,"Maire de Mons","Fort de mons","Les Pres" ,"Jean Jaures","Wasquehal Hotel\n de Ville" ,"Croix-Centre","Epeule Montesquieu" ,"Roubaix Charles\n de Gaulle","Roubaix Grand Place" ,"Pontde Neuville","Bourgogne","CH Dron","" };
    vector<string> nom_station_L1 = {" ", "Lille-CHR \nB-Calmette","CHR Oscar\n Lambret","Porte des\n Postes","Wazemmes","Gambetta","Republique \nBeaux Arts","Rihour","Gare Lille Flandres","Caulier","Fives","Marberie","Hellemmes","Lezennes","Pont de Bois","Villeneuve d'Ascq \nHotel de Ville","Triolo","Cite Scientifique \nProfesseur Gabillard","4 Cantons",""};

    for (size_t i = 1; i < listeStationsL1.size()-1; i++)
    {
        listeStationsL1[i].set_nom(nom_station_L1[i-1]);
    }
    for (size_t i = 1; i < listeStationsL2.size() - 1; i++)
    {
        listeStationsL2[i].set_nom(nom_station_L2[i - 1]);
    }

    //definition des rames
    Rame rame1_1(station1_begin, 1,1,false, Color::Blue);
    Rame rame1_2(station1_begin, 2,1,false, Color::Blue);
    Rame rame1_3(station1_begin, 3,1,false, Color::Blue);
    Rame rame1_4(station1_end, 4,1,true, Color::Blue);
    Rame rame1_5(station1_end, 5,1,true, Color::Blue);
    Rame rame1_6(station1_end, 6,1,true, Color::Blue);
    Rame rame2_1(station2_begin, 7,2,false, GREY);
    Rame rame2_2(station2_begin, 8,2,false, GREY);
    Rame rame2_3(station2_begin, 9,2,false, GREY);
    Rame rame2_4(station2_end, 10,2,true, GREY);
    Rame rame2_5(station2_end, 11,2,true, GREY);
    Rame rame2_6(station2_end, 12,2,true, GREY);

    
    vector<Rame> tabRame_L1 = { rame1_1,rame1_2,rame1_3,rame1_4,rame1_5,rame1_6 }; //on regroupe les rames de la ligne 1 dans un tableau
    vector<Rame> tabRame_L2 = { rame2_1,rame2_2,rame2_3,rame2_4,rame2_5,rame2_6 }; //on regroupe les rames de la ligne 2 dans un tableau

    //creation des threads, il y a un thread pour chaque rame
    thread thread1_1(moveRame, ref(rame1_1), ref(rame1_6), ref(listeStationsL1), true, ref(tabRame_L1), ref(text));
    thread thread2_1(moveRame, ref(rame2_1), ref(rame2_6), ref(listeStationsL2), true, ref(tabRame_L2), ref(text2));
    thread thread1_4(moveRame, ref(rame1_4), ref(rame1_3), ref(listeRStationsL1), true, ref(tabRame_L1), ref(text));
    thread thread2_4(moveRame, ref(rame2_4), ref(rame2_3), ref(listeRStationsL2), true, ref(tabRame_L2), ref(text2));
    thread thread1_2(moveRame, ref(rame1_2), ref(rame1_1), ref(listeStationsL1), false, ref(tabRame_L1), ref(text));
    thread thread1_3(moveRame, ref(rame1_3), ref(rame1_2), ref(listeStationsL1), false, ref(tabRame_L1), ref(text));
    thread thread1_5(moveRame, ref(rame1_5), ref(rame1_4), ref(listeRStationsL1), false, ref(tabRame_L1), ref(text));
    thread thread1_6(moveRame, ref(rame1_6), ref(rame1_5), ref(listeRStationsL1), false, ref(tabRame_L1), ref(text));
    thread thread2_2(moveRame, ref(rame2_2), ref(rame2_1), ref(listeStationsL2), false, ref(tabRame_L2), ref(text2));
    thread thread2_3(moveRame, ref(rame2_3), ref(rame2_2), ref(listeStationsL2), false, ref(tabRame_L2), ref(text2));
    thread thread2_5(moveRame, ref(rame2_5), ref(rame2_4), ref(listeRStationsL2), false, ref(tabRame_L2), ref(text2));
    thread thread2_6(moveRame, ref(rame2_6), ref(rame2_5), ref(listeRStationsL2), false, ref(tabRame_L2), ref(text2));

    //creation et gestion de la fenetre
    RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), WINDOW_NAME);

    // Definir l'icone de la fenetre
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    int nb_suivie_l1 = 0;
    int nb_suivie_l2 = 0;

    int nb_urgence = 0;
    int nb_max_rame1L1 = 0;
    int nb_max_rame2L1 = 0;
    int nb_max_rame3L1 = 0;
    int nb_max_rame4L1 = 0;
    int nb_max_rame5L1 = 0;
    int nb_max_rame6L1 = 0;
    int nb_max_rame1L2 = 0;
    int nb_max_rame2L2 = 0;
    int nb_max_rame3L2 = 0;
    int nb_max_rame4L2 = 0;
    int nb_max_rame5L2 = 0;
    int nb_max_rame6L2 = 0;

    while (window.isOpen())
    {
        //gestion de la destruction de la fenetre
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
                string titre ="simulation  finis";
                map<string, int> myMap = {
                                            {"nombre de suivie ligne 1:",nb_suivie_l1},
                                            {"nombre de suivie ligne 2:",nb_suivie_l2},
                                            {"nombre d'arret d'urgence totale ", nb_urgence},
                                            {"nombre maximum de passaget attainte dans la rame 1 Ligne 1",nb_max_rame1L1},
                                            {"nombre maximum de passaget attainte dans la rame 2 Ligne 1",nb_max_rame2L1},
                                            {"nombre maximum de passaget attainte dans la rame 3 Ligne 1",nb_max_rame3L1},
                                            {"nombre maximum de passaget attainte dans la rame 4 Ligne 1",nb_max_rame4L1},
                                            {"nombre maximum de passaget attainte dans la rame 5 Ligne 1",nb_max_rame5L1},
                                            {"nombre maximum de passaget attainte dans la rame 6 Ligne 1",nb_max_rame6L1},
                                            {"nombre maximum de passaget attainte dans la rame 1 Ligne 2",nb_max_rame1L2},
                                            {"nombre maximum de passaget attainte dans la rame 2 Ligne 2",nb_max_rame2L2},
                                            {"nombre maximum de passaget attainte dans la rame 3 Ligne 2",nb_max_rame3L2},
                                            {"nombre maximum de passaget attainte dans la rame 4 Ligne 2",nb_max_rame4L2},
                                            {"nombre maximum de passaget attainte dans la rame 5 Ligne 2",nb_max_rame5L2},
                                            {"nombre maximum de passaget attainte dans la rame 6 Ligne 2",nb_max_rame6L2}

                                          };

                affichage_joli(titre, myMap);

                //cout <<"nombre d'arret d'urgence : "<< (int)(nb_urgence/2) << endl;
                //cout << "nombre de suivie ligne 1: " << nb_suivie_l1 << endl;
                //cout << "nombre de suivie linge 2: " << nb_suivie_l1 << endl;
                //cout << "nombre max dans la rame1L1: " << nb_max_rame1L1 << endl;
                //cout << "nombre max dans la rame2L1: " << nb_max_rame2L1 << endl;
                //cout << "nombre max dans la rame3L1: " << nb_max_rame3L1 << endl;
                //cout << "nombre max dans la rame4L1: " << nb_max_rame4L1 << endl;




            }
            //on gere les clics sur les boutons ou sur les rames
            nb_suivie_l1+= visible(rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6, event, window, Rame1L1, Rame2L1, Rame3L1, Rame4L1, Rame5L1, Rame6L1, affiche1); //on gere la visibilite des rames de la ligne 1
            nb_suivie_l2 += visible(rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6, event, window, Rame1L2, Rame2L2, Rame3L2, Rame4L2, Rame5L2, Rame6L2, affiche2); //on gere la visibilite des rames de la ligne 2
            nb_urgence +=arret_urgence_window(window, event, rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6, rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6); //on gere l'arret d'urgence pour chaque rame
        }

        window.clear(Color::Black); //couleur d'arriere plan

        clignotement_rame(rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6, rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6); //clignotement en cas d'arret d'urgence

        if (rame1_1.get_passagers()>nb_max_rame1L1)
        {
            nb_max_rame1L1 = rame1_1.get_passagers();
        }
        if (rame1_2.get_passagers() > nb_max_rame2L1)
        {
            nb_max_rame2L1 = rame1_2.get_passagers();
        }
        if (rame1_3.get_passagers() > nb_max_rame3L1)
        {
            nb_max_rame3L1 = rame1_3.get_passagers();
        }
        if (rame1_4.get_passagers() > nb_max_rame4L1)
        {
            nb_max_rame4L1 = rame1_4.get_passagers();
        }
        if (rame1_5.get_passagers() > nb_max_rame5L1)
        {
            nb_max_rame5L1 = rame1_5.get_passagers();
        }
        if (rame1_6.get_passagers() > nb_max_rame6L1)
        {
            nb_max_rame6L1 = rame1_6.get_passagers();
        }

        if (rame2_1.get_passagers() > nb_max_rame1L2)
        {
            nb_max_rame1L2 = rame2_1.get_passagers();
        }
        if (rame2_2.get_passagers() > nb_max_rame2L2)
        {
            nb_max_rame2L2 = rame2_2.get_passagers();
        }
        if (rame2_3.get_passagers() > nb_max_rame3L2)
        {
            nb_max_rame3L2 = rame2_3.get_passagers();
        }
        if (rame2_4.get_passagers() > nb_max_rame4L2)
        {
            nb_max_rame4L2 = rame2_4.get_passagers();
        }
        if (rame2_5.get_passagers() > nb_max_rame5L2)
        {
            nb_max_rame5L2 = rame2_5.get_passagers();
        }
        if (rame2_6.get_passagers() > nb_max_rame6L2)
        {
            nb_max_rame6L2 = rame2_6.get_passagers();
        }

        //partie affichage des stations et des routes
        for (int i = 0; i < listeStationsL1.size(); i++) { //pour la L1
            listeStationsL1[i].setRepr(); //on set la representation de la station en cours
            if (i != listeStationsL1.size() - 1) { //la derniere station ne peut avoir de route a sa droite
                if (i == 0 || i == listeStationsL1.size() - 2) {
                    Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on cree une route de cette station e la suivante
                    Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on cree une route de retour
                    route.setRepr(); //on set la representation de la route
                    route_r.setReprRetour(); //on set la representation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour

                }
                else {
                    Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Yellow); //on cree une route de cette station a la suivante
                    Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Yellow); //on cree une route de retour
                    route.setRepr(); //on set la representation de la route
                    route_r.setReprRetour(); //on set la representation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour

                }
            }

            //on affiche le nombre de passager dans chaque rame de la ligne 1
            updateRameText(text, tabRame_L1, rame1_1, 0, 0);
            updateRameText(text, tabRame_L1, rame1_2, 0, 0);
            updateRameText(text, tabRame_L1, rame1_3, 0, 0);
            updateRameText(text, tabRame_L1, rame1_4, 0, 0);
            updateRameText(text, tabRame_L1, rame1_5, 0, 0);
            updateRameText(text, tabRame_L1, rame1_6, 0, 0);
            Text text_S;
            text_S.setFont(font);
            text_S.setCharacterSize(15);
            text_S.setFillColor(Color::White);
            //text_S.setPosition(listeStationsL1[i].getPositionX()+5, listeStationsL1[i].getPositionY() + 30);
            if (i<3 || i>=8)
            {
                text_S.setRotation(45.0f);
                text_S.setPosition(listeStationsL1[i].getPositionX() + 5, listeStationsL1[i].getPositionY() + 15);
            }
            if(i>=3 && i<8)
            {
                text_S.setRotation(295.0f);
                text_S.setPosition(listeStationsL1[i].getPositionX() + 5, listeStationsL1[i].getPositionY() - 20);
            }
            text_S.setString(nom_station_L1[i]);
            window.draw(listeStationsL1[i].getRepr());//on dessine la station
            window.draw(text_S);
        }

        for (int i = 0; i < listeStationsL2.size(); i++) { //pour la L2
            listeStationsL2[i].setRepr(); //on set la representation de la station en cours
            if (i != listeStationsL2.size() - 1) { //la derniere station ne peut avoir de route a sa droite
                if (i == 0 || i == listeStationsL2.size() - 2) {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on cree une route de cette station a la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on cree une route de retour
                    route.setRepr(); //on set la representation de la route
                    route_r.setReprRetour(); //on set la representation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
                else {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Red); //on cree une route de cette station a la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Red); //on cree une route de retour
                    route.setRepr(); //on set la representation de la route
                    route_r.setReprRetour(); //on set la representation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
            }

            //on affiche le nombre de passager dans chaque rame de la ligne 2
            updateRameText(text2, tabRame_L2, rame2_1, 500, 0);
            updateRameText(text2, tabRame_L2, rame2_2, 500, 0);
            updateRameText(text2, tabRame_L2, rame2_3, 500, 0);
            updateRameText(text2, tabRame_L2, rame2_4, 500, 0);
            updateRameText(text2, tabRame_L2, rame2_5, 500, 0);
            updateRameText(text2, tabRame_L2, rame2_6, 500, 0);
            Text text_S1;
            text_S1.setFont(font);
            text_S1.setCharacterSize(15);
            text_S1.setFillColor(Color::White);
            if ((i >= 10 && i < 16))
            {
                text_S1.setRotation(45.0f);
                text_S1.setPosition(listeStationsL2[i].getPositionX() + 5, listeStationsL2[i].getPositionY() + 15);
                text_S1.setString(nom_station_L2[i]);
            }

            if ((i <= 8)||(i>=17 && i<22)||i>=24)
            {
                text_S1.setRotation(295.0f);
                text_S1.setPosition(listeStationsL2[i].getPositionX() + 5, listeStationsL2[i].getPositionY() - 20);
                text_S1.setString(nom_station_L2[i]);
            }

            if ((i >= 22 && i < 24))
            {
                text_S1.setRotation(0.0f);
                text_S1.setPosition(listeStationsL2[i].getPositionX() + 20, listeStationsL2[i].getPositionY()-10);
                text_S1.setString(nom_station_L2[i]);
            }


            window.draw(listeStationsL2[i].getRepr());//on dessine la station
            window.draw(text_S1);
        }

        //on affiche le nombre de passager dans chaque rame de la ligne 1 et 2
        window.draw(text);
        window.draw(text2);

        //if (rame1_1.get_arret_urgence()) {
        //    if (clock1.getElapsedTime().asSeconds() >= 1.0f) {
        //        // Alternez entre jaune et orange
        //        if (rame1_1.getColor() == Color::Blue) {
        //            cout << "orange" << endl;
        //            rame1_1.setColor(Color(255, 165, 0));  // Orange
        //            rame1_1.setRepr(); //maj de l'element
        //        }
        //        else {
        //            cout << "bleu" << endl;
        //            rame1_1.setColor(Color::Blue);
        //            rame1_1.setRepr(); //maj de l'element
        //        }
        //        // Réinitialisez la minuterie
        //        clock1.restart();
        //    }
        //}
        //else {
        //    rame1_1.setColor(Color::Blue);
        //    rame1_1.setRepr(); //maj de l'element
        //}

        //on affiche les rames de la ligne 1 et 2 en fonction de leur visibilite
        affichage(rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6, window);
        affichage(rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6, window);

        //on affiche les boutons de gestion de visibilite des rames de la ligne 1
        window.draw(Rame1L1);
        window.draw(Rame2L1);
        window.draw(Rame3L1);
        window.draw(Rame4L1);
        window.draw(Rame5L1);
        window.draw(Rame6L1);

        //on affiche les boutons de gestion de visibilite des rames de la ligne 2
        window.draw(Rame1L2);
        window.draw(Rame2L2);
        window.draw(Rame3L2);
        window.draw(Rame4L2);
        window.draw(Rame5L2);
        window.draw(Rame6L2);

        //on affiche les boutons de reset de la visibilite des rames de la ligne 1 et 2
        window.draw(affiche1);
        window.draw(re1);
        window.draw(affiche2);
        window.draw(re2);

        window.display(); //affichage de la fenetre

    }

    //destruction des threads
    thread1_1.join();
    thread1_2.join();
    thread1_3.join();
    thread1_4.join();
    thread1_5.join();
    thread1_6.join();
    thread2_1.join();
    thread2_2.join();
    thread2_3.join();
    thread2_4.join();
    thread2_5.join();
    thread2_6.join();


    return 0;
}