#include "headers/fonctions_rames.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include "headers/fonctions_stations.hpp"

constexpr auto AJUSTEMENT = 8;
constexpr auto CHGT_VOIE = 16;
constexpr auto VITESSE_FREINAGE = 120;
constexpr auto VITESSE_CONSTANTE = 40;
constexpr auto VITESSE_ACCELERATION = 10;

using namespace std;

void updateRameText(Text& text, vector<Rame>& tabRame, Rame rame, int pos_x, int pos_y) {
    string tableauTexte;
    for (size_t i = 0; i < tabRame.size(); i++) {
        if (rame.get_numero() == tabRame[i].get_numero())
        {
            tabRame[i].set_passagers(rame.get_passagers());
            tableauTexte += "Ligne " + to_string(rame.get_ligne()) + " Rame " + to_string(tabRame[i].get_numero()) + "; Passagers : " + to_string(rame.get_passagers()) + "\n";
        }
        else
        {
            tableauTexte += "Ligne " + to_string(rame.get_ligne()) + " Rame " + to_string(tabRame[i].get_numero()) + "; Passagers : " + to_string(tabRame[i].get_passagers()) + "\n";
        }

    }
    text.setString(tableauTexte);
    text.setPosition(pos_x, pos_y);
}

bool nextGauche(Station actuelle, Station prochaine) {
    if (actuelle.getPositionX() > prochaine.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool nextDroite(Station actuelle, Station prochaine) {
    if (actuelle.getPositionX() < prochaine.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool nextHaut(Station actuelle, Station prochaine) {
    if (actuelle.getPositionY() > prochaine.getPositionY()) {
        return true;
    }
    else {
        return false;
    }
}

bool nextBas(Station actuelle, Station prochaine) {
    if (actuelle.getPositionY() < prochaine.getPositionY()) {
        return true;
    }
    else {
        return false;
    }
}

bool previousGauche(Station previous, Station actuelle) {
    if (previous.getPositionX() < actuelle.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool previousDroite(Station previous, Station actuelle) {
    if (previous.getPositionX() > actuelle.getPositionX()) {
        return true;
    }
    else {
        return false;
    }
}

bool previousHaut(Station previous, Station actuelle) {
    if (previous.getPositionY() < actuelle.getPositionY()) {
        return true;
    }
    else {
        return false;
    }
}

bool previousBas(Station previous, Station actuelle) {
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
        this_thread::sleep_for(chrono::seconds(randomNum(re)));
    }

    bool reverseOrder = false; //par defaut, on inverse pas la liste des stations de la ligne

    while (true) { //boucle infinie, pour recommencer indefiniment le parcours de la ligne pour la rame
        rame.setFreinage(false); //par defaut, on set la rame comme sur la voie (pas en direction de station blanche)
        if (reverseOrder) { //si l'inversement de liste des stations de la ligne est active
            reverse(listeStations.begin(), listeStations.end()); //on inverse la liste
        }

        for (int i = 0; i < listeStations.size(); i++) {

            float dist_entre_2_stations_x = 0.0; //initialisation de la distance entre la station en cours et la suivante en x
            float dist_entre_2_stations_y = 0.0; //initialisation de la distance entre la station en cours et la suivante en y

            if (i == listeStations.size() - 1) { //si on est a la derniere station
                rame.setFreinage(true); //si la rame se dirige vers une station blanche, on la set en mode freinage
            }
            else if (i == listeStations.size() - 2) { //si on est a la derniere station avant le terminus
                dist_entre_2_stations_x = abs(listeStations[listeStations.size() - 2].getPositionX() - listeStations[listeStations.size() - 3].getPositionX());
                dist_entre_2_stations_y = abs(listeStations[listeStations.size() - 2].getPositionY() - listeStations[listeStations.size() - 3].getPositionY());
            }
            else if (i != 0) { //sinon
                dist_entre_2_stations_x = abs(listeStations[i].getPositionX() - listeStations[i - 1].getPositionX());
                dist_entre_2_stations_y = abs(listeStations[i].getPositionY() - listeStations[i - 1].getPositionY());
            }
            else if (i == 0) {
                dist_entre_2_stations_x = abs(listeStations[i + 1].getPositionX() - listeStations[i].getPositionX());
                dist_entre_2_stations_y = abs(listeStations[i + 1].getPositionY() - listeStations[i].getPositionY());
            }
            float end_pos_x = listeStations[i].getPositionX(); //position x a atteindre (station suivante)
            float end_pos_y = listeStations[i].getPositionY() - 3; //position y a atteindre (station suivante)

            //gestion de la position d'arret si virage
            bool NextHAUT = false;
            bool NextBAS = false;
            bool NextGAUCHE = false;
            bool NextDROITE = false;
            if (i < listeStations.size() - 1) {
                NextHAUT = nextHaut(listeStations[i], listeStations[i + 1]);
                NextBAS = nextBas(listeStations[i], listeStations[i + 1]);
                NextGAUCHE = nextGauche(listeStations[i], listeStations[i + 1]);
                NextDROITE = nextDroite(listeStations[i], listeStations[i + 1]);
            }

            bool PrevGAUCHE = false;
            bool PrevDROITE = false;
            bool PrevHAUT = false;
            bool PrevBAS = false;
            if (i != 0) {
                PrevHAUT = previousHaut(listeStations[i-1], listeStations[i]);
                PrevBAS = previousBas(listeStations[i-1], listeStations[i]);
                PrevGAUCHE = previousGauche(listeStations[i-1], listeStations[i]);
                PrevDROITE = previousDroite(listeStations[i-1], listeStations[i]);
            }

            //position d'arret a la station en fonction de direction precedente et suivante
            if (i != 0 && i < listeStations.size()) {
                if (!rame.getRetour()) {
                    //exterieur gauche
                    if (PrevBAS && listeStations[i - 1].isVirage()) {
                        end_pos_x += AJUSTEMENT;
                        end_pos_y -= AJUSTEMENT;
                    }
                    //interieur droite
                    if (PrevGAUCHE && NextBAS) {
                        end_pos_x -= AJUSTEMENT;
                    }
                    //descente apres interieur droite
                    if (PrevHAUT && listeStations[i - 1].isVirage()) {
                        end_pos_x -= AJUSTEMENT;
                        end_pos_y -= AJUSTEMENT;
                    }
                    //continue descente
                    if (PrevHAUT && !listeStations[i - 1].isVirage()) {
                        end_pos_x -= AJUSTEMENT;
                    }
                    //continue montee
                    if (PrevBAS && !listeStations[i - 1].isVirage()) {
                        end_pos_x += AJUSTEMENT;
                    }
                }

                if (rame.getRetour()) {
                    if (PrevBAS && (!NextGAUCHE && !NextDROITE)) {
                        end_pos_y += AJUSTEMENT;
                    }
                    if (NextHAUT && listeStations[i].isVirage()) {
                        end_pos_x += AJUSTEMENT;
                    }
                    if (PrevBAS) {
                        end_pos_x += AJUSTEMENT;
                    }
                    //exterieur gauche
                    if (PrevHAUT && listeStations[i - 1].isVirage()) {
                        end_pos_x -= AJUSTEMENT;
                        end_pos_y += AJUSTEMENT;
                    }
                    if (PrevHAUT && !listeStations[i - 1].isVirage()) {
                        end_pos_x -= AJUSTEMENT;
                    }
                }

                //rotation
                if (NextHAUT && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (NextBAS && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateGauche();
                }
                if (NextDROITE && rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (NextHAUT && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateGauche();
                }
                if (NextBAS && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (NextGAUCHE && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                    rame.rotateDroite();
                }
                if (i >= 2) {
                    if (listeStations[i - 2].getPositionY() > listeStations[i - 1].getPositionY() && NextGAUCHE && rame.getRetour() && listeStations[i - 1].isVirage()) {
                        rame.rotateGauche();
                    }
                    if (listeStations[i - 2].getPositionY() < listeStations[i - 1].getPositionY() && NextGAUCHE && rame.getRetour() && listeStations[i - 1].isVirage()) {
                        rame.rotateDroite();
                    }
                    if (listeStations[i - 2].getPositionY() > listeStations[i - 1].getPositionY() && NextDROITE && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                        rame.rotateDroite();
                    }
                    if (listeStations[i - 2].getPositionY() < listeStations[i - 1].getPositionY() && NextDROITE && !rame.getRetour() && listeStations[i - 1].isVirage()) {
                        rame.rotateGauche();
                    }
                }
            }

            if (i != 0) {
                if(listeStations[i].getPositionY() == listeStations[i - 1].getPositionY()) {
                    rame.setHorizontal(true);
                }
                if (listeStations[i].getPositionX() == listeStations[i - 1].getPositionX()) {
                    rame.setHorizontal(false);
                }
            }

            int v; //initialisation de la vitesse

            while ((rame.get_position_x() != end_pos_x) || (rame.get_position_y() != end_pos_y)) {
                float distanceToStation_x = abs(end_pos_x - rame.get_position_x()); //distance x jusqu'a la prochaine station par rapport a la position x actuelle de la rame
                float distanceToStation_y = abs(end_pos_y - rame.get_position_y()); //distance x jusqu'a la prochaine station par rapport a la position x actuelle de la rame
                bool authorize_move = true; //on autorise le deplacement
                rame.setArrete(false); //la rame n'est pas en etat d'arret
                int dist_entre_rames_x = abs(rame_apres.get_position_x() - rame.get_position_x()); //distance entre la rame actuelle et celle devant
                int dist_entre_rames_y = abs(rame_apres.get_position_y() - rame.get_position_y()); //distance entre la rame actuelle et celle devant

                if (rame.getHorizontal()) {
                    if (dist_entre_rames_x == 0 && beginning == false) { //evite que des rames partent dans le mauvais ordre lors de la generation des threads
                        authorize_move = false;
                    }
                    if (distanceToStation_x >= (2.0 / 3.0) * dist_entre_2_stations_x) {
                        //on accelere la rame sur le premier tiers de la distance
                        v = VITESSE_ACCELERATION;
                    }
                    else if (distanceToStation_x >= (1.0 / 3.0) * dist_entre_2_stations_x) {
                        //on maintient une vitesse constante pour la rame sur le deuxieme tiers de la distance
                        v = VITESSE_CONSTANTE;
                    }
                    else if (distanceToStation_x < (1.0 / 3.0) * dist_entre_2_stations_x) {
                        //si une rame se rapproche d'une station (dernier tiers de la distance), on freine son deplacement
                        v = VITESSE_FREINAGE;
                    }
                    if (rame.isFreinage()) {
                        //si la rame se dirige vers une station blanche, on ralentit sa vitesse
                        v = VITESSE_FREINAGE;
                    }
                    if (dist_entre_rames_x < 150 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal() && rame_apres.get_position_y() == rame.get_position_y()) {
                        //si 2 rames se suivant sur une meme voie ont une distance faible, on freine le deplacement de la rame derriere
                        v = VITESSE_FREINAGE;
                    }
                    if (dist_entre_rames_x < 100 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal() && rame_apres.get_position_y() == rame.get_position_y()) {
                        //si 2 rames se suivant sur une meme voie ont une distance trop faible, on interdit le deplacement de la rame derriere
                        authorize_move = false;
                    }
                    else if (rame.get_arret_urgence() == true) {
                        authorize_move = false;
                    }
                }
                if(!rame.getHorizontal()) {
                    if (dist_entre_rames_y == 0 && beginning == false) { //evite que des rames partent dans le mauvais ordre lors de la generation des threads
                        authorize_move = false;
                    }
                    if (distanceToStation_y >= (2.0 / 3.0) * dist_entre_2_stations_y) {
                        //on accelere la rame sur le premier tiers de la distance
                        v = VITESSE_ACCELERATION;
                    }
                    else if (distanceToStation_y >= (1.0 / 3.0) * dist_entre_2_stations_y) {
                        //on maintient une vitesse constante pour la rame sur le deuxieme tiers de la distance
                        v = VITESSE_CONSTANTE;
                    }
                    else if (distanceToStation_y < (1.0 / 3.0) * dist_entre_2_stations_y) {
                        //si une rame se rapproche d'une station (dernier tiers de la distance), on freine son deplacement
                        v = VITESSE_FREINAGE;
                    }
                    if (dist_entre_rames_y < 150 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal() && rame_apres.get_position_x() == rame.get_position_x()) {
                        //si 2 rames se suivant sur une meme voie ont une distance faible, on freine le deplacement de la rame derriere
                        v = 30;
                    }
                    if (dist_entre_rames_y < 100 && rame_apres.hasStarted() == true && rame_apres.getRetour() == rame.getRetour() && rame_apres.getHorizontal() == rame.getHorizontal() && rame_apres.get_position_x() == rame.get_position_x()) {
                        //si 2 rames se suivant sur une meme voie ont une distance trop faible, on interdit le deplacement de la rame derriere
                        authorize_move = false;
                    }
                    else if (rame.get_arret_urgence() == true) {
                        authorize_move = false;
                    }
                }

                if (authorize_move) {
                    rame.setStarted(true); // on set la rame comme demarree

                    // deplacement horizontal
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

                    // deplacement vertical
                    if (rame.get_position_x() == end_pos_x) {
                        // si deplacement vers haut
                        if (end_pos_y < rame.get_position_y()) {
                            rame.moveHaut();
                            rame.set_position_y(rame.get_position_y() - 1);
                        }
                        // si deplacement vers bas
                        else if (end_pos_y > rame.get_position_y()) {
                            rame.moveBas();
                            rame.set_position_y(rame.get_position_y() + 1);
                        }
                    }
                }
                this_thread::sleep_for(chrono::milliseconds(v)); //reglage de la vitesse de la rame
            }
            if (i > 1 && i < listeStations.size() - 2) { //si on ne se situe pas sur un terminus
                int nb_entrant = remplir_rame(rame, listeStations[i]);
                int nb_sortant = sortir(rame);

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
                int nb_entrant = remplir_rame(rame, listeStations[i]);
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
                rame.set_position_y(rame.get_position_y() + CHGT_VOIE); //on monte la position y de la rame
                rame.rotate180(); //on tourne la rame de 180 degres
                rame.setRetour(true); //on active le mode retour (voie superieure)
                reverseOrder = true; //on active l'inversion de la liste des stations
            }
            ////descend
            else if (rame.estArrete() && rame.getRetour()) {
                rame.set_position_y(rame.get_position_y() - CHGT_VOIE); //on descend la position y de la rame
                rame.rotate180(); //on tourne la rame de 180 degres
                rame.setRetour(false); //on enleve le mode retour (voie inferieure)
                reverseOrder = true; //on active l'inversion de la liste des stations
            }
        }
    }
}

void arret_urgence_window(RenderWindow& window, Event event, Rame& R1_1, Rame& R1_2, Rame& R1_3, Rame& R1_4, Rame& R1_5, Rame& R1_6, Rame& R2_1, Rame& R2_2, Rame& R2_3, Rame& R2_4, Rame& R2_5, Rame& R2_6) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            Vector2i mousePosition = Mouse::getPosition(window);
            Vector2f convertedMousePosition = window.mapPixelToCoords(mousePosition);

            if (R1_1.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R1_1.set_arret_urgence(!R1_1.get_arret_urgence());
            }
            if (R1_2.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R1_2.set_arret_urgence(!R1_2.get_arret_urgence());
            }
            if (R1_3.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R1_3.set_arret_urgence(!R1_3.get_arret_urgence());
            }
            if (R1_4.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R1_4.set_arret_urgence(!R1_4.get_arret_urgence());
            }
            if (R1_5.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R1_5.set_arret_urgence(!R1_5.get_arret_urgence());
            }
            if (R1_6.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R1_6.set_arret_urgence(!R1_6.get_arret_urgence());
            }
            if (R2_1.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R2_1.set_arret_urgence(!R2_1.get_arret_urgence());
            }
            if (R2_2.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R2_2.set_arret_urgence(!R2_2.get_arret_urgence());
            }
            if (R2_3.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R2_3.set_arret_urgence(!R2_3.get_arret_urgence());
            }
            if (R2_4.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R2_4.set_arret_urgence(!R2_4.get_arret_urgence());
            }
            if (R2_5.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R2_5.set_arret_urgence(!R2_5.get_arret_urgence());
            }
            if (R2_6.getRepr().getGlobalBounds().contains(convertedMousePosition))
            {
                R2_6.set_arret_urgence(!R2_6.get_arret_urgence());
            }
        }
    }
}