#include "Station.hpp"

using namespace std;
using namespace sf;

Station::Station() {};

Station::Station(int id, string name, float x, float y, int nbpassagers, Color color) {
	id_station = id;
	nom = name;
	position[0] = x;
	position[1] = y;
	nb_passagers = nbpassagers;
	couleur = color;
}

int Station::getIdStation() {
	return id_station;
}

string Station::getNom() {
	return nom;
}

float Station::getPositionX() {
	return position[0];
}

float Station::getPositionY() {
	return position[1];
}

int Station::getNbPassagers() {
	return nb_passagers;
}

void Station::setRepr() {
	representation.setRadius(rayon);
	representation.setPosition(position[0] - rayon, position[1] - rayon);
	representation.setFillColor(couleur);
}

CircleShape Station::getRepr() {
	return representation;
}

void Station::setNbPassagers(int nb) {
	nb_passagers = nb;
}