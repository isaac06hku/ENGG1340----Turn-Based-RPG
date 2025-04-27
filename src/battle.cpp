#include <iostream>;
#include <new>;
#include <random>;
#include <ctime>;
#include "battle.h"
using namespace std;

const double probability = 0.5;//probability of success in a single roll; default 0.5

//numerical statue of a character
struct character_statue {
	string name;
	int speed;
	int attack;
	int armor;
	int health;
};

//roll(number_dies)
//input, the number of dies to roll, determined by statue of character
//output, the number of rolling result, number of successful rolls
int roll(bool number_dies) {
	int number_success = 0;
	for (int i = 0;i < number_dies;i++) {
		srand(static_cast<unsigned int>(time(nullptr)));
		int randomNum = std::rand() % 10 + 1;
		number_success++;
	}
	return number_success;
}

//print current statue
void print_board(character_statue player, character_statue enemy, int current_health_player, int current_health_enemy) {
	cout << player.name << endl;
	cout << "attack   " << player.attack << endl;
	cout << "armor    " << player.armor << endl;
	cout << "health   " << current_health_player << "/" << player.health << endl;
	cout << endl;
	cout << enemy.name << endl;
	cout << "attack   " << enemy.attack << endl;
	cout << "armor    " << enemy.armor << endl;
	cout << "health   " << current_health_enemy << "/" << enemy.health << endl;
}

//battle()
//input: statue of characters
//output: true-win, false-defeat
bool battle(character_statue player, character_statue enemy){
	int current_health_player = player.health;
	int current_health_enemy = enemy.health;
	int damage;//temporal value
	if (player.speed >= enemy.speed) {//determine order; case: you are faster
		cout << "you can attack first" << endl;
		print_board(player, enemy, current_health_player, current_health_enemy);
		damage = roll(max(1, player.attack - enemy.armor));
		cout << "-you launched an attack, deal " << damage << "to enemy" << endl;
		current_health_enemy -= damage;
		if (current_health_enemy <= 0) {//win in first turn
			cout << "you win";
			return true;
		}
	}
	else {
		cout << "enemy attack first" << endl;
	}
	
	while ((current_health_enemy >= 0) && (current_health_player >= 0)) {
		cout << "your turn" << endl;//your turn
		print_board(player, enemy, current_health_player, current_health_enemy);
		damage = roll(max(1, player.attack - enemy.armor));
		cout << "-you launched an attack, deal " << damage << "to enemy" << endl;
		current_health_enemy -= damage;
		if (current_health_enemy <= 0) {
			cout << "you win" << endl;
			return true;
		}

		print_board(player, enemy, current_health_player, current_health_enemy);//enemy's turn
		damage = roll(max(1, enemy.attack - player.armor));
		cout << "-enemy launched an attack, deal " << damage << "to you" << endl;
		current_health_player -= damage;
		if (current_health_player <= 0) {
			cout << "you loose" << endl;
			return false;
		}
	}
}
