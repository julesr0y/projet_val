#include <iostream>
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Station.hpp"
#include "Rame.hpp"
#include "Route.hpp"
#include "fonction_rames.hpp"

using namespace std;
using namespace sf;

#define WINDOW_X 1750 //largeur de la fenêtre
#define WINDOW_Y 900 //hauteur de la fenêtre
#define WINDOW_NAME "VAL" //nom de la fenêtre
#define FONT "merienda.ttf"
#define ICON "icon.png"

int main()
{
    Font font;
    if (!font.loadFromFile(FONT)) {
        // Gestion de l'erreur si la police ne peut pas être chargée
        return -1;
    }
    Text text;
    text.setFont(font);
    Text text2;
    text2.setFont(font);// Définir la police

    //légende
    CircleShape legende_station;
    legende_station.setRadius(20);
    legende_station.setPosition(50 - 15, 850 - 15);
    legende_station.setFillColor(Color::Red);
    CircleShape legende_retour;
    legende_retour.setRadius(20);
    legende_retour.setPosition(175 - 15, 850 - 15);
    legende_retour.setFillColor(Color::White);
    RectangleShape legende_route;
    legende_route.setSize(Vector2f(75, 8));
    legende_route.setPosition(300, 850);
    legende_route.setFillColor(Color::Yellow);

    //STATIONS (id, nom, position x, position y, nombre de passagers, couleur)
    //L1
    Station station1_begin(0, "Station Debut", 50, 300, 0, Color::White, false);
    Station station1_1(1, "Station1", 100, 300, 10, Color::Red, true);
    Station station1_2(2, "Station2", 300, 300, 10, Color::Red, false);
    Station station1_3(3, "Station3", 500, 300, 10, Color::Red, true);
    Station station1_4(4, "Station4", 700, 300, 10, Color::Red, false);
    Station station1_5(5, "Station5", 900, 300, 10, Color::Red, false);
    Station station1_6(6, "Station6", 1100, 300, 10, Color::Red, true);
    Station station1_end(7, "Station Fin", 550, 300, 0, Color::White, false);
    //L2
    Station station2_begin(0, "Station Debut", 50, 600, 0, Color::White, false);
    Station station2_1(1, "Station1", 100, 600, 10, Color::Yellow, true);
    Station station2_2(2, "Station2", 300, 600, 10, Color::Yellow, false);
    Station station2_3(3, "Station3", 500, 600, 10, Color::Yellow, false);
    Station station2_4(4, "Station4", 700, 600, 10, Color::Yellow, false);
    Station station2_5(5, "Station5", 900, 600, 10, Color::Yellow, false);
    Station station2_6(6, "Station6", 1100, 600, 10, Color::Yellow, false);
    Station station2_7(7, "Station6", 1300, 600, 10, Color::Yellow, true);
    Station station2_end(8, "Station Fin", 1350, 600, 0, Color::White, false);
    //on regroupe les stations des lignes dans des tableau, chaque tableau vaut une ligne
    vector<Station> listeStationsL1 = { station1_begin, station1_1, station1_2, station1_3, station1_end };
    vector<Station> listeRStationsL1 = listeStationsL1;
    reverse(listeRStationsL1.begin(), listeRStationsL1.end());
    vector<Station> listeStationsL2 = { station2_begin, station2_1, station2_2, station2_3, station2_4, station2_5, station2_6, station2_7, station2_end };
    vector<Station> listeRStationsL2 = listeStationsL2;
    reverse(listeRStationsL2.begin(), listeRStationsL2.end());

    //définition des rames (station d'apparition, id)
    Rame rame1_1(station1_begin, 1, false);
    Rame rame1_2(station1_begin, 2, false);
    Rame rame1_3(station1_begin, 3, false);
    Rame rame1_4(station1_end, 4, true);
    Rame rame1_5(station1_end, 5, true);
    Rame rame1_6(station1_end, 6, true);
    Rame rame2_1(station2_begin, 7, false);
    Rame rame2_2(station2_begin, 8, false);
    Rame rame2_3(station2_begin, 9, false);
    Rame rame2_4(station2_end, 10, true);
    Rame rame2_5(station2_end, 11, true);
    Rame rame2_6(station2_end, 12, true);

    
    vector<Rame> tabRame_L1 = { rame1_1,rame1_2,rame1_3,rame1_4,rame1_5,rame1_6 };
    vector<Rame> tabRame_L2 = { rame2_1,rame2_2,rame2_3,rame2_4,rame2_5,rame2_6 };

    //création des threads (fonction de déplacement, rame concernée, rame suivante, ligne concernée)
    thread thread1_1(moveRame, ref(rame1_1), ref(rame1_6), ref(listeStationsL1), true, ref(tabRame_L1), ref(text));
    thread thread2_1(moveRame, ref(rame2_1), ref(rame2_6), ref(listeStationsL2), true, ref(tabRame_L2), ref(text2));
    thread thread1_4(moveRame, ref(rame1_4), ref(rame1_3), ref(listeRStationsL1), true, ref(tabRame_L1), ref(text));
    thread thread2_4(moveRame, ref(rame2_4), ref(rame2_3), ref(listeRStationsL2), false, ref(tabRame_L2), ref(text2));

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

    //création et gestion de la fenêtre
    RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), WINDOW_NAME);

    // Définir l'icône de la fenêtre
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while (window.isOpen())
    {
        //gestion de la destruction de la fenêtre
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::Black); //couleur d'arrière plan

        //PARTIE AFFICHAGE DES STATIONS + ROUTES
        for (int i = 0; i < listeStationsL1.size(); i++) { //pour la L1
            listeStationsL1[i].setRepr(); //on set la représentation de la station en cours
            if (i != listeStationsL1.size() - 1) { //la dernière station ne peut avoir de route à sa droite
                if (i == 0 || i == listeStationsL1.size() - 2) {
                    Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on crée une route de cette station à la suivante
                    Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on crée une route de retour
                    route.setRepr(); //on set la représentation de la route
                    route_r.setReprRetour(); //on set la représentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
                else {
                    Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Red); //on crée une route de cette station à la suivante
                    Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Red); //on crée une route de retour
                    route.setRepr(); //on set la représentation de la route
                    route_r.setReprRetour(); //on set la représentation de la route de retour
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
            window.draw(listeStationsL1[i].getRepr()); //on dessine la station
        }

        for (int i = 0; i < listeStationsL2.size(); i++) { //pour la L2
            listeStationsL2[i].setRepr(); //on set la représentation de la station en cours
            if (i != listeStationsL2.size() - 1) { //la dernière station ne peut avoir de route à sa droite
                if (i == 0 || i == listeStationsL2.size() - 2) {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on crée une route de cette station à la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on crée une route de retour
                    route.setRepr(); //on set la représentation de la route
                    route_r.setReprRetour(); //on set la représentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
                else {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Yellow); //on crée une route de cette station à la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Yellow); //on crée une route de retour
                    route.setRepr(); //on set la représentation de la route
                    route_r.setReprRetour(); //on set la représentation de la route de retour
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
            window.draw(listeStationsL2[i].getRepr()); //on dessine la station
        }

        //on dessine les rames
        window.draw(rame1_1.getRepr());
        window.draw(rame1_2.getRepr());
        window.draw(rame1_3.getRepr());
        window.draw(rame1_4.getRepr());
        window.draw(rame1_5.getRepr());
        window.draw(rame1_6.getRepr());
        window.draw(rame2_1.getRepr());
        window.draw(rame2_2.getRepr());
        window.draw(rame2_3.getRepr());
        window.draw(rame2_4.getRepr());
        window.draw(rame2_5.getRepr());
        window.draw(rame2_6.getRepr());
        window.draw(text);
        window.draw(text2);


        window.draw(legende_station);
        window.draw(legende_retour);
        window.draw(legende_route);

        window.display(); //affichage de la fenêtre
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