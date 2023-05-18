#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "./AnimatedSprite.h"
#include <vector>

using namespace std;



int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "My window");
    window.setFramerateLimit(60);

    vector<sf::Sprite> sprites;

    sf::Texture bgTxt = loadTexture("background.png");
    sf::Sprite bg;
    bg.setTexture(bgTxt);
    sprites.emplace_back(bg);

    AnimatedSprite banan;
    sf::Texture bananTxt = loadTexture("banan.png");
    banan.setTexture(bananTxt);
    banan.setScale(0.1, 0.1);

    sf::Texture palmTxt = loadTexture("palm.png");
    sf::Sprite palm;
    palm.setTexture(palmTxt);
    palm.setScale(4, 8);

    sf::Texture floorTxt = loadTexture("floor.png");
    sf::Sprite floor;
    floor.setTexture(floorTxt, true);
    floor.setScale(4, 8);
    floor.setPosition(0, 540);
    floor.setScale(8,2);

    AnimatedSprite hero;
    sf::Texture texture_hero = loadTexture("character.png");
    hero.setTexture(texture_hero);
    hero.setSpeed(0, 0);
    hero.setPosition(0, 600 - 75);
    for (int i = 0; i < (9 * 50); i += 50)
    {
        hero.add_animation_frame(sf::IntRect(i, 0, 50, 37));
    }

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) { return -1;}
    sf::Text points;
    int pointsNumber = 0;
    points.setString("0");
    points.setCharacterSize(32);
    points.setFont(font);
    points.setFillColor(sf::Color::Blue);
    points.setPosition(850, 10);

    for (int i = 0;i < 3;i++) {
        palm.setPosition(250*i + 70, 130);
        sprites.emplace_back(palm);
    }

    //bananas generation
    vector<AnimatedSprite> bananas;

    for (int i = 0; i < 3;i++) {
        banan.setPosition(250 * i + 60, 170);
        bananas.emplace_back(banan);
        banan.setPosition(250 * i + 180, 170);
        bananas.emplace_back(banan);
    }

    sf::Clock clock;

    sf::Clock bananaClock;
    int fallingBanana = -1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        const sf::Time elapsed = clock.restart();

        hero.step(elapsed);
        hero.animate(elapsed);

        //events
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Down ) {
                hero.setSpeed(0,0);
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                hero.setSpeed(-120, 0);
                hero.setScale(-1.0f, 1.0f);
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                hero.setSpeed(120, 0);
                hero.setScale(1.0f, 1.0f);
            }
        }

        if (hero.getGlobalBounds().left <= 0) {
            hero.setSpeed(120, 0);
            hero.setScale(1.0f, 1.0f);
        }
        if (hero.getGlobalBounds().left + hero.getGlobalBounds().width>= 900) {
            hero.setSpeed(-120, 0);
            hero.setScale(-1.0f, 1.0f);
        }


        if (bananaClock.getElapsedTime().asSeconds() > 3 && fallingBanana == -1) {
            std::srand(std::time(NULL));
            fallingBanana = rand()%6;
            bananaClock.restart();
        }

        if (fallingBanana != -1) {
            //there is a banana falling
            bananas[fallingBanana].setSpeed(0,120);
            bananas[fallingBanana].step(elapsed);
            bananas[fallingBanana].animate(elapsed);
            if (bananas[fallingBanana].getGlobalBounds().intersects(floor.getGlobalBounds())) {
                pointsNumber -= 1;
                points.setString(to_string(pointsNumber));
                bananas[fallingBanana].setSpeed(0, 0);
                bananas[fallingBanana].setPosition(bananas[fallingBanana].getPosition().x, 170);
                fallingBanana = -1;
                bananaClock.restart();
            } else if (bananas[fallingBanana].getGlobalBounds().intersects(hero.getGlobalBounds())) {
                pointsNumber += 1;
                points.setString(to_string(pointsNumber));
                bananas[fallingBanana].setSpeed(0, 0);
                bananas[fallingBanana].setPosition(bananas[fallingBanana].getPosition().x, 170);
                fallingBanana = -1;
                bananaClock.restart();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        
        for (int i = 0;i < sprites.size();i++) {
            window.draw(sprites[i]);
        }
        window.draw(floor);
        window.draw(points);
        window.draw(hero);

        for (int i = 0;i < bananas.size();i++) {
            window.draw(bananas[i]);
        }


        // end the current frame
        window.display();
    }

    return 0;

} 