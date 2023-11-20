#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rame.hpp"
#include "Route.hpp"
#include <thread>

using namespace std;
using namespace sf;

//fonctions des threads
void moveTriangle1(Rame& rame, float base_pos, float end_pos) {
    while (base_pos != end_pos) {
        //on bouge le triangle
        rame.moveDroite();
        //cout << rame.get_position_x() << endl;
        base_pos++;

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

    //rame1
    Rame rame1;
    rame1.set_position_y(210);
    rame1.set_position_x(235);
    rame1.setRepr();

    //rame2
    Rame rame2;
    rame2.set_position_y(730);
    rame2.set_position_x(705);
    rame2.setRepr();

    Route route1(1, station1, station2);
    route1.setRepr();

    //création des threads
    thread thread1(moveTriangle1, ref(rame1), 210.0, 730.0);
    //thread thread2(rame2.move_toi(), ref(rame2.getRepr()), 730.0, 210.0);
    
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
        window.draw(route1.getRepr());
        //window.draw(triangle);
        //window.draw(triangle2);
        window.draw(rame1.getRepr());
        //window.draw(rame2.getRepr());

        window.display();
    }

    //destruction des threads
    thread1.join();

    //thread2.join();

    return 0;
}