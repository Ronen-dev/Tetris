#include "IShape.hpp"
#include "CubeShape.hpp"
#include <iostream>

IShape::IShape()
{
  r = n;

  speed = 1000000;
  currentTime = 0;
  timePressed = 0;

  isBlocked = false;

  AObject* object = new CubeShape(3, 19, sf::Color::Cyan);
  current.push_back(object);

  object = new CubeShape(4, 19, sf::Color::Cyan);
  current.push_back(object);

  // POINT DE PIVOT
  object = new CubeShape(5, 19, sf::Color::Cyan);
  current.push_back(object);

  object = new CubeShape(6, 19, sf::Color::Cyan);
  current.push_back(object);
}

IShape::~IShape()
{

}

void IShape::draw(sf::RenderWindow& window)
{
  for (int i = 0; i < 4; i++)
  {
    current[i]->draw(window);
  }
}

void IShape::update(
        sf::Keyboard input,
        sf::Time etime,
        std::vector<std::vector<AObject*> >& map
)
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

  if (
    sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
    timePressed <= 0
  )
  {
    moveRight(map, current);
    timePressed = 135000;
  }

  if (
    sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
    timePressed <= 0
  )
  {
    moveLeft(map, current);
    timePressed = 135000;
  }

  if (
    sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
    timePressed <= 0
  )
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

void IShape::_rotateN(std::vector<std::vector<AObject*> >& map)
{
  int x = current[2]->_pos_x;
  int y = current[2]->_pos_y;

  r = n;

  if (
    x != 9 &&
    x - 2 >= 0 &&
    x - 1 >= 0 &&
    x + 1 < 10 &&
    map[y][x - 2] == NULL &&
    map[y][x - 1] == NULL &&
    map[y][x + 1] == NULL
  )
  {
    current[0]->_pos_x = x - 2;
    current[0]->_pos_y = y;

    current[1]->_pos_x = x - 1;
    current[1]->_pos_y = y;

    current[3]->_pos_x = x + 1;
    current[3]->_pos_y = y;
  }
  // Si la pièce est collée au mur droit
  else if (x == 9)
  {
    if (
      map[y][6] == NULL &&
      map[y][7] == NULL &&
      map[y][8] == NULL &&
      map[y][9] == NULL
    )
    {
      current[0]->_pos_x = 6;
      current[0]->_pos_y = y;

      current[1]->_pos_x = 7;
      current[1]->_pos_y = y;

      current[2]->_pos_x = 8;
      current[2]->_pos_y = y;

      current[3]->_pos_x = 9;
      current[3]->_pos_y = y;
    }

    // Si la pièce est collée au mur gauche
  }
  else if (x == 0 || x == 1)
  {
    if (
      map[y][0] == NULL &&
      map[y][1] == NULL &&
      map[y][2] == NULL &&
      map[y][3] == NULL
    )
    {
      current[0]->_pos_x = 0;
      current[0]->_pos_y = y;

      current[1]->_pos_x = 1;
      current[1]->_pos_y = y;

      current[2]->_pos_x = 2;
      current[2]->_pos_y = y;

      current[3]->_pos_x = 3;
      current[3]->_pos_y = y;
    }
  }
  else
  {
    r = e;
  }
}

void IShape::_rotateE(std::vector<std::vector<AObject*> >& map)
{
  int x = current[2]->_pos_x;
  int y = current[2]->_pos_y;

  r = e;

  if (
    y - 2 >= 0 &&
    y - 1 >= 0 &&
    y + 1 < 20 &&
    map[y - 2][x] == NULL &&
    map[y - 1][x] == NULL &&
    map[y + 1][x] == NULL &&
    x != 9
  )
  {
    current[0]->_pos_x = x;
    current[0]->_pos_y = y - 2;

    current[1]->_pos_x = x;
    current[1]->_pos_y = y - 1;

    current[3]->_pos_x = x;
    current[3]->_pos_y = y + 1;
  }
  else
  {
    r = n;
  }
}

void IShape::_rotateS(std::vector<std::vector<AObject*> >& map)
{
  _rotateN(map);
}

void IShape::_rotateO(std::vector<std::vector<AObject*> >& map)
{
  _rotateE(map);
}