#include "settler/parser/INI/ini_parser.h"
#include "settler/parser/INI/ini_config.h"
#include <fstream>
#include <iostream>
#include <string>

settler::INIConfig settler::INIParser::Read(const std::string &filepath) {
  std::ifstream filestream;
  settler::INIConfig config;
  filestream.open(filepath.c_str());
  if (!filestream.is_open()) {
    std::cout << "Failed to read config" << std::endl;
    return config;
  }

  std::string section = "";
  std::string line;
  while (std::getline(filestream, line)) {
    std::cout << "line : " << line << std::endl;
    if (line[0] == '[') {
      section = line.substr(1, line.size() - 2);
    } else if (line.find('=') != std::string::npos) {
      std::string option = line.substr(0, line.find('='));
      std::string value = line.substr(line.find('=') + 1, line.size());
      config.setOption(section, option, value);
    } else {
      std::cout << "Invalid line: " << line << std::endl;
    }
  }

  filestream.close();
  return config;
}

void settler::INIParser::Write(INIConfig &iniConfig,
                               const std::string &filepath) {
  std::ofstream filestream;
  filestream.open(filepath.c_str());
  if (!filestream.is_open()) {
    std::cout << "Failed to write config" << std::endl;
    return;
  }

  for (const auto &section : iniConfig.getSectionsNames()) {
    filestream << "[" << section << "]" << std::endl;
    for (const auto &option : iniConfig.getOptionsNames(section)) {
      filestream << option << "=" << iniConfig.getOption(section, option)
                 << std::endl;
    }
  }
  filestream.close();
}
