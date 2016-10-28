#include "OShape.hpp"
#include "CubeShape.hpp"
#include <iostream>

OShape::OShape()
{
  r = n;
 
  speed = 1000000;
  currentTime = 0;
  timePressed = 0;

  isBlocked = false;

  AObject* object = new CubeShape(4, 19, sf::Color::Yellow);
  current.push_back(object);

  object = new CubeShape(5, 19, sf::Color::Yellow);
  current.push_back(object);

  object = new CubeShape(4, 18, sf::Color::Yellow);
  current.push_back(object);

  object = new CubeShape(5, 18, sf::Color::Yellow);
  current.push_back(object);
}

OShape::~OShape()
{

}

void OShape::draw(sf::RenderWindow& window)
{
  for (int i = 0; i < 4; i++)
  {
    current[i]->draw(window);
  }
}

void OShape::update(sf::Keyboard input,
                    sf::Time etime,
                    std::vector<std::vector<AObject*> >& map)
{
  currentTime += etime.asMicroseconds();
  timePressed -= etime.asMicroseconds();

  if (currentTime >= speed)
  {
    moveDown(map, current);
    currentTime = 0;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
      timePressed <= 0)
  {
    moveRight(map, current);
    timePressed = 135000;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
      timePressed <= 0)
  {
    moveLeft(map, current);
    timePressed = 135000;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
      timePressed <= 0)
  {
    moveDown(map, current);
    timePressed = 135000;
  }
}
