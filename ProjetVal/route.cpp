#include <iostream>
#include "Route.hpp"
#include "Station.hpp"

using namespace std;
using namespace sf;

Route::Route(int id, float longueur, Station station1, Station station2) {
	id = id_voie;
	station_depart = station1;
	station_arrivee = station2;
	//int position1 = station1.position[x][y];
}

int Route::get_id_voie() {
	return id_voie;
}

int Route::get_longueur() {
	return longueur;
}

void Route::setRepr() {
	representation.setOutlineThickness(20);
	representation.setPosition(station_depart,station_arrivee);
	//representation.setPosition(station_depart.getPosition().y,station_arrivee.getPosition().y);
	representation.setFillColor(Color::Blue);
}

RectangleShape Route::getRepr() {
	return representation;
}