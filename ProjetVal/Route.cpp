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
	hauteur = station1_y - station2_y;
	couleur = color;
}

int Route::get_id_voie() {
	return id_voie;
}

int Route::get_longueur() {
	return longueur;
}

int Route::get_hauteur() {
	return hauteur;
}

void Route::setRepr() {
	if (hauteur == 0) {
		representation.setSize(Vector2f(longueur, epaisseur));
		representation.setPosition(station1_x, station1_y + 6);
	}
	if (longueur == 0 && station1_y < station2_y) { //verticale descendante
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x - 10, station1_y);
	}
	if (longueur == 0 && station1_y > station2_y) { //verticale montante
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x + 6, station1_y);
	}
	representation.setFillColor(couleur);
}

void Route::setReprRetour() {
	if (hauteur == 0) {
		representation.setSize(Vector2f(longueur, epaisseur));
		representation.setPosition(station1_x, station1_y - 10);
	}
	if (longueur == 0 && station1_y < station2_y) {
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x + 6, station1_y);
	}
	if (longueur == 0 && station1_y > station2_y) {
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x - 10, station1_y);
	}
	representation.setFillColor(couleur);
}

RectangleShape Route::getRepr() {
	return representation;
}