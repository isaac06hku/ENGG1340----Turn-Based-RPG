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
      scrollText("You choose the gentle breath of the world. But remember — even soft winds carry unseen dangers.", 50
      );
      break;

      case 2:
      scrollText("You step into the heart of the storm, daring the world to test you.", 50
      );
      break;

      case 3:
      scrollText("You embrace the tempest. No safety. No forgiveness. Only strength... or oblivion.", 50
      );
      break;

      default:
      scrollText("Unexpected error. If you're seeing this in-game, something is very wrong.", 50
      );
    }

    return difficulty;
    
}

void displayIntro(){
  std::string file = "assets/data/intro.txt";
  std::cout << "===================================================\n"
            << "  ____            _                   _            \n"
            << " |  _ \\          (_)                 | |           \n"
            << " | |_) |_ __ __ _ _ _ __    _ __ ___ | |_          \n"
            << " |  _ <| '__/ _` | | '_ \\ | '__/ _ \\| __|         \n"
            << " | |_) | | | (_| | | | | | | | | (_) | |_          \n"
            << " |____/|_| \\__,_|_|_| |_| |_| \\___/\\__|         \n"
            << "     /\\      | |               | |                 \n"
            << "    /  \\   __| |_   _____ _ __ | |_ _   _ _ __ ___ \n"
            << "   / /\\ \\ / _` \\ \\ / / _ \\  _ \\| __| | | |  __/ _ \\\n"
            << "  / ____ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/\n"
            << " /_/    \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___|\n"
            << "                                                   \n"
            << "===================================================\n";
  scrollLines(file, 50);
}

void displayFightTungTungTung(BattleCharacter player, BattleCharacter enemy) {
  clearBottomScreen();
  displayArt("assets/ascii_art/enemy_art/tung_tung_tung_sahur.txt");
  while (true) {
    if (BattleSystem::run_battle(player, enemy)) {
      scrollLines("assets/data/fights/tung_tung_win.txt", 50
      );
      break;

    } else {
      scrollLines("assets/data/fights/tung_tung_win.txt", 50
      );
    }
}
}

void displayFightTralala(BattleCharacter player, BattleCharacter enemy){
  clearBottomScreen();
  displayArt("assets/ascii_art/enemy_art/tralalelo_tralala.txt");
  while (true) {
    if (BattleSystem::run_battle(player, enemy)) {
      scrollLines("assets/data/fights/tralalelo_win.txt", 50
      );
      break;

    } else {
      scrollLines("assets/data/fights/tralalelo_lose.txt", 50
      );
    }
}
}

void displayFightBoss(BattleCharacter player, BattleCharacter enemy){
  clearBottomScreen();
  displayArt("assets/ascii_art/enemy_art/bombardino_crocodilo.txt");
  while (true) {
    if (BattleSystem::run_battle(player, enemy)) {
      scrollLines("assets/data/fights/bombardino_win.txt", 50
      );
      break;

    } else {
      scrollLines("assets/data/fights/bombardino_lose.txt", 50
      );
    }
}
}


int main(){
  BattleCharacter player {"Player", {10, 10, 10, 50}, 50};

  displayIntro();
  clearBottomScreen();

  displayArt("assets/ascii_art/location_art/village_art.txt");
  scrollLines("assets/data/village_scene.txt", 50
  );

  int difficulty = difficultySelection();
  int multiplier = difficulty * 0.48;

  BattleCharacter tung_tung_tung_sahur {
    "Tung Tung Tung Sahur", 
    {multiplier * 4, multiplier * 7, multiplier * 2, multiplier * 30}, 
    multiplier * 30};

  BattleCharacter tralalelo_tralala {"Tralalelo Tralala", 
    {multiplier * 5, multiplier * 8, multiplier * 3, multiplier * 35}, 
    multiplier * 40};

  BattleCharacter bombardino_crocodilo {"Bombardino Crocodilo", 
    {multiplier * 8, multiplier * 8, multiplier * 8, multiplier * 40}, 
    multiplier * 45};

  displayArt("assets/ascii_art/enemy_art/tung_tung_tung_sahur.txt");
  scrollLines("assets/data/tung_tung_scene.txt", 50
  );
  clearBottomScreen();
  displayFightTungTungTung(player, tung_tung_tung_sahur);

  displayArt("assets/ascii_art/location_art/forest_art.txt");
  scrollLines("assets/data/forest_scene.txt", 50
  );
  
  displayArt("assets/ascii_art/location_art/beach_art.txt");
  scrollLines("assets/data/tralalelo_scene.txt", 50
  );
  displayFightTralala(player, tralalelo_tralala);
  
  displayArt("assets/ascii_art/location_art/castle_art.txt");
  scrollLines("assets/data/castle_scene.txt", 50
  );

  scrollLines("assets/data/bombardino_scene.txt", 50
  );
  displayFightBoss(player, bombardino_crocodilo);

  scrollLines("assets/data/ending.txt", 50
  );
  displayArt("assets/ascii_art/Rick_ still image.txt");

  return 0;
}
