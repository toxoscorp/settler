#include <catch2/catch_test_macros.hpp>

#include <settler/parser/INI/ini_config.h>

TEST_CASE("INIConfig", "[INI][A1]") {
  settler::INIConfig config;
  REQUIRE(config.hasSection("section") == false);
  REQUIRE(config.hasOption("section", "option") == false);
  REQUIRE(config.getOption("section", "option") == "");
  config.setOption("section", "option", "value");
  REQUIRE(config.hasSection("section") == true);
  REQUIRE(config.hasOption("section", "option") == true);
  REQUIRE(config.getOption("section", "option") == "value");
  config.removeOption("section", "option");
  REQUIRE(config.hasOption("section", "option") == false);
}
