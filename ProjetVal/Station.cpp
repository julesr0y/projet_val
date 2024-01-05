/**
	* @file Station.cpp
	* @brief Classe Station
*/
#include "headers/Station.hpp"

using namespace std;
using namespace sf;


/********************Constructeurs********************/

/**
	* @brief Constructeur par defaut
*/
Station::Station() {};

/**
	* @brief Constructeur avec parametres
	* @param[in] id Identifiant de la station
	* @param[in] x Position x de la station
	* @param[in] y Position x de la station
	* @param[in] color Couleur de la station
	* @param[in] terminus_ Booleen pour indiquer si terminus ou non
	* @param[in] vir Booleen pour indiquer si virage ou non
*/
Station::Station(int id, float x, float y, Color color, bool terminus_, bool vir) {
	id_station = id;
	position[0] = x;
	position[1] = y;
	couleur = color;
	terminus = terminus_;
	virage = vir;
}


/********************Setters********************/

/**
	* @brief Set la representation graphique de la station
*/
void Station::setRepr() {
	representation.setRadius(rayon);
	representation.setPosition(position[0] - rayon, position[1] - rayon);
	representation.setFillColor(couleur);
}

/**
	* @brief Set le nom de la station
	* @param[in] Snom Nom de la station
*/
void Station::set_nom(string Snom) {
	nom = Snom;
}

/**
	* @brief Set le nombre de passagers dans la station
	* @param[in] nb Nombre de passagers
*/
void Station::setNbPassagers(int nb) {
	nb_passagers = nb;
}


/********************Getters********************/

/**
	* @brief Indique l'id de la station
	* @return Identifiant de la station
*/
int Station::getIdStation() {
	return id_station;
}

/**
	* @brief Indique le nom de la station
	* @return Nom de la station
*/
string Station::getNom() {
	return nom;
}

/**
	* @brief Indique la position x de la station
	* @return Position en x
*/
float Station::getPositionX() {
	return position[0];
}

/**
	* @brief Indique la position y de la station
	* @return Position en y
*/
float Station::getPositionY() {
	return position[1];
}

/**
	* @brief Indique le nombre de passagers dans la station
	* @return Nombre de passagers
*/
int Station::getNbPassagers() {
	return nb_passagers;
}

/**
	* @brief Renvoie la representation graphique de la station
	* @return Le cercle representant la station
*/
CircleShape Station::getRepr() {
	return representation;
}

/**
	* @brief Indique si la station est un terminus ou non
	* @return True : est une station terminus, False : n'est pas un terminus
*/
bool Station::get_terminus() {
	return terminus;
}

/**
	* @brief Permet d'obtenir le nom de la station
	* @return Nom de la station
*/
string Station::get_nom() {
	return nom;
}

/**
	* @brief Indique si la station est un virage ou non
	* @return True : est un virage, False : n'est pas un virage
*/
bool Station::isVirage() {
	return virage;
}