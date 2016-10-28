#include "FactoryShape.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "OShape.hpp"
#include "IShape.hpp"
#include "LShape.hpp"
#include "JShape.hpp"
#include "SShape.hpp"
#include "ZShape.hpp"
#include "TShape.hpp"

FactoryShape::FactoryShape()
{

}

FactoryShape::~FactoryShape()
{

}

ItShape* FactoryShape::createRandShape()
{
  switch (std::rand() % 7)
  {
    case 0 :
      return new OShape();
    case 1 :
      return new IShape();
    case 2 :
      return new LShape();
    case 3 :
      return new JShape();
    case 4 :
      return new SShape();
    case 5 :
      return new ZShape();
    case 6 :
      return new TShape();
  }
}