#ifndef FACTORYSHAPE_HPP
#define FACTORYSHAPE_HPP

#include "ItShape.hpp"

class FactoryShape {
  public:
    FactoryShape();
    ~FactoryShape();

    static ItShape* createRandShape();

};

#endif