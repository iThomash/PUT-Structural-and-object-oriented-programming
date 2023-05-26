#ifndef ANIMATED_SPRITE_H
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite() : sf::Sprite() {}

    void add_animation_frame(const sf::IntRect& frame);
    void step(const sf::Time& elapsed);
    void setSpeed(int speed_x, int speed_y);
    void animate(const sf::Time& elapsed);
    void bounce(float window_width);
    void toLeft(int x);
    void toRight(int x);
    void   gravity(const sf::Time& elapsed);
    void setstart(int x, int y);
    void ret();


private:
    vector<sf::IntRect> frames_;
    vector<sf::IntRect>::iterator current_frame_ = frames_.begin();
    float elapsed_accumulator_ = 0;
    float fps = 10;
    int speed_x_ = 0;
    int speed_y_ = 0;
    int startx;
    int starty;
};
sf::Texture loadTexture(const std::string& filename_with_path);


#endif