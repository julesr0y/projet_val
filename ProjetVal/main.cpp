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

#define WINDOW_X 1500 //largeur de la fenêtre
#define WINDOW_Y 800 //hauteur de la fenêtre
#define WINDOW_NAME "VAL" //nom de la fenêtre

int main()
{
    //STATIONS (id, nom, position x, position y, nombre de passagers, couleur)
    //L1
    Station station1_1(1, "Station1", 100, 300, 10, Color::Red);
    Station station1_2(2, "Station2", 300, 300, 10, Color::Red);
    Station station1_3(3, "Station3", 500, 300, 10, Color::Red);
    Station station1_4(4, "Station4", 700, 300, 10, Color::Red);
    Station station1_5(5, "Station5", 900, 300, 10, Color::Red);
    Station station1_6(6, "Station6", 1100, 300, 10, Color::Red);
    //L2
    Station station2_1(1, "Station1", 100, 600, 10, Color::Yellow);
    Station station2_2(2, "Station2", 300, 600, 10, Color::Yellow);
    Station station2_3(3, "Station3", 500, 600, 10, Color::Yellow);
    Station station2_4(4, "Station4", 700, 600, 10, Color::Yellow);
    Station station2_5(5, "Station5", 900, 600, 10, Color::Yellow);
    Station station2_6(6, "Station6", 1100, 600, 10, Color::Yellow);
    Station station2_7(7, "Station6", 1300, 600, 10, Color::Yellow);
    //on regroupe les stations des lignes dans des tableau, chaque tableau vaut une ligne
    vector<Station> listeStationsL1 = { station1_1, station1_2, station1_3, station1_4, station1_5, station1_6 };
    vector<Station> listeStationsL2 = { station2_1, station2_2, station2_3, station2_4, station2_5, station2_6, station2_7 };

    //définition des rames (station d'apparition, id)
    Rame rame1(station1_1, 1);
    Rame rame2(station2_1, 2);
    //tableau des rames (un tableau de rames par ligne)
    vector<Rame> ramesL1 = { rame1 };
    vector<Rame> ramesL2 = { rame2 };

    //création des threads (fonction de déplacement, rame concernée, ligne concernée)
    thread thread1(moveRame, ref(rame1), ref(listeStationsL1));
    thread thread2(moveRame, ref(rame2), ref(listeStationsL2));
    
    //création et gestion de la fenêtre
    RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), WINDOW_NAME);
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
                Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Red); //on crée une route de cette station à la suivante
                Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on crée une route de retour
                route.setRepr(); //on set la représentation de la route
                route_r.setReprRetour(); //on set la représentation de la route de retour
                window.draw(route.getRepr()); //on dessine la route
                window.draw(route_r.getRepr()); //on dessine la route de retour
            }
            window.draw(listeStationsL1[i].getRepr()); //on dessine la station
        }

        for (int i = 0; i < listeStationsL2.size(); i++) { //pour la L2
            listeStationsL2[i].setRepr(); //on set la représentation de la station en cours
            if (i != listeStationsL2.size() - 1) { //la dernière station ne peut avoir de route à sa droite
                Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Yellow); //on crée une route de cette station à la suivante
                Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on crée une route de retour
                route.setRepr(); //on set la représentation de la route
                route_r.setReprRetour(); //on set la représentation de la route de retour
                window.draw(route.getRepr()); //on dessine la route
                window.draw(route_r.getRepr()); //on dessine la route de retour
            }
            window.draw(listeStationsL2[i].getRepr()); //on dessine la station
        }

        //on dessine les rames
        window.draw(rame1.getRepr());
        window.draw(rame2.getRepr());

        window.display(); //affichage de la fenêtre
    }

    //destruction des threads
    thread1.join();
    thread2.join();

    return 0;
}