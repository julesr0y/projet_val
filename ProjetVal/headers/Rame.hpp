/**
	* @file Rame.hpp
	* @brief Header de la classe Rame
*/
#pragma once
#include "Station.hpp"

class Rame {
private:
	float centre_x;
	float centre_y;
	float taille_cote = 18;
	int numero;
	int ligne;
	float vitesse = 10;
	float position_x;
	float position_y;
	int nb_passagers;
	bool est_Arrete = true;
	bool terminus = false;
	bool retour;
	bool hasStarted_ = false;
	bool en_freinage = false;
	ConvexShape representation;
	bool horizontal = true;
	bool visible;
	bool arret_urgence;
	Color couleur;
	int rotation = 0;

public:
	//constructeurs
	Rame();
	Rame(Station station_depart, int numero, int ligen, bool etat, Color color);
	Rame(Station station_depart);

	//setters
	void set_vitesse(float v);
	void set_position_x(int x);
	void set_position_y(int y);
	void set_passagers(int nb);
	void set_arret_urgence(bool etat);
	void setRepr();
	void setArrete(bool etat);
	void setTerminus(bool etat);
	void setRetour(bool etat);
	void setStarted(bool etat);
	void setFreinage(bool etat);
	void setHorizontal(bool etat);
	void setColor(Color color);

	//getters
	int get_numero();
	int get_ligne();
	float get_vitesse();
	int get_position_x();
	int get_position_y();
	int get_passagers();
	bool get_arret_urgence();
	bool estArrete();
	ConvexShape getRepr();
	int get_vitesse_int();
	bool getTerminus();
	bool getRetour();
	bool hasStarted();
	bool isFreinage();
	bool getHorizontal();
	Color getColor();

	//gestion des deplacements
	void moveDroite();
	void moveGauche();
	void moveHaut();
	void moveBas();
	void moveDiagonalHautDroite();
	void moveDiagonalHautGauche();
	void moveDiagonalBasDroite();
	void moveDiagonalBasGauche();
	void rotate180();
	void rotateGauche();
	void rotateDroite();

	//visible
	void toggleVisibility();
	bool isVisible();
	void set_visible(bool visibilite);
};