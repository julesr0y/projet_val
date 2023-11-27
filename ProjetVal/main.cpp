#include <iostream>
#include <SFML/Graphics.hpp>
#include "Station.hpp"
#include "Rame.hpp"
#include "Route.hpp"
#include "fonction_rames.hpp"
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
vector<Station> listeStationsl1 = { station1_1, station1_2, station1_3, station1_4, station1_5, station1_6 };
vector<Station> listeStationsl2 = { station2_1, station2_2, station2_3, station2_4, station2_5, station2_6, station2_7 };

int main()
{
    //apparition de la fenetre
    RenderWindow window(VideoMode(1500, 800), "VAL");
    
    Rame rame1(station1_1, 1);
    Rame rame2(station1_2, 2);
    Rame rame3(station1_3, 3);
    Rame rame4(station1_3, 4);

    //threads gestion
    //test1 : ligne vers la droite
    thread thread1(moveRame, ref(rame1), station1_6.getPositionX(), station1_6.getPositionY());
    thread thread2(moveRame, ref(rame2), station1_5.getPositionX(), station1_5.getPositionY());
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

    std::cout << "mon tableau de rames" << endl;

    vector<Rame> rames_sur_ligne_1 = { rame1, rame2, rame3, rame4 };
    for (int i = 0; i < rames_sur_ligne_1.size(); i++)
    {
        cout << rames_sur_ligne_1[i].get_numero() << "||";
    }

    std::cout << "numero de rame qui est apres la rame 1 " << endl;

    cout << endl;
    cout << get_rames_apres(rames_sur_ligne_1, rame1).get_numero();
    cout << endl;
    std::cout << "vitesses" << endl;

    cout << rame2.get_vitesse();
    cout << endl;
    acceleration(station1_6, rame2);
    cout << rame2.get_vitesse();
    cout << endl;



    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear(Color::Black);
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

        //window.draw(rame1.getRepr());
        //window.draw(rame1.getRepr());
        rame2.setRepr();
        window.draw(rame2.getRepr());

        window.display();
    }

    //destruction des threads
    thread1.join();
    thread2.join();

    return 0;
}