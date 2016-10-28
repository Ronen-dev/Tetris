#include <SFML/Graphics.hpp>
#include "Tetris.hpp"
#include "Timer.hpp"
#include "Fps.hpp"
#include "Score.hpp"
#include "GameOver.hpp"
#include "CubeShape.hpp"
#include "OShape.hpp"
#include "IShape.hpp"
#include "LShape.hpp"
#include "JShape.hpp"
#include "SShape.hpp"
#include "ZShape.hpp"
#include "TShape.hpp"
#include "FactoryShape.hpp"
#include <sstream>
#include <iostream>
#include <list>
#include <vector>

Tetris::Tetris()
{
  bool _gameOver = false;
}

Tetris::~Tetris()
{

}

void Tetris::init()
{    
  setParameter(750, 700, std::string("My Tetris"));
  
  for (int i = 0; i < 20; i++)
  {
    std::vector<AObject*> row;
    map.push_back(row);
    for (int j = 0; j < 10; j++)
    {
      map[i].push_back(NULL);
    }
  }

  current = FactoryShape::createRandShape();
}

void Tetris::update()
{
  sf::Time LoopTime = clock.getElapsedTime();
  clock.restart();
  
  Timer& time   = Timer::getInstance();
  Fps& fps      = Fps::getInstance();
  Score& score  = Score::getInstance();

  fps.update(input, LoopTime, font);

  if (current->isBlocked)
  {
    delete current;

    if (
      map[19][3] != NULL ||
      map[19][4] != NULL ||
      map[19][5] != NULL ||
      map[18][3] != NULL ||
      map[18][4] != NULL ||
      map[18][5] != NULL
    )
    {
      _gameOver = true;

      GameOver& go = GameOver::getInstance();
      go.update(input, LoopTime, font);
    }

    current = FactoryShape::createRandShape();
  }

  if (!_gameOver)
  {
    time.update(input, LoopTime, font);
    score.update(input, LoopTime, font, map);

    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++) {
        if (map[i][j] != NULL)
          map[i][j]->update(input, LoopTime);
      }
    }
    current->update(input, LoopTime, map);
  }


}

void Tetris::draw()
{
  Timer& time  = Timer::getInstance();
  Fps& fps     = Fps::getInstance();
  Score& score = Score::getInstance();
  GameOver& go = GameOver::getInstance();

  sf::RectangleShape rectangle(sf::Vector2f(300, 600));
  rectangle.setPosition(320, 50);
  rectangle.setOutlineColor(sf::Color::Black);
  rectangle.setOutlineThickness(3);
  
  fps.draw(window);
  time.draw(window);
  score.draw(window);
  window.draw(rectangle);

  for (int i = 0; i < 20; i++)
  { 
    for (int j = 0; j < 10; j++)
    {
      if (map[i][j] != NULL) {
        map[i][j]->draw(window);
      }
    }
  }

  current->draw(window);

  if (_gameOver)
    go.draw(window);
}
