#include "commands.hpp"

void novokhatskiy::circle(std::istream &in, novokhatskiy::mySet &res)
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
  if (res.find(s) == res.cend()) // contains
  {
    return;
  }
  res[s] = tmp;
}
void novokhatskiy::executeSet(std::istream &in, const novokhatskiy::mySet &circles, novokhatskiy::SetCircles &set)
{
  int size{};
  std::string nameOfSet;
  in >> nameOfSet >> size;
  if (size <= 0)
  {
    throw std::invalid_argument("Size can't be negative or equals zero");
  }
  if (set.circles.find(nameOfSet) == set.circles.cend())
  {
    throw std::invalid_argument("Set with this name already exists");
  }
  std::string nameOfCircle;
  novokhatskiy::mySet res;
  while (size != 0)
  {
    in >> nameOfCircle;
    if (circles.find(nameOfSet) == circles.cend()) // везде поменять cend() на contains
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
void novokhatskiy::executeShow(std::istream &in, std::ostream &out, const novokhatskiy::mySet &circles)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return;
  }
  std::string name;
  in >> name;
  if (circles.find(name) == circles.cend())
  {
    out << circles.find(name)->second;
  }
  else
  {
    out.setstate(std::ios::failbit);
  }
}
void novokhatskiy::executeShowSet(std::istream &in, std::ostream &out, const novokhatskiy::SetCircles set)
{
  std::string name;
  in >> name;
  if (!set.circles.find(name))
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
void novokhatskiy::getFrame(std::istream &in, std::ostream &out, const novokhatskiy::mySet &set)
{
  std::string name;
  in >> name;
  if (set.find(name) == set.cend())
  {
    throw std::invalid_argument("Invalid name");
  }
  auto circle = set.find(name);

  Rectangle res = countFrame(circle);

  out << res;
}

using it_t = novokhatskiy::mySet::const_iterator;

novokhatskiy::Rectangle countFrame(it_t it)
{
  int x = it->second.p.first;
  int y = it->second.p.second;
  int r = it->second.r;

  novokhatskiy::Rectangle res;

  res.leftBottom.first = x - r;
  res.leftBottom.second = x + r;
  res.rightTop.first = y - r;
  res.rightTop.second = y + r;

  return res;
}

void novokhatskiy::getFrameSet(std::istream &in, std::ostream &out, const novokhatskiy::SetCircles set)
{
  std::string name;
  in >> name;
  if (set.circles.find(name) == set.circles.cend())
  {
    throw std::invalid_argument("Invalid name");
  }
  for (auto it = set.circles.begin(); it != set.circles.cend(); it++)
  {
    for (auto i = (*it).second.cbegin(); i != (*it).second.cend(); i++)
    {
    }
  }
}
