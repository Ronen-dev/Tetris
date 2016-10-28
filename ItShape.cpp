#include "ItShape.hpp"

void ItShape::moveLeft(std::vector<std::vector<AObject*> >& map,
                       std::vector<AObject* > current)
{
  if (
    current[0]->_pos_x > 0 &&
    current[1]->_pos_x > 0 &&
    current[2]->_pos_x > 0 &&
    current[3]->_pos_x > 0
  ){
    if (
      map[current[0]->_pos_y][current[0]->_pos_x - 1] == NULL &&
      map[current[1]->_pos_y][current[1]->_pos_x - 1] == NULL &&
      map[current[2]->_pos_y][current[2]->_pos_x - 1] == NULL &&
      map[current[3]->_pos_y][current[3]->_pos_x - 1] == NULL
    ){
      current[0]->_pos_x -= 1;
      current[1]->_pos_x -= 1;
      current[2]->_pos_x -= 1;
      current[3]->_pos_x -= 1;
    }
  }
}

void ItShape::moveRight(std::vector<std::vector<AObject*> >& map,
                       std::vector<AObject* > current)
{
  if (
    current[0]->_pos_x < 9 &&
    current[1]->_pos_x < 9 &&
    current[2]->_pos_x < 9 &&
    current[3]->_pos_x < 9
  ){
    if (
      map[current[0]->_pos_y][current[0]->_pos_x + 1] == NULL &&
      map[current[1]->_pos_y][current[1]->_pos_x + 1] == NULL &&
      map[current[2]->_pos_y][current[2]->_pos_x + 1] == NULL &&
      map[current[3]->_pos_y][current[3]->_pos_x + 1] == NULL
    ){
      current[0]->_pos_x += 1;
      current[1]->_pos_x += 1;
      current[2]->_pos_x += 1;
      current[3]->_pos_x += 1;
    }
  }
}

void ItShape::moveDown(std::vector<std::vector<AObject*> >& map,
                       std::vector<AObject* > current)
{ 
  if (
    current[0]->_pos_y > 0 &&
    current[1]->_pos_y > 0 &&
    current[2]->_pos_y > 0 &&
    current[3]->_pos_y > 0
  ){
    if (
      map[current[0]->_pos_y - 1][current[0]->_pos_x] == NULL &&
      map[current[1]->_pos_y - 1][current[1]->_pos_x] == NULL &&
      map[current[2]->_pos_y - 1][current[2]->_pos_x] == NULL &&
      map[current[3]->_pos_y - 1][current[3]->_pos_x] == NULL
    ){
      current[0]->_pos_y -= 1;
      current[1]->_pos_y -= 1;
      current[2]->_pos_y -= 1;
      current[3]->_pos_y -= 1;
    } else {
      map[current[0]->_pos_y][current[0]->_pos_x] = current[0];
      map[current[1]->_pos_y][current[1]->_pos_x] = current[1];
      map[current[2]->_pos_y][current[2]->_pos_x] = current[2];
      map[current[3]->_pos_y][current[3]->_pos_x] = current[3];

      isBlocked = true;
    }
  } else {
    map[current[0]->_pos_y][current[0]->_pos_x] = current[0];
    map[current[1]->_pos_y][current[1]->_pos_x] = current[1];
    map[current[2]->_pos_y][current[2]->_pos_x] = current[2];
    map[current[3]->_pos_y][current[3]->_pos_x] = current[3];

    isBlocked = true;
  }
}
