#ifndef SETTLER_PARSER_INI_INI_CONFIG_H_
#define SETTLER_PARSER_INI_INI_CONFIG_H_

#include <map>
#include <string>
#include <vector>

namespace settler {

typedef std::map<std::string, std::string> INIOptions;

class INIConfig {
public:
  INIConfig() = default;
  ~INIConfig() = default;

  bool hasSection(const std::string &section) const;
  bool hasOption(const std::string &section, const std::string &option) const;
  std::string getOption(const std::string &section,
                        const std::string &option) const;
  void setOption(const std::string &section, const std::string &option,
                 const std::string &value);
  void removeOption(const std::string &section, const std::string &option);
  void removeSection(const std::string &section);
  std::map<std::string, INIOptions> getSections() const;
  std::vector<std::string> getSectionsNames() const;
  std::vector<std::string> getOptionsNames(const std::string &section) const;
  INIOptions getOptions(const std::string &section) const;

private:
  std::map<std::string, INIOptions> m_sections;
};
} // namespace settler

#endif // SETTLER_PARSER_INI_INI_CONFIG_H_
