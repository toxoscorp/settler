#ifndef SETTLER_PARSER_INI_INI_PARSER_H_
#define SETTLER_PARSER_INI_INI_PARSER_H_

#include "ini_config.h"

#include <string>

namespace settler {
class INIParser {
public:
  static INIConfig Read(const std::string &filepath);
  static void Write(INIConfig &iniConfig, const std::string &filepath);
};
} // namespace settler

#endif // SETTLER_PARSER_INI_INI_PARSER_H_
