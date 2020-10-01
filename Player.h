//
// Created by Afik on 05/06/2018.
//

#ifndef EX4_WET_PLAYER_H
#define EX4_WET_PLAYER_H

#include <cstring>
#include <iostream>
#include "Weapon.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;


class Player {
    char* player_name;
    int level;
    int life;
    int strength;
    Weapon player_weapon;
    int location;
    // A printing function for a Player
    // Parameters: output stream operator and a player
    // Returns {player name: name, weapon: weapon} to the output stream.
    friend ostream& operator<<(ostream& os, const Player& player);
    // The function gets two players and reduces the second players' LIFE/
    // STRENGTH/LEVEL points, according to the first player's weapon value.
    // Parameters: two players.
    void reduce_points(Player& player1, Player& player2);

public:
    // A c'tor function for the class Player.
    // Parameters: player name, a weapon.
    // Initializes the player's name and player's weapon according to the given
    // parameters, and sets the level, life and strength to 1, location to 0.
    explicit Player(const char* name, const Weapon& weapon);
    // A d'tor function for the class Player.
    // Deletes the player's char* name array.
    ~Player();
    // The function increases player's level by 1.
    void nextLevel();
    // The function receives a player's name, and returns true if it's the name
    // of the current player class.
    bool isPlayer(const char* playerName) const;
    // The function increases player's location by 1.
    void makeStep();
    // The function increases player's life points by 1.
    void addLife();
    // The function increases player's strength by the strength parameter given.
    void addStrength(int strengthToAdd);
    // The function returns true if player's LEVEL, LIFE and STRENGTH points
    // all positive, otherwise returns false - which means the player isn't
    // alive according to the game's rules.
    bool isAlive() const;
    // The function receives as a parameter a number, and if a player's
    // weapon's strength is lower than that - returns true. False otherwise.
    bool weaponIsWeak(int weaponMinStrength) const;
    // Defining a < operator for Player, based on a player's name.
    // Checks if the right player parameter name is shown
    // before the left player's name (by a lexicographical order).
    bool operator<(const Player& player)const;
    // Defining a > operator for Player, based on a player's name.
    // Checks if the left player parameter name is shown
    // before the right player's name (by a lexicographical order).
    bool operator>(const Player& player)const;
    // The function receives a Player, and reduces the player's LIFE/
    // STRENGTH/LEVEL points, according to the other player's, the one with
    // the higher weapon value, weapon value.
    // The function also returns true, unless both player ain't at the same
    // location nor have different weapon value.
    bool fight(Player& player);
    // A copy c'tor for a Player class. Receives a Player (by reference), and
    // returns a copy of it (by value).
    Player(const Player& player);
    // An assignment c'tor for a Player class. Receives a Player (by reference),
    // deletes all current values of *this player, and replaces it with the
    // values of the given player.
    Player& operator=(const Player& player);
    // The function returns the player's weapon.
    Weapon& getWeapon();
};


// SHOULD I IMPLEMENT A COPY AND ASSIGNMENT CONSTRUCTORS?



#endif //EX4_WET_PLAYER_H
