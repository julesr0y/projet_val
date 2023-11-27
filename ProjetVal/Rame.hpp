#ifndef RAME_H
#define RAME_H

#include "Station.hpp"

class Rame
{
public:
	Rame(Station station_depart);//constructeur
	Rame(Station station_depart,int numero);
	Rame();
	~Rame();//destructeur


	//methodes de la class
	void vitesse_plus(int pourcentage);
	void vitesse_moins(int pourcentage);

	//setter
	void set_numero(int nb);
	void set_vitesse(float v);
	void set_position_x(int x);
	void set_position_y(int y);
	void set_passagers(int nb);
	void set_distance_arret_urgence(float dis);
	void set_poids(float p);
	void setRepr();

	//getters
	int get_numero();
	float get_vitesse();
	float get_position_x();
	float get_position_y();
	int  get_passagers();
	float get_distance_arret_urgence();
	int get_poids();
	ConvexShape getRepr();

	//gestion des déplacements
	void moveDroite();
	void moveGauche();
	void moveHaut();
	void moveBas();
	void moveDiagonalHautDroite();
	void moveDiagonalHautGauche();
	void moveDiagonalBasDroite();
	void moveDiagonalBasGauche();

private:
	float centre_x;
	float centre_y;
	float taille_cote = 25;
	int numero;
	float vitesse;
	int terminus;
	float position_x;
	float position_y;
	int nb_passagers;
	float distance_arret_urgence;
	float poids;
	ConvexShape representation;
};

#endif RAME_H