#include "settler/parser/INI/ini_parser.h"
#include "settler/parser/INI/ini_config.h"
#include <fstream>
#include <iostream>
#include <string>

void strip(std::string *line) {
  while (line->size() > 0 && line->at(0) == ' ') {
    line->erase(0, 1);
  }
  while (line->size() > 0 && line->at(line->size() - 1) == ' ') {
    line->erase(line->size() - 1, 1);
  }
}

void remove_comment(std::string *line) {
  if (line->find(';') != std::string::npos) {
    line->erase(line->find(';'), line->size());
  }
  if (line->find('#') != std::string::npos) {
    line->erase(line->find('#'), line->size());
  }
}

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
  bool multiline = false;
  while (std::getline(filestream, line)) {
    strip(&line);
    remove_comment(&line);
    std::cout << "line : " << line << std::endl;
    if (line[0] == '[' && line.find(']') != std::string::npos) {
      section = line.substr(1, line.find(']') - 1);
    } else if (line[0] == ';' || line[0] == '#') {
      continue;
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
