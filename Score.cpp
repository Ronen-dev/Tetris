#include "Score.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

Score& Score::getInstance()
{
  static Score instance;

  return instance;
}

Score::Score()
{
  _pos_x = 50;
  _pos_y = 300;

  _score = 0;
}

Score::~Score()
{

}

void Score::init()
{

}

void Score::draw(sf::RenderWindow& window)
{
  int a = _score;
  std::stringstream ss;
  ss << a;
  std::string str = ss.str();

  text.setString("Score : " + str);
  text.setCharacterSize(40);
  text.setColor(sf::Color::White);
  text.setPosition(_pos_x, _pos_y);

  window.draw(text);
}

void Score::update(sf::Keyboard input, sf::Time etime, sf::Font &font, std::vector<std::vector<AObject*> >& map)
{
  std::vector<int > tmp_y;
  int tmp = 0;
  int j   = 0;

  for (int i = 0; i < 20; i++)
  {
    for (j = 0; j < 10; j++)
    {
      if (map[i][j] == NULL)
      {
        break;
      }
    }
    if (j == 10)
    {
      tmp_y.push_back(i);
      tmp += 1;
      for (j = 0; j < 10; j++)
      {
        delete map[i][j];
        map[i][j] = NULL;
      }
    }
  }
  if (tmp == 4)
  {
    _score += 80;
  } else if (tmp > 0) {
    _score += tmp * 10;
  }

  for (int i = 0; i < tmp_y.size(); i ++)
  {
    for (int j = tmp_y[i]+1 - i ; j < 20;j++)
    {
      for (int x = 0; x < 10; x++)
      {
        if (map[j][x]) {
          std::cout << map[j][x]->_pos_x << std::endl;
          std::cout << map[j][x]->_pos_y << std::endl;
          map[j][x]->_pos_y = j - 1;
        }

        map[j-1][x] = map[j][x];
      }
    }
  }

  text.setFont(font);
}

void Score::update(sf::Keyboard input, sf::Time etime)
{

}

sf::Text Score::getText() const
{
  return text;
}
