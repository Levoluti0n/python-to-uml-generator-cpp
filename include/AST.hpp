#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>

class Method {
public:
    std::string name;
    Method(const std::string&);
};

class PythonClass {
public:
    std::string className;
    std::vector<std::string> baseClasses;
    std::vector<Method> methods;

    PythonClass(const std::string&);

    void addBaseClass(const std::string&);
    void addMethod(const std::string&);
};

class AST {
public:
    std::vector<PythonClass> classes;

    void addClass(const PythonClass&);
    void printAST() const;
};

#endif