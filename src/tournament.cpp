#include "include/Tournament.hpp"

namespace chessDataLib {

// === Constructors ===

Tournament::Tournament(const std::string& name) : name(name) {}

// === Getters ===

const std::string& Tournament::GetName() const {
    return name;
}

int Tournament::GetTotalGames() const {
    return totalGames;
}

int Tournament::GetUniquePlayers() const {
    return uniquePlayers;
}

const std::vector<std::string>& Tournament::GetPlayers() const {
    return players;
}

const std::unordered_map<std::string, int>& Tournament::GetPlayerGameCount() const {
    return playerGameCount;
}

// === Setters ===

void Tournament::SetName(const std::string& val) {
    name = val;
}

void Tournament::SetTotalGames(int val) {
    totalGames = val;
}

void Tournament::SetUniquePlayers(int val) {
    uniquePlayers = val;
}

void Tournament::SetPlayers(const std::vector<std::string>& val) {
    players = val;
}

void Tournament::SetPlayerGameCount(const std::unordered_map<std::string, int>& val) {
    playerGameCount = val;
}

// === Helpers ===

void Tournament::AddPlayer(const std::string& player) {
    if (playerGameCount[player]++ == 0) {
        players.push_back(player);
        uniquePlayers++;
    }
    totalGames++;
}

void Tournament::AddGame() {
    totalGames++;
}

} // namespace chessDataLib
