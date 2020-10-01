//
// Created by Afik on 05/06/2018.
//

#ifndef EX4_WET_WEAPON_H
#define EX4_WET_WEAPON_H

#include <cstring>
#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;


enum Target {
    LEVEL,
    STRENGTH,
    LIFE
};

class Weapon {

    char* weapon_name;
    Target weapon_target;
    int hit_strength;
    // A printing function for a Weapon
    // Parameters: output stream operator and a weapon
    // Returns {𝑤𝑒𝑎𝑝𝑜𝑛 𝑛𝑎𝑚𝑒: 𝑛𝑎𝑚𝑒, 𝑤𝑒𝑎𝑝𝑜𝑛 𝑣𝑎𝑙𝑢𝑒: 𝑤𝑒𝑎𝑝𝑜𝑛.𝑔𝑒𝑡𝑉𝑎𝑙𝑢𝑒()} to the output
    // stream.
    friend ostream& operator<<(ostream& os, const Weapon& weapon);

public:
    // A c'tor function for the class Weapon.
    // Parameters: weapon name, a weapon's target and a weapon hit strength.
    // Initializes the weapon's name, target and strength according to the given
    // parameters.
    explicit Weapon(const char* name, Target target, int hit_strength); // tested
    // A d'tor function for the class Weapon.
    // Deletes the Weapon's char* name array.
    ~Weapon();
    // The function returns the Target of a weapon
    Target getTarget() const; // tested
    // The function returns the hit strength of a weapon.
    int getHitStrength() const; // tested
    // The function calculates and returns the value of a weapon.
    // For a LEVEL targeted weapon 1*(hit strength),
    // for a STRENGTH targeted weapon 2*(hit strength),
    // for a LIFE targeted weapon 3*(hit strength).
    int getValue() const; // tested
    // Defining a == operator for Weapon, based on a weapon's value.
    // Checks if the right weapon's value is equal to the the left's one.
    bool operator==(const Weapon& weapon1) const; // tested
    // Defining a != operator for Weapon, based on a weapon's value.
    // Checks if the right weapon's value isn't equal to the the left's one.
    bool operator!=(const Weapon& weapon1)const; // tested
    // Defining a < operator for Weapon, based on a weapon's value.
    // Checks if the right weapon's value is lower the the left's one.
    bool operator<(const Weapon& weapon1)const; // tested
    // Defining a > operator for Weapon, based on a weapon's value.
    // Checks if the left weapon's value is lower the the right's one.
    bool operator>(const Weapon& weapon1)const; // tested
    // A copy c'tor for a Weapon class. Receives a Weapon (by reference), and
    // returns a copy of it (by value).
    Weapon(const Weapon& weapon); // copy, tested
    // An assignment c'tor for a Weapon class. Receives a Weapon (by reference),
    // deletes all current values of *this Weapon, and replaces it with the
    // values of the given Weapon.
    Weapon& operator=(const Weapon& weapon); // tested
};

#endif //EX4_WET_WEAPON_H
