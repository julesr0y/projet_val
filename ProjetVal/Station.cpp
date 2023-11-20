#include <iostream>
#include "Station.hpp"

using namespace std;
using namespace sf;

Station::Station() {};

Station::Station(int id, string name, float x, float y, int nbpassagers) {
	id_station = id;
	nom = name;
	position[0] = x;
	position[1] = y;
	nb_passagers = nbpassagers;
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
	representation.setRadius(20);
	representation.setPosition(position[0], position[1]);
	representation.setFillColor(Color::Red);
}

CircleShape Station::getRepr() {
	return representation;
}