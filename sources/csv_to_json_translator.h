#pragma once
#include <string>

class CsvToJsonTranslator {
public:
  CsvToJsonTranslator();
  ~CsvToJsonTranslator();
  void csvToJson(std::string const & input_file, std::string const & output_file, bool has_header);
};
