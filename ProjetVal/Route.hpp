#ifndef ROUTE_H
#define ROUTE_H

#include "Rame.hpp"

using namespace std;
using namespace sf;

class Route {
private:
	int id_voie;
	float longueur;
	RectangleShape representation;
	int epaisseur = 8;
	Station station_depart;
	Station station_arrivee;
	float station1_x;
	float station1_y;
	float station2_x;
	float station2_y;
public:
	Route();
	Route(int id, Station station1, Station station2);
	int get_id_voie();
	int get_longueur();
	void setRepr();
	void Route::setReprRetour();
	RectangleShape getRepr();
};

#endif ROUTE_H