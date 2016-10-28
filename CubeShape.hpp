#ifndef CUBESHAPE_HPP
#define CUBESHAPE_HPP

#include "AObject.hpp"

class CubeShape : public AObject
{
  public:
    CubeShape(int x, int y, sf::Color color);
    ~CubeShape();

    void update(sf::Keyboard input, sf::Time etime);
    void draw(sf::RenderWindow& window);
    void init();
  
    sf::RectangleShape& getCube();
 
  private:
    sf::Color _color;
    sf::RectangleShape _cube;
};

#endif
