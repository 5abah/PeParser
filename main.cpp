#include "Colors.h"
#include "parse.h"
#include <ios>
#include <print>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    errorPrint("INCORRECT USAGE! Usage: PeParser.exe [filename]");
    return -1;
  }

  std::ifstream file(argv[1], std::ios::binary);

  PeParser peParser(file);

  peParser.parseDosHeaders();
  peParser.parseNTHeaders(file);
}
