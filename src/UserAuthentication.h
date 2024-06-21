#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include <string>
#include <vector>
#include "User.h"

class UserAuthentication {
public:
    UserAuthentication(const std::string& filePath);
    bool authenticate();

private:
    std::string filePath;
    std::vector<User> loadUsers();
};

#endif
