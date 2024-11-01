#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <functional>
#include "Circle.hpp"
#include "commands.hpp"

int main()
{
  using namespace novokhatskiy;
  mySet c;
  std::string s = "";
  Circle c1{};
  Circle c2{};
  circle(std::cin, c);
  executeShow(std::cin, std::cout, c);
  std::map< std::string, std::function< void(std::istream&, std::ostream&) > > cmd
    {

    };
  //std::cin >> s >> c2;

  if (c.contains(s))
  {
    std::cerr << "Key already exists\n";
    return 1;
  }
  else
  {
    c[s] = c2;
  }
  return 0;
}
