#include "Circle.hpp"

bool novokhatskiy::Circle::operator<(const Circle &other) const noexcept
{
  return (this->r < other.r) && (this->p.first < other.p.first) && (this->p.second < other.p.second);
}

std::istream &novokhatskiy::operator>>(std::istream &in, Circle &circle)
{
  in >> circle.r >> circle.p.first >> circle.p.second;
  return in;
}

std::ostream &novokhatskiy::operator<<(std::ostream &out, const Circle &circle)
{
  out << circle.r << " (" << circle.p.first << ' ' << circle.p.second << ')';
  return out;
}

std::ostream &novokhatskiy::operator<<(std::ostream &out, const Rectangle &rec)
{
  // add sentry
  out << '(' << rec.leftBottom.first << ' ' << rec.leftBottom.second << ") (" << rec.rightTop.first << ' ' << rec.rightTop.second << ')';
  return out;
}

bool novokhatskiy::Rectangle::operator<(const Rectangle &other) const
{
  return (this->leftBottom.first < other.leftBottom.first && this->leftBottom.second < other.leftBottom.second) &&
         (this->rightTop.first < other.rightTop.first && this->rightTop.second < other.rightTop.second);
}