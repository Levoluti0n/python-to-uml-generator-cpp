#include "PythonParser.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdio>

std::string PythonParser::parsePythonFile(const std::string& filePath) {
    std::string command = "python3 ../python/parse_ast.py ../" + filePath;
    return exec(command.c_str());
}

std::string PythonParser::exec(const char* cmd){
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}
