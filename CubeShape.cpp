#include "SFML/Graphics.hpp"
#include "CubeShape.hpp"

CubeShape::CubeShape(int x, int y, sf::Color color)
{
  _pos_x = x;
  _pos_y = y;
  _color = color;
}

CubeShape::~CubeShape()
{

}

void CubeShape::update(sf::Keyboard input, sf::Time etime)
{

}

void CubeShape::draw(sf::RenderWindow& window)
{
  _cube.setSize(sf::Vector2f(30, 30));
  _cube.setFillColor(_color);
  _cube.setOutlineColor(sf::Color::Black);  
  _cube.setOutlineThickness(-2);
  _cube.setPosition(320 + (_pos_x * 30), ((20 - _pos_y) * 30) + 20);
   
  window.draw(_cube);
}

void CubeShape::init()
{

}

sf::RectangleShape& CubeShape::getCube()
{
  return _cube;
}
