#include <iostream>
#include <SFML/Graphics.hpp>
#include "Station.hpp"
#include "Rame.hpp"
#include "Route.hpp"
#include <thread>
#include <vector>

using namespace std;
using namespace sf;

//LISTE DES STATIONS
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

//on regroupe les stations des lignes dans des tableau
vector<Station> listeStationsl1 = {station1_1, station1_2, station1_3, station1_4, station1_5, station1_6};
vector<Station> listeStationsl2 = { station2_1, station2_2, station2_3, station2_4, station2_5, station2_6, station2_7 };

//fonctions des threads
void moveRame(Rame& rame, float end_pos_x, float end_pos_y) {
    cout << "(" << rame.get_position_x() << ";" << rame.get_position_y() << ")" << endl;
    while ((rame.get_position_x() != end_pos_x) || (rame.get_position_y() != end_pos_y)) {
        if (rame.get_position_x() == end_pos_x)
        {
            if (end_pos_y < rame.get_position_y())
            {
                rame.moveHaut();
                rame.set_position_y(rame.get_position_y() - 1);
                cout << "Haut" << endl;

            }
            if (end_pos_y > rame.get_position_y())
            {
                rame.moveBas();
                rame.set_position_y(rame.get_position_y() + 1);
                cout << "bas" << endl;
            }
        }
        if (rame.get_position_y() == end_pos_y)
        {
            if (end_pos_x < rame.get_position_x())
            {
                rame.moveGauche();
                rame.set_position_x(rame.get_position_x() - 1);
                cout << "gauche" << endl;
            }
            if (end_pos_x > rame.get_position_x())
            {
                rame.moveDroite();
                rame.set_position_x(rame.get_position_x() + 1);
                cout << "droite" << endl;
            }
        }
        else
        {
            if (end_pos_y < rame.get_position_y() && end_pos_x > rame.get_position_x())
            {
                rame.moveDiagonalHautDroite();
                rame.set_position_y(rame.get_position_y() - 1);
                rame.set_position_x(rame.get_position_x() + 1);
                cout << "haut/droite" << endl;
            }
            if (end_pos_y > rame.get_position_y() && end_pos_x > rame.get_position_x())
            {
                rame.moveDiagonalBasDroite();
                rame.set_position_y(rame.get_position_y() + 1);
                rame.set_position_x(rame.get_position_x() + 1);
                cout << "bas/droite" << endl;
            }
            if (end_pos_y < rame.get_position_y() && end_pos_x < rame.get_position_x())
            {
                rame.moveDiagonalHautGauche();
                rame.set_position_y(rame.get_position_y() - 1);
                rame.set_position_x(rame.get_position_x() - 1);
                cout << "haut/gauche" << endl;
            }
            if (end_pos_y > rame.get_position_y() && end_pos_x < rame.get_position_x())
            {
                rame.moveDiagonalBasGauche();
                rame.set_position_y(rame.get_position_y() + 1);
                rame.set_position_x(rame.get_position_x() - 1);
                cout << "bas/gauche" << endl;
            }
        }
        //temps attente entre opérations
        this_thread::sleep_for(chrono::milliseconds(10)); // Adjust the sleep duration
    }
}

int main()
{
    //apparition de la fenetre
    RenderWindow window(VideoMode(1500, 800), "VAL");

    //rame1
    Rame rame1(station1_1);
    rame1.setRepr();
    
    //threads gestion
    //test1 : ligne vers la droite
    //thread thread1(moveRame, ref(rame1), 1000, 400);

    //test2 : ligne vers la gauche
    //thread thread1(moveRame, ref(rame1), 500, 400);

    //test3 : ligne vers le haut
    //thread thread1(moveRame, ref(rame1), 750, 200);

    //test4 : ligne vers le bas
    //thread thread1(moveRame, ref(rame1), 750, 600);

    //test5 : ligne haut/droite
    //thread thread1(moveRame, ref(rame1), 1000, 200);

    //test6 : ligne haut/gauche
    //thread thread1(moveRame, ref(rame1), 500, 200);

    //test7 : ligne bas/gauche
    //thread thread1(moveRame, ref(rame1), 500, 600);

    //test8 : ligne bas/droite 
    //thread thread1(moveRame, ref(rame1), 1000, 600);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::White);

        //PARTIE AFFICHAGE DES STATIONS + ROUTES
        for (int i = 0; i < listeStationsl1.size(); i++) {
            listeStationsl1[i].setRepr();
            if (i != listeStationsl1.size() - 1) {
                Route route(i + 1, listeStationsl1[i], listeStationsl1[i + 1], Color::Red);
                route.setRepr();
                window.draw(route.getRepr());
            }
            window.draw(listeStationsl1[i].getRepr());
        }

        for (int i = 0; i < listeStationsl2.size(); i++) {
            listeStationsl2[i].setRepr();
            if (i != listeStationsl2.size() - 1) {
                Route route(i + 1, listeStationsl2[i], listeStationsl2[i + 1], Color::Yellow);
                route.setRepr();
                window.draw(route.getRepr());
            }
            window.draw(listeStationsl2[i].getRepr());
        }

        window.draw(rame1.getRepr());

        window.display();
    }

    //destruction des threads
    //thread1.join();

    return 0;
}