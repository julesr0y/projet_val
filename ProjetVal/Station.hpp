#ifndef STATION_H
#define STATION_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Station {
private:
	int id_station;
	string nom;
	float position[2];
	int nb_passagers;
	//float temps;
	CircleShape representation;
	float rayon = 20;
	Color couleur;

public:
	Station();
	Station(int id, string name, float x, float y, int nbpassagers, Color color);
	//Stations ~Stations();
	int getIdStation();
	string getNom();
	float getPositionX();
	float getPositionY();
	int getNbPassagers();
	//bool estVide();
	void setRepr();
	CircleShape getRepr();
};

#endif STATION_H