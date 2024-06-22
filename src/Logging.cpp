#include "Logging.h"
#include <fstream>

Logging::Logging(const std::string& filePath) : filePath(filePath) {}

void Logging::log(const std::string& message) {
    std::ofstream file(filePath, std::ios::app);
    file << message << std::endl;
}
