#ifndef AOBJECT_HPP
#define AOBJECT_HPP

#include "SFML/Graphics.hpp"

class AObject
{
  public:
    ~AObject(){};

    virtual void init() = 0;
    virtual void update(sf::Keyboard input, sf::Time etime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    int _pos_x;
    int _pos_y;
};

#endif
