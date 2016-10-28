#ifndef TIMER_HPP
#define TIMER_HPP

#include "SFML/Graphics.hpp"
#include "AObject.hpp"

class Timer : public AObject
{
  public:
    static Timer &getInstance();
        
    void init();
    void draw(sf::RenderWindow& window);
    void update(sf::Keyboard input, sf::Time etime);
    void update(sf::Keyboard input, sf::Time etime, sf::Font &font);
        
    sf::Text getText() const;

  private:
    Timer();
    ~Timer();  

    sf::Time time;
    sf::Text text;
};

#endif
