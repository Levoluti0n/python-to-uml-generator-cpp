#ifndef UML_GENERATOR_HPP
#define UML_GENERATOR_HPP

#include "AST.hpp"

class UMLGenerator {
public:
    void generateUML(const AST&) const;
};

#endif