//
// Created by Afik on 05/06/2018.
//

#ifndef EX4_WET_GAME_H
#define EX4_WET_GAME_H

#include "Weapon.h"
#include "Player.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

enum GameStatus {
    INVALID_PARAM,
    NAME_ALREADY_EXISTS,
    GAME_FULL,
    NAME_DOES_NOT_EXIST,
    FIGHT_FAILED,
    SUCCESS
};

class Game{
    int max_players;
    int num_players;
    Player** players;
    // A printing function for a Game
    // Parameters: output stream operator and a game
    // Returns: player 0: player0,
    //          player 1: player1, ...
    // to the output stream.
    friend ostream& operator<<(ostream& os,  Game& game);
    // A sorting function for players, according lexicographical order
    void maxSort(int max_players);
    // Receives 2 players by reference and swap their places in the array
    void swap(Player& player1, Player& player2);
    // Receives the number of maximum players, calculates and returns the
    // index of the maximal player.
    int indexOfMax(int max_players);

    public:
    // A c'tor function for the class Game.
    // Parameter: maximum players.
    // Initializes the game's max players, the number of current players, and
    // the players array.
    explicit Game(int max_players);
    // A d'tor function for the class Game.
    // Deletes the game's (Player**) players array.
    ~Game();
    // The function receives a player name, weapon name, a target and hit
    // strength. creates a new player with a new weapon and adds him to the
    // game. Returns status:
    // NAME_ALREADY_EXISTS - if the player already exists
    // SUCCESS - for successful insert
    // GAME_FULL - if there is no room for more players
    GameStatus addPlayer(const char* playerName, const char* weaponName,
            Target target, int hit_strength);
    // Increases a player (by the given player name) level by 1.
    // If the player doesn't exist returns NAME_DOES_NOT_EXIST,
    // for success returns SUCCESS.
    GameStatus nextLevel (const char* playerName);
    // Increases a player (by the given player name) location by 1.
    // If the player doesn't exist returns NAME_DOES_NOT_EXIST,
    // for success returns SUCCESS.
    GameStatus makeStep(const char* playerName);
    // Increases a player (by the given player name) life by 1.
    // If the player doesn't exist returns NAME_DOES_NOT_EXIST,
    // for success returns SUCCESS.
    GameStatus addLife(const char* playerName);
    // Increases a player (by the given player name) strength by the given
    // param.
    // If the player doesn't exist returns NAME_DOES_NOT_EXIST,
    // for success returns SUCCESS.
    GameStatus addStrength(const char* playerName, int strengthToAdd);
    // The function receives a weapon strength value and removes all players
    // with weapons which have lower strength.
    // returns true if removes at least 1 player, false otherwise.
    bool removeAllPlayersWithWeakWeapon(int weaponStrength);
    // The function receives 2 players names.
    // returns NAME_DOES_NOT_EXIST - if one of the names doesn't represent a
    // player in the game.
    // FIGHT_FAILED - if the fight failed (both players ain't at the same
    // location.
    // Removes a "dead" player, and returns SUCCESS.
    GameStatus fight(const char* playerName1, const char* playerName2);
    // A copy c'tor for a Game class. Receives a Game (by reference), and
    // returns a copy of it (by value).
    Game(const Game& game);
    // An assignment c'tor for a Game class. Receives a Game (by reference),
    // deletes all current values of *this game, and replaces it with the
    // values of the given game.
    Game& operator=(const Game& game);
};

#endif //EX4_WET_GAME_H
