#include "Fps.hpp"
#include <iostream>
#include <string>
#include <sstream>

Fps& Fps::getInstance()
{
  static Fps instance;

  return instance;
}

Fps::Fps()
{
  _pos_x = 50;
  _pos_y = 600;
}

Fps::~Fps()
{

}

void Fps::init()
{

}

void Fps::draw(sf::RenderWindow& window)
{
  int b;
  if (time.asMicroseconds() != 0) {
    b = 1000000 / time.asMicroseconds(); 
  } else {
    b = -1;
    std::cout << time.asMicroseconds() << std::endl;
  }
  std::stringstream ss1;
  ss1 << b;
  std::string str1 = ss1.str();

  text.setString("fps : " + str1);
  text.setCharacterSize(20);
  text.setColor(sf::Color::White);
  text.setPosition(_pos_x, _pos_y);
  
  window.draw(text);
}

void Fps::update(sf::Keyboard input, sf::Time etime, sf::Font &font)
{
  time = etime;
  text.setFont(font);
}

void Fps::update(sf::Keyboard input, sf::Time etime)
{

}

sf::Text Fps::getText() const
{
  return text;
}
