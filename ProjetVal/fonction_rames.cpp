#include "fonction_rames.hpp"
#include "fonction_station.hpp"
#include <iostream>
#include <random>
#include <ctime>


using namespace std;

void moveRame(Rame& rame, Rame& rame_apres, vector<Station>& listeStations, bool beginning) {
    if (!beginning) {
        //srand(static_cast<unsigned int>(time(0)));
        //int randomNum = 7 + (rand() % 4); // 7 + (0 to 3)
        default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> randomNum{ 7, 10 };
        //cout << randomNum(re) << endl;
        this_thread::sleep_for(chrono::seconds(randomNum(re)));
    }
    //remplire_rame(rame, listeStations[0]);
    while (true) {
        for (int i = 0; i < listeStations.size(); i++) {
            float distance_totale;
            if (i == listeStations.size() - 1) {
                distance_totale = listeStations.back().getPositionX() - listeStations[listeStations.size() - 2].getPositionX();
            }
            else {
                distance_totale = listeStations[i + 1].getPositionX() - listeStations[i].getPositionX();
            }
            float end_pos_x = listeStations[i].getPositionX();
            float end_pos_y = listeStations[i].getPositionY();
            float distance_x = abs(end_pos_x - rame.get_position_x());
            float distance_y = abs(end_pos_y - rame.get_position_y());
            int v;

            //cout << "(" << rame.get_position_x() << ";" << rame.get_position_y() << ")" << endl;
            while ((rame.get_position_x() != end_pos_x) || (rame.get_position_y() != end_pos_y)) {
                //cout << rame_apres.get_position_x() << endl;
                distance_x = end_pos_x - rame.get_position_x();
                distance_y = end_pos_y - rame.get_position_y();
                float distance_var = abs(distance_x);
                bool authorize_move = true;

                int dist = abs(rame_apres.get_position_x() - rame.get_position_x());
                int dist_y = abs(rame_apres.get_position_y() - rame.get_position_y());
                //cout << "Distance: " << dist << endl;

                //cout << dist_y << endl;
                if (distance_var >= (2.0 / 3.0) * distance_totale)
                {
                    //cout << "acceleration" << endl;
                    v = 1;
                }
                if (distance_var >= (1.0 / 3.0) * distance_totale)
                {
                    //cout << "constant" << endl;
                    v = 10;
                    //cout << dist_y << endl;
                }
                if ((dist < 150 || distance_var < (1.0 / 3.0) * distance_totale) && rame_apres.getRetour() == rame.getRetour()) {
                    //cout << "freinage" << endl;
                    v = 30;
                    //cout << dist_y << endl;
                }
                if ((dist < 100 && beginning == false) && rame_apres.getRetour() == rame.getRetour()) {
                    authorize_move = false;
                }

                if (authorize_move) {
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
                            /*rame.moveDiagonalBasDroite();
                            rame.set_position_y(rame.get_position_y() + 1);
                            rame.set_position_x(rame.get_position_x() + 1);*/

                            rame.moveBas();
                            rame.set_position_y(rame.get_position_y() + 1);
                        }
                        if (end_pos_y < rame.get_position_y() && end_pos_x < rame.get_position_x())
                        {
                            /*rame.moveDiagonalHautGauche();
                            rame.set_position_y(rame.get_position_y() - 1);
                            rame.set_position_x(rame.get_position_x() - 1);*/

                            rame.moveHaut();
                            rame.set_position_y(rame.get_position_y() - 1);
                        }
                        if (end_pos_y > rame.get_position_y() && end_pos_x < rame.get_position_x())
                        {
                            rame.moveDiagonalBasGauche();
                            rame.set_position_y(rame.get_position_y() + 1);
                            rame.set_position_x(rame.get_position_x() - 1);

                        }
                    }
                }
                //temps attente entre opérations
                this_thread::sleep_for(chrono::milliseconds(v));
            }
            if (i > 0) {
                cout << "nb passager dans la rame  " << rame.get_numero() << " avant entrer : " << rame.get_passagers()<<endl;
                int nb_entrant = remplire_rame(rame, listeStations[i]);
                cout << "numero de rame " << rame.get_numero() << " nb entrant : " << nb_entrant << endl;
                int nb_sortant = sortire(rame);
                cout << "numero de rame " << rame.get_numero() << " nb sortant : " << nb_sortant << endl;
                cout << "nb passager dans la rame  " << rame.get_numero() << " apres entrer : " << rame.get_passagers()<<endl;

                rame.setArrete(true); //on set la rame en mode d'arret
                int temp_attente = (int)(nb_entrant + nb_sortant)/10;
                if (temp_attente < 2)
                {
                    temp_attente = 2;
                }
                cout << "temp attente : " << temp_attente << endl;
                this_thread::sleep_for(chrono::seconds(temp_attente)); //pause dans les stations
            }
            //remonte
            if (rame.estArrete() && i == listeStations.size() - 1 && !rame.getRetour()) {
                rame.set_position_y(rame.get_position_y() + 20);
                rame.rotate180();
                rame.setRetour(true);
            }
            ////descend
            else if (rame.estArrete() && rame.getRetour()) {
                rame.set_position_y(rame.get_position_y() - 20);
                rame.rotate180();
                rame.setRetour(false);
            }
            //cout << "en retour: " << rame.getRetour() << endl;
           // cout << rame.get_numero() << " : " << rame.get_position_y() << endl;
        }
    }
}


Rame get_rames_apres(vector<Rame>& liste, Rame& rame) {
    int i = 0;//recupere l'indice du rame dans la liste
    
    //tant que le numéro dans la liste ne correspond pas au numéro de la rame actuelle
    while (liste[i].get_numero() != rame.get_numero())
    {
        i++; //on incrémente i
    }

    if (i == 0)
    {
        return liste.back(); //alors la rame suivante correspond au dernier élément de la liste
    }
    else
    {
        return liste[i - 1]; //sinon, on récupère l'élément d'indice moins un
    }
}