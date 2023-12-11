#include <iostream>
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Station.hpp"
#include "Rame.hpp"
#include "Route.hpp"
#include "fonction_rames.hpp"
#include "visible.hpp"

using namespace std;
using namespace sf;

#define WINDOW_X 1900 //largeur de la fen�tre
#define WINDOW_Y 900 //hauteur de la fen�tre
#define WINDOW_NAME "VAL" //nom de la fen�tre
#define FONT "merienda.ttf"
#define ICON "icon.png"
bool arret_urgence = false;

int main() {
    Font font;
    if (!font.loadFromFile(FONT)) {
        // Gestion de l'erreur si la police ne peut pas �tre charg�e
        return -1;
    }
    Text text;
    text.setFont(font);
    Text text2;
    text2.setFont(font);// D�finir la police
    text2.setCharacterSize(17); // D�finir la taille du texte

    text2.setFillColor(Color::White); // D�finir la couleur du texte

    text.setCharacterSize(17); // D�finir la taille du texte
    text.setFillColor(Color::White); // D�finir la couleur du texte

    //DESSAIN D4UN RECTANGLE POUR TOUS AFFICHER
    RectangleShape  affiche1(Vector2f(150,50));
    affiche1.setPosition(100.0f, 150.0f);
    affiche1.setFillColor(Color::Yellow);

    RectangleShape  affiche2(Vector2f(150, 50));
    affiche2.setPosition(600.0f, 150.0f);
    affiche2.setFillColor(Color::Red);

    string reset = "Reset";
    Text re1;
    Text re2;

    re1.setFont(font);
    re1.setCharacterSize(25);
    re1.setFillColor(Color::Black);
    re1.setPosition(145.0f, 160.0f);
    re1.setString(reset);

    re2.setFont(font);
    re2.setCharacterSize(25);
    re2.setFillColor(Color::Black);
    re2.setPosition(645.0f, 160.0f);
    re2.setString(reset);

    //DESSAIN DES POINT L1
    CircleShape Rame1L1;
    Rame1L1.setRadius(10);
    Rame1L1.setPosition(355,2);
    Rame1L1.setFillColor(Color::Yellow);
    CircleShape Rame2L1;
    Rame2L1.setRadius(10);
    Rame2L1.setPosition(355, 25);
    Rame2L1.setFillColor(Color::Yellow);
    CircleShape Rame3L1;
    Rame3L1.setRadius(10);
    Rame3L1.setPosition(355, 50);
    Rame3L1.setFillColor(Color::Yellow);
    CircleShape Rame4L1;
    Rame4L1.setRadius(10);
    Rame4L1.setPosition(355, 75);
    Rame4L1.setFillColor(Color::Yellow);
    CircleShape Rame5L1;
    Rame5L1.setRadius(10);
    Rame5L1.setPosition(355, 100);
    Rame5L1.setFillColor(Color::Yellow);
    CircleShape Rame6L1;
    Rame6L1.setRadius(10);
    Rame6L1.setPosition(355, 125);
    Rame6L1.setFillColor(Color::Yellow);

    //DESSAIN DES POINTS L2
    CircleShape Rame1L2;
    Rame1L2.setRadius(10);
    Rame1L2.setPosition(855, 2);
    Rame1L2.setFillColor(Color::Red);
    CircleShape Rame2L2;
    Rame2L2.setRadius(10);
    Rame2L2.setPosition(855, 25);
    Rame2L2.setFillColor(Color::Red);
    CircleShape Rame3L2;
    Rame3L2.setRadius(10);
    Rame3L2.setPosition(855, 50);
    Rame3L2.setFillColor(Color::Red);
    CircleShape Rame4L2;
    Rame4L2.setRadius(10);
    Rame4L2.setPosition(855, 75);
    Rame4L2.setFillColor(Color::Red);
    CircleShape Rame5L2;
    Rame5L2.setRadius(10);
    Rame5L2.setPosition(855, 100);
    Rame5L2.setFillColor(Color::Red);
    CircleShape Rame6L2;
    Rame6L2.setRadius(10);
    Rame6L2.setPosition(855, 125);
    Rame6L2.setFillColor(Color::Red);



    CircleShape legende_retour;
    legende_retour.setRadius(20);
    legende_retour.setPosition(175 - 15, 850 - 15);
    legende_retour.setFillColor(Color::White);
    RectangleShape legende_route;
    legende_route.setSize(Vector2f(75, 8));
    legende_route.setPosition(300, 850);
    legende_route.setFillColor(Color::Yellow);

    //STATIONS (id, nom, position x, position y, nombre de passagers, couleur)
    //L2
    Station station2_begin(0, "Station Debut", 50, 300, 0, Color::White, false);
    Station station2_1(1, "Station1", 100, 300, 10, Color::Red, true);
    Station station2_2(2, "Station2", 300, 300, 10, Color::Red, false);
    Station station2_3(3, "Station3", 500, 300, 10, Color::Red, true);
    Station station2_4(4, "Station4", 700, 300, 10, Color::Red, false);
    Station station2_5(5, "Station5", 900, 300, 10, Color::Red, false);
    Station station2_6(6, "Station6", 1100, 300, 10, Color::Red, true);
    Station station2_end(7, "Station Fin", 550, 300, 0, Color::White, false);

    //L1
    Station station1_begin(0, "Station Debut", 50, 600, 0, Color::White, false);
    Station station1_1(1, "Station1", 141, 600, 10, Color::Yellow, true);
    Station station1_2(2, "Station2", 232, 600, 10, Color::Yellow, false);
    Station station1_3(3, "Station3", 323, 600, 10, Color::Yellow, false);
    Station station1_4(4, "Station4", 414, 600, 10, Color::Yellow, false);
    Station station1_5(5, "Station5", 505, 600, 10, Color::Yellow, false);
    Station station1_6(6, "Station6", 596, 600, 10, Color::Yellow, false);
    Station station1_7(7, "Station7", 687, 600, 10, Color::Yellow, false);
    Station station1_8(8, "Station6", 778, 600, 10, Color::Yellow, false);
    Station station1_9(9, "Station6", 869, 600, 10, Color::Yellow, false);
    Station station1_10(10, "Station6", 960, 600, 10, Color::Yellow, false);
    Station station1_11(11, "Station6", 1051, 600, 10, Color::Yellow, false);
    Station station1_12(12, "Station6", 1142, 600, 10, Color::Yellow, false);
    Station station1_13(13, "Station6", 1233, 600, 10, Color::Yellow, false);
    Station station1_14(14, "Station6", 1324, 600, 10, Color::Yellow, false);
    Station station1_15(15, "Station6", 1415, 600, 10, Color::Yellow, false);
    Station station1_16(16, "Station6", 1506, 600, 10, Color::Yellow, false);
    Station station1_17(17, "Station6", 1597, 600, 10, Color::Yellow, false);
    Station station1_18(18, "Station6", 1688, 600, 10, Color::Yellow, true);

    Station station1_end(8, "Station Fin", 1779, 600, 0, Color::White, false);
    //on regroupe les stations des lignes dans des tableau, chaque tableau vaut une ligne
    vector<Station> listeStationsL2 = { station2_begin, station2_1, station2_2, station2_3, station2_end };
    vector<Station> listeRStationsL2 = listeStationsL2;

    reverse(listeRStationsL2.begin(), listeRStationsL2.end());
    vector<Station> listeStationsL1 = { station1_begin, station1_1, station1_2, station1_3, station1_4, station1_5, station1_6, station1_7, station1_8, station1_9,station1_10, station1_11, station1_12, station1_13, station1_14,station1_15, station1_16, station1_17, station1_18,station1_end };
    vector<Station> listeRStationsL1 = listeStationsL1;
    reverse(listeRStationsL1.begin(), listeRStationsL1.end());
    vector<string> nom_station_L2 = { " ","lomme St Philibert","Bourg","Maison des Enfant","Mitterie","Pont Sup�rieur","Lomme_Lambersant","Canteleu","Bois Blancs","Port de Lille","Cormontainge","Montebello","Porte des Postes","" };
    vector<string> nom_station_L1 = { " ", "Lille-CHR B-Calmette","CHR Oscar Lambret","Porte des Postes","Wazemmes","Gambetta","R�publique Beaux Arts","Rihour","Gare Lille Flandres","Caulier","Fives","Marberie","Hellemmes","Lezennes","Pont de Bois","Villeneuve d'Ascq H�tel de Ville","Triolo","Cit� Scientifique Professeur Gabillard","4 Cantons","" };

    for (size_t i = 1; i < listeStationsL1.size() - 1; i++)
    {
        listeStationsL1[i].set_nom(nom_station_L1[i - 1]);
    }
    //d�finition des rames (station d'apparition, id)

    Rame rame1_1(station1_begin, 1, 1, false);
    Rame rame1_2(station1_begin, 2, 1, false);
    Rame rame1_3(station1_begin, 3, 1, false);
    Rame rame1_4(station1_end, 4, 1, true);
    Rame rame1_5(station1_end, 5, 1, true);
    Rame rame1_6(station1_end, 6, 1, true);
    Rame rame2_1(station2_begin, 7, 2, false);
    Rame rame2_2(station2_begin, 8, 2, false);
    Rame rame2_3(station2_begin, 9, 2, false);
    Rame rame2_4(station2_end, 10, 2, true);
    Rame rame2_5(station2_end, 11, 2, true);
    Rame rame2_6(station2_end, 12, 2, true);


    vector<Rame> tabRame_L1 = { rame1_1,rame1_2,rame1_3,rame1_4,rame1_5,rame1_6 };
    vector<Rame> tabRame_L2 = { rame2_1,rame2_2,rame2_3,rame2_4,rame2_5,rame2_6 };

    //cr�ation des threads (fonction de d�placement, rame concern�e, rame suivante, ligne concern�e)
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


    Image icon;
    if (!icon.loadFromFile(ICON)) {
        return EXIT_FAILURE;
    }

    //cr�ation et gestion de la fen�tre
    RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), WINDOW_NAME);

    // D�finir l'ic�ne de la fen�tre
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while (window.isOpen())
    {
        //gestion de la destruction de la fen�tre
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            visible(rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6, event, window, Rame1L1, Rame2L1, Rame3L1, Rame4L1, Rame5L1, Rame6L1,affiche1);
            visible(rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6, event, window, Rame1L2, Rame2L2, Rame3L2, Rame4L2, Rame5L2, Rame6L2,affiche2);

           
        }

        window.clear(Color::Black); //couleur d'arri�re plan

        //PARTIE AFFICHAGE DES STATIONS + ROUTES
        for (int i = 0; i < listeStationsL1.size(); i++) { //pour la L1
            listeStationsL1[i].setRepr(); //on set la repr�sentation de la station en cours
            if (i != listeStationsL1.size() - 1) { //la derni�re station ne peut avoir de route � sa droite
                if (i == 0 || i == listeStationsL1.size() - 2) {
                    Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on cr�e une route de cette station � la suivante
                    Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on cr�e une route de retour
                    route.setRepr(); //on set la repr�sentation de la route
                    route_r.setReprRetour(); //on set la repr�sentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour

                }
                else {
                    Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Yellow); //on cr�e une route de cette station � la suivante
                    Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Yellow); //on cr�e une route de retour
                    route.setRepr(); //on set la repr�sentation de la route
                    route_r.setReprRetour(); //on set la repr�sentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour

                }

            }

            updateRameText(text, tabRame_L1, rame1_1, 0);
            updateRameText(text, tabRame_L1, rame1_2, 0);
            updateRameText(text, tabRame_L1, rame1_3, 0);
            updateRameText(text, tabRame_L1, rame1_4, 0);
            updateRameText(text, tabRame_L1, rame1_5, 0);
            updateRameText(text, tabRame_L1, rame1_6, 0);
            Text text_S;
            text_S.setFont(font);
            text_S.setCharacterSize(15);
            text_S.setFillColor(Color::White);
            text_S.setPosition(listeStationsL1[i].getPositionX() + 5, listeStationsL1[i].getPositionY() + 30); // Adjust the Y-coordinate
            text_S.setRotation(45.0f);
            text_S.setString(nom_station_L1[i]);
            window.draw(listeStationsL1[i].getRepr());//on dessine la station
            window.draw(text_S);

        }

        for (int i = 0; i < listeStationsL2.size(); i++) { //pour la L2
            listeStationsL2[i].setRepr(); //on set la repr�sentation de la station en cours
            if (i != listeStationsL2.size() - 1) { //la derni�re station ne peut avoir de route � sa droite
                if (i == 0 || i == listeStationsL2.size() - 2) {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on cr�e une route de cette station � la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on cr�e une route de retour
                    route.setRepr(); //on set la repr�sentation de la route
                    route_r.setReprRetour(); //on set la repr�sentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
                else {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Red); //on cr�e une route de cette station � la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Red); //on cr�e une route de retour
                    route.setRepr(); //on set la repr�sentation de la route
                    route_r.setReprRetour(); //on set la repr�sentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }

            }

            updateRameText(text2, tabRame_L2, rame2_1, 500);
            updateRameText(text2, tabRame_L2, rame2_2, 500);
            updateRameText(text2, tabRame_L2, rame2_3, 500);
            updateRameText(text2, tabRame_L2, rame2_4, 500);
            updateRameText(text2, tabRame_L2, rame2_5, 500);
            updateRameText(text2, tabRame_L2, rame2_6, 500);
            Text text_S;
            text_S.setFont(font);
            text_S.setCharacterSize(15);
            text_S.setFillColor(Color::White);
            text_S.setPosition(listeStationsL2[i].getPositionX() + 5, listeStationsL2[i].getPositionY() + 30); // Adjust the Y-coordinate
            text_S.setRotation(45.0f);
            text_S.setString(nom_station_L2[i]);
            window.draw(listeStationsL2[i].getRepr());//on dessine la station
            window.draw(text_S);
        }
       

        
        affichage(rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6,window);
        affichage(rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6, window);


        window.draw(text);
        window.draw(text2);


        //window.draw(text_S);

        window.draw(Rame1L1);
        window.draw(Rame2L1);
        window.draw(Rame3L1);
        window.draw(Rame4L1);
        window.draw(Rame5L1);
        window.draw(Rame6L1);

        window.draw(Rame1L2);
        window.draw(Rame2L2);
        window.draw(Rame3L2);
        window.draw(Rame4L2);
        window.draw(Rame5L2);
        window.draw(Rame6L2);

        window.draw(affiche1);
        window.draw(re1);
        window.draw(affiche2);
        window.draw(re2);


        window.draw(legende_retour);
        window.draw(legende_route);

        window.display(); //affichage de la fen�tre
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