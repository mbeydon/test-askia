#include <iostream>
#include "csv_to_json_translator.h"

void usage() {
  std::cerr << "usage: ./csv_to_json [-h] input_file output_file" << std::endl;
}

int main(int argc, char ** argv) {
  if (argc < 3) {
    usage();
    return (1);
  }

  bool has_header = false;
  std::string input_file;
  std::string output_file;

  if (std::string("-h") != std::string(argv[1])) {
    input_file = argv[1];
    output_file = argv[2];
  } else {
    if (argc < 4) {
      usage();
      return (1);
    }
    has_header = true;
    input_file = argv[2];
    output_file = argv[3];
  }

  CsvToJsonTranslator trans;

  trans.csvToJson(input_file, output_file, has_header);
  return (0);
}
