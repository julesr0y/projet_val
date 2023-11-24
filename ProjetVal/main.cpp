#include <iostream>
#include <SFML/Graphics.hpp>
#include "Station.hpp"
#include "Rame.hpp"
#include "Route.hpp"
#include <thread>

using namespace std;
using namespace sf;

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

    //rond 1
    Station station1(1, "Station1", 200, 200, 10); //classe station
    station1.setRepr(); //on set la représentation graphique

    //rond 2
    Station station2(2, "Station2", 700, 200, 10); //classe station
    station2.setRepr(); //on set la représentation graphique

    //rond 3 de test
    Station station3(3, "Station3", 750, 400, 10);
    station3.setRepr();

    //rame1
    Rame rame1(station3);
    rame1.setRepr();

    Route route1_allé(1, station1, station2);
    route1_allé.setRepr();

    Route route1_retour(9, station1, station2);
    route1_retour.setReprRetour();
    
    //threads gestion
    //test1 : ligne vers la droite
    thread thread1(moveRame, ref(rame1), 1000, 400);

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
        window.draw(station1.getRepr());
        window.draw(station2.getRepr());
        window.draw(station3.getRepr());
        window.draw(route1_allé.getRepr());
        window.draw(route1_retour.getRepr());
        //window.draw(triangle);
        //window.draw(triangle2);
        window.draw(rame1.getRepr());
        //window.draw(rame2.getRepr());

        window.display();
    }

    //destruction des threads
    thread1.join();

    return 0;
}