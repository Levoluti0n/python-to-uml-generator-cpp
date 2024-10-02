#include "FileGenerator.hpp"
#include "PythonParser.hpp"
#include "UMLGenerator.hpp"
#include "helper.hpp"
#include "AST.hpp"

#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

nlohmann::json buildASTFromJson(std::string& jsonString, AST& ast) {
    auto json = nlohmann::json::parse(jsonString);
    for (const auto& classInfo : json) {
        PythonClass pyClass(classInfo["class_name"]);
        
        for (const auto& base : classInfo["bases"]) {
            pyClass.addBaseClass(base);
        }
        
        for (const auto& method : classInfo["methods"]) {
            pyClass.addMethod(method);
        }
        
        ast.addClass(pyClass);
    }
    return json;
}

int main() {
    PythonParser parser;
    std::string jsonAst = parser.parsePythonFile("data/test_data.py");

    AST ast;
    auto parsed = buildASTFromJson(jsonAst, ast);

    ast.printAST();

    UMLGenerator umlGen;
    umlGen.generateUML(ast);

    FileGenerator fuml;
    if (popup("SAVE THE UML"))
        fuml.generateDotFile(parsed);

    if(popup("GENERATE DOT FILE IMAGE"))
        fuml.generateImageFromDot();

    return 0;
}