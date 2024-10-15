#include <iostream>
#include <vector>
#include <string>

// To avoid having to use std:: before every standard libray feature, its possible to use:
// using namespace std;
// this line above will set the standard library as the general library for the file and prevent 
// needing to use std:: before every feature

int main() {
    std::vector<std::string> msg {"Hello,", "Friend."};
    for (const std::string& word: msg) {
        std::cout << word << " ";
    }
    std::cout << std::endl; // Dont end the line until the string is finished printing
    return 0;
}