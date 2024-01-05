/**
	* @file Station.hpp
	* @brief Header de la classe Station
*/
#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Station {
private:
	int id_station;
	string nom;
	float position[2];
	int nb_passagers;
	CircleShape representation;
	float rayon = 10;
	Color couleur;
	bool terminus;
	bool virage;

public:
	//constructeurs
	Station();
	Station(int id, float x, float y, Color color, bool terminus_, bool virage);

	//setters
	void setRepr();
	void set_nom(string Snom);
	void setNbPassagers(int nb);

	//getters
	int getIdStation();
	string getNom();
	float getPositionX();
	float getPositionY();
	int getNbPassagers();
	CircleShape getRepr();
	bool get_terminus();
	string get_nom();
	bool isVirage();
};