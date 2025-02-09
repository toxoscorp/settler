#include <iostream>

#include <settler/parser/INI/ini_config.h>
#include <settler/parser/INI/ini_parser.h>
#include <settler/settler.h>

int main() {
  std::cout << "Hello, World!" << std::endl;
  settler::say_hello();

  settler::INIConfig config = settler::INIParser::Read("example.ini");
  // settler::INIConfig config;
  config.setOption("section", "option", "value");
  settler::INIParser::Write(config, "example_processed.ini");

  return 0;
}
