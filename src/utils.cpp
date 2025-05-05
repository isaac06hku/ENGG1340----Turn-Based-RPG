#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

void scrollText(const std::string& text, int delayMs) {
    if (delayMs < 50) delayMs = 50;

    int length = text.length();
    for (int i = 1; i <= length; ++i) { // Incremental reveal
        std::cout << "\r"; // Return to the start of the line
        for (int j = 0; j < i; ++j) { // Print the first i characters
            putchar(text[j]);
        }
        std::cout.flush(); // Flush the output to ensure it appears immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs)); // Delay
    }

    std::cin.get();
    putchar('\n'); // Move to the next line after scrolling
}

void scrollLines(const std::string& lines_file, int delayMs) {
    std::string line;

    std::ifstream file(lines_file);
    if (!file.is_open()) {
        std::cout << "Failed to open the art file: " << lines_file << std::endl;
        return;
    }

    while(std::getline(file, line)) {
        if (!line.empty()) {
            scrollText(line, delayMs);
        }
        else {
            std::cout << line << std::endl;
        }
    }


    file.close();

}

void displayArt(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the art file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
void clearBottomScreen() {
    // Clear the bottom of the screen to showcase the text
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl;
    }
}

int randint(int min, int max) {
    static std::random_device rd;  // Obtain a random number from hardware
    static std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(min, max); // Define the range
    return distr(eng); // Generate and return a random number
}