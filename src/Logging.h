#ifndef LOGGING_H
#define LOGGING_H

#include <string>

class Logging {
public:
    Logging(const std::string& filePath);
    void log(const std::string& message);

private:
    std::string filePath;
};

#endif
