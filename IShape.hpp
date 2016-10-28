#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "SFML/Graphics.hpp"
#include "ItShape.hpp"

class IShape : public ItShape
{
  public:
    IShape();
    ~IShape();

    void draw(sf::RenderWindow& window);
    void update(sf::Keyboard input,
                sf::Time etime,
                std::vector<std::vector<AObject*> >& map);

  private:
    void _rotateN(std::vector<std::vector<AObject*> >& map);
    void _rotateE(std::vector<std::vector<AObject*> >& map);
    void _rotateS(std::vector<std::vector<AObject*> >& map);
    void _rotateO(std::vector<std::vector<AObject*> >& map);

};

#endif
