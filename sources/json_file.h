#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "item.h"

class	JsonFile {
public:
  JsonFile(std::string const & name);
  ~JsonFile();
  void setHeader(std::vector<Item> const & header);
  void initFile(std::string const & name);
  void write(std::vector<Item> const & items);
  void endFile();
private:
  std::vector<Item>		_header;
  std::ofstream			_file;
  bool				_is_first_item = true;
};
