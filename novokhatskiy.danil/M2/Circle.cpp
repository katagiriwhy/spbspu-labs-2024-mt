#include "Circle.hpp"

bool novokhatskiy::Circle::operator<(const Circle& other) const noexcept
{
    return (this->r < other.r) && (this->p.first < other.p.first) && (this->p.second < other.p.second);
}

std::istream& novokhatskiy::operator>>(std::istream& in, Circle& circle)
{
  in >> circle.r >> circle.p.first >> circle.p.second;
  return in;
}

std::ostream& novokhatskiy::operator<<(std::ostream& out, const Circle& circle)
{
  out << circle.r << " (" << circle.p.first << ' ' << circle.p.second << ')';
  return out;
}