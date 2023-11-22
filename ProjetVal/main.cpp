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

            }
            if (end_pos_y > rame.get_position_y())
            {
                rame.moveBas();
                rame.set_position_y(rame.get_position_y() + 1);
            }
        }
        if (rame.get_position_y() == end_pos_y)
        {
            if (end_pos_x < rame.get_position_x())
            {
                rame.moveGauche();
                rame.set_position_x(rame.get_position_x() - 1);
            }
            if (end_pos_x > rame.get_position_x())
            {
                rame.moveDroite();
                rame.set_position_x(rame.get_position_x() + 1);
            }
        }
        else
        {
            if (end_pos_y < rame.get_position_y() && end_pos_x > rame.get_position_x())
            {
                rame.moveDiagonalHautDroite();
                rame.set_position_y(rame.get_position_y() - 1);
                rame.set_position_x(rame.get_position_x() + 1);
            }
            if (end_pos_y > rame.get_position_y() && end_pos_x > rame.get_position_x())
            {
                rame.moveDiagonalBasDroite();
                rame.set_position_y(rame.get_position_y() + 1);
                rame.set_position_x(rame.get_position_x() + 1);
            }
            if (end_pos_y < rame.get_position_y() && end_pos_x < rame.get_position_x())
            {
                rame.moveDiagonalHautGauche();
                rame.set_position_y(rame.get_position_y() - 1);
                rame.set_position_x(rame.get_position_x() - 1);
            }
            if (end_pos_y > rame.get_position_y() && end_pos_x < rame.get_position_x())
            {
                rame.moveDiagonalBasGauche();
                rame.set_position_y(rame.get_position_y() + 1);
                rame.set_position_x(rame.get_position_x() - 1);
                
            }
        }
        //temps attente entre opérations
        this_thread::sleep_for(chrono::milliseconds(10)); // Adjust the sleep duration
    }
}


vector<Rame> get_rames_avant_apres(vector<Rame>liste ,Rame& rame) {
    int i = 0;//recupere l'indice du rame dans la liste 
    vector<Rame> rame_avant_apres(2);
    while (liste[i].get_numero() == rame.get_numero() || i <= liste.size())
    {
        i++;
    }

    if (i==0)
    {
        rame_avant_apres[0]= *liste.end() ;
        rame_avant_apres[1] = liste[i + 1];
        return rame_avant_apres;
    }
    if (i == liste.size()) {
        rame_avant_apres[1] = *liste.begin();
        rame_avant_apres[0] = liste[i - 1];
        return rame_avant_apres;
    }
    else
    {
        rame_avant_apres[0] = liste[i - 1];
        rame_avant_apres[1] = liste[i + 1];
        return rame_avant_apres;
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
    Rame rame1(station3,0);
    Rame rame2(station3, 1);
    Rame rame3(station3, 2);
    Rame rame4(station3, 3);
    //rame1.setRepr();

    //route1
    Route route1(1, station1, station2);
    route1.setRepr();
    
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


    vector<Rame> rames_sur_ligne_1(4);
    rames_sur_ligne_1[0] = rame1;
    rames_sur_ligne_1[1] = rame2;
    rames_sur_ligne_1[2] = rame3;
    rames_sur_ligne_1[3] = rame4;
    for (size_t i = 0; i <rames_sur_ligne_1.size(); i++)
    {
        cout << rames_sur_ligne_1[i].get_numero() << "||";
    }
    cout << endl;
    for (size_t i = 0; i < get_rames_avant_apres(rames_sur_ligne_1, rame2).size(); i++)
    {
        cout << get_rames_avant_apres(rames_sur_ligne_1, rame2)[i].get_numero() << "||";
    }

    



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
        window.draw(route1.getRepr());
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