#include <iostream>
#include <random>
#include <algorithm>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include "core_types.h"
#include "battle.h"
#include "enemy.h"
#include "input.h"
#include "location.h"
#include "player.h"
#include "utils.h"

int difficultySelection() {
  int difficulty;

  while (true) {
    std::cout << "[Pick your difficulty: (1) Wanderer, (2) Seeker, (3) Doomstrider]: ";
    std::cin >> difficulty;

    if (std::cin.fail() || !(difficulty > 0 && difficulty < 4)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please try again." << std::endl;

    } else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
        break;
    }
  }

  switch (difficulty)
    {
      case 1:
      scrollText("You choose the gentle breath of the world. But remember — even soft winds carry unseen dangers.", 100);
      break;

      case 2:
      scrollText("You step into the heart of the storm, daring the world to test you.", 100);
      break;

      case 3:
      scrollText("You embrace the tempest. No safety. No forgiveness. Only strength... or oblivion.", 100);
      break;

      default:
      scrollText("Unexpected error. If you're seeing this in-game, something is very wrong.", 100);
    }

    return difficulty;
    
}

void displayIntro(){
  std::string file = "assets/data/intro.txt";
  scrollLines(file, 100);
}

void displayFightTungTungTung(BattleCharacter player, BattleCharacter enemy) {
  clearBottomScreen();
  displayArt("assets/ascii_art/enemy_art/tung_tung_tung_sahur.txt");
  while (true) {
    if (BattleSystem::run_battle(player, enemy)) {
      scrollLines("assets/data/fights/tung_tung_win.txt", 100);
      break;

    } else {
      scrollLines("assets/data/fights/tung_tung_win.txt", 100);
    }
}
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
  BattleCharacter player {"Player", {10, 10, 10, 50}, 100};
  BattleCharacter tung_tung_tung_sahur {"Tung Tung Tung Sahur", {4, 7, 2, 20}, 30};
  BattleCharacter tralalelo_tralala {"Tralalelo Tralala", {5, 8, 3, 30}, 40};
  BattleCharacter bombardino_crocodilo {"Bombardino Crocodilo", {11, 11, 13, 45}, 60};


  displayIntro();
  clearBottomScreen();

  displayArt("assets/ascii_art/location_art/village_art.txt");
  scrollLines("assets/data/village_scene.txt", 100);
  clearBottomScreen();

  int difficulty = difficultySelection();

  displayArt("assets/ascii_art/enemy_art/tung_tung_tung_sahur.txt");
  scrollLines("assets/data/tung_tung_scene.txt", 100);
  clearBottomScreen();
  displayFightTungTungTung(player, tung_tung_tung_sahur);

  displayArt("assets/ascii_art/location_art/forest_art.txt");
  scrollLines("assets/data/forest_scene.txt", 100);
  
  

  return 0;
}
