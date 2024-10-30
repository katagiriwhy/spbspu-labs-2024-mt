#include <iostream>
#include <string>
#include <map>
#include <exception>
#include "Circle.hpp"

using mySet = std::map< std::string, novokhatskiy::Circle >;

void circle(std::istream& in, mySet& res)
{
  novokhatskiy::Circle tmp{};
  std::string s = "";
  in >> s >> tmp;
  if (tmp.r < 0 || tmp.p.first < 0 || tmp.p.second < 0)
  {
    throw std::invalid_argument("Radius or a point can't be negative");
  }
  if (res.contains(s))
  {
    return;
  }
  res[s] = tmp;
}

void executeSet(std::istream& in)
{
  
}


int main()
{
  using namespace novokhatskiy;
  SetCircles c;
  std::string s = "";
  Circle c1{};
  Circle c2{};
  std::cin >> s >> c1;
  std::cout << c1;
  c.circles[s] = c1;
  std::cin >> s >> c2;

  if (c.circles.contains(s))
  {
    std::cerr << "Key already exists\n";
    return 1;
  }
  else
  {
    c.circles[s] = c2;
  }

  std::cout << c.circles.size();
  return 0;
}
