/**
	* @file Route.hpp
	* @brief Header de la classe Route
*/
#pragma once
#include "Rame.hpp"

using namespace std;
using namespace sf;

class Route {
private:
	// implémentation des variables
	int id_voie;
	float hauteur;
	float longueur;
	RectangleShape representation;
	int epaisseur = 4;
	Station station_depart;
	Station station_arrivee;
	float station1_x;
	float station1_y;
	float station2_x;
	float station2_y;
	Color couleur;

public:
	//constructeurs
	Route();
	Route(int id, Station station1, Station station2, Color color);

	//setters
	void setRepr();
	void setReprRetour();

	//getters
	int get_id_voie();
	int get_longueur();
	int get_hauteur();
	RectangleShape getRepr();
};