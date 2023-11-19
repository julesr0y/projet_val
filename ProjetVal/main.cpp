#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rame.hpp"
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

void moveTriangle1(ConvexShape triangle, float base_pos, float end_pos) {
    while (base_pos != end_pos) {
        //on bouge le triangle
        triangle.move(1, 0);
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


    //route entre les deux stations
    RectangleShape line(Vector2f(700 - 200, 5)); //Longueur = distance entre les deux cercles, Hauteur = 5 pixels
    line.setPosition(200, 200 + 20); //Position de la route
    line.setFillColor(Color::Red); //couleur

    ////Création du triangle équilatéral
    //ConvexShape triangle(3);
    //triangle.setPoint(0, Vector2f(210, 210)); // Coin supérieur
    //triangle.setPoint(1, Vector2f(210, 230)); // Coin inférieur
    //triangle.setPoint(2, Vector2f(235, 220)); // Coin droit
    //triangle.setFillColor(Color::Blue); // Couleur du triangle


    //// Création du triangle équilatéral 2
    //ConvexShape triangle2(3);
    //triangle2.setPoint(0, Vector2f(730, 210)); // Coin supérieur
    //triangle2.setPoint(1, Vector2f(730, 230)); // Coin inférieur
    //triangle2.setPoint(2, Vector2f(705, 220)); // Coin gauche
    //triangle2.setFillColor(Color::Blue); // Couleur du triangle

    //création des threads
    thread thread1(moveTriangle1, rame1.getRepr(),rame1.get_position_y(), rame2.get_position_y());
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
        window.draw(line);
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