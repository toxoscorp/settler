cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 20)

project(SETTLER VERSION 0.0.1 LANGUAGES CXX)


add_library(${PROJECT_NAME} src/settler.cpp src/parser/INI/ini_config.cpp src/parser/INI/ini_parser.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_executable(${PROJECT_NAME}_example example/main.cpp)
target_link_libraries(${PROJECT_NAME}_example PRIVATE ${PROJECT_NAME})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
# install(TARGETS ${PROJECT_NAME} DESTINATION bin)

add_subdirectory(tests)

enable_testing()
