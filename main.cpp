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
        cout << "enfoncébas";
    }

    if (sf::Joystick::getAxisPosition(controller, sf::Joystick::PovY) == 0 && posdown){
        posdown = 0;
        active = 1;
        cout << "activébas";
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

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(screenx, screeny), "SFML window");
    app.setFramerateLimit(10);

    sf::Mouse mouse;

    sf::Keyboard keyboard;

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("images/fond2.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Vector2i possprite(0,0);
    sf::Texture texture_sprite;
    if (!texture_sprite.loadFromFile("images/sprites_cool.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite1(texture_sprite);


    // Charger une police
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

    int choix = 1;
    bool down = 0;

    // Création d'un texte
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

cout << sf::Joystick::getButtonCount(0) << " bouttons" << endl;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && choix > 1 || activedcrossup(0) && choix > 1){
                choix --;
                cout << choix << endl;


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && choix < 3 || activedcrossdown(0) && choix < 3){
                choix ++;
                cout << choix << endl;
            }
            // cout << activedcrossdown(0) << endl;
/*
            if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 0)
                down = 1;

            if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) == 0 && choix < 3 && down == 1){
                choix ++;
                down = 0;
                cout << choix << endl;
            }
    */

                texte_jouer.setFont(font);
                texte_options.setFont(font);
                texte_quitter.setFont(font);

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

cout << possprite.x * 400 << " - " << possprite.y * 530 << endl;
cout << texture_sprite.getSize().x << " - " << texture_sprite.getSize().y << endl;
//cout << "x = " << possprite.x << " - y = " << possprite.y << endl;
        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);
        app.draw(sprite1);

        // afficher le texte
        app.draw(texte_jouer);
        app.draw(texte_options);
        app.draw(texte_quitter);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
