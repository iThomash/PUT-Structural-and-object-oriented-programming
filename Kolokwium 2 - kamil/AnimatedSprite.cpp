#include "AnimatedSprite.h"

#include <iostream>


void AnimatedSprite::add_animation_frame(const sf::IntRect& frame) {
    frames_.emplace_back(frame);
    current_frame_ = frames_.begin();
}

void AnimatedSprite::step(const sf::Time& elapsed) {
    elapsed_accumulator_ += elapsed.asSeconds();
    while (elapsed_accumulator_ >= 1.0 / fps) {
        elapsed_accumulator_ -= 1.0 / fps;
        if (!frames_.empty()) {
            setTextureRect(*current_frame_);
            current_frame_++;
            if (current_frame_ == frames_.end())
            {
                current_frame_ = frames_.begin();
            }
        }
    }
}

void AnimatedSprite::setSpeed(
    int speed_x, int speed_y
)
{
    speed_x_ = speed_x;
    speed_y_ = speed_y;
}

void AnimatedSprite::animate(const sf::Time& elapsed) {
    move(speed_x_ * elapsed.asSeconds(), speed_y_ * elapsed.asSeconds());
}

void AnimatedSprite::bounce(float window_width)    // implementacja zderzeñ z granicami obszaru
{
    sf::FloatRect hero_bounds = getGlobalBounds();

    if (hero_bounds.left <= 0)
    {
        speed_x_ = std::abs(speed_x_);
        setScale(1.f, 1.f);
    }
    if (hero_bounds.left + hero_bounds.width >= window_width)
    {
        speed_x_ = -std::abs(speed_x_);
        setScale(-1.f, 1.f);
    }
}
void AnimatedSprite::toLeft(int x)
{
    if (speed_x_ == 0)
    {
        speed_x_ = -x;
    }
    else {
        speed_x_ = -std::abs(speed_x_);
    }
    setScale(-1.f, 1.f);
}

void AnimatedSprite::toRight(int x)
{
    if (speed_x_ == 0)
    {
        speed_x_ = -x;
    }
    else {

        speed_x_ = std::abs(speed_x_);
    }
    setScale(1.f, 1.f);
}


void AnimatedSprite::gravity(const sf::Time& elapsed)
{

    float g = 100;
    speed_y_ += g * elapsed.asSeconds();
    move(0, speed_y_ * elapsed.asSeconds());
    cout << speed_y_ << endl;
}
void AnimatedSprite::setstart(int x, int y)
{
    startx = x;
    starty = y;
}

void AnimatedSprite::ret() {
    setPosition(startx, starty);
    speed_x_ = 0;
    speed_y_ = 0;
}


sf::Texture loadTexture(const std::string& filename_with_path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename_with_path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    return texture;
}