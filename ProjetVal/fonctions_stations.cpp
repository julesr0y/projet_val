#include "headers/fonctions_stations.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

int remplire_rame(Rame& rame, Station& station) {
    int nb_max = 100;
    default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> randomNum{ 0, 50};
    int nb = randomNum(re);
    station.setNbPassagers(nb);

    if (rame.get_passagers() + nb < nb_max) {
        rame.set_passagers(rame.get_passagers() + nb);
        station.setNbPassagers(station.getNbPassagers() - nb);

        return nb;
    }
    else {
        int nb_a_entrer = nb_max - rame.get_passagers();
        rame.set_passagers(rame.get_passagers() + nb_a_entrer);
        station.setNbPassagers(station.getNbPassagers() - nb_a_entrer );

        return nb_a_entrer;
    }
    
}

int sortire(Rame& rame) {
    default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> randomNum{ 0, 20 };
    int nb = randomNum(re);

    if (nb < rame.get_passagers()) {
        rame.set_passagers(rame.get_passagers() - nb);
    }
    else {
        rame.set_passagers(0);
    }

    return nb;
}