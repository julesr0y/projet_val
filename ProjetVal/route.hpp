#include <SFML/Graphics.hpp>
#include "Station.hpp"
using namespace std;
using namespace sf;

class Route {
private:
	int id_voie;
	float longueur;
	RectangleShape representation;
	Station station_depart;
	Station station_arrivee;
public:
	Route(int id, float longueur, Station station1, Station station2);
	void get_id_voie();
	void get_longueur();
	void get_position();
	void set_id_voie();
	void set_longueur();
	void set_position();
	void setRepr();
	RectangleShape getRepr();
};