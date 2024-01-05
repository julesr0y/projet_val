/**
	* @file Route.cpp
	* @brief Classe Route pour les voies
*/
#include "headers/Route.hpp"

using namespace std;
using namespace sf;


/********************Constructeurs********************/

/**
	* @brief Constructeur par defaut
*/
Route::Route() {}

/**
	* @brief Constructeur avec parametres
	* @param[in] id Identifiant de la route
	* @param[in] station1 Station de depart de creation de la route
	* @param[in] station2 Station de fin de creation de la route
	* @param[in] color Couleur de la route
*/
Route::Route(int id, Station station1, Station station2, Color color) {
	id_voie = id; //id de la voie pour situer les rames
	//id des stations pour dessiner la voie
	station_depart = station1;
	station_arrivee = station2;
	//position des stations 
	station1_x = station1.getPositionX();
	station1_y = station1.getPositionY();
	station2_x = station2.getPositionX();
	station2_y = station2.getPositionY();
	//définition de la longueur de la voie à l'horizontale (longueur) et à la verticale (hauteur)
	longueur = station2_x - station1_x;
	hauteur = station1_y - station2_y;
	couleur = color; // couleur des voies
}

/********************Setters********************/

/**
	* @brief Set la representation graphique de la route
*/
void Route::setRepr() {
	if (hauteur == 0) { // horizontale
		representation.setSize(Vector2f(longueur, epaisseur));
		representation.setPosition(station1_x, station1_y + 6);
	}
	if (longueur == 0 && station1_y < station2_y) { //verticale descendante
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x - 10, station1_y);
	}
	if (longueur == 0 && station1_y > station2_y) { //verticale montante
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x + 6, station1_y);
	}
	representation.setFillColor(couleur); // couleur de la voie
}

/**
	* @brief Set la representation graphique d'une route de retour
*/
void Route::setReprRetour() {
	if (hauteur == 0) { // horizontale
		representation.setSize(Vector2f(longueur, epaisseur));
		representation.setPosition(station1_x, station1_y - 10);
	}
	if (longueur == 0 && station1_y < station2_y) { // verticale descendante
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x + 6, station1_y);
	}
	if (longueur == 0 && station1_y > station2_y) { // verticale montante
		representation.setSize(Vector2f(hauteur, epaisseur));
		representation.rotate(-90);
		representation.setPosition(station1_x - 10, station1_y);
	}
	representation.setFillColor(couleur);// couleur de la voie
}


/********************Getters********************/

/**
	* @brief Indique l'id de la route
	* @return Identifiant de la route
*/
int Route::get_id_voie() {
	return id_voie;
}

/**
	* @brief Indique la longueur a parcourir
	* @return La longueur
*/
int Route::get_longueur() {
	return longueur;
}

/**
	* @brief Indique la hauteur a parcourir
	* @return La hauteur
*/
int Route::get_hauteur() {
	return hauteur;
}

/**
	* @brief Renvoie la representation graphique de la route
	* @return Le rectangle representant la route
*/
RectangleShape Route::getRepr() {
	return representation;
}