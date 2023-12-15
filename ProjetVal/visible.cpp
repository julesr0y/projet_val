#include "visible.hpp";


void visible(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6, Event event, RenderWindow& window, CircleShape C1, CircleShape C2, CircleShape C3, CircleShape C4, CircleShape C5, CircleShape C6, RectangleShape  affiche1)
{
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

            }

            if (C2.getGlobalBounds().contains(convertedMousePosition)) {
                N2.set_visible(true); 
                N1.set_visible(!N2.isVisible());
                N3.set_visible(!N2.isVisible());
                N4.set_visible(!N2.isVisible());
                N5.set_visible(!N2.isVisible());
                N6.set_visible(!N2.isVisible());
            }

            if (C3.getGlobalBounds().contains(convertedMousePosition)) {
                N3.set_visible(true);
                N2.set_visible(!N3.isVisible());
                N1.set_visible(!N3.isVisible());
                N4.set_visible(!N3.isVisible());
                N5.set_visible(!N3.isVisible());
                N6.set_visible(!N3.isVisible());
            }

            if (C4.getGlobalBounds().contains(convertedMousePosition)) {
                N4.set_visible(true);  
                N2.set_visible(!N4.isVisible());
                N3.set_visible(!N4.isVisible());
                N1.set_visible(!N4.isVisible());
                N5.set_visible(!N4.isVisible());
                N6.set_visible(!N4.isVisible());
            }

            if (C5.getGlobalBounds().contains(convertedMousePosition)) {
                N5.set_visible(true);
                N2.set_visible(!N5.isVisible());
                N3.set_visible(!N5.isVisible());
                N4.set_visible(!N5.isVisible());
                N1.set_visible(!N5.isVisible());
                N6.set_visible(!N5.isVisible());
            }

            if (C6.getGlobalBounds().contains(convertedMousePosition)) {
                N6.set_visible(true);  
                N2.set_visible(!N6.isVisible());
                N3.set_visible(!N6.isVisible());
                N4.set_visible(!N6.isVisible());
                N5.set_visible(!N6.isVisible());
                N1.set_visible(!N6.isVisible());
            }
            reset(N1, N2, N3, N4, N5, N6, affiche1, mousePosition);


        }
    }
}

void reset(Rame& N1, Rame& N2, Rame& N3, Rame& N4, Rame& N5, Rame& N6,RectangleShape  affiche1, Vector2i mousePosition) {
    if (affiche1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        N5.set_visible(true); 
        N2.set_visible(true);
        N3.set_visible(true);
        N4.set_visible(true);
        N1.set_visible(true);
        N6.set_visible(true);
    }
}

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