#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int screenx = 1280;
int screeny = 720;

// fonction pour détecter un boutton pressé sur la manette
// l'activation se fait lorsque le bouton est relaché
bool posdown = 0;
bool activedcrossdown(int controller){

    bool active = 0;

    if (sf::Joystick::getAxisPosition(controller, sf::Joystick::PovY) > 0){
        posdown = 1;
        cout << "enfoncébas\n";
    }

    if (sf::Joystick::getAxisPosition(controller, sf::Joystick::PovY) == 0 && posdown){
        posdown = 0;
        active = 1;
        std::cout << "activébas\n";
    }

    return active;
}
bool posup = 0;
bool activedcrossup(int controller){

    bool active = 0;

    if (sf::Joystick::getAxisPosition(controller, sf::Joystick::PovY) < 0){
        posup = 1;
        cout << "enfoncéhaut";
    }

    if (sf::Joystick::getAxisPosition(controller, sf::Joystick::PovY) == 0 && posup){
        posup = 0;
        active = 1;
        cout << "activéhaut";
    }

    return active;
}

class Menu {
    public:
        sf::Texture texture_bg_menu;
        sf::Font police1;
        sf::Font police2;
        int choix;

        Menu(sf::Texture texture_bg, sf::Font police1, sf::Font police2,int choix){
            this->texture_bg_menu = texture_bg;
            this->police1 = police1;
            this->police2 = police2;
            this->choix = choix;
        }


        void Menu_affiche(sf::RenderWindow app){

    sf::Sprite sprite(texture_bg_menu);
        // Création des textes
    sf::Text texte_jouer;
    texte_jouer.setFont(police1);
    texte_jouer.setString("Jouer");
    texte_jouer.setPosition(10, screeny / 2);

    sf::Text texte_options;
    texte_options.setFont(police1);
    texte_options.setString("Options");
    texte_options.setPosition(10, (screeny / 2 + 60));

    sf::Text texte_quitter;
    texte_quitter.setFont(police1);
    texte_quitter.setString("Quitter");
    texte_quitter.setPosition(10, screeny / 2 + 120);

         // Évènements
        sf::Event event;
        while (app.pollEvent(event))
        {

            // Initialisation du menu
            texte_jouer.setFont(police1);
            texte_options.setFont(police1);
            texte_quitter.setFont(police1);

            // fremeture de la fenêtre
            if (event.type == sf::Event::Closed)
                app.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && choix > 1 || activedcrossup(0) && choix > 1){ // menu haut
                choix --;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && choix < 3 || activedcrossdown(0) && choix < 3){ // menu bas
                choix ++;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){ // menu selectionné
                switch (choix){
                    case 1 : break;
                    case 2 : break;
                    case 3 : app.close(); break;
                }
            }

            // Gestion du "hover" sur le menu
            if (choix == 1)
                texte_jouer.setFont(police2);

            if (choix == 2)
                texte_options.setFont(police2);

            if (choix == 3)
                texte_quitter.setFont(police2);

        }

        // Effacer l'écran
        app.clear();

        // Dessiner le texte
        app.draw(texte_jouer);
        app.draw(texte_options);
        app.draw(texte_quitter);




}
};


int main()
{
    // Création de la fenêtre
    sf::RenderWindow app(sf::VideoMode(screenx, screeny), "Game", sf::Style::Fullscreen);
    app.setFramerateLimit(60); // 60fps
    app.setMouseCursorVisible(false); // ne pas afficher le curseur

    // Chargement des textures
    sf::Texture texture_bg_menu;
    if (!texture_bg_menu.loadFromFile("images/fond2.jpg")) // background
        return EXIT_FAILURE;
/*    sf::Sprite sprite(texture_bg_menu);

    sf::Vector2i possprite(0,0);
    sf::Texture texture_sprite;
    if (!texture_sprite.loadFromFile("images/sprites_cool.png")) // sprites perso
        return EXIT_FAILURE;
    sf::Sprite sprite1(texture_sprite);
*/
    // Chargement des police
    sf::Font font;
    if (!font.loadFromFile("polices/Kraash Black.ttf"))
    {
        cout << "can't load Kraash Black.ttf" << endl;
    }

    sf::Font font2;
    if (!font2.loadFromFile("polices/Kraash.ttf"))
    {
        cout << "can't load Kraash.ttf" << endl;
    }

    //    Menu Menu(texture_bg_menu, font, font2, 1);
    //    Menu.Menu_affiche(app);
/*
    // Création des textes
    sf::Text texte_jouer;
    texte_jouer.setFont(font);
    texte_jouer.setString("Jouer");
    texte_jouer.setPosition(10, screeny / 2);

    sf::Text texte_options;
    texte_options.setFont(font);
    texte_options.setString("Options");
    texte_options.setPosition(10, (screeny / 2 + 60));

    sf::Text texte_quitter;
    texte_quitter.setFont(font);
    texte_quitter.setString("Quitter");
    texte_quitter.setPosition(10, screeny / 2 + 120);


    // position dans le menu
    int choix = 1;



    // Boucle principale
    while (app.isOpen())
    {
        // Évènements
        sf::Event event;
        while (app.pollEvent(event))
        {

            // Initialisation du menu
            texte_jouer.setFont(font);
            texte_options.setFont(font);
            texte_quitter.setFont(font);

            // fremeture de la fenêtre
            if (event.type == sf::Event::Closed)
                app.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && choix > 1 || activedcrossup(0) && choix > 1){ // menu haut
                choix --;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && choix < 3 || activedcrossdown(0) && choix < 3){ // menu bas
                choix ++;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){ // menu selectionné
                switch (choix){
                    case 1 : break;
                    case 2 : break;
                    case 3 : app.close(); break;
                }
            }

            // Gestion du "hover" sur le menu
            if (choix == 1)
                texte_jouer.setFont(font2);

            if (choix == 2)
                texte_options.setFont(font2);

            if (choix == 3)
                texte_quitter.setFont(font2);


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                possprite.x++;
                if (possprite.x * 400 >= texture_sprite.getSize().x){
                    possprite.x = 0;

                    possprite.y ++;
                    if (possprite.y * 530 >= texture_sprite.getSize().y)
                        possprite.y = 0;
                }
            }
        sprite1.setTextureRect(sf::IntRect(possprite.x*400, possprite.y * 530, 400, 530));

        // Effacer l'écran
        app.clear();

        // Dessiner les sprites
        app.draw(sprite);
        app.draw(sprite1);

        // Dessiner le texte
        app.draw(texte_jouer);
        app.draw(texte_options);
        app.draw(texte_quitter);

        // Afficher les modifications
        app.display();
    }
*/

    // Afficher les modifications
    app.display();

    return EXIT_SUCCESS;

}

