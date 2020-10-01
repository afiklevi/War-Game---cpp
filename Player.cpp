//
// Created by Afik on 05/06/2018.
//

#include "Player.h"

Player::Player(const char* name, const Weapon& weapon):
        player_name(new char[strlen(name)+1]),
        level(1),
        life(1),
        strength(1),
        player_weapon(Weapon(weapon)),
        location(0){
    strcpy(player_name, name);
}
Player::~Player() {
    delete[]player_name;
}
void Player::nextLevel(){
    level++;
}
bool Player::isPlayer(const char* playerName) const{
    return strcmp(player_name, playerName) == 0;
}
void Player::makeStep(){
    location++;
}
void Player::addLife(){
    life++;
}
void Player::addStrength(int strengthToAdd){
    strength+=strengthToAdd;
}
bool Player::isAlive() const{
    return !((level <= 0) || (life <= 0) || (strength <= 0));
}
bool Player::weaponIsWeak(int weaponMinStrength) const{
    return player_weapon.getValue()<weaponMinStrength;
}
bool Player::operator<(const Player& player)const{
    int result = strcmp(player_name,player.player_name);
    return (result<0);
}
bool Player::operator>(const Player& player)const{
    int result = strcmp(player_name,player.player_name);
    return (result>0);
}
ostream& operator<<(ostream& os, const Player& player){
    return os << "{player name: " << player.player_name <<
          ", weapon: " << player.player_weapon << "}," << std::endl;
}
Player::Player(const Player& player):
    player_name(new char[strlen(player.player_name)+1]),
    level(player.level),
    life(player.life),
    strength(player.strength),
    player_weapon(Weapon(player.player_weapon)), // using copy c'tor
    location(player.location){
    strcpy(player_name,player.player_name);
}

Player& Player::operator=(const Player& player){
    if (this == &player){
        return *this;
    }
    if (this != nullptr) {
        delete[] (player_name);
    }
    player_name = new char[strlen(player.player_name)+1];
    strcpy(player_name,player.player_name);
    level = player.level;
    life = player.life;
    strength = player.strength;
    player_weapon = Weapon(player.player_weapon);
    location = player.location;
    return *this;
}
bool Player::fight(Player& player) {
    if (location != player.location || player_weapon == player.player_weapon) {
        return false;
    }
    if (player_weapon > player.player_weapon) {
        reduce_points(*this, player);
        return true;
    }
    else{
        reduce_points(player, *this);
        return true;
    }
}
void Player::reduce_points(Player& player1, Player& player2){
    if (player1.player_weapon.getTarget() == LIFE) {
        player2.life -= player1.player_weapon.getHitStrength();
        if (player2.life < 0) {
            player2.life = 0;
        }
    } else {
        if (player1.player_weapon.getTarget() == STRENGTH) {
            player2.strength -= player1.player_weapon.getHitStrength();
            if (player2.strength < 0) {
                player2.strength = 0;
            }
        } else {
            player2.level -= player1.player_weapon.getHitStrength();
            if (player2.level < 0) {
                player2.level = 0;
            }
        }
    }
}
Weapon& Player::getWeapon(){
    return player_weapon;
}