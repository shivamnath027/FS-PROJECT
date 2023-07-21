#include <iostream>
#include <fstream>
#include <string>
#include <map>

struct User {
    std::string username;
    std::string password;
};

class UserManager {
private:
    std::map<std::string, User> users;
    std::string userFile;

public:
    UserManager(const std::string& filename) : userFile(filename) {
        LoadUsers();
    }

    bool SignUp(const std::string& username, const std::string& password) {
        if (users.find(username) == users.end()) {
            User newUser;
            newUser.username = username;
            newUser.password = password;
            users[username] = newUser;
            SaveUsers();
            return true;
        }
        return false;
    }

    bool SignIn(const std::string& username, const std::string& password) {
        if (users.find(username) != users.end()) {
            User& existingUser = users[username];
            if (existingUser.password == password) {
                std::cout << "Welcome, " << existingUser.username << "!" << std::endl;
                return true;
            }
        }
        return false;
    }

    void LoadUsers() {
        std::ifstream file(userFile);
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
    }

    void SaveUsers() {
        std::ofstream file(userFile);
        if (file.is_open()) {
            for (const auto& pair : users) {
                file << pair.first << "\n";
                file << pair.second.password << "\n";
            }
            file.close();
        }
    }
};

int main() {
    UserManager userManager("users.txt");
    std::string username, password;

    // Sign up
    std::cout << "Sign Up" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (userManager.SignUp(username, password)) {
        std::cout << "Sign up successful!" << std::endl;
    } else {
        std::cout << "Username already exists. Sign up failed." << std::endl;
    }

    // Sign in
    std::cout << "\nSign In" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (userManager.SignIn(username, password)) {
        std::cout << "Sign in successful!" << std::endl;
    } else {
        std::cout << "Invalid username or password. Sign in failed." << std::endl;
    }

    return 0;
}
