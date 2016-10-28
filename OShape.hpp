#ifndef OSHAPE_HPP
#define OSHAPE_HPP

#include "SFML/Graphics.hpp"
#include "ItShape.hpp"

class OShape : public ItShape
{
  public:
    OShape();
    ~OShape();

    void draw(sf::RenderWindow& window);
    void update(sf::Keyboard input,
                sf::Time etime,
                std::vector<std::vector<AObject*> >& map);
 
  private:
        
};

#endif
