#include "visible.hpp";


void visible(Rame N1, Rame N2, Rame N3, Rame N4, Rame N5, Rame N6,Event event,Window window) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            Vector2i mousePosition = Mouse::getPosition(window);
            Vector2f circlePosition = Rame1L1.getPosition();

            // Check if the mouse click is within the bounds of the yellow circle (Rame1L1)
            //float circleRadius = Rame1L1.getRadius();
            //FloatRect circleBounds = Rame1L1.getGlobalBounds();
            int id;
            if (Rame1L1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame1_1.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame1_2.set_visible(!rame1_1.isVisible());
                rame1_3.set_visible(!rame1_1.isVisible());
                rame1_4.set_visible(!rame1_1.isVisible());
                rame1_5.set_visible(!rame1_1.isVisible());
                rame1_6.set_visible(!rame1_1.isVisible());

                //for (size_t i = 0; i < tabRame_L1.size(); i++)
                //{
                //    if (id != tabRame_L1[i].get_numero())
                //    {
                //        tabRame_L1[i].set_visible(!rame1_1.isVisible());
                //    }
                //}
            }

            if (Rame2L1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame1_2.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame1_1.set_visible(!rame1_2.isVisible());
                rame1_3.set_visible(!rame1_2.isVisible());
                rame1_4.set_visible(!rame1_2.isVisible());
                rame1_5.set_visible(!rame1_2.isVisible());
                rame1_6.set_visible(!rame1_2.isVisible());
            }

            if (Rame3L1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame1_3.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame1_2.set_visible(!rame1_3.isVisible());
                rame1_1.set_visible(!rame1_3.isVisible());
                rame1_4.set_visible(!rame1_3.isVisible());
                rame1_5.set_visible(!rame1_3.isVisible());
                rame1_6.set_visible(!rame1_3.isVisible());
            }

            if (Rame4L1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame1_4.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame1_2.set_visible(!rame1_4.isVisible());
                rame1_3.set_visible(!rame1_4.isVisible());
                rame1_1.set_visible(!rame1_4.isVisible());
                rame1_5.set_visible(!rame1_4.isVisible());
                rame1_6.set_visible(!rame1_4.isVisible());
            }

            if (Rame5L1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame1_5.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame1_2.set_visible(!rame1_5.isVisible());
                rame1_3.set_visible(!rame1_5.isVisible());
                rame1_4.set_visible(!rame1_5.isVisible());
                rame1_1.set_visible(!rame1_5.isVisible());
                rame1_6.set_visible(!rame1_5.isVisible());
            }

            if (Rame6L1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame1_6.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame1_2.set_visible(!rame1_6.isVisible());
                rame1_3.set_visible(!rame1_6.isVisible());
                rame1_4.set_visible(!rame1_6.isVisible());
                rame1_5.set_visible(!rame1_6.isVisible());
                rame1_1.set_visible(!rame1_6.isVisible());
            }



            if (Rame1L2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame2_1.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame2_2.set_visible(!rame1_6.isVisible());
                rame2_3.set_visible(!rame1_6.isVisible());
                rame2_4.set_visible(!rame1_6.isVisible());
                rame2_5.set_visible(!rame1_6.isVisible());
                rame2_6.set_visible(!rame1_6.isVisible()); // Add a member function to Rame class to toggle visibility
            }

            if (Rame2L2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame2_2.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame2_1.set_visible(!rame1_6.isVisible());
                rame2_3.set_visible(!rame1_6.isVisible());
                rame2_4.set_visible(!rame1_6.isVisible());
                rame2_5.set_visible(!rame1_6.isVisible());
                rame2_6.set_visible(!rame1_6.isVisible());
            }

            if (Rame3L2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame2_3.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame2_2.set_visible(!rame1_6.isVisible());
                rame2_1.set_visible(!rame1_6.isVisible());
                rame2_4.set_visible(!rame1_6.isVisible());
                rame2_5.set_visible(!rame1_6.isVisible());
                rame2_6.set_visible(!rame1_6.isVisible());
            }

            if (Rame4L2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame2_4.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame2_2.set_visible(!rame1_6.isVisible());
                rame2_3.set_visible(!rame1_6.isVisible());
                rame2_1.set_visible(!rame1_6.isVisible());
                rame2_5.set_visible(!rame1_6.isVisible());
                rame2_6.set_visible(!rame1_6.isVisible());
            }

            if (Rame5L2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame2_5.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame2_2.set_visible(!rame1_6.isVisible());
                rame2_3.set_visible(!rame1_6.isVisible());
                rame2_4.set_visible(!rame1_6.isVisible());
                rame2_1.set_visible(!rame1_6.isVisible());
                rame2_6.set_visible(!rame1_6.isVisible());
            }

            if (Rame6L2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame2_6.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame2_2.set_visible(!rame1_6.isVisible());
                rame2_3.set_visible(!rame1_6.isVisible());
                rame2_4.set_visible(!rame1_6.isVisible());
                rame2_5.set_visible(!rame1_6.isVisible());
                rame2_1.set_visible(!rame1_6.isVisible());
            }

            if (affiche1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame1_5.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame1_2.set_visible(true);
                rame1_3.set_visible(true);
                rame1_4.set_visible(true);
                rame1_1.set_visible(true);
                rame1_6.set_visible(true);
            }

            if (affiche2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Toggle the visibility of Rame1L1
                rame2_5.set_visible(true);  // Add a member function to Rame class to toggle visibility
                rame2_2.set_visible(true);
                rame2_3.set_visible(true);
                rame2_4.set_visible(true);
                rame2_1.set_visible(true);
                rame2_6.set_visible(true);
            }

        }

};