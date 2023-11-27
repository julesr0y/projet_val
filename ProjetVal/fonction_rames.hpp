#include "Rame.hpp"
#include <thread>

void moveRame(Rame& rame, float end_pos_x, float end_pos_y);
Rame get_rames_apres(vector<Rame>& liste, Rame& rame);
void acceleration(Station& station, Rame& rame);