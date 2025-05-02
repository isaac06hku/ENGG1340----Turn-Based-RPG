#include <iostream>
#include <random>
#include <algorithm>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include "core_types.h"lea
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

void displayFightTralala(BattleCharacter player, BattleCharacter enemy){
  clearBottomScreen();
  displayArt("assets/ascii_art/enemy_art/tralalelo_tralala.txt");
  while (true) {
    if (BattleSystem::run_battle(player, enemy)) {
      scrollLines("assets/data/fights/tung_tung_win.txt", 100);
      break;

    } else {
      scrollLines("assets/data/fights/tung_tung_win.txt", 100);
    }
}
}

void displayFightBoss(BattleCharacter player, BattleCharacter enemy){
  clearBottomScreen();
  displayArt("assets/ascii_art/enemy_art/bombardino_crocodilo.txt");
  while (true) {
    if (BattleSystem::run_battle(player, enemy)) {
      scrollLines("assets/data/fights/bombardino_win.txt", 100);
      break;

    } else {
      scrollLines("assets/data/fights/bombardino_lose.txt", 100);
    }
}
}


int main(){
  BattleCharacter player {"Player", {10, 10, 10, 50}, 50};

  displayIntro();
  clearBottomScreen();

  displayArt("assets/ascii_art/location_art/village_art.txt");
  scrollLines("assets/data/village_scene.txt", 100);

  int difficulty = difficultySelection();
  int multiplier = difficulty * 0.5;

  BattleCharacter tung_tung_tung_sahur {
    "Tung Tung Tung Sahur", 
    {multiplier * 4, multiplier * 7, multiplier * 2, multiplier * 20}, 
    multiplier * 20};

  BattleCharacter tralalelo_tralala {"Tralalelo Tralala", 
    {multiplier * 5, multiplier * 8, multiplier * 3, multiplier * 30}, 
    multiplier * 30};

  BattleCharacter bombardino_crocodilo {"Bombardino Crocodilo", 
    {multiplier * 11, multiplier * 11, multiplier * 13, multiplier * 35}, 
    multiplier * 35};

  displayArt("assets/ascii_art/enemy_art/tung_tung_tung_sahur.txt");
  scrollLines("assets/data/tung_tung_scene.txt", 100);
  clearBottomScreen();
  displayFightTungTungTung(player, tung_tung_tung_sahur);

  displayArt("assets/ascii_art/location_art/forest_art.txt");
  scrollLines("assets/data/forest_scene.txt", 100);
  
  displayArt("assets/ascii_art/location_art/beach_art.txt");
  scrollLines("assets/data/tralalelo_scene.txt", 100);
  displayFightTralala(player, tralalelo_tralala);
  
  displayArt("assets/ascii_art/location_art/castle_art.txt");
  scrollLines("assets/data/castle_scene.txt", 100);

  scrollLines("assets/data/castle_scene.txt", 100);
  scrollLines("assets/data/bombardino_scene.txt", 100);
  displayFightBoss(player, bombardino_crocodilo);

  scrollLines("assets/data/ending.txt", 100);
  displayArt("assets/ascii_art/Rick_ still image");

  return 0;
}
