#include "UserAuthentication.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

UserAuthentication::UserAuthentication(const std::string& filePath) : filePath(filePath) {}

bool UserAuthentication::authenticate() {
    std::string userId, password;
    std::cout << "Enter User ID: ";
    std::cin >> userId;
    std::cout << "Enter Password: ";
    std::cin >> password;
    std::vector<User> users = loadUsers();
    for (const auto& user : users) {
        if (user.userId == userId && user.password == password) {
            std::cout << "Login successful." << std::endl;
            return true;
        }
    }
    std::cout << "Invalid User ID or Password." << std::endl;
    return false;
}

std::vector<User> UserAuthentication::loadUsers() {
    std::vector<User> users;
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string userId, password;
        ss >> userId >> password;
        users.push_back(User(userId, password));
    }
    return users;
}
