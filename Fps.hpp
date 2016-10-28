#ifndef FPS_HPP
#define FPS_HPP

#include "SFML/Graphics.hpp"
#include "AObject.hpp"

class Fps : public AObject
{
  public:
    static Fps &getInstance();
        
    void init();
    void draw(sf::RenderWindow& window);
    void update(sf::Keyboard input, sf::Time etime);
    void update(sf::Keyboard input, sf::Time etime, sf::Font &font);

    sf::Text getText() const;

  private:
    Fps();
    ~Fps();  
        
    sf::Time time;
    sf::Text text;
};

#endif
