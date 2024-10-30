#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <utility>
#include <map>
#include <iostream>

namespace novokhatskiy
{
  struct Circle
  {
    Circle() = default;
    int r = 0;
    std::pair< int, int > p;
    bool operator<(const Circle& other) const noexcept;
  };

  std::istream& operator>>(std::istream& in, Circle& circle);
  std::ostream& operator<<(std::ostream& out, const Circle& circle);

  struct SetCircles
  {
    std::map<std::string, std::map< std::string, Circle > >circles;
  };
}
#endif
