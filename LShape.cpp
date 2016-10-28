#include "LShape.hpp"
#include "CubeShape.hpp"
#include <iostream>

LShape::LShape()
{
  r = n;

  speed = 1000000;
  currentTime = 0;
  timePressed = 0;

  isBlocked = false;

  AObject* object = new CubeShape(3, 19, sf::Color(255, 128, 0));
  current.push_back(object);

  // POINT DE PIVOT
  object = new CubeShape(4, 19, sf::Color(255, 128, 0));
  current.push_back(object);

  object = new CubeShape(5, 19, sf::Color(255, 128, 0));
  current.push_back(object);

  object = new CubeShape(3, 18, sf::Color(255, 128, 0));
  current.push_back(object);
}

LShape::~LShape()
{

}

void LShape::draw(sf::RenderWindow& window)
{
  for (int i = 0; i < 4; i++)
  {
    current[i]->draw(window);
  }
}

void LShape::update(sf::Keyboard input,
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

  // Right
  if (
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) &&
    timePressed <= 0
  )
  {
    if (r == n)
      _rotateE(map);
    else if (r == e)
      _rotateS(map);
    else if (r == s)
      _rotateO(map);
    else if (r == o)
      _rotateN(map);

    timePressed = 135000;
  }

  // Left
  if (
    sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) &&
    timePressed <= 0
  )
  {
    if (r == n)
      _rotateO(map);
    else if (r == o)
      _rotateS(map);
    else if (r == s)
      _rotateE(map);
    else if (r == e)
      _rotateN(map);

    timePressed = 135000;
  }
}

void LShape::_rotateN(std::vector<std::vector<AObject*> >& map)
{
  int x = current[1]->_pos_x;
  int y = current[1]->_pos_y;

  Rotation tmp = r;
  r = n;

  if (
    x != 9 &&
    x != 0 &&
    x + 1 < 10 &&
    x - 1 >= 0 &&
    y - 1 >= 0 &&
    map[y][x + 1] == NULL &&
    map[y][x - 1] == NULL &&
    map[y - 1][x - 1] == NULL
  )
  {
    current[0]->_pos_x = x - 1;
    current[0]->_pos_y = y;

    current[2]->_pos_x = x + 1;
    current[2]->_pos_y = y;

    current[3]->_pos_x = x - 1;
    current[3]->_pos_y = y - 1;
  }
  // Si la pièce est collée au mur droit
  else if (x == 9)
  {
    if (
      map[y][7] == NULL &&
      map[y][8] == NULL &&
      map[y][9] == NULL &&
      map[y  - 1][7] == NULL
    )
    {
      current[0]->_pos_x = 7;
      current[0]->_pos_y = y;

      current[1]->_pos_x = 8;
      current[1]->_pos_y = y;

      current[2]->_pos_x = 9;
      current[2]->_pos_y = y;

      current[3]->_pos_x = 7;
      current[3]->_pos_y = y - 1;
    }
    else
    {
      r = tmp;
    }
  }
  // Si la pièce est collée est au mur gauche
  else if (x == 0)
  {
    if (
      map[y][0] == NULL &&
      map[y][1] == NULL &&
      map[y][2] == NULL &&
      map[y + 1][1] == NULL
    )
    {
      current[0]->_pos_x = 0;
      current[0]->_pos_y = y;

      current[1]->_pos_x = 1;
      current[1]->_pos_y = y;

      current[2]->_pos_x = 2;
      current[2]->_pos_y = y;

      current[3]->_pos_x = 0;
      current[3]->_pos_y = y - 1;
    }
    else
    {
      r = tmp;
    }
  }
  else
  {
    r = tmp;
  }
}

void LShape::_rotateE(std::vector<std::vector<AObject*> >& map)
{
  int x = current[1]->_pos_x;
  int y = current[1]->_pos_y;

  Rotation tmp = r;
  r = e;

  if (
    y - 1 >= 0 &&
    y + 1 < 20 &&
    x - 1 >= 0 &&
    map[y - 1][x] == NULL &&
    map[y + 1][x] == NULL &&
    map[y + 1][x - 1] == NULL
  )
  {
    current[0]->_pos_x = x;
    current[0]->_pos_y = y - 1;

    current[2]->_pos_x = x;
    current[2]->_pos_y = y + 1;

    current[3]->_pos_x = x - 1;
    current[3]->_pos_y = y + 1;
  }
  else
  {
    r = tmp;
  }
}

void LShape::_rotateS(std::vector<std::vector<AObject*> >& map)
{
  int x = current[1]->_pos_x;
  int y = current[1]->_pos_y;

  Rotation tmp = r;
  r = s;

  if (
    x != 9 &&
    x != 0 &&
    x + 1 < 10 &&
    x - 1 >= 0 &&
    y + 1 < 20 &&
    map[y][x + 1] == NULL &&
    map[y][x - 1] == NULL &&
    map[y + 1][x + 1] == NULL
  )
  {
    current[0]->_pos_x = x + 1;
    current[0]->_pos_y = y;

    current[2]->_pos_x = x - 1;
    current[2]->_pos_y = y;

    current[3]->_pos_x = x + 1;
    current[3]->_pos_y = y + 1;
  }
  // Si la pièce est collée au mur droit
  else if (x == 9)
  {
    if (
      map[y][7] == NULL &&
      map[y][8] == NULL &&
      map[y][9] == NULL &&
      map[y + 1][7] == NULL
      )
    {
      current[0]->_pos_x = 7;
      current[0]->_pos_y = y;

      current[1]->_pos_x = 8;
      current[1]->_pos_y = y;

      current[2]->_pos_x = 9;
      current[2]->_pos_y = y;

      current[3]->_pos_x = 7;
      current[3]->_pos_y = y + 1;
    }
    else
    {
      r = tmp;
    }
  }
  // Si la pièce est collée est au mur gauche
  else if (x == 0)
  {
    if (
      map[y][0] == NULL &&
      map[y][1] == NULL &&
      map[y][2] == NULL &&
      map[y + 1][2] == NULL
      )
    {
      current[0]->_pos_x = 0;
      current[0]->_pos_y = y;

      current[1]->_pos_x = 1;
      current[1]->_pos_y = y;

      current[2]->_pos_x = 2;
      current[2]->_pos_y = y;

      current[3]->_pos_x = 2;
      current[3]->_pos_y = y + 1;
    }
    else
    {
      r = tmp;
    }
  }
  else
  {
    r = tmp;
  }
}

void LShape::_rotateO(std::vector<std::vector<AObject*> >& map)
{
  int x = current[1]->_pos_x;
  int y = current[1]->_pos_y;

  Rotation tmp = r;
  r = o;

  if (
    y - 1 >= 0 &&
    y + 1 < 20 &&
    x + 1 >= 0 &&
    map[y - 1][x] == NULL &&
    map[y + 1][x] == NULL &&
    map[y - 1][x + 1] == NULL
  )
  {
    current[0]->_pos_x = x;
    current[0]->_pos_y = y - 1;

    current[2]->_pos_x = x;
    current[2]->_pos_y = y + 1;

    current[3]->_pos_x = x + 1;
    current[3]->_pos_y = y - 1;
  }
  else
  {
    r = tmp;
  }
}
