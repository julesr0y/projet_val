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

#define WINDOW_X 1500 //largeur de la fen�tre
#define WINDOW_Y 800 //hauteur de la fen�tre
#define WINDOW_NAME "VAL" //nom de la fen�tre
#define FONT "arial.ttf"

int main()
{
    //STATIONS (id, nom, position x, position y, nombre de passagers, couleur)
//L1
    Station station1_begin(0, "Station Debut", 50, 300, 0, Color::White);
    Station station1_1(1, "Station1", 100, 300, 10, Color::Red);
    Station station1_2(2, "Station2", 300, 300, 10, Color::Red);
    Station station1_3(3, "Station3", 500, 300, 10, Color::Red);
    Station station1_4(4, "Station4", 700, 300, 10, Color::Red);
    Station station1_5(5, "Station5", 900, 300, 10, Color::Red);
    Station station1_6(6, "Station6", 1100, 300, 10, Color::Red);
    Station station1_end(7, "Station Fin", 1150, 300, 0, Color::White);
    //L2
    Station station2_begin(0, "Station Debut", 50, 600, 0, Color::White);
    Station station2_1(1, "Station1", 100, 600, 10, Color::Yellow);
    Station station2_2(2, "Station2", 300, 600, 10, Color::Yellow);
    Station station2_3(3, "Station3", 500, 600, 10, Color::Yellow);
    Station station2_4(4, "Station4", 700, 600, 10, Color::Yellow);
    Station station2_5(5, "Station5", 900, 600, 10, Color::Yellow);
    Station station2_6(6, "Station6", 1100, 600, 10, Color::Yellow);
    Station station2_7(7, "Station6", 1300, 600, 10, Color::Yellow);
    Station station2_end(8, "Station Fin", 1350, 600, 0, Color::White);

    //on regroupe les stations des lignes dans des tableau, chaque tableau vaut une ligne
    vector<Station> listeStationsL1 = { station1_begin, station1_1, station1_2, station1_3, station1_4, station1_5, station1_6, station1_end };
    vector<Station> listeStationsL2 = { station2_begin, station2_1, station2_2, station2_3, station2_4, station2_5, station2_6, station2_7, station2_end };

    //d�finition des rames (station d'apparition, id)
    Rame rame1_1(station1_begin, 1);
    Rame rame1_2(station1_begin, 2);
    Rame rame1_3(station1_begin, 3);
    Rame rame1_4(station1_begin, 4);
    Rame rame1_5(station1_begin, 5);
    Rame rame1_6(station1_begin, 6);
    Rame rame2_1(station2_begin, 7);
    Rame rame2_2(station2_begin, 8);
    Rame rame2_3(station2_begin, 9);
    Rame rame2_4(station2_begin, 10);
    Rame rame2_5(station2_begin, 11);
    Rame rame2_6(station2_begin, 12);

    //cr�ation des threads (fonction de d�placement, rame concern�e, rame suivante, ligne concern�e)
    thread thread1_1(moveRame, ref(rame1_1), ref(rame1_6), ref(listeStationsL1), true);
    thread thread2_1(moveRame, ref(rame2_1), ref(rame2_6), ref(listeStationsL2), true);

    thread thread1_2(moveRame, ref(rame1_2), ref(rame1_1), ref(listeStationsL1), false);
    thread thread1_3(moveRame, ref(rame1_3), ref(rame1_2), ref(listeStationsL1), false);
    thread thread1_4(moveRame, ref(rame1_4), ref(rame1_3), ref(listeStationsL1), false);
    thread thread1_5(moveRame, ref(rame1_5), ref(rame1_4), ref(listeStationsL1), false);
    thread thread1_6(moveRame, ref(rame1_6), ref(rame1_5), ref(listeStationsL1), false);

    thread thread2_2(moveRame, ref(rame2_2), ref(rame2_1), ref(listeStationsL2), false);
    thread thread2_3(moveRame, ref(rame2_3), ref(rame2_2), ref(listeStationsL2), false);
    thread thread2_4(moveRame, ref(rame2_4), ref(rame2_3), ref(listeStationsL2), false);
    thread thread2_5(moveRame, ref(rame2_5), ref(rame2_4), ref(listeStationsL2), false);
    thread thread2_6(moveRame, ref(rame2_6), ref(rame2_5), ref(listeStationsL2), false);

    Font font;
    if (!font.loadFromFile(FONT)) {
        // Gestion de l'erreur si la police ne peut pas �tre charg�e
        return -1;
    }
    Text text;
    text.setFont(font); // D�finir la police
    text.setString("Projet VAL"); // D�finir le texte
    text.setCharacterSize(24); // D�finir la taille du texte
    text.setFillColor(Color::White); // D�finir la couleur du texte

    //cr�ation et gestion de la fen�tre
    RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), WINDOW_NAME);
    while (window.isOpen())
    {
        //gestion de la destruction de la fen�tre
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
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
                    Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Red); //on cr�e une route de cette station � la suivante
                    Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Red); //on cr�e une route de retour
                    route.setRepr(); //on set la repr�sentation de la route
                    route_r.setReprRetour(); //on set la repr�sentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
            }
            window.draw(listeStationsL1[i].getRepr()); //on dessine la station
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
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Yellow); //on cr�e une route de cette station � la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Yellow); //on cr�e une route de retour
                    route.setRepr(); //on set la repr�sentation de la route
                    route_r.setReprRetour(); //on set la repr�sentation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
            }
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