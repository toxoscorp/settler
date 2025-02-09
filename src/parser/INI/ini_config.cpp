#include "settler/parser/INI/ini_config.h"

bool settler::INIConfig::hasSection(const std::string &section) const {
  return m_sections.contains(section);
}

bool settler::INIConfig::hasOption(const std::string &section,
                                   const std::string &option) const {
  if (!hasSection(section))
    return false;

  return m_sections.at(section).contains(option);
}

std::string settler::INIConfig::getOption(const std::string &section,
                                          const std::string &option) const {
  if (!hasOption(section, option))
    return "";

  return m_sections.at(section).at(option);
}

void settler::INIConfig::setOption(const std::string &section,
                                   const std::string &option,
                                   const std::string &value) {
  if (!hasSection(section))
    m_sections[section] = INIOptions();

  m_sections[section][option] = value;
}

void settler::INIConfig::removeOption(const std::string &section,
                                      const std::string &option) {
  if (!hasOption(section, option))
    return;

  m_sections[section].erase(option);
}

void settler::INIConfig::removeSection(const std::string &section) {
  if (!hasSection(section))
    return;

  m_sections.erase(section);
}

std::map<std::string, settler::INIOptions>
settler::INIConfig::getSections() const {
  return m_sections;
}

std::vector<std::string> settler::INIConfig::getSectionsNames() const {
  std::vector<std::string> sectionsNames;
  for (const auto &[section, _] : m_sections)
    sectionsNames.push_back(section);
  return sectionsNames;
}

std::vector<std::string>
settler::INIConfig::getOptionsNames(const std::string &section) const {
  if (!hasSection(section))
    return {};
  std::vector<std::string> optionsNames;
  for (const auto &[option, _] : m_sections.at(section))
    optionsNames.push_back(option);
  return optionsNames;
}

settler::INIOptions
settler::INIConfig::getOptions(const std::string &section) const {
  if (!hasSection(section))
    return {};
  return m_sections.at(section);
}
