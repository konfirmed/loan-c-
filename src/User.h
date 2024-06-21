#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    std::string userId;
    std::string password;

    User(std::string id, std::string pass) : userId(id), password(pass) {}
};

#endif
