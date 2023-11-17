#include <iostream>
#include "Route.hpp"
#include "Station.hpp"
using namespace std;
using namespace sf;

Route::Route(int id, float longueur, Station station1, Station station2) {
	id = id_voie;
	station_depart = station1;
	station_arrivee = staion2;
	//int position1 = station1.position[x][y];
}

void Route::get_id_voie() {
	return id_voie;
}

void Route::get_longueur() {
	return longueur;
}
void Route::get_position() {
	return position;
}

void Route::setRepr() {
	representation.setOutlineThickness(20);
	representation.setPosition(station_depart.getPosition().x,station_arrivee.getPosition().x);
	//representation.setPosition(station_depart.getPosition().y,station_arrivee.getPosition().y);
	representation.setFillColor(Color::Blue);
}

RectangleShape Route::getRepr() {
	return representation;
}