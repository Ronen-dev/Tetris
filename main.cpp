#include <SFML/Graphics.hpp>
#include "Tetris.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
  Tetris t;

  std::srand(std::time(0));

  t.init();
  t.run();

  return EXIT_SUCCESS;
}
