/**
	* @file visible.hpp
	* @brief Header des fonctions de visibilite des rames
*/
#pragma once
#include "Rame.hpp"

int visible(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6, Event event, RenderWindow& window, CircleShape C1, CircleShape C2, CircleShape C3, CircleShape C4, CircleShape C5, CircleShape C6, RectangleShape  affiche1);
void reset(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6, RectangleShape  affiche1, Vector2i mousePosition);
void affichage(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6, RenderWindow& window);
