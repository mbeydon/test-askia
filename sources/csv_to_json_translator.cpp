#include "csv_to_json_translator.h"
#include "csv_file.h"
#include "json_file.h"

CsvToJsonTranslator::CsvToJsonTranslator() {}

CsvToJsonTranslator::~CsvToJsonTranslator() {}

void CsvToJsonTranslator::csvToJson(std::string const & input_file, std::string const & output_file, bool has_header) {
  CsvFile	in(input_file);
  std::vector<Item> header;
  header = in.getNextLine();

  JsonFile	out(output_file);

  if (has_header)
    out.setHeader(header);
  while (!in.eof()) {
    out.write(in.getNextLine());
  }

  out.endFile();
}
