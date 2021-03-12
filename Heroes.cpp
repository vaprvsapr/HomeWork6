#include <iostream>
#include <ctime>
#include <utility>
#include <stdlib.h>

using namespace std;

class Hero {
private:

    const string character_type;
    const string character_name;

    double health;
    double strength;

public:
    Hero(string  type, string  name, const double hp, const double st) :
    character_type(std::move(type)),
    character_name(std::move(name)),
    health(hp),
    strength(st) {}

    void Strike(Hero& otherHero) {
        if (this->health <= 0) {
            cout
            << this->character_type << " " << this->character_name
            << " is dead and not able to fight any more." << endl;
        } else {
            if (otherHero.health <= 0) {
                cout
                        << otherHero.character_type << " " << otherHero.character_name
                        << " is already dead." << endl;
            } else {
                otherHero.health -= this->strength *
                        static_cast<double>((rand() % 1000)) / 1000;

                cout << this->character_name << " attacks " << otherHero.character_name
                     << ". Now " << otherHero.character_name << " has "
                     <<((otherHero.health > 0) ? otherHero.health : 0)
                     << " health points." << endl;

                if(otherHero.health <= 0) {
                    otherHero.~Hero();
                    cout << otherHero.character_type << " "
                         << otherHero.character_name << " is dead." << endl;
                }
            }
        }

    }

    double GetHealthPoints() const {
        return health;
    }
};

void SimpleTest() {
    Hero h1("Elf", "Aragorn", 100, 50);
    Hero h2("Ork", "Jabar", 75, 10);

    cout << "First round. Fight!!!" << endl;

    h1.Strike(h2);
    h2.Strike(h1);

    cout << "Second round. Fight!!!" << endl;

    h1.Strike(h2);

    h2.Strike(h1);
    h1.Strike(h2);
}

void SimulateRandomFight() {

    Hero h1("Elf", "Aragorn", 100, 25);
    Hero h2("Ork", "Jabar", 75, 30);

    while (h1.GetHealthPoints() >= 0 and h2.GetHealthPoints() >= 0) {
        cout << "Fight!!!" << endl;
        h1.Strike(h2);
        h2.Strike(h1);
    }
}

int main() {
    srand(time(0));

    SimpleTest();

    cout << endl << "Random fight." << "\n\n";

    SimulateRandomFight();
}
