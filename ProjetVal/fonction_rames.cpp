#include "fonction_rames.hpp"
#include <iostream>

void moveRame(Rame& rame, Station& destination) {
    float end_pos_x = destination.getPositionX();
    float end_pos_y = destination.getPositionY();
    float distance_x = end_pos_x - rame.get_position_x();
    float distance_y = end_pos_y - rame.get_position_y();
    const float distance = abs(distance_x * distance_x + distance_y * distance_y);
    int v;
    //cout << "(" << rame.get_position_x() << ";" << rame.get_position_y() << ")" << endl;
    while ((rame.get_position_x() != end_pos_x) || (rame.get_position_y() != end_pos_y)) {
        distance_x = end_pos_x - rame.get_position_x();
        distance_y = end_pos_y - rame.get_position_y();
        float distance_var = abs(distance_x * distance_x + distance_y * distance_y);
        if (distance_var>=(1/3)* distance)
        {
            std::cout << 1 / 3 << endl;
            v = 1;
            //rame.set_vitesse(1);
        }
        if (distance_var <= (1 / 3) * distance && distance_var >= (2 / 3) * distance)
        {
            std::cout << 2 / 3 << endl;
            v = 10;
            //rame.set_vitesse(10);
        }
        if (distance_var <= (2/ 3) * distance && distance_var >=distance)
        {
            std::cout << 1  << endl;
            v = 1000;
            //rame.set_vitesse(1000);
        }

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
        this_thread::sleep_for(chrono::milliseconds(v)); // Adjust the sleep duration
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