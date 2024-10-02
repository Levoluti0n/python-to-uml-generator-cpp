#ifndef PYTHON_PARSER_HPP
#define PYTHON_PARSER_HPP

#include <string>

class PythonParser {
    public:
        std::string parsePythonFile(const std::string&);
    private:
        std::string exec(const char*);
};


#endif