#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include "battle.h"
#include "enemy.h"
#include "input.h"
#include "location.h"
#include "player.h"
#include "save_load.h"
#include "utils.h"

void displayIntro();
void displayArt(const std::string& filename);
void displayFightTralala();
void displayFightBoss();
void clearBottomScreen() ;

void clearBottomScreen() {
    // Clear the bottom of the screen to showcase the text
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl;
    }
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

void displayIntro(){
  std::cout << "scrolling reels then black out" << std::endl;
  displayArt("assets/ascii_art/location_art/forest_art.txt");
  
  std::cout << "See tung tung tung sahur..." << std::endl;
  displayArt("assets/ascii_art/tung_tung_tung_sahur.txt");
  
}

void displayFightTralala(){
  std::cout << "Fighting Tralalelo!" << std::endl;
  displayArt("assets/ascii_art/enemy_art/tralalelo_tralala.txt");
}

void displayFightBoss(){
  std::cout << "Final Boss Fight: Bombardino Crocodile!" << std::endl;
  displayArt("assets/ascii_art/enemy_art/bombardino_crocodilo.txt");
}

int main(){
  displayIntro();
  // battleSequence(); (wheres this from?)

  return 0;
}
