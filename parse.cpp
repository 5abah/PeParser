#include "parse.h"
#include "Colors.h"
#include <chrono>
#include <fstream>
#include <print>
#include <winnt.h>

PeParser::PeParser(std::ifstream &file) {
  if (!file.is_open()) {
    errorPrint("CANT FIND FILE");
    return;
  }

  file.read(reinterpret_cast<char *>(&dosHeader), sizeof(dosHeader));
}

void PeParser::parseDosHeaders() {
  if (dosHeader.e_magic != IMAGE_DOS_SIGNATURE) {
    errorPrint("NOT A VALID PE FILE");
    return;
  }
  std::println("{}DOS HEADER{}\n-----------------------------", Colors::yellow,
               Colors::reset);

  parsePrint("Bytes on last page of file:", dosHeader.e_cblp);
  parsePrint("Pages in file:", dosHeader.e_cp);
  parsePrint("Size of header in paragraphs:", dosHeader.e_cparhdr);
  parsePrint("File address of relocation table:", dosHeader.e_lfarlc);
  parsePrint("File address of NT Headers:", dosHeader.e_lfanew);

  std::println("-----------------------------\n");
}

void PeParser::parseNTHeaders(std::ifstream &file) {
  file.seekg(dosHeader.e_lfanew, std::ios::beg);
  file.read(reinterpret_cast<char *>(&ntHeaders), sizeof(ntHeaders));

  std::println("{}NT HEADERS{}\n-----------------------------\n",
               Colors::yellow, Colors::reset);

  std::println("{}FILE HEADER{}\n-----------------------------\n", Colors::blue,
               Colors::reset);
  switch (ntHeaders.FileHeader.Machine) {
  case 34404:
    parsePrint("Machine:", "AMD64");
    break;
  default:
    parsePrint("Machine:", "INTEL 80386");
    break;
  }

  parsePrint("Size of Section Table:", ntHeaders.FileHeader.NumberOfSections);

  // format time properly
  std::chrono::seconds timeSeconds{
      *reinterpret_cast<std::int32_t *>(&ntHeaders.FileHeader.TimeDateStamp)};
  std::chrono::sys_seconds timeStamp{timeSeconds};
  std::string formattedTime = std::format("{:%Y-%m-%d %H:%M:%S}", timeStamp);
  // format time properly

  parsePrint("File Creation Time:", formattedTime);
  parsePrint("Size of Optional Header:",
             ntHeaders.FileHeader.SizeOfOptionalHeader);
  parsePrint("Characteristic:", ntHeaders.FileHeader.Characteristics);
}

void errorPrint(const std::string_view message) {
  std::println("{}{}{}", Colors::red, message, Colors::reset);
}

void parsePrint(const std::string_view infoDesc, const auto parsedInfo) {
  std::println("{}{} {}{}", Colors::green, infoDesc, Colors::reset, parsedInfo);
}
