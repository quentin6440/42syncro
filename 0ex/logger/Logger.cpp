#include "Logger.hpp"

#include <iostream>
#include <string>

Logger::Logger() {
    // Constructor implementation
}

void Logger::log(const std::string& message) {
    // Log the message
    std::cout << "Log: " << message << std::endl;
}