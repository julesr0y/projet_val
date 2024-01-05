/**
	* @file Rame.cpp
	* @brief Classe Rame
*/
#include "headers/Rame.hpp"
#include <cmath>

using namespace std;
using namespace sf;


/********************Constructeurs********************/

/**
	* @brief Constructeur par defaut
*/
Rame::Rame() : representation(3){}

/**
	* @brief Constructeur avec parametres
	* @param[in] station_depart Station sur laquelle apparait la rame
	* @param[in] num Numero de la rame
	* @param[in] etat True: Rame en direction retour, False : Rame en direction aller
	* @param[in] color Couleur de la rame
 */
Rame::Rame(Station station_depart, int num, int L, bool etat, Color color) : representation(3)
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
	retour = etat;
	visible = true;
	arret_urgence = false;
	couleur = color;
}

/**
	* @brief Constructeur
*/
Rame::Rame(Station station_depart) : representation(3) {
	centre_x = station_depart.getPositionX();
	centre_y = station_depart.getPositionY();
	terminus = 0;
	numero = 0;
	position_x = centre_x;
	position_y = centre_y;
	nb_passagers = 0;
	vitesse = 1;
	visible = true;
}


/********************Setters********************/

/**
	* @brief Set la vitesse de la rame
	* @param[in] v Valeur de la vitesse
 */
void Rame::set_vitesse(float v) {
	vitesse = v;
}

/**
	* @brief Set la position x de la rame
	* @param[in] x Valeur de la position x
 */
void Rame::set_position_x(int x) {
	position_x = x;
}

/**
	* @brief Set la position y de la rame
	* @param[in] y Valeur de la position y
 */
void Rame::set_position_y(int y) {
	position_y = y;
}

/**
	* @brief Set le nombre de passagers dans la rame
	* @param[in] nb Nombre de passagers
 */
void Rame::set_passagers(int nb) {
	nb_passagers = nb;
}

/**
	* @brief Definit si la rame est en arret d'urgence
	* @param[in] etat Booleen d'arret d'urgence
*/
void Rame::set_arret_urgence(bool etat) {
	arret_urgence = etat;
}

/**
	* @brief Set la representation graphique de la rame
 */
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

/**
	* @brief Definit si la rame est arretee ou non
	* @param[in] etat Booleen d'etat d'arret
 */
void Rame::setArrete(bool etat) {
	est_Arrete = etat;
}

/**
	* @brief Definit si la rame est a un terminus
	* @param[in] etat Booleen de terminus
*/
void Rame::setTerminus(bool etat) {
	terminus = etat;
}

/**
	* @brief Definit la direction de la rame
	* @param[in] etat Booleen de direction
*/
void Rame::setRetour(bool etat) {
	retour = etat;
}

/**
	* @brief Definit si la rame a demarree
	* @param[in] etat Booleen de demarrage
*/
void Rame::setStarted(bool etat) {
	hasStarted_ = etat;
}

/**
	* @brief Definit si la rame est en freinage
	* @param[in] etat Booleen de freinage
*/
void Rame::setFreinage(bool etat) {
	en_freinage = etat;
}

/**
	* @brief Definit si la rame se deplace a l'horizontale ou a la verticale
	* @param[in] etat Booleen d'orientation
*/
void Rame::setHorizontal(bool etat) {
	horizontal = etat;
}

/**
	* @brief Set la couleur de la rame
	* @param[in] color Couleur souhaitee pour la rame
 */
void Rame::setColor(Color color) {
	couleur = color;
}


/********************Getters********************/

/**
	* @brief Indique le numero de la rame
	* @return Numero de la rame
*/
int Rame::get_numero() {
	return numero;
}

/**
	* @brief Indique la ligne
	* @return Numero de la ligne
*/
int Rame::get_ligne() {
	return ligne;
}

/**
	* @brief Renvoie la vitesse de la rame
	* @return La valeur de la vitesse actuelle
 */
float Rame::get_vitesse() {
	return vitesse;
}

/**
	* @brief Renvoie la position x de la rame
	* @return La valeur de la position x
 */
int Rame::get_position_x() {
	return position_x;
}

/**
	* @brief Renvoie la position y de la rame
	* @return La valeur de la position y
 */
int Rame::get_position_y() {
	return position_y;
}

