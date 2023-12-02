#include "Rame.hpp"

using namespace std;
using namespace sf;

//constructeur
Rame::Rame() : representation(3){}

Rame::Rame(Station station_depart,int num) : representation(3)
{
	centre_x = station_depart.getPositionX();
	centre_y = station_depart.getPositionY();
	terminus = 0;
	numero = num;
	position_x = centre_x;
	position_y = centre_y;
	nb_passagers = 0;
	vitesse = 1;
	distance_arret_urgence = 3.4;//à voir 
	poids = 0;
}

Rame::Rame(Station station_depart) : representation(3) {
	centre_x = station_depart.getPositionX();
	centre_y = station_depart.getPositionY();
	terminus = 0;
	numero = 0;
	position_x = centre_x;
	position_y = centre_y;
	nb_passagers = 0;
	vitesse = 1;
	distance_arret_urgence = 3.4;//à voir 
	poids = 0;
}

//methodes de la classe
void Rame::vitesse_plus(int pourcentage) {
	vitesse += vitesse * (pourcentage / 100);
}


void Rame::vitesse_moins(int pourcentage) {
	vitesse -= vitesse * (pourcentage / 100);
}


//les setters
void Rame::set_distance_arret_urgence(float dis) {
	distance_arret_urgence = dis;
}

void Rame::set_numero(int nb) {
	numero = nb;
}

void Rame::set_passagers(int nb) {
	nb_passagers = nb;
}


void Rame::set_position_x(int x) {
	position_x = x;
}

void Rame::set_position_y(int y) {
	position_y = y;
}

void Rame::set_vitesse(float v) {
	vitesse = v;
}

void Rame::set_poids(float p) {
	poids = p;
}

void Rame::setRepr() {
	Vector2f centre_rame(centre_x, centre_y);
	representation.setPoint(0, Vector2f(centre_rame.x - taille_cote / 2, centre_rame.y - taille_cote/2));
	representation.setPoint(1, Vector2f(centre_rame.x + taille_cote / 2, centre_rame.y));
	representation.setPoint(2, Vector2f(centre_rame.x - taille_cote / 2, centre_rame.y + taille_cote / 2));
	representation.setFillColor(Color::Blue);
	float angleRad = angleRotation * (3.14159 / 180.0); // Convertir l'angle en radians

	for (int i = 0; i < 3; ++i) {
		float newX = (representation.getPoint(i).x - centre_x) * cos(angleRad) - (representation.getPoint(i).y - centre_y) * sin(angleRad) + centre_x;
		float newY = (representation.getPoint(i).x - centre_x) * sin(angleRad) + (representation.getPoint(i).y - centre_y) * cos(angleRad) + centre_y;
		representation.setPoint(i, Vector2f(newX, newY + 15));
	}
}

void Rame::rotate180() {
	angleRotation += 180.0;
	if (angleRotation >= 360.0) {
		angleRotation -= 360.0;
	}
	setRepr();
}



//les getters 
float Rame::get_vitesse() {
	return vitesse;
}
int Rame::get_position_x() {
	return position_x;
}
int Rame::get_position_y() {
	return position_y;
}
int Rame::get_passagers() {
	return nb_passagers;
}
float Rame::get_distance_arret_urgence() {
	return distance_arret_urgence;
}

int Rame::get_poids() {
	return poids;
}

int Rame::get_numero() {
	return numero;
}

ConvexShape Rame::getRepr() {
	return representation;
}

int Rame::get_vitesse_int() {
	return (int)vitesse;
}

//les moves 
void Rame::moveDroite() {
	representation.move(vitesse, 0);
	setRepr();
}

void Rame::moveGauche() {
	representation.move(-vitesse, 0);
	setRepr();
}

void Rame::moveHaut() {
	representation.move(0, -vitesse);
	setRepr();
}

void Rame::moveBas() {
	representation.move(0, vitesse);
	setRepr();
}

void Rame::moveDiagonalHautDroite() {
	representation.move(vitesse, -vitesse);
	setRepr();
}

void Rame::moveDiagonalHautGauche() {
	representation.move(-vitesse, -vitesse);
	setRepr();
}

void Rame::moveDiagonalBasDroite() {
	representation.move(vitesse, vitesse);
	setRepr();
}

void Rame::moveDiagonalBasGauche() {
	representation.move(-vitesse, vitesse);
	setRepr();
}

bool Rame::estArrete() {
	if (est_Arrete) {
		return true;
	}
	else {
		return false;
	}
}

void Rame::setArrete(bool etat) {
	est_Arrete = etat;
}

bool Rame::getTerminus() {
	if (terminus) {
		return true;
	}
	else {
		return false;
	}
}

void Rame::setTerminus(bool etat) {
	terminus = etat;
}

bool Rame::getRetour() {
	if (retour) {
		return true;
	}
	else {
		return false;
	}
}

void Rame::setRetour(bool etat) {
	retour = etat;
}

bool Rame::hasStarted() {
	if (hasStarted_) {
		return true;
	}
	else {
		return false;
	}
}

void Rame::setFreinage(bool etat) {
	en_freinage = etat;
}

bool Rame::isFreinage() {
	if (en_freinage) {
		return true;
	}
	else {
		return false;
	}
}

void Rame::setStarted(bool etat) {
	hasStarted_ = etat;
}

//destructeur
Rame::~Rame()
{

}