#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "IGame.hpp"
#include <iostream>

IGame::IGame()
{

}

IGame::~IGame()
{

}

void IGame::setParameter(int x, int y, std::string label)
{
  _size_x = x;
  _size_y = y;
  _label  = label;
}

void IGame::run()
{
  init();
  window.create(sf::VideoMode(_size_x, _size_y), _label.c_str());   

  sf::Music music;

  if (!music.openFromFile("Tetris.ogg"))
  {
    std::cout << "Error while loading song" << std::endl;
  }

  music.setLoop(true);
  music.play();

  if (!font.loadFromFile("arial.ttf")) {
    std::cout << EXIT_FAILURE;
  }
    
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    update();
    window.clear(); 
    draw();
    window.display();
  }
}
