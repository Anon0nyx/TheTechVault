#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    // Pretty simple, gather inputs and then print them to the screen
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;
    return 0;
}
