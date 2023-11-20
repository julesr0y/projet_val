#include <iostream>
#include "Route.hpp"

using namespace std;
using namespace sf;

Route::Route(int id, Station station1, Station station2) {
	id_voie = id;
	station_depart = station1;
	station_arrivee = station2;
	station1_x = station1.getPositionX();
	station1_y = station1.getPositionY();
	station2_x = station2.getPositionX();
	station2_y = station2.getPositionY();
	longueur = station2_x - station1_x;
}

int Route::get_id_voie() {
	return id_voie;
}

int Route::get_longueur() {
	return longueur;
}

void Route::setRepr() {
	representation.setSize(Vector2f(longueur, epaisseur));
	representation.setPosition(station1_x, station1_y + 20);
	representation.setFillColor(Color::Red);
}

RectangleShape Route::getRepr() {
	return representation;
}