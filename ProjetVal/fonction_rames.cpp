#include "fonction_rames.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "fonction_station.hpp"

using namespace std;

void updateRameText(Text& text, vector<Rame>& tabRame, Rame rame, int pos_x) {
    string tableauTexte;
    for (size_t i = 0; i < tabRame.size(); i++) {
        if (rame.get_numero() == tabRame[i].get_numero())
        {
            tabRame[i].set_passagers(rame.get_passagers());
            tableauTexte += "ligne N° : "+ to_string(rame.get_ligne()) + " Rame N° : " + to_string(tabRame[i].get_numero()) + " nb passager : " + to_string(rame.get_passagers()) + "\n";
        }
        else
        {
            tableauTexte += "ligne N° : " + to_string(rame.get_ligne()) + " Rame N° : " + to_string(tabRame[i].get_numero()) + " nb passager : " + to_string(tabRame[i].get_passagers()) + "\n";
        }

    }
    text.setString(tableauTexte);
    text.setPosition(pos_x, 0);
}

bool aGauche(Station actuelle, Station prochaine) {
    if (actuelle.getPositionX() > prochaine.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool aDroite(Station actuelle, Station prochaine) {
    if (actuelle.getPositionX() < prochaine.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool enHaut(Station actuelle, Station prochaine) {
    if (actuelle.getPositionY() > prochaine.getPositionY()) {
        return true;
    }
    else {
        return false;
    }
}

bool enBas(Station actuelle, Station prochaine) {
    if (actuelle.getPositionY() < prochaine.getPositionY()) {
        return true;
    }
    else {
        return false;
    }
}

bool PreviousaGauche(Station previous, Station actuelle) {
    if (previous.getPositionX() < actuelle.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool PreviousaDroite(Station previous, Station actuelle) {
    if (previous.getPositionX() > actuelle.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool PreviousenHaut(Station previous, Station actuelle) {
    if (previous.getPositionY() < actuelle.getPositionY()) {
        return true;
    }
    else {
        return false;
    }
}

bool PreviousenBas(Station previous, Station actuelle) {
    if (previous.getPositionY() > actuelle.getPositionY()) {
        return true;
    }
    else {
        return false;
    }
}

void moveRame(Rame& rame, Rame& rame_apres, vector<Station> listeStations, bool beginning, vector<Rame>& tabRame, Text& text) {
    if (!beginning) {
        default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> randomNum{ 4, 10 };
        //cout << randomNum(re) << endl;
        this_thread::sleep_for(chrono::seconds(randomNum(re)));
    }

    bool reverseOrder = false; //par défaut, on inverse pas la liste des stations de la ligne

    while (true) { //boucle infinie, pour recommencer indéfiniment le parcours de la ligne pour la rame
        rame.setFreinage(false); //par défaut, on set la rame comme sur la voie (pas en direction de station blanche)
        if (reverseOrder) { //si l'inversement de liste des stations de la ligne est activé
            reverse(listeStations.begin(), listeStations.end()); //on inverse la liste
        }

        for (int i = 0; i < listeStations.size(); i++) {

            float dist_entre_2_stations_x = 0.0; //initialisation de la distance entre la station en cours et la suivante en x
            float dist_entre_2_stations_y = 0.0; //initialisation de la distance entre la station en cours et la suivante en y

            if (i == listeStations.size() - 1) { //si on est à la dernière station
                rame.setFreinage(true); //si la rame se dirige vers une station blanche, on la set en mode freinage
            }
            else if (i == listeStations.size() - 2) { //si on est à la dernière station avant le terminus
                dist_entre_2_stations_x = abs(listeStations[listeStations.size() - 2].getPositionX() - listeStations[listeStations.size() - 3].getPositionX());
                dist_entre_2_stations_y = abs(listeStations[listeStations.size() - 2].getPositionY() - listeStations[listeStations.size() - 3].getPositionY());
            }
            else if (i != 0) { //sinon
                cout << listeStations[i].getPositionX() << " " << listeStations[i - 1].getPositionX() << endl;
                dist_entre_2_stations_x = abs(listeStations[i].getPositionX() - listeStations[i - 1].getPositionX());
                dist_entre_2_stations_y = abs(listeStations[i].getPositionY() - listeStations[i - 1].getPositionY());
            }
            else if (i == 0) {
                dist_entre_2_stations_x = abs(listeStations[i + 1].getPositionX() - listeStations[i].getPositionX());
                dist_entre_2_stations_y = abs(listeStations[i + 1].getPositionY() - listeStations[i].getPositionY());
            }
            float end_pos_x = listeStations[i].getPositionX(); //position x à atteindre (station suivante)
            float end_pos_y = listeStations[i].getPositionY(); //position y à atteindre (station suivante)

            //gestion de la position d'arret si virage
            bool HAUT = false;
            bool BAS = false;
            bool GAUCHE = false;
            bool DROITE = false;
            if (i < listeStations.size() - 1) {
                HAUT = enHaut(listeStations[i], listeStations[i + 1]);
                BAS = enBas(listeStations[i], listeStations[i + 1]);
                GAUCHE = aGauche(listeStations[i], listeStations[i + 1]);
                DROITE = aDroite(listeStations[i], listeStations[i + 1]);
            }

            bool PrevGAUCHE = false;
            bool PrevDROITE = false;
            bool PrevHAUT = false;
            bool PrevBAS = false;
            if (i != 0) {
                PrevHAUT = PreviousenHaut(listeStations[i-1], listeStations[i]);
                PrevBAS = PreviousenBas(listeStations[i-1], listeStations[i]);
                PrevGAUCHE = PreviousaGauche(listeStations[i-1], listeStations[i]);
                PrevDROITE = PreviousaDroite(listeStations[i-1], listeStations[i]);
            }

            if (i != 0) {
                if (BAS && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    end_pos_x -= 15;
                }
                if (PrevHAUT && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    end_pos_y += 15;
                }
                if (PrevHAUT && !rame.getRetour() && (!GAUCHE && !DROITE)) {
                    end_pos_y -= 15;
                }
                if (PrevHAUT && !rame.getRetour()) {
                    end_pos_x -= 15;
                }
                if (PrevBAS && rame.getRetour() && (!GAUCHE && !DROITE)) {
                    end_pos_y += 15;
                }
                if (PrevBAS && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    end_pos_y -= 15;
                }
                if (HAUT && rame.getRetour() && listeStations[i].isVirage()) {
                    end_pos_x += 15;
                }
                if (PrevBAS && rame.getRetour()) {
                    end_pos_x += 15;
                }
                if (HAUT && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    end_pos_x += 15;
                }
                if (BAS && !rame.getRetour() && listeStations[i].isVirage()) {
                    end_pos_x -= 15;
                }

                //rotation
                if (HAUT && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateGauche();
                }
                if (BAS && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (GAUCHE && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateGauche();
                }
                if (DROITE && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (HAUT && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (BAS && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateGauche();
                }
                if (GAUCHE && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (DROITE && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
            }

            if (GAUCHE && PrevHAUT && rame.getRetour()) {
                end_pos_x -= 15;
            }

            if (DROITE && PrevBAS && !rame.getRetour()) {
                end_pos_x += 15;
            }

            int v; //initialisation de la vitesse

            while ((rame.get_position_x() != end_pos_x) || (rame.get_position_y() != end_pos_y)) {
                float distanceToStation_x = abs(end_pos_x - rame.get_position_x()); //distance x jusqu'a la prochaine station par rapport a la position x actuelle de la rame
                float distanceToStation_y = abs(end_pos_y - rame.get_position_y()); //distance x jusqu'a la prochaine station par rapport a la position x actuelle de la rame
                bool authorize_move = true; //on autorise le déplacement
                rame.setArrete(false); //la rame n'est pas en etat d'arret
                int dist_entre_rames_x = abs(rame_apres.get_position_x() - rame.get_position_x()); //distance entre la rame actuelle et celle devant
                int dist_entre_rames_y = abs(rame_apres.get_position_y() - rame.get_position_y()); //distance entre la rame actuelle et celle devant

                if (rame.getHorizontal()) {
                    if (dist_entre_rames_x == 0 && beginning == false) { //évite que des rames partent dans le mauvais ordre lors de la génération des threads
                        authorize_move = false;
                    }
                    if (distanceToStation_x >= (2.0 / 3.0) * dist_entre_2_stations_x) {
                        //on accélère la rame sur le premier tiers de la distance
                        v = 1;
                        cout << "Accelere" << endl;
                    }
                    else if (distanceToStation_x >= (1.0 / 3.0) * dist_entre_2_stations_x) {
                        //on maintient une vitesse constante pour la rame sur le deuxième tiers de la distance
                        v = 10;
                        cout << "Constant" << endl;
                    }
                    else if (distanceToStation_x < (1.0 / 3.0) * dist_entre_2_stations_x) {
                        //si une rame se rapproche d'une station (dernier tiers de la distance), on freine son déplacement
                        v = 30;
                        cout << "Freine" << endl;
                    }
                    if (rame.isFreinage()) {
                        //si la rame se dirige vers une station blanche, on ralentit sa vitesse
                        v = 30;
                    }
                    if (dist_entre_rames_x < 150 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal()) {
                        //si 2 rames se suivant sur une même voie ont une distance faible, on freine le deplacement de la rame derrière
                        v = 30;
                    }
                    if (dist_entre_rames_x < 100 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal()) {
                        //si 2 rames se suivant sur une même voie ont une distance trop faible, on interdit le deplacement de la rame derrière
                        authorize_move = false;
                    }
                }
                if(!rame.getHorizontal()) {
                    if (dist_entre_rames_y == 0 && beginning == false) { //évite que des rames partent dans le mauvais ordre lors de la génération des threads
                        authorize_move = false;
                    }
                    if (distanceToStation_y >= (2.0 / 3.0) * dist_entre_2_stations_y) {
                        //on accélère la rame sur le premier tiers de la distance
                        v = 1;
                        cout << "Accelere" << endl;
                    }
                    else if (distanceToStation_y >= (1.0 / 3.0) * dist_entre_2_stations_y) {
                        //on maintient une vitesse constante pour la rame sur le deuxième tiers de la distance
                        v = 10;
                        cout << "Constant" << endl;
                    }
                    else if (distanceToStation_y < (1.0 / 3.0) * dist_entre_2_stations_y) {
                        //si une rame se rapproche d'une station (dernier tiers de la distance), on freine son déplacement
                        v = 30;
                        cout << "Freine" << endl;
                    }
                    if (dist_entre_rames_y < 150 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal()) {
                        //si 2 rames se suivant sur une même voie ont une distance faible, on freine le deplacement de la rame derrière
                        v = 30;
                    }
                    if (dist_entre_rames_y < 100 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal()) {
                        //si 2 rames se suivant sur une même voie ont une distance trop faible, on interdit le deplacement de la rame derrière
                        authorize_move = false;
                    }
                }

                if (authorize_move) {
                    rame.setStarted(true); // on set la rame comme démarrée

                    // déplacement horizontal
                    if (rame.get_position_y() == end_pos_y || rame.get_position_y() != end_pos_y) {
                        // si direction vers gauche
                        if (end_pos_x < rame.get_position_x()) {
                            rame.moveGauche();
                            rame.set_position_x(rame.get_position_x() - 1);
                        }
                        // si direction vers droite
                        else if (end_pos_x > rame.get_position_x()) {
                            rame.moveDroite();
                            rame.set_position_x(rame.get_position_x() + 1);
                        }
                    }

                    // déplacement vertical
                    if (rame.get_position_x() == end_pos_x) {
                        // si déplacement vers haut
                        if (end_pos_y < rame.get_position_y()) {
                            rame.moveHaut();
                            rame.set_position_y(rame.get_position_y() - 1);
                        }
                        // si déplacement vers bas
                        else if (end_pos_y > rame.get_position_y()) {
                            rame.moveBas();
                            rame.set_position_y(rame.get_position_y() + 1);
                        }
                    }
                }
                this_thread::sleep_for(chrono::milliseconds(v)); //réglage de la vitesse de la rame
            }
            if (i > 1 && i < listeStations.size() - 2) { //si on ne se situe pas sur un terminus
                int nb_entrant = remplire_rame(rame, listeStations[i]);
                int nb_sortant = sortire(rame);

                int temp_attente = (int)(nb_entrant + nb_sortant) / 10;
                if (temp_attente < 2)
                {
                    temp_attente = 2;
                }
                
                //si on est sur une station blanche
                if (i == 0 || i == listeStations.size() - 1) {
                    temp_attente = 2;
                }
                this_thread::sleep_for(chrono::seconds(temp_attente)); //pause dans les stations
            }
            else if (i == 1) {
                int nb_entrant = remplire_rame(rame, listeStations[i]);
                int temp_attente = (int)(nb_entrant) / 10;
               
                if (temp_attente < 2)
                {
                    temp_attente = 2;
                }
                
                this_thread::sleep_for(chrono::seconds(temp_attente)); //pause dans les stations
            }
            else if (i == listeStations.size() - 2) {
                int nb_attente = (int)(rame.get_passagers()) / 10;
                rame.set_passagers(0);
                if (nb_attente < 2)
                {
                    nb_attente = 2;
                }

                this_thread::sleep_for(chrono::seconds(nb_attente)); //pause dans les stations

            }
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

            if (HAUT || BAS) {
                rame.setHorizontal(false);
            }
            if (GAUCHE || DROITE) {
                rame.setHorizontal(true);
            }
        }
    }
}