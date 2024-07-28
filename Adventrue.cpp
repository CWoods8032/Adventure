#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Hero {
public:
	string name;
	int health;
	int strength;
	bool done = false;


		Hero(string n, int h, int s) : name(n), health(h), strength(s) {}

		void attack(Hero & enemy) {
			int damage = (rand() % strength) + 1;
			cout << name << " attacks " << enemy.name << " and deals " << damage << " damage!\n ";
			enemy.health -= damage;
		}

		bool isAlive() {
			return health > 0;
		}
	};

	void introduction() {
		cout << "Welcome to the Adventure Game!\n";
		cout << "You are a brave hero adventuring into a dangerous cave.\n";
	}

	void encounterMonster(Hero& hero) {
		Hero monster("Monster", 20, 5);
		cout << "A wild " << monster.name << " appears!\n";

		while (hero.isAlive() && monster.isAlive()) {
			cout << "Choose an action:\n";
			cout << "1. Attack\n";
			cout << "2. Heal\n";
			int choice;
			cin >> choice;

			if (choice == 1) {
				hero.attack(monster);
			}
			else if (choice == 2) {
				hero.health += 5;
				cout << hero.name << " heals for 5 health points. Health is now " << hero.health << ".\n";
			}
			else {
				cout << "Invalid choice. You lose your turn.\n";
			}

			if (monster.isAlive()) {
				monster.attack(hero);
			}
		}

		if (hero.isAlive()) {
			cout << "You defeated the monster!\n";
		}
		else {
			cout << "You were defeated by the monster...\n";
		}
	}

	void exploreCave(Hero& hero);

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

	void findTreasure(Hero& hero) {
		cout << " You found a treasure chest!\n";
		cout << " Inside the chest, you find a health potion. Your health is restored.\n";
		hero.health += 20;
		cout << " Your health is now " << hero.health << ".\n ";
	}

	void exploreCave(Hero& hero) {
		string direction;
		cout << "Choose a direction to explore (left, right, forward): ";
		cin >> direction;

		for (char& c : direction) {
			c = tolower(c);
		}

		if (direction == "left") {
			cout << "You move left and encounter a monster!\n";
			encounterMonster(hero);
		}
		else if (direction == "right") {
			cout << "You move right and find a treasure chest!\n";
			deadEnd(hero);
		}
		else if (direction == "forward") {
			cout << "You move forward and encounter a monster!\n";
			encounterMonster(hero);
		}
		else {
			cout << "Not a direction. You get lost and need to turn back.\n";
		}
	}
	int main() {
		srand(time(0));

		bool done = false;
		while (!done) {

			introduction();

			string heroName;
			cout << "Enter your hero's name:";
			getline(cin, heroName);


			Hero hero(heroName, 30, 10);
			cout << " Welcome, " << hero.name << "! Your adventure begins now\n";

			cout << "You enter the cave...\n";
			exploreCave(hero);

			if (hero.isAlive()) {
				findTreasure(hero);
				cout << "Congratulations, " << hero.name << "! You completed your adventure.\n";
			}
			else {
				cout << "Your adventure ends here...\n";
			}

			char type;
			do {
				cout << "continue? Y/N ";
				cin >> type;
				type = toupper(type);
				if (type != 'Y' && type != 'N')
				{
					cout << "Invalid input. Please enter 'Y' or 'N'.\n";
				}
			} while (type != 'Y' && type != 'N');

			if (type == 'N') {
				done = true;
				cout << "Thanks for Playing!\n";
			}
		}

	return 0;

}

