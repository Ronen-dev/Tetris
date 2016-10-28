#include "Timer.hpp"
#include <iostream>
#include <string>
#include <sstream>

Timer& Timer::getInstance()
{
  static Timer instance;

  return instance;
}

Timer::Timer()
{
  _pos_x = 50;
  _pos_y = 50;
}

Timer::~Timer()
{

}

void Timer::init()
{

}

void Timer::draw(sf::RenderWindow& window)
{
  int a = time.asSeconds();
  std::stringstream ss;
  ss << a;
  std::string str = ss.str();

  int b = time.asMilliseconds() % 1000 / 10;
  std::stringstream ss1;
  ss1 << b;
  std::string str1 = ss1.str();

  text.setString(str + " : " + str1);
  text.setCharacterSize(50);
  text.setColor(sf::Color::White);
  text.setPosition(_pos_x, _pos_y);
  
  window.draw(text);
}

void Timer::update(sf::Keyboard input, sf::Time etime, sf::Font &font)
{
  time += etime;
  text.setFont(font);
}

void Timer::update(sf::Keyboard input, sf::Time etime)
{

}

sf::Text Timer::getText() const
{
  return text;
}
