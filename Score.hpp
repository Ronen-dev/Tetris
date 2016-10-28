#ifndef SCORE_HPP
#define SOCRE_HPP

#include "SFML/Graphics.hpp"
#include "AObject.hpp"
#include <vector>

class Score : public AObject
{
  public:
    static Score &getInstance();

    void init();
    void draw(sf::RenderWindow& window);
    void update(sf::Keyboard input, sf::Time etime);
    void update(sf::Keyboard input, sf::Time etime, sf::Font &font, std::vector<std::vector<AObject*> >& map);

    sf::Text getText() const;

  private:
    Score();
    ~Score();

    sf::Text text;

    int _score;
};

#endif
