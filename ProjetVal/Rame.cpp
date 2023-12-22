#include "headers/Rame.hpp"
#include <cmath>

using namespace std;
using namespace sf;

//constructeur
Rame::Rame() : representation(3){}

Rame::Rame(Station station_depart,int num , int L,bool etat, Color color) : representation(3)
{
	centre_x = station_depart.getPositionX();
	centre_y = station_depart.getPositionY();
	terminus = 0;
	numero = num;
	ligne = L;
	position_x = centre_x;
	position_y = centre_y;
	if (etat == true) {
		position_y += 8;
		rotation += 180;
	}
	else {
		position_y -= 8;
	}
	nb_passagers = 0;
	vitesse = 1;
	distance_arret_urgence = 3.4; //a voir 
	retour = etat;
	visible = true;
	arret_urgence = false;
	couleur = color;
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
	distance_arret_urgence = 3.4; //a voir 
	visible = true;
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

void Rame::setRepr() {
	Vector2f centre_rame(centre_x, centre_y);
	representation.setPoint(0, Vector2f(centre_rame.x - taille_cote / 2, centre_rame.y - taille_cote/2));
	representation.setPoint(1, Vector2f(centre_rame.x + taille_cote / 2, centre_rame.y));
	representation.setPoint(2, Vector2f(centre_rame.x - taille_cote / 2, centre_rame.y + taille_cote / 2));
	representation.setFillColor(couleur);
	float angleRad = rotation * (3.14159 / 180.0);
	for (int i = 0; i < 3; ++i) {
		float newX = (representation.getPoint(i).x - centre_x) * cos(angleRad) - (representation.getPoint(i).y - centre_y) * sin(angleRad) + centre_x;
		float newY = (representation.getPoint(i).x - centre_x) * sin(angleRad) + (representation.getPoint(i).y - centre_y) * cos(angleRad) + centre_y;
		representation.setPoint(i, Vector2f(newX, newY + 3));
	}
}

void Rame::rotate180() {
	rotation += 180;
	if (rotation == 360) {
		rotation = 0;
	}
	setRepr();
}

void Rame::rotateGauche() {
	rotation -= 90;
	if (rotation == -360) {
		rotation = 0;
	}
	setRepr();
}

void Rame::rotateDroite() {
	rotation += 90;
	if (rotation == 360) {
		rotation = 0;
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

int Rame::get_numero() {
	return numero;
}

ConvexShape Rame::getRepr() {
	return representation;
}

int Rame::get_vitesse_int() {
	return (int)vitesse;
}

Color Rame::getColor() {
	return couleur;
}

void Rame::setColor(Color color) {
	couleur = color;
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

bool Rame::getHorizontal() {
	if (horizontal) {
		return true;
	}
	else {
		return false;
	}
}

void Rame::setHorizontal(bool etat) {
	horizontal = etat;
}

int Rame::get_ligne(){
	return ligne;
}

void Rame::toggleVisibility() {
	visible = !visible;
};
bool Rame::isVisible() {
	return visible;
};
void Rame::set_visible(bool visibilite) {
	visible = visibilite;
}

bool Rame::get_arret_urgence() {
	return arret_urgence;
}

void Rame::set_arret_urgence(bool etat) {
	arret_urgence = etat;
}

//destructeur
Rame::~Rame()
{

}