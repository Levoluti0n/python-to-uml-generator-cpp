#include "helper.hpp"

bool popup(const std::string& line) {
    std::string answer;
    std::cout << line << " ? [Y/*]: ";
    std::getline(std::cin, answer);

    if (answer == "y") 
        return true;
    return false;
}