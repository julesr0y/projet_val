#include <string>
using namespace std;

class Stations {
private:
	int id_station;
	string nom;
	int position[2];
	int nb_passagers;
	float temps;

public:
	Stations Stations();
	Stations Stations(int id, string nom, int position[2]);
	Stations ~Stations();
	int getIdStation();
	string getNom();
	int getPosition();
	int getNbPassagers();
	bool estVide();
};