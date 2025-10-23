#include "databaseStats.hpp"
#include "utils/csv.hpp"
#include <algorithm>
#include <string>

namespace chessDataLib {

// Helper to normalize result tokens used throughout the library
static std::string NormalizeResultToken(std::string r) {
    using chessDataLib::utils::Trim;
    r = Trim(r);
    if (r == "*" || r == "?" || r.empty()) return "UNKNOWN";
    // remove trailing punctuation sometimes attached
    while (!r.empty() && (r.back() == ';' || r.back() == '.')) r.pop_back();
    if (r == "1-0") return "1-0";
    if (r == "0-1") return "0-1";
    if (r == "1/2-1/2" || r == "1/2") return "1/2-1/2";
    return r;
}

void DatabaseStats::IncrementResultCount(const std::string& resultRaw) {
    const auto result = NormalizeResultToken(resultRaw);
    if (result == "1-0") ++whiteWins;
    else if (result == "0-1") ++blackWins;
    else if (result == "1/2-1/2") ++draws;
    else ++unknownResults;
}

// === Getters ===

int DatabaseStats::GetTotalGames() const {
    return totalGames;
}

int DatabaseStats::GetUniqueTournaments() const {
    return uniqueTournaments;
}

int DatabaseStats::GetUniquePlayers() const {
    return uniquePlayers;
}

int DatabaseStats::GetWhiteWins() const {
    return whiteWins;
}

int DatabaseStats::GetBlackWins() const {
    return blackWins;
}

int DatabaseStats::GetDraws() const {
    return draws;
}

int DatabaseStats::GetUnknownResults() const {
    return unknownResults;
}

const std::string& DatabaseStats::GetMostActivePlayer() const {
    return mostActivePlayer;
}

int DatabaseStats::GetMaxGamesByPlayer() const {
    return maxGamesByPlayer;
}

const std::string& DatabaseStats::GetLargestTournament() const {
    return largestTournament;
}

int DatabaseStats::GetMaxGamesInTournament() const {
    return maxGamesInTournament;
}

double DatabaseStats::GetParsingTimeSeconds() const {
    return parsingTimeSeconds;
}

const std::vector<std::string>& DatabaseStats::GetTournamentNames() const {
    return tournamentNames;
}

const std::vector<std::string>& DatabaseStats::GetPlayerNames() const {
    return playerNames;
}

const std::unordered_map<std::string, Player>& DatabaseStats::GetPlayerStats() const {
    return playerStats;
}

const std::unordered_map<std::string, Tournament>& DatabaseStats::GetTournaments() const {
    return tournaments;
}

// === Setters ===

void DatabaseStats::SetTotalGames(int val) {
    totalGames = val;
}

void DatabaseStats::SetUniqueTournaments(int val) {
    uniqueTournaments = val;
}

void DatabaseStats::SetUniquePlayers(int val) {
    uniquePlayers = val;
}

void DatabaseStats::SetWhiteWins(int val) {
    whiteWins = val;
}

void DatabaseStats::SetBlackWins(int val) {
    blackWins = val;
}

void DatabaseStats::SetDraws(int val) {
    draws = val;
}

void DatabaseStats::SetUnknownResults(int val) {
    unknownResults = val;
}

void DatabaseStats::SetMostActivePlayer(const std::string& val) {
    mostActivePlayer = val;
}

void DatabaseStats::SetMaxGamesByPlayer(int val) {
    maxGamesByPlayer = val;
}

void DatabaseStats::SetLargestTournament(const std::string& val) {
    largestTournament = val;
}

void DatabaseStats::SetMaxGamesInTournament(int val) {
    maxGamesInTournament = val;
}

void DatabaseStats::SetParsingTimeSeconds(double val) {
    parsingTimeSeconds = val;
}

void DatabaseStats::SetTournamentNames(const std::vector<std::string>& val) {
    tournamentNames = val;
}

void DatabaseStats::SetPlayerNames(const std::vector<std::string>& val) {
    playerNames = val;
}

void DatabaseStats::SetPlayerStats(const std::unordered_map<std::string, Player>& val) {
    playerStats = val;
}

void DatabaseStats::SetTournaments(const std::unordered_map<std::string, Tournament>& val) {
    tournaments = val;
}

// === Helpers ===

void DatabaseStats::AddTournament(const std::string& name, const Tournament& tournament) {
    tournaments[name] = tournament;
    tournamentNames.push_back(name);
    uniqueTournaments++;

    int gameCount = tournament.GetTotalGames();
    if (gameCount > maxGamesInTournament) {
        maxGamesInTournament = gameCount;
        largestTournament = name;
    }
}

void DatabaseStats::AddPlayer(const std::string& name, const Player& stats) {
    playerStats[name] = stats;
    playerNames.push_back(name);
    uniquePlayers++;

    int games = stats.GetTotalGames();
    if (games > maxGamesByPlayer) {
        maxGamesByPlayer = games;
        mostActivePlayer = name;
    }
}

} // namespace chessDataLib
