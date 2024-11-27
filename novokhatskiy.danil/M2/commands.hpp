#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "Circle.hpp"

namespace novokhatskiy
{
  void circle(std::istream &in, mySet &res);
  void executeSet(std::istream &in, const mySet &circles, SetCircles &set);
  void executeShow(std::istream &in, std::ostream &out, const novokhatskiy::mySet &circles);
  void executeShowSet(std::istream &in, std::ostream &out, const novokhatskiy::SetCircles set);
  void getFrame(std::istream &in, std::ostream &out, const novokhatskiy::mySet &set);
  void getFrameSet(std::istream &in, std::ostream &out, const novokhatskiy::SetCircles set);

}

#endif
