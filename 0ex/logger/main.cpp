#include "Logger.hpp"

#include <string>

int main() {
    std::string greeting = "Hello, World!";

    Logger logger;

    logger.log("GREET");

    return 0;
}