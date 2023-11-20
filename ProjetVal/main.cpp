#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rame.hpp"
#include "Route.hpp"
#include "Station.hpp"
#include <thread>

using namespace std;
using namespace sf;

//fonctions des threads
//void moveTriangle1(ConvexShape& triangle, float base_pos, float end_pos) {
//    while (base_pos != end_pos) {
//        //on bouge le triangle
//        triangle.move(1, 0);
//        base_pos++;
//        //temps attente entre opérations
//        this_thread::sleep_for(chrono::milliseconds(10)); // Adjust the sleep duration
//    }
//}
//
//void moveTriangle2(ConvexShape& triangle2, float base_pos, float end_pos) {
//    while (base_pos != end_pos) {
//        //on bouge le triangle
//        triangle2.move(-1, 0);
//        base_pos--;
//        //temps attente entre opérations
//        this_thread::sleep_for(chrono::milliseconds(10)); // Adjust the sleep duration
//    }
//}

void moveTriangle1(Rame& rame, float end_pos_x,float end_pos_y) {
    cout << "(" << rame.get_position_x() << ";" << rame.get_position_y() << ")" << endl;
    while ((rame.get_position_x() != end_pos_x) || (rame.get_position_y() != end_pos_y)) {
        //cout << "while" << endl;
        if (rame.get_position_x() == end_pos_x)
        {
            if (end_pos_y < rame.get_position_y())
            {
                rame.moveBas();
                rame.set_position_y(rame.get_position_y() - 1);
                cout << "bas"<<endl;

            }
            if (end_pos_y > rame.get_position_y())
            {
                rame.moveHaut();
                rame.set_position_y(rame.get_position_y() + 1);
                cout << "haut"<<endl;
            }

        }
        if (rame.get_position_y() == end_pos_y)
        {
            if (end_pos_x < rame.get_position_x())
            {
                rame.moveGauche();
                //rame.set_position_x(rame.get_position_x() - 1);
                cout << "gauche" << endl;

            }
            if (end_pos_x > rame.get_position_x())
            {
                rame.moveDroite();
                //rame.set_position_x(rame.get_position_x() + 1);
                cout << "droite" << endl;
            }

        }
        else
        {
            if (end_pos_y > rame.get_position_y() && end_pos_x > rame.get_position_x())
            {
                rame.moveDiagonalHautDroite();
                rame.set_position_y(rame.get_position_y() + 1);
                rame.set_position_x(rame.get_position_x() + 1);
                cout << "haut/droite" << endl;
            }
            if (end_pos_y < rame.get_position_y() && end_pos_x > rame.get_position_x())
            {
                rame.moveDiagonalBasDroite();
                rame.set_position_y(rame.get_position_y() - 1);
                rame.set_position_x(rame.get_position_x() + 1);
                cout << "bas/droite" << endl;
            }

            if (end_pos_y > rame.get_position_y() && end_pos_x < rame.get_position_x())
            {
                rame.moveDiagonalHautGauche();
                rame.set_position_y(rame.get_position_y() + 1);
                rame.set_position_x(rame.get_position_x() - 1);
                cout << "haut/gauche" << endl;

            }
            if (end_pos_y < rame.get_position_y() && end_pos_x < rame.get_position_x())
            {
                rame.moveDiagonalBasGauche();
                rame.set_position_y(rame.get_position_y() - 1);
                rame.set_position_x(rame.get_position_x() - 1);
                cout << "bas/gauche" << endl;

            }


        }
        
        //on bouge le triangle
        //cout << rame.get_position_x() << endl;
        //base_pos++;

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
   

    //test1 : ligne vers la droite (==>il marche )
    thread thread1(moveTriangle1, ref(rame1), 730.0,210.0,ref(station1));

    //test2 : ligne vers la gauche (==>il marche pas ;-; )
    //thread thread1(moveTriangle1, ref(rame2), 235.0, 210.0);
    
    //test3 : ligne vers le haut (==>il marche )
    //thread thread1(moveTriangle1, ref(rame1), 235.0, 400.0);

    //test4 : ligne vers le bas (==>il marche pas ;-; )
    //thread thread1(moveTriangle1, ref(rame2), 235.0, 200.0);

    //test5 : ligne haut/droite(==>pb dans la boucle droit ) 
    //thread thread1(moveTriangle1, ref(rame1), 730.0, 400.0);

    //test5 : ligne haut/gauche (==>il fait un bas gauche )
    //thread thread1(moveTriangle1, ref(rame2), 235.0, 400.0);

    //test6 : ligne bas/gauche (==>pb dans la boucle gauche)
    //thread thread1(moveTriangle1, ref(rame2), 235.0, 400.0);

    //test6 : ligne bas/droite (==>il marche) 
    //thread thread1(moveTriangle1, ref(rame1), 730.0, 150.0);

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
        window.draw(rame2.getRepr());

        window.display();
    }

    //destruction des threads
    //thread1.join();

    //thread2.join();

    return 0;
}