#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Hero class definition
class Hero {
public:
	string name; // Hero's name
	int health; // Hero's health
	int strength; // Hero's strength
	bool done = false; // Flag to indicate if the hero is done with their adventure

		// Constructor to initialize the hero's attributes
		Hero(string n, int h, int s) : name(n), health(h), strength(s) {}


		// Method for the hero to attack an enemy
		void attack(Hero & enemy) {
			int damage = (rand() % strength) + 1; // Calculate random damage based on hero's strength
			cout << name << " attacks " << enemy.name << " and deals " << damage << " damage!\n ";
			enemy.health -= damage; // Reduce enemy's health by the damage dealt
		}

		// Method to check if the hero is still alive
		bool isAlive() {
			return health > 0;
		}
	};

	// Function to introduce the game
	void introduction() {
		cout << "Welcome to the Adventure Game!\n";
		cout << "You are a brave hero adventuring into a dangerous cave.\n";
	}

	// Function to handle an encounter with a monster
	void encounterMonster(Hero& hero) {
		Hero monster("Monster", 20, 5); // Create a monster with specific attributes
		cout << "A wild " << monster.name << " appears!\n";

		// Battle loop
		while (hero.isAlive() && monster.isAlive()) {
			cout << "Choose an action:\n";
			cout << "1. Attack\n";
			cout << "2. Heal\n";
			int choice;
			cin >> choice;

			if (choice == 1) {
				hero.attack(monster); // Hero attacks the monster
			}
			else if (choice == 2) {
				hero.health += 5; // Hero heals
				cout << hero.name << " heals for 5 health points. Health is now " << hero.health << ".\n";
			}
			else {
				cout << "Invalid choice. You lose your turn.\n";
			}

			// If the monster is still alive, it attacks the hero
			if (monster.isAlive()) {
				monster.attack(hero);
			}
		}

		// Determine the outcome of the battle
		if (hero.isAlive()) {
			cout << "You defeated the monster!\n";
		}
		else {
			cout << "You were defeated by the monster...\n";
		}
	}

	void exploreCave(Hero& hero);

	// Function to explore a dead end in the cave
	void deadEnd(Hero& hero) {
		cout << "You reached a dead end. Choose an action:\n";
		cout << "1. Turn around\n";
		cout << "2. Stay\n";
		int choice;
		cin >> choice;

		if (choice == 1) {
			exploreCave(hero);
		}
		else if (choice == 2) {
			cout << "Are you scared to continue?\n";
			deadEnd(hero);
		} else {
			cout << "Invalid choice. You remain at the dead end.\n";
		}
	}

	// Function to find a treasure in the cave
	void findTreasure(Hero& hero) {
		cout << " You found a treasure chest!\n";
		cout << " Inside the chest, you find a health potion. Your health is restored.\n";
		hero.health += 20;
		cout << " Your health is now " << hero.health << ".\n ";
	}

	// Function to explore the cave
	void exploreCave(Hero& hero) {
		string direction;
		cout << "Choose a direction to explore (left, right, forward): ";
		cin >> direction;

		// Convert direction to lowercase
		for (char& c : direction) {
			c = tolower(c);
		}

		// Determine the outcome based on the chosen direction
		if (direction == "left") {
			cout << "You move left and encounter a monster!\n";
			encounterMonster(hero); // Encounter a monster
		}
		else if (direction == "right") {
			cout << "You move right and find a treasure chest!\n";
			deadEnd(hero); // Find a dead end
		}
		else if (direction == "forward") {
			cout << "You move forward and encounter a monster!\n";
			encounterMonster(hero); // Encounter a monster
		}
		else {
			cout << "Not a direction. You get lost and need to turn back.\n";
		}
	}
	int main() {
		srand(time(0)); // Seed the random number generator

		bool done = false;
		while (!done) {

			introduction(); // Display the game introduction

			string heroName;
			cout << "Enter your hero's name:";
			getline(cin, heroName); // Get the hero's name from the user


			Hero hero(heroName, 30, 10); // Create a hero with the given name and initial attributes
			cout << " Welcome, " << hero.name << "! Your adventure begins now\n";

			cout << "You enter the cave...\n";
			exploreCave(hero); // Start exploring the cave

			// Check if the hero is still alive and handle the outcome
			if (hero.isAlive()) {
				findTreasure(hero); // Find a treasure if the hero is still alive
				cout << "Congratulations, " << hero.name << "! You completed your adventure.\n";
			}
			else {
				cout << "Your adventure ends here...\n";
			}

			char type;
			do {
				cout << "continue? Y/N ";
				cin >> type;
				type = toupper(type); // Convert the input to uppercase
				if (type != 'Y' && type != 'N')
				{
					cout << "Invalid input. Please enter 'Y' or 'N'.\n";
				}
			} while (type != 'Y' && type != 'N');

			if (type == 'N') {
				done = true; // Exit the game if the user chooses 'N'
				cout << "Thanks for Playing!\n";
			}
		}

	return 0; // End the program

}

