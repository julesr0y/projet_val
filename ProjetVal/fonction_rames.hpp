#pragma once

#include "Rame.hpp"
#include <thread>
#include <vector>

extern bool arret_urgence; //récupération de la variable globale d'arret d'urgence

void moveRame(Rame& rame, Rame& rame_apres, vector<Station> listeStations, bool beginning, vector<Rame>& tabRame, Text& text); //fonction de déplacement des rames
void updateRameText(Text& text, vector<Rame>& tabRame, Rame rame, int pos_x); //fonction de mise à jour du texte du nombre de passagers dans les rames