//
// Created by Afik on 05/06/2018.
//

#include "Game.h"


Game::Game(int max_players):
        max_players(max_players),
        num_players(0),
        players(new Player*[max_players])
        {
    for (int i=0; i<max_players; i++){
        players[i]= nullptr;
    }
}

Game::~Game(){
    for (int i=0; i<max_players; i++){
        if (players[i]!= nullptr){
            delete (players[i]);
        }
    }
    delete []players;
}

GameStatus Game::addPlayer(const char* playerName, const char* weaponName,
                     Target target, int hit_strength){
    if (num_players==max_players) {
        return GAME_FULL;
    }
    int i=0;
    for (i=0; i<max_players; i++) {
        if (players[i] != nullptr) {
            if ((*players[i]).isPlayer(playerName)) {
                return NAME_ALREADY_EXISTS;
            }
        }
    }
    for (i=0; i<max_players; i++) {
        if (players[i] == nullptr) {
            players[i] = new Player(playerName,
                                 Weapon(weaponName, target, hit_strength));
            num_players++;
            return SUCCESS;
        }
    }
    return SUCCESS;
}
GameStatus Game::nextLevel (const char* playerName){
    int i=0;
    for (i=0; i<max_players; i++) {
        if (players[i] != nullptr) {
            if ((*players[i]).isPlayer(playerName)) {
                (*players[i]).nextLevel();
                return SUCCESS;
            }
        }
    }
    return NAME_DOES_NOT_EXIST;
}
GameStatus Game::makeStep(const char* playerName){
    int i=0;
    for (i=0; i<max_players; i++) {
        if (players[i] != nullptr) {
            if ((*players[i]).isPlayer(playerName)) {
                (*players[i]).makeStep();
                return SUCCESS;
            }
        }
    }
    return NAME_DOES_NOT_EXIST;
}
GameStatus Game::addLife(const char* playerName){
    int i=0;
    for (i=0; i<max_players; i++) {
        if (players[i] != nullptr) {
            if ((*players[i]).isPlayer(playerName)) {
                (*players[i]).addLife();
                return SUCCESS;
            }
        }
    }
    return NAME_DOES_NOT_EXIST;
}
GameStatus Game::addStrength(const char* playerName, int strengthToAdd){
    if (strengthToAdd<0){
        return INVALID_PARAM;
    }
    int i=0;
    for (i=0; i<max_players; i++) {
        if (players[i] != nullptr) {
            if ((*players[i]).isPlayer(playerName)) {
                (*players[i]).addStrength(strengthToAdd);
                return SUCCESS;
            }
        }
    }
    return NAME_DOES_NOT_EXIST;;
}
bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    int i = 0;
    bool removed = false;
    for (i = 0; i < max_players; i++) {
        if (players[i] != nullptr) {
            if ((*players[i]).weaponIsWeak(weaponStrength)){
                delete players[i];
                players[i]= nullptr;
                num_players--;
                removed = true;
            }
        }
    }
    return removed;
}

GameStatus Game::fight(const char* playerName1, const char* playerName2){
    int i=0;
    int player1 = -1, player2 = -1;
    for (i=0; i<max_players; i++) {
        if (players[i] != nullptr) {
            if ((*players[i]).isPlayer(playerName1) && player1 == -1) {
                player1 = i;
            }
            if ((*players[i]).isPlayer(playerName2) && player2 == -1) {
                player2 = i;
            }
        }
    }
    if ((player1==-1)||(player2==-1)){
        return NAME_DOES_NOT_EXIST;
    }
    bool fight = (*players[player1]).fight((*players[player2]));
    if (!fight){
        return FIGHT_FAILED;
    }
    if (!(*players[player1]).isAlive()){
        delete players[player1];
        players[player1] = nullptr;
        num_players--;
    }
    if (!(*players[player2]).isAlive()){
        delete players[player2];
        players[player2] = nullptr;
        num_players--;
    }
    return SUCCESS;
}
ostream& operator<<(ostream& os, Game& game) {
    game.maxSort(game.max_players);
    int player_num=0;
    for (int i = 0; i < game.max_players; i++) {
        if ((game.players[i])!= nullptr) {
            os << "player " << player_num << ": " << (*game.players[i]);
            player_num++;
        }
    }
    return os;
}
Game::Game(const Game& game):
        max_players(game.max_players),
        num_players(game.num_players),
    players(new Player*[game.max_players]){
    for (int i=0; i<max_players; i++){
        players[i]= nullptr;
    }
    for (int i=0; i<game.max_players; i++){
        if (game.players[i]!= nullptr) {
            *players[i] = *(game.players[i]);
        }
    }
}
Game& Game::operator=(const Game& game){
    if (this == &game){
        return *this;
    }
    max_players = game.max_players;
    num_players = game.num_players;
    delete[](players);
    players = new Player*[max_players];
    for (int i=0; i<max_players; i++){
        players[i]= nullptr;
    }
    for (int i=0; i<game.max_players; i++){
        if (game.players[i]!= nullptr) {
            players[i] = new Player("a",(*(game.players[i])).getWeapon());
            *players[i] = (*(game.players[i]));
        }
    }
    return *this;
}
void Game::maxSort(int max_players){
    for(int len = max_players; len > 1; len--){
        if (this->players[len-1]!=nullptr) {
            int index = indexOfMax(len);
            swap(*players[len - 1], *players[index]);
        }
    }
}
int Game::indexOfMax(int max_players){
    int index = 0;
    while (players[index]== nullptr){
        index++;
    }
    for(int i = 1; i < max_players; i++){
        if (players[i]!= nullptr) {
            if ((*players[i]) > (*players[index])) {
                index = i;
            }
        }
    }
    return index;
}
void Game::swap(Player& player1, Player& player2){
    Player tmp = player1;
    player1 = player2;
    player2 = tmp;
}