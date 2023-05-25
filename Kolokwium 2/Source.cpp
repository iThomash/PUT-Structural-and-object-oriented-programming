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

    sf::Texture bgTxt = loadTexture("sky.png");
    sf::Sprite bg;
    bg.setTexture(bgTxt);
    sprites.emplace_back(bg);

    AnimatedSprite apple;
    sf::Texture appleTxt = loadTexture("apple.png");
    apple.setTexture(appleTxt);

    sf::Texture treeTxt = loadTexture("tree.png");
    sf::Sprite tree;
    tree.setTexture(treeTxt);

    tree.setPosition(50, 20);
    sprites.emplace_back(tree);
    tree.setPosition(450, 20);
    sprites.emplace_back(tree);


    sf::Texture floorTxt = loadTexture("grass-3.png");
    //w przypadku gdy tekstura bedzie za krotka to ta metoda pozwoli na jej powtarzanie az do momentu ponizej
    floorTxt.setRepeated(true);
    
    sf::Sprite floor;
    floor.setTexture(floorTxt, true);
    //setTextureRect pozwala na wczesniejsze uzycie metody .setRepeated()
    floor.setTextureRect({0,0, 900, 48 });
    floor.setPosition(0, 600-48);

    AnimatedSprite hero;
    sf::Texture texture_hero = loadTexture("Farmer.png");
    hero.setTexture(texture_hero);
    hero.setSpeed(0, 0);
    hero.setPosition(50, 600 - 85);
    //(15 * 50) - oznacza jak dlugo wykonywac petle animacji
    //15 - liczna pojedynczych klatek bohatera
    //64 - szerokosc pojedynczej tekstury
    for (int i = 0; i < (15 * 64); i += 64)
    {
        // kolejne argumenty IntRect to:
        //i - miejsce x w ktorym rozpoczynamy teksture 
        //0 - miejsce y w ktorym rozpoczynamy teksture 
        //64 - szerokosc tekstury
        //72 - wysokosc tekstury
        hero.add_animation_frame(sf::IntRect(i, 0, 64, 72));
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

    vector<AnimatedSprite> apples;

    for (int i = 0; i < 8;i++) {
        apple.setPosition(100 * i + 140, 110);
        apples.emplace_back(apple);
    }

    sf::Clock clock;

    sf::Clock appleClock;
    int fallingApple = -1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsed = clock.restart();

        hero.step(elapsed);
        hero.animate(elapsed);

        //wydarzenia
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Down ) {
                hero.setSpeed(0,0);
            }
        }

        //tutaj jest ustawienie, ktore przy kazdej klatce ustawia srodek bohatera, aby pozniejsze skalowanie(odracanie tekstury) bylo poprawne 
        //tzn odbywalo sie wzgledem srodka 
        hero.setOrigin(sf::Vector2f(hero.getLocalBounds().width / 2.f, 0));
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                hero.setSpeed(-120, 0);
                //ten sprytny zapis pozwala na latwe obrocenie tekstury
                hero.setScale(-1.0f, 1.0f);
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                hero.setSpeed(120, 0);
                //ten sprytny zapis pozwala na latwe obrocenie tekstury
                hero.setScale(1.0f, 1.0f);
            }
        }
        //Ponizsze dwa if'y to zaiste detekcja zderzen z sciana
        if (hero.getGlobalBounds().left <= 0) {
            hero.setSpeed(120, 0);
            hero.setScale(1.0f, 1.0f);
        }
        if (hero.getGlobalBounds().left + hero.getGlobalBounds().width>= 900) {
            hero.setSpeed(-120, 0);
            hero.setScale(-1.0f, 1.0f);
        }


        if (appleClock.getElapsedTime().asSeconds() > 3 && fallingApple == -1) {
            //ziarno generowania
            std::srand(std::time(NULL));
            //modulo 8 bo mamy 8 jablek wiec nasze reszty z dzielenia beda w zakresie od 0 do 7
            fallingApple = rand()%8;
            appleClock.restart();
        }

        //spada jablko wiec poczekajmy az spadnie
        if (fallingApple != -1) {
            apples[fallingApple].setSpeed(0,120);
            apples[fallingApple].step(elapsed);
            apples[fallingApple].animate(elapsed);
            if (apples[fallingApple].getGlobalBounds().intersects(floor.getGlobalBounds())) {
                pointsNumber -= 1;
                points.setString(to_string(pointsNumber));
                apples[fallingApple].setSpeed(0, 0);
                apples[fallingApple].setPosition(apples[fallingApple].getPosition().x, 110);
                fallingApple = -1;
                appleClock.restart();
            } else if (apples[fallingApple].getGlobalBounds().intersects(hero.getGlobalBounds())) {
                pointsNumber += 1;
                points.setString(to_string(pointsNumber));
                apples[fallingApple].setSpeed(0, 0);
                apples[fallingApple].setPosition(apples[fallingApple].getPosition().x, 110);
                fallingApple = -1;
                appleClock.restart();
            }
        }

        //jesli nie bedzie tej linijki to nic zlego sie nie stanie
        //window.clear(sf::Color::Black);
        
        for (int i = 0;i < sprites.size();i++) {
            window.draw(sprites[i]);
        }

        window.draw(floor);
        window.draw(points);
        window.draw(hero);

        for (int i = 0;i < apples.size();i++) {
            window.draw(apples[i]);
        }

        window.display();
    }

    return 0;

} 