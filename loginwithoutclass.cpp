#include <iostream>
#include <fstream>
#include <string>
#include <map>

struct User {
    std::string username;
    std::string password;
};

std::map<std::string, User> LoadUsers(const std::string& filename) {
    std::map<std::string, User> users;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::string username = line;
            std::string password;
            if (getline(file, password)) {
                User newUser;
                newUser.username = username;
                newUser.password = password;
                users[username] = newUser;
            }
        }
        file.close();
    }
    return users;
}

void SaveUsers(const std::string& filename, const std::map<std::string, User>& users) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : users) {
            file << pair.first << "\n";
            file << pair.second.password << "\n";
        }
        file.close();
    }
}

bool SignUp(const std::string& username, const std::string& password, std::map<std::string, User>& users) {
    if (users.find(username) == users.end()) {
        User newUser;
        newUser.username = username;
        newUser.password = password;
        users[username] = newUser;
        return true;
    }
    return false;
}

bool SignIn(const std::string& username, const std::string& password, const std::map<std::string, User>& users) {
    if (users.find(username) != users.end()) {
        const User& existingUser = users.at(username);
        if (existingUser.password == password) {
            std::cout << "Welcome, " << existingUser.username << "!" << std::endl;
            return true;
        }
    }
    return false;
}

int main() {
    std::string userFile = "users.txt";
    std::map<std::string, User> users = LoadUsers(userFile);
    std::string username, password;

    // Sign up
    std::cout << "Sign Up" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (SignUp(username, password, users)) {
        std::cout << "Sign up successful!" << std::endl;
        SaveUsers(userFile, users);
    } else {
        std::cout << "Username already exists. Sign up failed." << std::endl;
    }

    // Sign in
    std::cout << "\nSign In" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (SignIn(username, password, users)) {
        std::cout << "Sign in successful!" << std::endl;
    } else {
        std::cout << "Invalid username or password. Sign in failed." << std::endl;
    }

    return 0;
}
