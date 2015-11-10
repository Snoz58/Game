#include <SFML/Graphics.hpp>

int main()
{
    // Création de la fenêtre
    int screenx = 800;
    int screeny = 600;
    sf::RenderWindow app(sf::VideoMode(screenx, screeny), "red dot");

    // Création du point
    sf::CircleShape dot;
    dot.setFillColor(sf::Color(255,0,0));
    dot.setRadius(15);
    float posx = 800/2-dot.getRadius();
    float posy = 600/2-dot.getRadius();
    dot.setPosition(posx, posy);

    sf::ContextSettings parametres;
    parametres.antialiasingLevel = 4;

	// Boucle du jeu
    while (app.isOpen())
    {

        // Gestion évenements
        sf::Event event;

        while (app.pollEvent(event))
        {
            // fermeture de la fenêtre
            if (event.type == sf::Event::Closed)
                app.close();
        }

        if (posx > 0 && posx < screenx-dot.getRadius() && posy > 0 && posy < screeny-dot.getRadius())

       // dot.move(sf::Joystick::getAxisPosition(0,sf::Joystick::X)/50,sf::Joystick::getAxisPosition(0,sf::Joystick::Y)/50);

        // Effacer l'écran
        app.clear();

        // Afficher le rond
        app.draw(dot);

        // Afficher l'écran
        app.display();
    }

    return EXIT_SUCCESS;
}
