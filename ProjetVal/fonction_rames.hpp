#pragma once

#include "Rame.hpp"
#include <thread>
#include <vector>

extern bool arret_urgence; //récupération de la variable globale d'arret d'urgence

void moveRame(Rame& rame, Rame& rame_apres, vector<Station> listeStations, bool beginning, vector<Rame>& tabRame, Text& text); //fonction de déplacement des rames
void updateRameText(Text& text, vector<Rame>& tabRame, Rame rame, int pos_x); //fonction de mise à jour du texte du nombre de passagers dans les rames
int nextStation(Station actual, Station next, bool sens); //indique a la rame dans quelle direction s'orienter en cas de virage
void arret_urgence_window(Window& window, Event event, Rame& R1_1, Rame& R1_2, Rame& R1_3, Rame& R1_4, Rame& R1_5, Rame& R1_6, Rame& R2_1, Rame& R2_2, Rame& R2_3, Rame& R2_4, Rame& R2_5, Rame& R2_6);