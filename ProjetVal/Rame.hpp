#ifndef RAME_H
#define RAME_H

#include "Station.hpp"

class Rame {
private:
	float centre_x;
	float centre_y;
	float taille_cote = 25;
	int numero;
	int ligne;
	float vitesse = 10;
	float position_x;
	float position_y;
	int nb_passagers;
	float distance_arret_urgence;
	bool est_Arrete = true;
	bool terminus = false;
	bool retour;
	bool hasStarted_ = false;
	bool en_freinage = false;
	float angleRotation = 0.0;
	ConvexShape representation;
	bool horizontal = true;

public:
	Rame(Station station_depart);//constructeur
	Rame(Station station_depart, int numero,int ligen,bool etat);
	Rame();
	~Rame();//destructeur


	//methodes de la classe
	void vitesse_plus(int pourcentage);
	void vitesse_moins(int pourcentage);

	//setters
	void set_numero(int nb);
	void set_vitesse(float v);
	void set_position_x(int x);
	void set_position_y(int y);
	void set_passagers(int nb);
	void set_distance_arret_urgence(float dis);
	void setRepr();
	void setArrete(bool etat);
	void setTerminus(bool etat);
	void setRetour(bool etat);
	void setStarted(bool etat);
	void setFreinage(bool etat);
	void setHorizontal(bool etat);

	//getters
	int get_numero();
	int get_ligne();
	float get_vitesse();
	int get_position_x();
	int get_position_y();
	int get_passagers();
	float get_distance_arret_urgence();
	int get_poids();
	bool estArrete();
	ConvexShape getRepr();
	int get_vitesse_int();
	bool getTerminus();
	bool getRetour();
	bool hasStarted();
	bool isFreinage();
	bool getHorizontal();

	//gestion des d�placements
	void moveDroite();
	void moveGauche();
	void moveHaut();
	void moveBas();
	void moveDiagonalHautDroite();
	void moveDiagonalHautGauche();
	void moveDiagonalBasDroite();
	void moveDiagonalBasGauche();
	void rotate180();
};

#endif RAME_H