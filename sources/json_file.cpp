#include "json_file.h"

JsonFile::JsonFile(std::string const & name) {
  initFile(name);
}

JsonFile::~JsonFile() {

}

void		JsonFile::initFile(std::string const & name) {
  _file.open(name);
  _file << "{" << std::endl;
}

void		JsonFile::setHeader(std::vector<Item> const & header) {
  _header = header;
}

void		JsonFile::write(std::vector<Item> const & items) {
  if (items.empty())
    return;

  if (!_header.empty() && items.size() > _header.size())
    throw std::invalid_argument("Line longer than header");

  if (_is_first_item)
    _is_first_item = false;
  else
    _file << "," << std::endl;

  _file << (_header.empty() ? '[' : '{');

  bool first = true;
  for (unsigned int i = 0; i < items.size(); ++i) {
    if (first)
      first = false;
    else
      _file << ",";
    _file << items[i].toJson((_header.empty() ? "" : _header[i].getValue()));
  }

  _file << (_header.empty() ? ']' : '}');
}

void		JsonFile::endFile() {
  _file << std::endl << "}";
}
