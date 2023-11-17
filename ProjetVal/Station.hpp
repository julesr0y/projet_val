#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Station {
private:
	int id_station;
	string nom;
	float position[2];
	int nb_passagers;
	//float temps;
	CircleShape representation;

public:
	Station(int id, string name, float x, float y, int nbpassagers);
	//Stations ~Stations();
	int getIdStation();
	string getNom();
	float getPositionX();
	float getPositionY();
	int getNbPassagers();
	//bool estVide();
	void setRepr();
	CircleShape getRepr();
};