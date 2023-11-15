#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1500, 800), "VAL");
    RectangleShape button(Vector2f(200, 100));
    button.setPosition(750, 400);
    button.setFillColor(Color::Red);

    // Déplacez la déclaration de isBlue à l'extérieur de la boucle
    bool isBlue = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            // Gestion des clics de la souris
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Vérification si le clic de la souris est sur le bouton
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f buttonPos = button.getPosition();
                    sf::Vector2f buttonSize = button.getSize();

                    if (mousePos.x > buttonPos.x && mousePos.x < buttonPos.x + buttonSize.x &&
                        mousePos.y > buttonPos.y && mousePos.y < buttonPos.y + buttonSize.y) {
                        // Changer la couleur du bouton
                        if (!isBlue) {
                            button.setFillColor(sf::Color::Blue);
                        }
                        else {
                            button.setFillColor(sf::Color::Red);
                        }

                        isBlue = !isBlue;
                    }
                }
            }
        }

        window.clear();
        window.draw(button);
        window.display();
    }

    return 0;
}