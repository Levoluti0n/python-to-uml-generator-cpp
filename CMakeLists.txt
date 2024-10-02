cmake_minimum_required(VERSION 3.10)
project(cpp-python-uml)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-python-uml
    src/main.cpp
    src/FileGenerator.cpp
    src/PythonParser.cpp
    src/UMLGenerator.cpp
    src/helper.cpp
    src/AST.cpp
)

target_include_directories(cpp-python-uml PUBLIC include)

find_package(nlohmann_json REQUIRED)
target_link_libraries(cpp-python-uml nlohmann_json::nlohmann_json)
