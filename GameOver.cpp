#include "GameOver.hpp"
#include <iostream>
#include <string>
#include <sstream>

GameOver& GameOver::getInstance()
{
  static GameOver instance;

  return instance;
}

GameOver::GameOver()
{
  _pos_x = 200;
  _pos_y = 300;
}

GameOver::~GameOver()
{

}

void GameOver::init()
{

}

void GameOver::draw(sf::RenderWindow& window)
{
  /*int a = time.asSeconds();
  std::stringstream ss;
  ss << a;
  std::string str = ss.str();

  int b = time.asMilliseconds() % 1000 / 10;
  std::stringstream ss1;
  ss1 << b;
  std::string str1 = ss1.str();*/

  text.setString("Game Over !");
  text.setCharacterSize(80);
  text.setColor(sf::Color::Red);
  text.setPosition(_pos_x, _pos_y);

  window.draw(text);
}

void GameOver::update(sf::Keyboard input, sf::Time etime, sf::Font &font)
{
  // time += etime;
  text.setFont(font);
}

void GameOver::update(sf::Keyboard input, sf::Time etime)
{

}

sf::Text GameOver::getText() const
{
  return text;
}
