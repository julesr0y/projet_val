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
	bool next_direction_haut;
	bool next_direction_bas;
	bool next_direction_gauche;
	bool next_direction_droite;
	bool virage;

public:
	Station();
	Station(int id, string name, float x, float y, int nbpassagers, Color color, bool terminus_, bool virage);
	//Stations ~Stations();
	int getIdStation();
	string getNom();
	float getPositionX();
	float getPositionY();
	int getNbPassagers();
	void setRepr();
	CircleShape getRepr();
	void setNbPassagers(int nb);
	bool get_terminus();
	void set_nom(string Snom);
	string get_nom();
	bool isVirage();
};