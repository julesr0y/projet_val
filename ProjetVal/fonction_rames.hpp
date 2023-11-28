#include "Rame.hpp"
#include <thread>
#include <vector>

void moveRame(Rame& rame, Rame& rame_apres, vector<Station>& listeStations, bool beginning);
Rame get_rames_apres(vector<Rame>& liste, Rame& rame);