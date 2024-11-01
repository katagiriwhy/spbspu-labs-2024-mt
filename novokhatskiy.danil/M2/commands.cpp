#include "commands.hpp"

void novokhatskiy::circle(std::istream& in, novokhatskiy::mySet& res)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    in.setstate(std::ios::failbit);
    return;
  }
  novokhatskiy::Circle tmp{};
  std::string s;
  in >> s >> tmp;
  if (tmp.r < 0 || tmp.p.first < 0 || tmp.p.second < 0)
  {
    in.setstate(std::ios::failbit);
    throw std::invalid_argument("Radius or a point can't be negative");
  }
  if (res.contains(s))
  {
    return;
  }
  res[s] = tmp;
}
void novokhatskiy::executeSet(std::istream& in, const novokhatskiy::mySet& circles, novokhatskiy::SetCircles& set)
{
  int size{};
  std::string nameOfSet;
  in >> nameOfSet >> size;
  if (size <= 0)
  {
    throw std::invalid_argument("Size can't be negative or equals zero");
  }
  if (set.circles.contains(nameOfSet))
  {
    throw std::invalid_argument("Set with this name already exists");
  }
  std::string nameOfCircle;
  novokhatskiy::mySet res;
  while (size != 0)
  {
    in >> nameOfCircle;
    if (circles.contains(nameOfSet))
    {
      auto tmp = circles.find(nameOfCircle);
      if (tmp == circles.end())
      {
        continue;
      }
      res[tmp->first] = tmp->second;
    }
    size--;
  }
  set.circles[nameOfSet] = res;
}
void novokhatskiy::executeShow(std::istream& in, std::ostream& out, const novokhatskiy::mySet& circles)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return;
  }
  std::string name;
  in >> name;
  if (circles.contains(name))
  {
    out << circles.find(name)->second;
  }
  else
  {
    out.setstate(std::ios::failbit);
  }
}
void novokhatskiy::executeShowSet(std::istream& in, std::ostream& out, const novokhatskiy::SetCircles set)
{
  std::string name;
  in >> name;
  if (!set.circles.contains(name))
  {
    throw std::invalid_argument("Set with the name doesn't exist");
  }
  auto it = set.circles.cbegin();

  while (it != set.circles.cend())
  {
    auto res = it->second.cbegin();
    while (res != it->second.cend())
    {
      out << res->second;
      res++;
    }
    it++;
  }
}
void novokhatskiy::frame(std::istream& in, std::ostream& out, const novokhatskiy::mySet& set)
{
  std::string name;
  in >> name;
  if (!set.contains(name))
  {
    throw std::invalid_argument("Invalid name");
  }
  auto circle = set.find(name);
  int x = circle->second.p.first;
  int y = circle->second.p.second;
  int r = circle->second.r;

  int left = x - r;
  int right = x + r;
  int top = y - r;
  int bottom = y + r;

  out << '(' << left << ' ' << top << ") (" << right << ' ' << bottom << ')';
}
void novokhatskiy::frameSet(std::istream& in, std::ostream& out, const novokhatskiy::SetCircles set)
{
  std::string name;
  in >> name;
  if (!set.circles.contains(name))
  {
    throw std::invalid_argument("Invalid name");
  }
}
