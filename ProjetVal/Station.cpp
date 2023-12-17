#include "headers/Station.hpp"

using namespace std;
using namespace sf;

Station::Station() {};

Station::Station(int id, string name, float x, float y, int nbpassagers, Color color, bool terminus_, bool vir) {
	id_station = id;
	nom = name;
	position[0] = x;
	position[1] = y;
	nb_passagers = nbpassagers;
	couleur = color;
	terminus = terminus_;
	virage = vir;
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

bool Station::get_terminus() {
	return terminus;
}

void Station::set_nom(string Snom) {
	nom = Snom;
}
string Station::get_nom() {
	return nom;
}

bool Station::isVirage() {
	return virage;
}