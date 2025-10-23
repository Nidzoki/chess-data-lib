#include "include/types.hpp"
#include <algorithm>

namespace chessDataLib {

// === Getteri ===


const std::string& Player::GetName() const{ return name; }

int Player::GetTotalGames() const{
    return totalGames;
}

int Player::GetGamesAsWhiteCount()  const{
    return gamesAsWhite;
}

int Player::GetGamesAsBlackCount()  const{
    return gamesAsBlack;
}

int Player::GetWinsCount()  const{
    return wins;
}

int Player::GetLossCount()  const{
    return losses;
}

int Player::GetDrawCount()  const{
    return draws;
}

double Player::GetWinPercentage() const{
    return totalGames > 0 ? static_cast<double>(wins) / totalGames * 100.0 : 0.0;
}

double Player::GetLossPercentage() const{
    return totalGames > 0 ? static_cast<double>(losses) / totalGames * 100.0 : 0.0;
}

double Player::GetDrawPercentage() const{
    return totalGames > 0 ? static_cast<double>(draws) / totalGames * 100.0 : 0.0;
}

const std::vector<std::string> Player::GetOpponents() const{
    return opponents;
}

const std::unordered_map<std::string, int> Player::GetOpeningFrequency()  const{
    return openingFrequency;
}

// === Setteri ===

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

void Player::AddOpponent(const std::string& name) {
    if (std::find(opponents.begin(), opponents.end(), name) == opponents.end()) {
        opponents.push_back(name);
    }
}

void Player::IncrementOpening(const std::string& ecoCode) {
    ++openingFrequency[ecoCode];
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

    for (const auto& [opening, count] : other.openingFrequency) {
        openingFrequency[opening] += count;
    }
}

std::string Player::ToString() const {
    std::string summary;
    summary += "Player: " + name + "\n";
    summary += "Total Games: " + std::to_string(totalGames) + "\n";
    summary += "White: " + std::to_string(gamesAsWhite) + ", Black: " + std::to_string(gamesAsBlack) + "\n";
    summary += "Wins: " + std::to_string(wins) + " (" + std::to_string(GetWinPercentage()) + "%)\n";
    summary += "Losses: " + std::to_string(losses) + " (" + std::to_string(GetLossPercentage()) + "%)\n";
    summary += "Draws: " + std::to_string(draws) + " (" + std::to_string(GetDrawPercentage()) + "%)\n";
    summary += "Unique Opponents: " + std::to_string(opponents.size()) + "\n";
    summary += "Openings Used: " + std::to_string(openingFrequency.size()) + "\n";
    return summary;
}


} // namespace chessDataLib
