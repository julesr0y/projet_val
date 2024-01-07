/**
    * @file visible.cpp
    * @brief Fonction associees a la visibilite des rames
*/
#include "headers/visible.hpp"

/**
    * @brief Permet l'arret d'urgence d'une rame lorsque l'on clique dessus
    * @param[in] N1... Ensemble des rames
    * @param[in] event Evenement
    * @param[in] window Fenetre
    * @param[in] C1... Ensemble des boutons
    * @return Le nombre de fois ou une rame seule a ete suivie par le superviseur
*/
int visible(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6, Event event, RenderWindow& window, CircleShape C1, CircleShape C2, CircleShape C3, CircleShape C4, CircleShape C5, CircleShape C6, RectangleShape  affiche1)
{
    int nb_suivie = 0;
    if (event.type == Event::Closed) {
        window.close();
    }
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            Vector2i mousePosition = Mouse::getPosition(window);
            Vector2f convertedMousePosition = window.mapPixelToCoords(mousePosition);

            int id;
            if (C1.getGlobalBounds().contains(convertedMousePosition)) {
                N1.set_visible(true); 
                N2.set_visible(!N1.isVisible());
                N3.set_visible(!N1.isVisible());
                N4.set_visible(!N1.isVisible());
                N5.set_visible(!N1.isVisible());
                N6.set_visible(!N1.isVisible());
                nb_suivie++;
            }

            if (C2.getGlobalBounds().contains(convertedMousePosition)) {
                N2.set_visible(true); 
                N1.set_visible(!N2.isVisible());
                N3.set_visible(!N2.isVisible());
                N4.set_visible(!N2.isVisible());
                N5.set_visible(!N2.isVisible());
                N6.set_visible(!N2.isVisible());
                nb_suivie++;
            }

            if (C3.getGlobalBounds().contains(convertedMousePosition)) {
                N3.set_visible(true);
                N2.set_visible(!N3.isVisible());
                N1.set_visible(!N3.isVisible());
                N4.set_visible(!N3.isVisible());
                N5.set_visible(!N3.isVisible());
                N6.set_visible(!N3.isVisible());
                nb_suivie++;
            }

            if (C4.getGlobalBounds().contains(convertedMousePosition)) {
                N4.set_visible(true);  
                N2.set_visible(!N4.isVisible());
                N3.set_visible(!N4.isVisible());
                N1.set_visible(!N4.isVisible());
                N5.set_visible(!N4.isVisible());
                N6.set_visible(!N4.isVisible());
                nb_suivie++;
            }

            if (C5.getGlobalBounds().contains(convertedMousePosition)) {
                N5.set_visible(true);
                N2.set_visible(!N5.isVisible());
                N3.set_visible(!N5.isVisible());
                N4.set_visible(!N5.isVisible());
                N1.set_visible(!N5.isVisible());
                N6.set_visible(!N5.isVisible());
                nb_suivie++;
            }

            if (C6.getGlobalBounds().contains(convertedMousePosition)) {
                N6.set_visible(true);  
                N2.set_visible(!N6.isVisible());
                N3.set_visible(!N6.isVisible());
                N4.set_visible(!N6.isVisible());
                N5.set_visible(!N6.isVisible());
                N1.set_visible(!N6.isVisible());
                nb_suivie++;
            }
            reset(N1, N2, N3, N4, N5, N6, affiche1, mousePosition, window);
        }
    }
    return nb_suivie;
}

/**
    * @brief Permet de reafficher toutes les rames lors du clic
    * @param[in] N1... Ensemble des rames
    * @param[in] affiche1 Bouton de reset (rectangle)
    * @param[in] mousPosition Position du clic
*/
void reset(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6,RectangleShape affiche1, Vector2i mousePosition, RenderWindow &window) {
    Vector2f convertedMousePosition = window.mapPixelToCoords(mousePosition);
    if (affiche1.getGlobalBounds().contains(convertedMousePosition)) {
        N5.set_visible(true); 
        N2.set_visible(true);
        N3.set_visible(true);
        N4.set_visible(true);
        N1.set_visible(true);
        N6.set_visible(true);
    }
}

/**
    * @brief Affiche les rames sur la fenetre en fonction de leur visibilite
    * @param[in] N1... Ensemble des rames
    * @param[in] window Fenetre
*/
void affichage(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6, RenderWindow& window) {
    if (N1.isVisible()) {
        window.draw(N1.getRepr());
    }
    if (N2.isVisible()) {
        window.draw(N2.getRepr());
    }

    if (N3.isVisible()) {
        window.draw(N3.getRepr());
    }
    if (N4.isVisible()) {
        window.draw(N4.getRepr());
    }

    if (N5.isVisible()) {
        window.draw(N5.getRepr());
    }
    if (N6.isVisible()) {
        window.draw(N6.getRepr());
    }
}