/* HALILA Nada - HU Lucas - ROY Jules */

#include <iostream>
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Station.hpp"
#include "Rame.hpp"
#include "Route.hpp"
#include "fonction_rames.hpp"
#include "visible.hpp"

using namespace std;
using namespace sf;

#define WINDOW_X 1900 //largeur de la fenetre
#define WINDOW_Y 900 //hauteur de la fenetre
#define WINDOW_NAME "VAL" //nom de la fenetre
#define FONT "merienda.ttf"
#define ICON "icon.png"
bool arret_urgence = false;

int main()
{
    Font font;
    if (!font.loadFromFile(FONT)) {
        // Gestion de l'erreur si la police ne peut pas etre charg�e
        return -1;
    }
    Text text;
    text.setFont(font);
    Text text2;
    text2.setFont(font);// Definir la police
    text2.setCharacterSize(17); // Definir la taille du texte
    text2.setFillColor(Color::White); // Definir la couleur du texte
    text.setCharacterSize(17); // Definir la taille du texte
    text.setFillColor(Color::White); // Definir la couleur du texte

    //DESSAIN D4UN RECTANGLE POUR TOUS AFFICHER
    RectangleShape  affiche1(Vector2f(150, 50));
    affiche1.setPosition(100.0f, 150.0f);
    affiche1.setFillColor(Color::Yellow);

    RectangleShape  affiche2(Vector2f(150, 50));
    affiche2.setPosition(600.0f, 150.0f);
    affiche2.setFillColor(Color::Red);

    string reset = "Reset";
    Text re1;
    Text re2;

    re1.setFont(font);
    re1.setCharacterSize(25);
    re1.setFillColor(Color::Black);
    re1.setPosition(145.0f, 160.0f);
    re1.setString(reset);

    re2.setFont(font);
    re2.setCharacterSize(25);
    re2.setFillColor(Color::Black);
    re2.setPosition(645.0f, 160.0f);
    re2.setString(reset);

    //DESSAIN DES POINT L1
    CircleShape Rame1L1;
    Rame1L1.setRadius(10);
    Rame1L1.setPosition(355, 2);
    Rame1L1.setFillColor(Color::Yellow);
    CircleShape Rame2L1;
    Rame2L1.setRadius(10);
    Rame2L1.setPosition(355, 25);
    Rame2L1.setFillColor(Color::Yellow);
    CircleShape Rame3L1;
    Rame3L1.setRadius(10);
    Rame3L1.setPosition(355, 50);
    Rame3L1.setFillColor(Color::Yellow);
    CircleShape Rame4L1;
    Rame4L1.setRadius(10);
    Rame4L1.setPosition(355, 75);
    Rame4L1.setFillColor(Color::Yellow);
    CircleShape Rame5L1;
    Rame5L1.setRadius(10);
    Rame5L1.setPosition(355, 100);
    Rame5L1.setFillColor(Color::Yellow);
    CircleShape Rame6L1;
    Rame6L1.setRadius(10);
    Rame6L1.setPosition(355, 125);
    Rame6L1.setFillColor(Color::Yellow);

    //DESSAIN DES POINTS L2
    CircleShape Rame1L2;
    Rame1L2.setRadius(10);
    Rame1L2.setPosition(855, 2);
    Rame1L2.setFillColor(Color::Red);
    CircleShape Rame2L2;
    Rame2L2.setRadius(10);
    Rame2L2.setPosition(855, 25);
    Rame2L2.setFillColor(Color::Red);
    CircleShape Rame3L2;
    Rame3L2.setRadius(10);
    Rame3L2.setPosition(855, 50);
    Rame3L2.setFillColor(Color::Red);
    CircleShape Rame4L2;
    Rame4L2.setRadius(10);
    Rame4L2.setPosition(855, 75);
    Rame4L2.setFillColor(Color::Red);
    CircleShape Rame5L2;
    Rame5L2.setRadius(10);
    Rame5L2.setPosition(855, 100);
    Rame5L2.setFillColor(Color::Red);
    CircleShape Rame6L2;
    Rame6L2.setRadius(10);
    Rame6L2.setPosition(855, 125);
    Rame6L2.setFillColor(Color::Red);

    //STATIONS (id, nom, position x, position y, nombre de passagers, couleur) 
    //L1
    Station station1_begin(0, "Station Debut", 50, 600, 0, Color::White, false, false);
    Station station1_1(1, "Station1", 141, 600, 10, Color::Yellow, true, false);
    Station station1_2(2, "Station2", 232, 600, 10, Color::Yellow, false, false);
    Station station1_3(3, "Station3", 323, 600, 10, Color::Yellow, false, false);
    Station station1_4(4, "Station4", 414, 600, 10, Color::Yellow, false, false);
    Station station1_5(5, "Station5", 505, 600, 10, Color::Yellow, false, false);
    Station station1_6(6, "Station6", 596, 600, 10, Color::Yellow, false, false);
    Station station1_7(7, "Station7", 687, 600, 10, Color::Yellow, false, false);
    Station station1_8(8, "Station6", 778, 600, 10, Color::Yellow, false, false);
    Station station1_9(9, "Station6", 869, 600, 10, Color::Yellow, false, false);
    Station station1_10(10, "Station6", 960, 600, 10, Color::Yellow, false, false);
    Station station1_11(11, "Station6", 1051, 600, 10, Color::Yellow, false, false);
    Station station1_12(12, "Station6", 1142, 600, 10, Color::Yellow, false, false);
    Station station1_13(13, "Station6", 1233, 600, 10, Color::Yellow, false, false);
    Station station1_14(14, "Station6", 1324, 600, 10, Color::Yellow, false, false);
    Station station1_15(15, "Station6", 1415, 600, 10, Color::Yellow, false, false);
    Station station1_16(16, "Station6", 1506, 600, 10, Color::Yellow, false, false);
    Station station1_17(17, "Station6", 1597, 600, 10, Color::Yellow, false, false);
    Station station1_18(18, "Station6", 1688, 600, 10, Color::Yellow, true, false);
    Station station1_end(8, "Station Fin", 1779, 600, 0, Color::White, false, false);

    //L2
    Station station2_begin(0, "Station Debut", 45, 600, 0, Color::White, false, false);
    Station station2_1(1, "Station1", 90, 600, 10, Color::Red, true, false);
    Station station2_2(2, "Station2", 135, 600, 10, Color::Red, false, false);
    Station station2_3(3, "Station3", 180, 600, 10, Color::Red, false, false);
    Station station2_4(4, "Station4", 225, 600, 10, Color::Red, false, false);
    Station station2_5(5, "Station5", 270, 600, 10, Color::Red, false, false);
    Station station2_6(6, "Station6", 315, 600, 10, Color::Red, false, false);
    Station station2_7(7, "Station7", 360, 600, 10, Color::Red, false, false);
    Station station2_8(8, "Station8", 405, 600, 10, Color::Red, false, false);
    Station station2_9(9, "Station9", 450, 600, 10, Color::Red, false, false);
    Station station2_10(10, "Station10", 495, 600, 10, Color::Red, false, false);
    Station station2_11(3, "Station3", 540, 600, 10, Color::Red, false, true);
    Station station2_12(4, "Station3", 540, 645, 10, Color::Red, false, false);
    Station station2_13(5, "Station6", 540, 690, 10, Color::Red, false, true);
    Station station2_14(6, "Station7", 585, 690, 10, Color::Red, false, false);
    Station station2_15(7, "Station8", 630, 690, 10, Color::Red, false, false);
    Station station2_16(8, "Station9", 675, 690, 10, Color::Red, false, false);
    Station station2_17(1, "Station1", 720, 690, 10, Color::Red, false, true);
    Station station2_18(2, "Station2", 720, 645, 10, Color::Red, false, false);
    Station station2_19(3, "Station3", 720, 600, 10, Color::Red, false, true);
    Station station2_20(4, "Station4", 765, 600, 10, Color::Red, false, false);
    Station station2_21(5, "Station5", 810, 600, 10, Color::Red, false, false);
    Station station2_22(6, "Station6", 855, 600, 10, Color::Red, false, false);
    Station station2_23(7, "Station7", 900, 600, 10, Color::Red, false, false);
    Station station2_24(8, "Station8", 945, 600, 10, Color::Red, false, false);
    Station station2_25(9, "Station9", 990, 600, 10, Color::Red, false, true);
    Station station2_26(1, "Station1", 990, 555, 10, Color::Red, false, false);
    Station station2_27(3, "Station3", 990, 510, 10, Color::Red, false, true);
    Station station2_28(4, "Station3", 1035, 510, 10, Color::Red, false, false);
    Station station2_29(5, "Station6", 1080, 510, 10, Color::Red, false, false);
    Station station2_30(6, "Station7", 1125, 510, 10, Color::Red, false, false);
    Station station2_31(7, "Station8", 1170, 510, 10, Color::Red, false, false);
    Station station2_32(8, "Station9", 1215, 510, 10, Color::Red, false, false);
    Station station2_33(1, "Station1", 1260, 510, 10, Color::Red, true, false);
    Station station2_34(2, "Station2", 1305, 510, 10, Color::Red, false, false);
    Station station2_35(3, "Station3", 1350, 510, 10, Color::Red, false, false);
    Station station2_36(4, "Station4", 1395, 510, 10, Color::Red, false, false);
    Station station2_37(5, "Station5", 1440, 510, 10, Color::Red, false, false);
    Station station2_38(6, "Station6", 1485, 510, 10, Color::Red, false, false);
    Station station2_39(7, "Station7", 1530, 510, 10, Color::Red, false, false);
    Station station2_40(8, "Station8", 1575, 510, 10, Color::Red, false, false);
    Station station2_41(9, "Station9", 1620, 510, 10, Color::Red, false, false);
    Station station2_42(1, "Station1", 1665, 510, 10, Color::Red, false, false);
    Station station2_43(3, "Station3", 1710, 510, 10, Color::Red, false, false);
    Station station2_44(4, "Station3", 1755, 510, 10, Color::Red, true, false);
    Station station2_end(45, "Station Fin", 1800, 510, 0, Color::White, false, false);

    //on regroupe les stations des lignes dans des tableau, chaque tableau vaut une ligne
    vector<Station> listeStationsL2 = { station2_begin, station2_1, station2_2, station2_3, station2_4, station2_5, station2_6, station2_7, station2_8, station2_9, station2_10, station2_11, station2_12, station2_13, station2_14, station2_15, station2_16, station2_17, station2_18, station2_19, station2_20, station2_21, station2_22, station2_23, station2_24, station2_25, station2_26, station2_27, station2_28, station2_29, station2_30, station2_31, station2_32, station2_33, station2_34, station2_35, station2_36, station2_37, station2_38, station2_39, station2_40, station2_41, station2_42, station2_43, station2_44, station2_end };
    vector<Station> listeRStationsL2 = listeStationsL2;
    reverse(listeRStationsL2.begin(), listeRStationsL2.end());

    vector<Station> listeStationsL1 = { station1_begin, station1_1, station1_2, station1_3, station1_4, station1_5, station1_6, station1_7, station1_8, station1_9,station1_10, station1_11, station1_12, station1_13, station1_14,station1_15, station1_16, station1_17, station1_18,station1_end};
    vector<Station> listeRStationsL1 = listeStationsL1;
    reverse(listeRStationsL1.begin(), listeRStationsL1.end());

    vector<string> nom_station_L2 = { " ", "","lomme St Philibert","Bourg","Maison des Enfant","Mitterie","Pont Sup�rieur","Lomme_Lambersant","Canteleu","Bois Blancs","Port de Lille","Cormontainge","Montebello","Porte des Postes","","","","","","" ,"","","" ,"","","" ,"","","" ,"","","" ,"","","" ,"","","" ,"","","" ,"","","" ,"","","" };
    vector<string> nom_station_L1 = {" ", "Lille-CHR B-Calmette","CHR Oscar Lambret","Porte des Postes","Wazemmes","Gambetta","R�publique Beaux Arts","Rihour","Gare Lille Flandres","Caulier","Fives","Marberie","Hellemmes","Lezennes","Pont de Bois","Villeneuve d'Ascq Hotel de Ville","Triolo","Cit� Scientifique Professeur Gabillard","4 Cantons",""};

    for (size_t i = 1; i < listeStationsL1.size()-1; i++)
    {
        listeStationsL1[i].set_nom(nom_station_L1[i-1]);
    }

    //definition des rames (station d'apparition, id)
    Rame rame1_1(station1_begin, 1,1,false);
    Rame rame1_2(station1_begin, 2,1,false);
    Rame rame1_3(station1_begin, 3,1,false);
    Rame rame1_4(station1_end, 4,1,true);
    Rame rame1_5(station1_end, 5,1,true);
    Rame rame1_6(station1_end, 6,1,true);
    Rame rame2_1(station2_begin, 7,2,false);
    Rame rame2_2(station2_begin, 8,2,false);
    Rame rame2_3(station2_begin, 9,2,false);
    Rame rame2_4(station2_end, 10,2,true);
    Rame rame2_5(station2_end, 11,2,true);
    Rame rame2_6(station2_end, 12,2,true);

    
    vector<Rame> tabRame_L1 = { rame1_1,rame1_2,rame1_3,rame1_4,rame1_5,rame1_6 };
    vector<Rame> tabRame_L2 = { rame2_1,rame2_2,rame2_3,rame2_4,rame2_5,rame2_6 };

    //creation des threads (fonction de deplacement, rame concernee, rame suivante, ligne concernee)
    //thread thread1_1(moveRame, ref(rame1_1), ref(rame1_6), ref(listeStationsL1), true, ref(tabRame_L1), ref(text));
    //thread thread2_1(moveRame, ref(rame2_1), ref(rame2_6), ref(listeStationsL2), true, ref(tabRame_L2), ref(text2));
    //thread thread1_4(moveRame, ref(rame1_4), ref(rame1_3), ref(listeRStationsL1), true, ref(tabRame_L1), ref(text));
    thread thread2_4(moveRame, ref(rame2_4), ref(rame2_3), ref(listeRStationsL2), true, ref(tabRame_L2), ref(text2));

    //thread thread1_2(moveRame, ref(rame1_2), ref(rame1_1), ref(listeStationsL1), false, ref(tabRame_L1), ref(text));
    //thread thread1_3(moveRame, ref(rame1_3), ref(rame1_2), ref(listeStationsL1), false, ref(tabRame_L1), ref(text));
    //thread thread1_5(moveRame, ref(rame1_5), ref(rame1_4), ref(listeRStationsL1), false, ref(tabRame_L1), ref(text));
    //thread thread1_6(moveRame, ref(rame1_6), ref(rame1_5), ref(listeRStationsL1), false, ref(tabRame_L1), ref(text));
    /*thread thread2_2(moveRame, ref(rame2_2), ref(rame2_1), ref(listeStationsL2), false, ref(tabRame_L2), ref(text2));
    thread thread2_3(moveRame, ref(rame2_3), ref(rame2_2), ref(listeStationsL2), false, ref(tabRame_L2), ref(text2));
    thread thread2_5(moveRame, ref(rame2_5), ref(rame2_4), ref(listeRStationsL2), false, ref(tabRame_L2), ref(text2));
    thread thread2_6(moveRame, ref(rame2_6), ref(rame2_5), ref(listeRStationsL2), false, ref(tabRame_L2), ref(text2));*/

    Image icon;
    if (!icon.loadFromFile(ICON)) {
        return EXIT_FAILURE;
    }

    //creation et gestion de la fenetre
    RenderWindow window(VideoMode(WINDOW_X, WINDOW_Y), WINDOW_NAME);

    // Definir l'icone de la fenetre
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while (window.isOpen())
    {
        //gestion de la destruction de la fenetre
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }

            //visible(rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6, event, window, Rame1L1, Rame2L1, Rame3L1, Rame4L1, Rame5L1, Rame6L1, affiche1);
            visible(rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6, event, window, Rame1L2, Rame2L2, Rame3L2, Rame4L2, Rame5L2, Rame6L2, affiche2);
        }

        window.clear(Color::Black); //couleur d'arriere plan

        //PARTIE AFFICHAGE DES STATIONS + ROUTES
        //for (int i = 0; i < listeStationsL1.size(); i++) { //pour la L1
        //    listeStationsL1[i].setRepr(); //on set la representation de la station en cours
        //    if (i != listeStationsL1.size() - 1) { //la derniere station ne peut avoir de route a sa droite
        //        if (i == 0 || i == listeStationsL1.size() - 2) {
        //            Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on cree une route de cette station e la suivante
        //            Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::White); //on cree une route de retour
        //            route.setRepr(); //on set la repr�sentation de la route
        //            route_r.setReprRetour(); //on set la repr�sentation de la route de retour
        //            window.draw(route.getRepr()); //on dessine la route
        //            window.draw(route_r.getRepr()); //on dessine la route de retour

        //        }
        //        else {
        //            Route route(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Yellow); //on cree une route de cette station a la suivante
        //            Route route_r(i + 1, listeStationsL1[i], listeStationsL1[i + 1], Color::Yellow); //on cree une route de retour
        //            route.setRepr(); //on set la repr�sentation de la route
        //            route_r.setReprRetour(); //on set la representation de la route de retour
        //            window.draw(route.getRepr()); //on dessine la route
        //            window.draw(route_r.getRepr()); //on dessine la route de retour

        //        }

        //    }

        //    updateRameText(text, tabRame_L1, rame1_1,0);
        //    updateRameText(text, tabRame_L1, rame1_2,0);
        //    updateRameText(text, tabRame_L1, rame1_3,0);
        //    updateRameText(text, tabRame_L1, rame1_4,0);
        //    updateRameText(text, tabRame_L1, rame1_5,0);
        //    updateRameText(text, tabRame_L1, rame1_6,0);
        //    Text text_S;
        //    text_S.setFont(font);
        //    text_S.setCharacterSize(15);
        //    text_S.setFillColor(Color::White);
        //    text_S.setPosition(listeStationsL1[i].getPositionX()+5, listeStationsL1[i].getPositionY() + 30);
        //    text_S.setRotation(45.0f);
        //    text_S.setString(nom_station_L1[i]);
        //    window.draw(listeStationsL1[i].getRepr());//on dessine la station
        //    window.draw(text_S);

        //}

        for (int i = 0; i < listeStationsL2.size(); i++) { //pour la L2
            listeStationsL2[i].setRepr(); //on set la representation de la station en cours
            if (i != listeStationsL2.size() - 1) { //la derniere station ne peut avoir de route a sa droite
                if (i == 0 || i == listeStationsL2.size() - 2) {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on cree une route de cette station a la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::White); //on cree une route de retour
                    route.setRepr(); //on set la repr�sentation de la route
                    route_r.setReprRetour(); //on set la representation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }
                else {
                    Route route(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Red); //on cree une route de cette station a la suivante
                    Route route_r(i + 1, listeStationsL2[i], listeStationsL2[i + 1], Color::Red); //on cree une route de retour
                    route.setRepr(); //on set la representation de la route
                    route_r.setReprRetour(); //on set la representation de la route de retour
                    window.draw(route.getRepr()); //on dessine la route
                    window.draw(route_r.getRepr()); //on dessine la route de retour
                }

            }

            updateRameText(text2, tabRame_L2, rame2_1,500);
            updateRameText(text2, tabRame_L2, rame2_2,500);
            updateRameText(text2, tabRame_L2, rame2_3,500);
            updateRameText(text2, tabRame_L2, rame2_4,500);
            updateRameText(text2, tabRame_L2, rame2_5,500);
            updateRameText(text2, tabRame_L2, rame2_6,500);
            Text text_S;
            text_S.setFont(font);
            text_S.setCharacterSize(15);
            text_S.setFillColor(Color::White);
            text_S.setPosition(listeStationsL2[i].getPositionX()+5, listeStationsL2[i].getPositionY() + 30);
            text_S.setRotation(45.0f);
            text_S.setString(nom_station_L2[i]);
            window.draw(listeStationsL2[i].getRepr());//on dessine la station
            window.draw(text_S);
        }

        window.draw(text);
        window.draw(text2);

        affichage(rame1_1, rame1_2, rame1_3, rame1_4, rame1_5, rame1_6, window);
        affichage(rame2_1, rame2_2, rame2_3, rame2_4, rame2_5, rame2_6, window);

        //on dessine les rames
        //window.draw(rame1_1.getRepr());
        //window.draw(rame1_2.getRepr());
        //window.draw(rame1_3.getRepr());
        //window.draw(rame1_4.getRepr());
        //window.draw(rame1_5.getRepr());
        //window.draw(rame1_6.getRepr());
        //window.draw(rame2_1.getRepr());
        //window.draw(rame2_2.getRepr());
        //window.draw(rame2_3.getRepr());
        //window.draw(rame2_4.getRepr());
        //window.draw(rame2_5.getRepr());
        //window.draw(rame2_6.getRepr());

        window.draw(Rame1L1);
        window.draw(Rame2L1);
        window.draw(Rame3L1);
        window.draw(Rame4L1);
        window.draw(Rame5L1);
        window.draw(Rame6L1);

        window.draw(Rame1L2);
        window.draw(Rame2L2);
        window.draw(Rame3L2);
        window.draw(Rame4L2);
        window.draw(Rame5L2);
        window.draw(Rame6L2);

        window.draw(affiche1);
        window.draw(re1);
        window.draw(affiche2);
        window.draw(re2);

        window.display(); //affichage de la fenetre
    }

    //destruction des threads
    //thread1_1.join();
    //thread1_2.join();
    //thread1_3.join();
    //thread1_4.join();
    //thread1_5.join();
    //thread1_6.join();
    //thread2_1.join();
    //thread2_2.join();
    //thread2_3.join();
    thread2_4.join();
    //thread2_5.join();
    //thread2_6.join();

    return 0;
}