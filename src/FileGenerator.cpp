#include "FileGenerator.hpp"
#include <iostream>
#include <fstream>

std::string dotFilePath = "../output/class_relationships_with_access.dot";
std::string imageFilePath = "../output/class_relationships_with_access.png";

void FileGenerator::generateImageFromDot() {
    std::cout << "[+] Generating dot file image "<< imageFilePath << " ..." << std::endl;
    std::string command = "dot -Tpng " + dotFilePath + " -o " + imageFilePath;
    if (system(command.c_str()) == 0) {
        std::cout << "[+] Image generated successfully at " << imageFilePath << std::endl;
    } else {
        std::cerr << "[-] Error generating image from DOT file." << std::endl;
    }
}

void FileGenerator::generateDotFile(const nlohmann::json& classData) {
    std::cout << "[+] Generating file " << dotFilePath << " ..." << std::endl;
    std::ofstream dotFile(dotFilePath);
    if (!dotFile.is_open()) {
        std::cerr << "[-] Failed to open " << dotFilePath << " for writing." << std::endl;
        return;
    }
    
    dotFile << "digraph G {\n";
    dotFile << "    node [shape=box];\n";

    for (const auto& cls : classData) {
        std::string className = cls["class_name"];
        dotFile << "    " << className << " [label=\"" << className << "\\n";
        dotFile << "Methods:\\n";

        for (const auto& method : cls["methods"]) {
            std::string methodName = method["name"];
            std::string accessSpecifier = method["access_specifier"];
            std::string methodSymbol;

            if (accessSpecifier == "public") {
                methodSymbol = "+";
            } else if (accessSpecifier == "protected") {
                methodSymbol = "#";
            } else if (accessSpecifier == "private") {
                methodSymbol = "-";
            }

            dotFile << methodSymbol << " " << methodName << "\\n";
        }
        dotFile << "\"];\n";

        for (const auto& base : cls["bases"]) {
            dotFile << "    " << base << " -> " << className << ";\n";
        }
    }

    dotFile << "}\n";
    dotFile.close();
    std::cout << "[+] File generated successfully at " << dotFilePath << std::endl;
}
