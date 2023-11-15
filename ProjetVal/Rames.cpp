#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rames.hpp"
using namespace std;
using namespace sf;

//constructeur
Rames::Rames()
{
	terminus,numero,position_x,position_y,nb_passagers= 0;
	vitesse = 0.0;
	distance_arret_urgence = 3.4;//à voir 

}

//methodes de la class
void Rames::acceleration(int pourcentage) {
	vitesse += vitesse * (pourcentage / 100);
}


void Rames::deceleration(int pourcentage) {
	vitesse -= vitesse * (pourcentage / 100);
}


//les setters
void Rames::set_distance_arret_urgence(int dis) {
	distance_arret_urgence = dis;
}

void Rames::set_numero(int nb) {
	numero = nb;
}

void Rames::set_passagers(int nb) {
	nb_passagers = nb;
}


void Rames::set_position_x(int x) {
	position_x = x;
}

void Rames::set_position_y(int y) {
	position_y = y;
}

void Rames::set_vitesse(int v) {
	vitesse = v;
}

void Rames::set_poid(int p) {
	poid = p;
}




//les getters 
float Rames::get_vitesse() {
	return vitesse;
}
int Rames::get_position_x() {
	return position_x;
}
int Rames::get_position_y(){
	return position_y;
}
int Rames::get_passagers() {
	return nb_passagers;
}
float Rames::get_distance_arret_urgence() {
	return distance_arret_urgence;
}

int Rames::get_poid() {
	return poid;
}

int Rames::get_numero() {
	return numero;
}

//destructeur
Rames::~Rames()
{

}