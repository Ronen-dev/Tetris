#ifndef ITSHAPE_HPP
#define ITSHAPE_HPP

#include <vector>
#include "AObject.hpp"
#include "SFML/Graphics.hpp"

enum Rotation {
  n = 0,
  e,
  s,
  o
};

class ItShape
{
  public:
    std::vector<AObject*> current;
    
    Rotation r; 
    
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(sf::Keyboard input,
                        sf::Time etime,
                        std::vector<std::vector<AObject*> >& map) = 0;

    void moveLeft(std::vector<std::vector<AObject*> >& map,
                          std::vector<AObject* > current);
    void moveRight(std::vector<std::vector<AObject*> >& map,
                           std::vector<AObject* > current);
    void moveDown(std::vector<std::vector<AObject*> >& map,
                          std::vector<AObject* > current);
 
    int speed;
    int currentTime;
    int timePressed;

    bool isBlocked;

  private:
    
};

#endif
