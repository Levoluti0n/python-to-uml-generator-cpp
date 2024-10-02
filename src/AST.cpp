#include "AST.hpp"
#include <iostream>

Method::Method(const std::string& methodName) : name(methodName) {}

PythonClass::PythonClass(const std::string& name) : className(name) {}
void PythonClass::addBaseClass(const std::string& baseClass) {
    baseClasses.push_back(baseClass);
}
void PythonClass::addMethod(const std::string& methodName) {
    methods.push_back(Method(methodName));
}

void AST::addClass(const PythonClass& pyClass) {
    classes.push_back(pyClass);
}
void AST::printAST() const {
    for(const auto& pyClass : classes) {
        std::cout << "Class: " << pyClass.className << "\n";
        if(!pyClass.baseClasses.empty()) {
            std::cout << "  Inherits: ";
            for (const auto& base : pyClass.baseClasses) {
                std::cout << base << " ";
            }
            std::cout << "\n";
        }
        std::cout << "  Methods: \n";
        for (const auto& method : pyClass.methods) {
            std::cout << " * " << method.name << "\n";
        }
        std::cout << "----------------------------------\n";
    }
}



