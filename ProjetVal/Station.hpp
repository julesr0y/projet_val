#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Station {
private:
	int id_station;
	string nom;
	int position[2];
	int nb_passagers;
	//float temps;
	CircleShape representation;

public:
	Station(int id, string name, int x, int y, int nbpassagers);
	//Stations ~Stations();
	int getIdStation();
	string getNom();
	int getPosition();
	int getNbPassagers();
	bool estVide();
	void setRepr();
	CircleShape getRepr();
};