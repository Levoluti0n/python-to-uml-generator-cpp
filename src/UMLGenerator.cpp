#include "UMLGenerator.hpp"
#include <iostream>

void UMLGenerator::generateUML(const AST& ast) const {
    std::cout << "digraph G {" << std::endl;
    for(const auto& pyClass : ast.classes) {
        std::cout << "\"" << pyClass.className << "\"" << std::endl;
        for(const auto& base : pyClass.baseClasses) {
            std::cout << "\"" << base << "\" -> \"" << pyClass.className << "\";" << std::endl;
        }
    }
    std::cout << "}" << std::endl;
}
