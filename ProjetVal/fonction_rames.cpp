#include "fonction_rames.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

void moveRame(Rame& rame, Rame& rame_apres, vector<Station> listeStations, bool beginning) {
    if (!beginning) {
        //srand(static_cast<unsigned int>(time(0)));
        //int randomNum = 7 + (rand() % 4); // 7 + (0 to 3)
        default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> randomNum{ 7, 10 };
        //cout << randomNum(re) << endl;
        this_thread::sleep_for(chrono::seconds(randomNum(re)));
    }

    bool reverseOrder = false; //par défaut, on inverse pas la liste des stations de la ligne

    while (true) { //boucle infinie, pour recommencer indéfiniment le parcours de la ligne pour la rame

        if (reverseOrder) { //si l'inversement de liste des stations de la ligne est activé
            reverse(listeStations.begin(), listeStations.end()); //on inverse la liste
        }

        for (int i = 0; i < listeStations.size(); i++) {
            float dist_entre_2_stations; //initialisation de la distance entre la station en cours et la suivante

            if (i == listeStations.size() - 1) { //si on est à la dernière station
                dist_entre_2_stations = abs(listeStations.back().getPositionX() - listeStations[listeStations.size() - 2].getPositionX());
            }
            else { //sinon
                dist_entre_2_stations = abs(listeStations[i + 1].getPositionX() - listeStations[i].getPositionX());
            }

            float end_pos_x = listeStations[i].getPositionX(); //position x à atteindre (station suivante)
            float end_pos_y = listeStations[i].getPositionY(); //position y à atteindre (station suivante)
            int v; //initialisation de la vitesse

            while ((rame.get_position_x() != end_pos_x) || (rame.get_position_y() != end_pos_y)) {
                float distanceToSation_x = abs(end_pos_x - rame.get_position_x()); //distance x jusqu'a la prochaine station par rapport a la position x actuelle de la rame
                bool authorize_move = true; //on autorise le déplacement
                rame.setArrete(false); //la rame n'est pas en etat d'arret
                int dist_entre_rames = abs(rame_apres.get_position_x() - rame.get_position_x()); //distance entre la rame actuelle et celle devant

                if (distanceToSation_x >= (2.0 / 3.0) * dist_entre_2_stations) {
                    //on accélère la rame sur le premier tiers de la distance
                    v = 1;
                   //cout << "Accelere" << endl;
                }
                else if (distanceToSation_x >= (1.0 / 3.0) * dist_entre_2_stations) {
                    //on maintient une vitesse constante pour la rame sur le deuxième tiers de la distance
                    v = 10;
                    //cout << "Constant" << endl;
                }
                else if (distanceToSation_x < (1.0 / 3.0) * dist_entre_2_stations) {
                    //si une rame se rapproche d'une station (dernier tiers de la distance), on freine son déplacement
                    v = 30;
                    //cout << "Freine" << endl;
                }
                if (dist_entre_rames < 150 && rame_apres.getRetour() == rame.getRetour()) {
                    //si 2 rames se suivant sur une même voie ont une distance faible, on freine le deplacement de la rame derrière
                    v = 30;
                }
                if (dist_entre_rames < 100 && beginning == false && rame_apres.getRetour() == rame.getRetour()) {
                    //si 2 rames se suivant sur une même voie ont une distance trop faible, on interdit le deplacement de la rame derrière
                    authorize_move = false;
                }

                if (authorize_move) {
                    //si déplacement vertical
                    if (rame.get_position_x() == end_pos_x)
                    {
                        //si déplacement vers haut
                        if (end_pos_y < rame.get_position_y())
                        {
                            rame.moveHaut();
                            rame.set_position_y(rame.get_position_y() - 1);
                        }
                        //si déplacement vers bas
                        if (end_pos_y > rame.get_position_y())
                        {
                            rame.moveBas();
                            rame.set_position_y(rame.get_position_y() + 1);
                        }
                    }
                    //si déplacement horizontal
                    if (rame.get_position_y() == end_pos_y)
                    {
                        //si direction vers gauche
                        if (end_pos_x < rame.get_position_x())
                        {
                            rame.moveGauche();
                            rame.set_position_x(rame.get_position_x() - 1);
                        }
                        //si direction vers droite
                        if (end_pos_x > rame.get_position_x())
                        {
                            rame.moveDroite();
                            rame.set_position_x(rame.get_position_x() + 1);
                        }
                    }
                    else //cas des déplacements en diagonale
                    {
                        //si direction vers haut droite
                        if (end_pos_y < rame.get_position_y() && end_pos_x > rame.get_position_x())
                        {
                            rame.moveDiagonalHautDroite();
                            rame.set_position_y(rame.get_position_y() - 1);
                            rame.set_position_x(rame.get_position_x() + 1);
                        }
                        //si direction vers bas droite
                        if (end_pos_y > rame.get_position_y() && end_pos_x > rame.get_position_x())
                        {
                            /*rame.moveDiagonalBasDroite();
                            rame.set_position_y(rame.get_position_y() + 1);
                            rame.set_position_x(rame.get_position_x() + 1);*/

                            rame.moveBas();
                            rame.set_position_y(rame.get_position_y() + 1);
                        }
                        //si direction vers haut gauche
                        if (end_pos_y < rame.get_position_y() && end_pos_x < rame.get_position_x())
                        {
                            /*rame.moveDiagonalHautGauche();
                            rame.set_position_y(rame.get_position_y() - 1);
                            rame.set_position_x(rame.get_position_x() - 1);*/

                            rame.moveHaut();
                            rame.set_position_y(rame.get_position_y() - 1);
                        }
                        //si direction vers bas gauche
                        if (end_pos_y > rame.get_position_y() && end_pos_x < rame.get_position_x())
                        {
                            rame.moveDiagonalBasGauche();
                            rame.set_position_y(rame.get_position_y() + 1);
                            rame.set_position_x(rame.get_position_x() - 1);
                        }
                    }
                }
                this_thread::sleep_for(chrono::milliseconds(v)); //réglage de la vitesse de la rame
            }
            /*cout << "STOP" << endl;
            cout << dist_entre_2_stations << endl;*/
            this_thread::sleep_for(chrono::seconds(2)); //pause dans les stations

            if (i == listeStations.size() - 1) { //si on est au bout de la ligne
                rame.setArrete(true); //on met la rame en mode arret
            }
            //monte
            if (rame.estArrete() && i == listeStations.size() - 1 && !rame.getRetour()) {
                rame.set_position_y(rame.get_position_y() + 30); //on monte la position y de la rame
                rame.rotate180(); //on tourne la rame de 180 degrés
                rame.setRetour(true); //on active le mode retour (voie supérieure)
                reverseOrder = true; //on active l'inversion de la liste des stations
            }
            ////descend
            else if (rame.estArrete() && rame.getRetour()) {
                rame.set_position_y(rame.get_position_y() - 30); //on descend la position y de la rame
                rame.rotate180(); //on tourne la rame de 180 degrés
                rame.setRetour(false); //on enleve le mode retour (voie inférieure)
                reverseOrder = true; //on active l'inversion de la liste des stations
            }
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