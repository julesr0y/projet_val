#include "Route.hpp"

using namespace std;
using namespace sf;

Route::Route() {}

Route::Route(int id, Station station1, Station station2, Color color) {
	id_voie = id;
	station_depart = station1;
	station_arrivee = station2;
	station1_x = station1.getPositionX();
	station1_y = station1.getPositionY();
	station2_x = station2.getPositionX();
	station2_y = station2.getPositionY();
	longueur = station2_x - station1_x;
	couleur = color;
}

int Route::get_id_voie() {
	return id_voie;
}

int Route::get_longueur() {
	return longueur;
}

void Route::setRepr() {
	representation.setSize(Vector2f(longueur, epaisseur));
	representation.setPosition(station1_x, station1_y + 12);
	representation.setFillColor(couleur);
}

void Route::setReprRetour() {
	representation.setSize(Vector2f(longueur, epaisseur));
	representation.setPosition(station1_x, station1_y - 20);
	representation.setFillColor(couleur);
}

RectangleShape Route::getRepr() {
	return representation;
}