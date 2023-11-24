#include <iostream>
#include "fonction_rames.hpp"

void moveRame(Rame& rame, float end_pos_x, float end_pos_y) {
    //cout << "(" << rame.get_position_x() << ";" << rame.get_position_y() << ")" << endl;
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


Rame get_rames_apres(vector<Rame>& liste, Rame& rame) {
    int i = 0;//recupere l'indice du rame dans la liste 
    while (liste[i].get_numero() == rame.get_numero())
    {
        i++;
    }
    //i++;
    //std::cout << i;
    if (i == 0)
    {
        return liste.back();
        //rame_avant_apres[1] = liste[i + 1];
        //return rame_avant_apres;
    }
    if (i == liste.size()) {
        //rame_avant_apres[1] = *liste.begin();
        return liste[i - 1];
        //return rame_avant_apres;
    }
    else
    {
        return liste[i - 1];
        //rame_avant_apres[1] = liste[i + 1];
        //return rame_avant_apres;
    }
}

void acceleration(vector<Rame>& liste, Rame& rame) {
    std::cout << "acceleration" << endl;
    Rame rame_apres = get_rames_apres(liste, rame);
    std::cout << "rame_id " << rame_apres.get_numero() << endl;

    std::cout << "rame3x " << rame_apres.get_position_x()<< endl;
    std::cout << "rame3y " << rame_apres.get_position_y() << endl;
    std::cout << "rame2x " << rame.get_position_x() << endl;
    std::cout << "rame2y " << rame.get_position_y() << endl;
    float distance_rame1_2_x = rame_apres.get_position_x() - rame.get_position_x();
    std::cout << "distance_x " << distance_rame1_2_x << endl;

    float distance_rame1_2_y = rame_apres.get_position_y() - rame.get_position_y();
    std::cout << "distance_y " << distance_rame1_2_y << endl;

    float distance = (distance_rame1_2_x * distance_rame1_2_x) + (distance_rame1_2_y * distance_rame1_2_y);
    std::cout << "distance "<<distance<<endl;
    if (distance > 2 * rame.get_distance_arret_urgence())
    {
        rame.vitesse_plus(30);
    }
}