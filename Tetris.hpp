#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "IGame.hpp"
#include "AObject.hpp"
#include "ItShape.hpp"
#include <vector>

class Tetris : public IGame
{
  public:
    Tetris();
    ~Tetris();

    void init();
    void update();
    void draw();

  private:
    std::vector< std::vector<AObject*> > map;       
    ItShape* current;
    ItShape* tmp_shape;

    bool _gameOver;
};

#endif
