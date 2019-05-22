#pragma once
#include <fstream>
#include <vector>
#include "item.h"

class	CsvFile {
public:
  CsvFile(std::string const & file_path = "");
  ~CsvFile();
  void open(std::string const & file_path);
  std::vector<Item> getNextLine();
  bool eof() const;
private:
  std::ifstream	_file;
};
