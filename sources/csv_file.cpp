#include "csv_file.h"

CsvFile::CsvFile(std::string const & file_path) {
  if (!file_path.empty())
    open(file_path);
}

CsvFile::~CsvFile() {}

void		CsvFile::open(std::string const & file_path) {
  if (_file.is_open())
    _file.close();

  _file.open(file_path);
  if (_file.fail())
    throw std::invalid_argument("file does not exist");
}

std::vector<Item> CsvFile::getNextLine() {
  std::vector<Item> res;
  std::string line;
  std::string item;
  bool needs_match = false;
  bool done = false;

  while (!done && !_file.eof()) {
    std::getline(_file, line);
    for (auto c : line) {
      if (c == ',') {
	if (!needs_match) {
	  res.push_back(Item(item));
	  item.clear();
	}
      } else if (c == '"') {
	needs_match = !needs_match;
      } else {
	item.push_back(c);
      }
    }
    if (!needs_match) {
      res.push_back(Item(item));
      done = true;
    }
  }
  if (!done)
    throw std::invalid_argument("Bad file format");
  return res;
}

bool		CsvFile::eof() const {
  return (_file.eof());
}
