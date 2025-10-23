#include "include/Player.hpp"
#include <sstream>
#include <algorithm>

namespace chessDataLib {

// === Getters ===

const std::string& Player::GetName() const {
    return name;
}

int Player::GetTotalGames() const {
    return totalGames;
}

int Player::GetGamesAsWhiteCount() const {
    return gamesAsWhite;
}

int Player::GetGamesAsBlackCount() const {
    return gamesAsBlack;
}

int Player::GetWinsCount() const {
    return wins;
}

int Player::GetLossCount() const {
    return losses;
}

int Player::GetDrawCount() const {
    return draws;
}

double Player::GetWinPercentage() const {
    return totalGames ? (100.0 * wins / totalGames) : 0.0;
}

double Player::GetLossPercentage() const {
    return totalGames ? (100.0 * losses / totalGames) : 0.0;
}

double Player::GetDrawPercentage() const {
    return totalGames ? (100.0 * draws / totalGames) : 0.0;
}

const std::vector<std::string> Player::GetOpponents() const {
    return opponents;
}

const std::unordered_map<std::string, int> Player::GetOpeningFrequency() const {
    return openingFrequency;
}

// === Setters ===

void Player::SetName(const std::string& val) {
    name = val;
}

void Player::SetTotalGames(int val) {
    totalGames = val;
}

void Player::SetGamesAsWhite(int val) {
    gamesAsWhite = val;
}

void Player::SetGamesAsBlack(int val) {
    gamesAsBlack = val;
}

void Player::SetWins(int val) {
    wins = val;
}

void Player::SetLosses(int val) {
    losses = val;
}

void Player::SetDraws(int val) {
    draws = val;
}

void Player::SetOpponents(const std::vector<std::string>& val) {
    opponents = val;
}

void Player::SetOpeningFrequency(const std::unordered_map<std::string, int>& val) {
    openingFrequency = val;
}

// === Incremental updates ===

void Player::IncrementGameCount() {
    totalGames++;
}

void Player::IncrementWinCount() {
    wins++;
}

void Player::IncrementLossCount() {
    losses++;
}

void Player::IncrementDrawCount() {
    draws++;
}

void Player::AddOpponent(const std::string& opponentName) {
    if (std::find(opponents.begin(), opponents.end(), opponentName) == opponents.end()) {
        opponents.push_back(opponentName);
    }
}

void Player::IncrementOpening(const std::string& ecoCode) {
    openingFrequency[ecoCode]++;
}

void Player::ResetStats() {
    totalGames = 0;
    gamesAsWhite = 0;
    gamesAsBlack = 0;
    wins = 0;
    losses = 0;
    draws = 0;
    opponents.clear();
    openingFrequency.clear();
}

void Player::MergeWith(const Player& other) {
    totalGames += other.totalGames;
    gamesAsWhite += other.gamesAsWhite;
    gamesAsBlack += other.gamesAsBlack;
    wins += other.wins;
    losses += other.losses;
    draws += other.draws;

    for (const auto& opp : other.opponents) {
        AddOpponent(opp);
    }

    for (const auto& [eco, count] : other.openingFrequency) {
        openingFrequency[eco] += count;
    }
}

std::string Player::ToString() const {
    std::ostringstream out;
    out << "Player: " << name << "\n"
        << "Total Games: " << totalGames << "\n"
        << "Wins: " << wins << " (" << GetWinPercentage() << "%)\n"
        << "Losses: " << losses << " (" << GetLossPercentage() << "%)\n"
        << "Draws: " << draws << " (" << GetDrawPercentage() << "%)\n"
        << "Games as White: " << gamesAsWhite << "\n"
        << "Games as Black: " << gamesAsBlack << "\n"
        << "Opponents: " << opponents.size() << "\n"
        << "Openings used: " << openingFrequency.size() << "\n";
    return out.str();
}

} // namespace chessDataLib