/**
	* @brief Renvoie le nombre de passagers dans la rame
	* @return Le nombre de passagers
 */
int Rame::get_passagers() {
	return nb_passagers;
}

/**
	* @brief Indique si la rame est en etat d'arret d'urgence
	* @return True : en arret d'urgence, False : n'est pas en arret d'urgence
*/
bool Rame::get_arret_urgence() {
	return arret_urgence;
}

/**
	* @brief Indique si la rame est arretee ou non
	* @return True : Arretee, False : En mouvement
 */
bool Rame::estArrete() {
	if (est_Arrete) {
		return true;
	}
	else {
		return false;
	}
}

/**
	* @brief Renvoie la representation graphique de la rame
	* @return Le triangle representant la rame
 */
ConvexShape Rame::getRepr() {
	return representation;
}

/**
	* @brief Indique la vitesse sous forme d'un entier
	* @return La vitesse
*/
int Rame::get_vitesse_int() {
	return (int)vitesse;
}

/**
	* @brief Indique si la rame est a un terminus ou non
	* @return True : est a un terminus, False : n'est pas a un terminus
*/
bool Rame::getTerminus() {
	if (terminus) {
		return true;
	}
	else {
		return false;
	}
}

/**
	* @brief Indique la direction de la rame (aller/retour)
	* @return True : en direction retour, False : en direction aller
*/
bool Rame::getRetour() {
	if (retour) {
		return true;
	}
	else {
		return false;
	}
}

/**
	* @brief Indique si la rame a demarree
	* @return True : a demarree, False : n'a pas demarree
*/
bool Rame::hasStarted() {
	if (hasStarted_) {
		return true;
	}
	else {
		return false;
	}
}

/**
	* @brief Indique si la rame est en freinage
	* @return True : en freinage, False : n'est pas en freinage
*/
bool Rame::isFreinage() {
	if (en_freinage) {
		return true;
	}
	else {
		return false;
	}
}

/**
	* @brief Indique si la rame se deplace a l'horizontale ou a la verticale
	* @return True : deplacement horizontal, False : deplacement vertical
*/
bool Rame::getHorizontal() {
	if (horizontal) {
		return true;
	}
	else {
		return false;
	}
}

/**
	* @brief Renvoie la couleur de la rame
	* @return La couleur
 */
Color Rame::getColor() {
	return couleur;
}


/********************Gestion des deplacements********************/

/**
	* @brief Deplace la rame vers la droite, et met a jour sa representation
 */
void Rame::moveDroite() {
	representation.move(vitesse, 0);
	setRepr();
}

/**
	* @brief Deplace la rame vers la gauche, et met a jour sa representation
 */
void Rame::moveGauche() {
	representation.move(-vitesse, 0);
	setRepr();
}

/**
	* @brief Deplace la rame vers le haut, et met a jour sa representation
 */
void Rame::moveHaut() {
	representation.move(0, -vitesse);
	setRepr();
}

/**
	* @brief Deplace la rame vers le bas, et met a jour sa representation
 */
void Rame::moveBas() {
	representation.move(0, vitesse);
	setRepr();
}

/**
	* @brief Permet a une rame d'effectuer une rotation a 180 degrés
 */
void Rame::rotate180() {
	rotation += 180;
	if (rotation == 360) {
		rotation = 0;
	}
	setRepr();
}

/**
	* @brief Permet a une rame d'effectuer une rotation vers la gauche
 */
void Rame::rotateGauche() {
	rotation -= 90;
	if (rotation == -360) {
		rotation = 0;
	}
	setRepr();
}

/**
	* @brief Permet a une rame d'effectuer une rotation vers la droite
 */
void Rame::rotateDroite() {
	rotation += 90;
	if (rotation == 360) {
		rotation = 0;
	}
	setRepr();
}


/********************Visibilite********************/

/**
	* @brief Modifie la visibilite de la rame
*/
void Rame::toggleVisibility() {
	visible = !visible;
}

/**
	* @brief Indique si la rame est visible ou non
	* @return True : visible, False : non visible
*/
bool Rame::isVisible() {
	return visible;
}

/**
	* @brief Definit si la rame est visible
	* @param[in] visibilite Booleen de visibilite
*/
void Rame::set_visible(bool visibilite) {
	visible = visibilite;
}