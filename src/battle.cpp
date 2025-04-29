include <iostream>;
#include <new>;
#include <random>;
#include <ctime>;
#include <cmath>;
#include "battle.h"
#include "player.h"
using namespace std;

const double probability = 0.5;//probability of success in a single roll; default 0.5


total_statue calculating_total_statue(Player_item Player_item) {//total statue, player with item
	total_statue total_statue;
	for (int i = 0; i < 3; ++i) {
		if (Player_item.equipment[i] != nullptr) {
			total_statue.total_Speed += Player_item.equipment[i]->speed;
			total_statue.total_Attack += Player_item.equipment[i]->attack;
			total_statue.total_Armour += Player_item.equipment[i]->armour;
			total_statue.total_Health += Player_item.equipment[i]->health;
		}
	}
	return total_statue;
}


//roll(number_dies)
//input, the number of dies to roll, determined by statue of character
//output, the number of rolling result, number of successful rolls
int roll(int number_dies) {
	int number_success = 0;
	for (int i = 0;i < number_dies;i++) {
		srand(static_cast<unsigned int>(time(nullptr)));
		int randomNum = std::rand() % 10 + 1;
		number_success++;
	}
	return number_success;
}

//print current statue
void print_board(Player_item player, Player_item enemy, int current_health_player, int current_health_enemy) {
	total_statue player_in_battle;
	total_statue enemy_in_battle;
	player_in_battle = calculating_total_statue(player);
	enemy_in_battle = calculating_total_statue(enemy);

	cout << player.name << endl;
	cout << "attack   " << player_in_battle.total_Attack << endl;
	cout << "armour    " << player_in_battle.total_Armour << endl;
	cout << "health   " << current_health_player << "/" << player.health << endl;
	cout << endl;
	cout << enemy.name << endl;
	cout << "attack   " << enemy_in_battle.total_Attack << endl;
	cout << "armour    " << enemy_in_battle.total_Armour << endl;
	cout << "health   " << current_health_enemy << "/" << enemy.health << endl;
}

//battle()
//input: statue of characters
//output: true-win, false-defeat
bool battle(Player_item player, Player_item enemy){
	total_statue player_in_battle;
	total_statue enemy_in_battle;
	player_in_battle = calculating_total_statue(player);
	enemy_in_battle = calculating_total_statue(enemy);
	int current_health_player = player_in_battle.total_Health;
	int current_health_enemy = enemy_in_battle.total_Health;


	int damage;//temporal value
	if (player_in_battle.total_Speed >= enemy_in_battle.total_Speed) {//determine order; case: you are faster
		cout << "you can attack first" << endl;
		print_board(player, enemy, current_health_player, current_health_enemy);
		damage = roll(max(1, player_in_battle.total_Attack - enemy_in_battle.total_Armour));
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
		damage = roll(max(1, player_in_battle.total_Attack - enemy_in_battle.total_Armour));
		cout << "-you launched an attack, deal " << damage << "to enemy" << endl;
		current_health_enemy -= damage;
		if (current_health_enemy <= 0) {
			cout << "you win" << endl;
			return true;
		}

		print_board(player, enemy, current_health_player, current_health_enemy);//enemy's turn
		damage = roll(max(1, enemy_in_battle.total_Attack - player_in_battle.total_Armour));
		cout << "-enemy launched an attack, deal " << damage << "to you" << endl;
		current_health_player -= damage;
		if (current_health_player <= 0) {
			cout << "you loose" << endl;
			return false;
		}
	}
}
