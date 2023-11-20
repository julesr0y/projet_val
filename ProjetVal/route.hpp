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
	int get_id_voie();
	int get_longueur();
	void setRepr();
	RectangleShape getRepr();
};