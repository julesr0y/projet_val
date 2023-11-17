#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rame.hpp"

using namespace std;
using namespace sf;

//constructeur
Rame::Rame()
{
	terminus,numero,position_x,position_y,nb_passagers= 0;
	vitesse = 0.0;
	distance_arret_urgence = 3.4;//à voir 

}

//methodes de la classe
void Rame::acceleration(int pourcentage) {
	vitesse += vitesse * (pourcentage / 100);
}


void Rame::deceleration(int pourcentage) {
	vitesse -= vitesse * (pourcentage / 100);
}


//les setters
void Rame::set_distance_arret_urgence(int dis) {
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

void Rame::set_vitesse(int v) {
	vitesse = v;
}

void Rame::set_poids(int p) {
	poids = p;
}




//les getters 
float Rame::get_vitesse() {
	return vitesse;
}
int Rame::get_position_x() {
	return position_x;
}
int Rame::get_position_y(){
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

//destructeur
Rame::~Rame()
{

}