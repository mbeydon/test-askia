#include <algorithm>
#include <cctype>
#include <sstream>
#include <functional>
#include "item.h"


Item::Item(std::string const & value) : _value(value) {}

Item::~Item() {}

std::string const &	Item::getValue() const {
  return _value;
}

Item &			Item::operator+(Item const & item) {
  _value += item.getValue();
}

std::string		Item::toJson(std::string const & name) const {
  bool is_int = std::all_of(_value.begin(), _value.end(), [](unsigned char c) {return std::isdigit(c);});

  std::ostringstream res;
  if (!name.empty())
    res << "\"" << name << "\":";
  if (!is_int && _value[0] != '"')
    res << "\"";
  res << _value;
  if (!is_int && _value.back() != '"')
    res << "\"";
  return res.str();
}
