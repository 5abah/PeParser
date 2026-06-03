#include <fstream>
#include <string_view>
#include <windows.h>

void errorPrint(const std::string_view message);
void parsePrint(const std::string_view infoDesc, const auto parsedInfo);

class PeParser {
public:
  PeParser(std::ifstream &file);
  void parseDosHeaders();
  void parseNTHeaders(std::ifstream &file);

private:
  IMAGE_DOS_HEADER dosHeader{};
  IMAGE_NT_HEADERS ntHeaders{};
};
