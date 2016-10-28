#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "SFML/Graphics.hpp"
#include "AObject.hpp"

class GameOver : public AObject
{
  public:
    static GameOver &getInstance();

    void init();
    void draw(sf::RenderWindow& window);
    void update(sf::Keyboard input, sf::Time etime);
    void update(sf::Keyboard input, sf::Time etime, sf::Font &font);

    sf::Text getText() const;

  private:
    GameOver();
    ~GameOver();

    sf::Text text;
};

#endif
