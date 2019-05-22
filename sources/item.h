#pragma once
#include <string>
#include <iostream>

class	Item{
public:
  Item(std::string const & value);
  ~Item();
  Item & operator+(Item const &);
  std::string const & getValue() const;
  std::string toJson(std::string const & name = "") const;
private:
  std::string	_value;
};
