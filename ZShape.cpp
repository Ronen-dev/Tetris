#include "ZShape.hpp"
#include "CubeShape.hpp"
#include <iostream>

ZShape::ZShape()
{
  r = n;

  speed = 1000000;
  currentTime = 0;
  timePressed = 0;

  isBlocked = false;

  AObject* object = new CubeShape(3, 19, sf::Color::Green);
  current.push_back(object);
  
  // POINT DE PIVOT
  object = new CubeShape(4, 19, sf::Color::Green);
  current.push_back(object);

  object = new CubeShape(4, 18, sf::Color::Green);
  current.push_back(object);

  object = new CubeShape(5, 18, sf::Color::Green);
  current.push_back(object);
}

ZShape::~ZShape()
{

}

void ZShape::draw(sf::RenderWindow& window)
{
  for (int i = 0; i < 4; i++)
  {
    current[i]->draw(window);
  }
}

void ZShape::update(sf::Keyboard input,
                    sf::Time etime,
                    std::vector<std::vector<AObject*> >& map)
{
  currentTime += etime.asMicroseconds();
  
  if (timePressed > 0)
  {
    timePressed -= etime.asMicroseconds();
  }

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

  // Right & Left
  if (
    (
      sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)
    ) &&
    timePressed <= 0
  )
  {
    if (r == n)
      _rotateE(map);
    else if (r == e)
      _rotateN(map);

    timePressed = 135000;
  }
}

void ZShape::_rotateN(std::vector<std::vector<AObject*> >& map)
{
  int x = current[1]->_pos_x;
  int y = current[1]->_pos_y;

  Rotation tmp = r;
  r = n;

  if (
    x - 1 >= 0 &&
    y - 1 >= 0 &&
    x + 1 < 10 &&
    map[y][x - 1] == NULL &&
    map[y - 1][x] == NULL &&
    map[y - 1][x + 1] == NULL &&
    x != 9
  )
  {
    current[0]->_pos_x = x - 1;
    current[0]->_pos_y = y;

    current[2]->_pos_x = x;
    current[2]->_pos_y = y - 1;

    current[3]->_pos_x = x + 1;
    current[3]->_pos_y = y - 1;
  }
  else if (x == 9)
  {
    if (
      map[y - 1][9] == NULL &&
      map[y - 1][8] == NULL &&
      map[y][8] == NULL &&
      map[y][7] == NULL
    )
    {
      current[0]->_pos_x = 7;
      current[0]->_pos_y = y;

      current[1]->_pos_x = 8;
      current[1]->_pos_y = y;

      current[2]->_pos_x = 8;
      current[2]->_pos_y = y - 1;

      current[3]->_pos_x = 9;
      current[3]->_pos_y = y - 1;
    }
    else
    {
      r = e;
    }
  }
  else
  {
    r = e;
  }
}

void ZShape::_rotateE(std::vector<std::vector<AObject*> >& map)
{
  int x = current[1]->_pos_x;
  int y = current[1]->_pos_y;

  r = e;

  if (
    y + 1 < 20 &&
    x - 1 < 10 &&
    y - 1 < 20 &&
    map[y + 1][x] == NULL &&
    map[y][x - 1] == NULL &&
    map[y - 1][x - 1] == NULL
  )
  {
    current[0]->_pos_x = x;
    current[0]->_pos_y = y + 1;

    current[2]->_pos_x = x - 1;
    current[2]->_pos_y = y;

    current[3]->_pos_x = x - 1;
    current[3]->_pos_y = y - 1;
  }
  else
  {
    r = n;
  }
}

void ZShape::_rotateS(std::vector<std::vector<AObject*> >& map)
{
  _rotateN(map);
}

void ZShape::_rotateO(std::vector<std::vector<AObject*> >& map)
{
  _rotateE(map);
}

