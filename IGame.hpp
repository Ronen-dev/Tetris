#ifndef IGAME_HPP
#define IGAME_HPP

#include <string>

class IGame
{
  public:
    IGame();
    ~IGame();

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    
    void setParameter(int x, int y, std::string label);
                
    void run();     

    int _size_x;
    int _size_y;
    std::string _label;

    sf::Event event;
    sf::Keyboard input;
    sf::Clock clock;
    sf::RenderWindow window;
    sf::Font font;
};

#endif
