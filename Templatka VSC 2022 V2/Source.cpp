#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../AnimatedSprite.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "My window");
    window.setFramerateLimit(60);
    sf::Sprite bg;
    sf::Texture background;

    if (!background.loadFromFile("background.png")) {
        return -1;
    } else {
        bg.setTexture(background);
    }
 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(bg);



        // end the current frame
        window.display();
    }

    return 0;

    return 0;
} 