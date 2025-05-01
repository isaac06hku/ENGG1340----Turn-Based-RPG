#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void scrollText(const std::string& text, int delayMs);
void scrollLines(const std::string& lines_file, int delayMs);
void displayArt(const std::string& filename);
void clearBottomScreen();
#endif