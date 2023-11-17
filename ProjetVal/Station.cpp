#include <iostream>
#include "Station.hpp"

using namespace std;
using namespace sf;

Station::Station(int id, string name, int x, int y, int nbpassagers) {
	id_station = id;
	nom = name;
	position[0] = x;
	position[1] = y;
	nb_passagers = nbpassagers;
}

void Station::setRepr() {
	representation.setRadius(20);
	representation.setPosition(position[0], position[1]);
	representation.setFillColor(Color::Red);
}

CircleShape Station::getRepr() {
	return representation;
}