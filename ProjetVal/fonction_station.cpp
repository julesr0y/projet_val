#include "fonction_station.hpp"
#include<iostream>
#include <random>
#include <ctime>
#include<chrono>

using namespace std;

int remplire_rame(Rame& rame, Station& station) {
    //cout << "======================================================================================" << endl;
    //cout << endl;

    int nb_max = 100;
    default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> randomNum{ 0, 50};
    int nb = randomNum(re);
    station.setNbPassagers(nb);
    //cout << "nb passager dans la station " << station.getNbPassagers() << endl;
    //cout << "nb dans la rame avant : " << rame.get_passagers() << endl;

    if (rame.get_passagers() + nb < nb_max)
    {
        rame.set_passagers(rame.get_passagers() + nb);
        //cout << "nb dans la rame apres entrer: " << rame.get_passagers() << endl;
        station.setNbPassagers(station.getNbPassagers() - nb);
        //cout << "nb passager dans la station " << station.getNbPassagers() << endl;

        return  nb; 
    }
    else
    {
        int nb_à_entrer = nb_max - rame.get_passagers();
        rame.set_passagers(rame.get_passagers()+nb_à_entrer);
        //cout << "nb dans la rame apres entrer  : " << rame.get_passagers() << endl;

        station.setNbPassagers(station.getNbPassagers() - nb_à_entrer );
        //cout << "nb passager dans la station " << station.getNbPassagers() << endl;

        return nb_à_entrer;
    }
    
}

int sortire(Rame& rame) {
    default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> randomNum{ 0, 20 };
    int nb = randomNum(re);
    if (nb<rame.get_passagers())
    {
        //cout << "nb sortant " << nb << endl;
        rame.set_passagers(rame.get_passagers() - nb);
        //cout << "nb dans la rame  apres sorti : " << rame.get_passagers() << endl;

    }
    else
    {
        //cout << "nb sortant " << nb << endl;
        rame.set_passagers(0);
        //cout << "nb dans la rame  apres sorti : " << rame.get_passagers() << endl;


    }

    return nb;

}