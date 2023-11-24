#include "Route.hpp"
#include <cmath>

using namespace std;
using namespace sf;

Route::Route() {}

Route::Route(int id, Station station1, Station station2) {
	id_voie = id;
	station_depart = station1;
	station_arrivee = station2;
	station1_x = station1.getPositionX();
	station1_y = station1.getPositionY();
	station2_x = station2.getPositionX();
	station2_y = station2.getPositionY();
	longueur = station2_x - station1_x;
	//longueur = sqrt(((int)station2_x - (int)station1_x)^2 + ((int)station1_y - (int)station2_y)^2);
}

int Route::get_id_voie() {
	return id_voie;
}

int Route::get_longueur() {
	return longueur;
}

void Route::setRepr() {
	representation.setSize(Vector2f(longueur, epaisseur));
	representation.setPosition(station1_x, station1_y);
	representation.setFillColor(Color::Red);
}

RectangleShape Route::getRepr() {
	return representation;
}