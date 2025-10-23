#include "include/Parser.hpp"
#include <fstream>
#include <sstream>

namespace chessDataLib {

// === Internal implementation ===

struct Parser::Impl {
    DatabaseStats stats;
    std::vector<Game> games;
    std::unordered_map<std::string, Player> players;
    std::unordered_map<std::string, Tournament> tournaments;

    bool ParseFile(const std::string& filename, Parser::ProgressCallback callback) {
        // Placeholder: implement PGN parsing logic here
        if (callback) callback(0, "Starting parsing...");
        // Simulate parsing
        if (callback) callback(100, "Parsing complete.");
        return true;
    }
};

// === Public interface ===

Parser::Parser() : pimpl(std::make_unique<Impl>()) {}

Parser::~Parser() = default;

bool Parser::LoadFile(const std::string& filename, ProgressCallback callback) {
    return pimpl->ParseFile(filename, callback);
}

const DatabaseStats& Parser::GetStats() const {
    return pimpl->stats;
}

const std::vector<Game>& Parser::GetGames() const {
    return pimpl->games;
}

const std::unordered_map<std::string, Player>& Parser::GetPlayerStats() const {
    return pimpl->players;
}

const std::unordered_map<std::string, Tournament>& Parser::GetTournaments() const {
    return pimpl->tournaments;
}

void Parser::ExportPlayerStatsCSV(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return;

    out << "Player,TotalGames,Wins,Losses,Draws,Win%,Loss%,Draw%\n";
    for (const auto& [name, player] : pimpl->players) {
        out << name << ","
            << player.GetTotalGames() << ","
            << player.GetWinsCount() << ","
            << player.GetLossCount() << ","
            << player.GetDrawCount() << ","
            << player.GetWinPercentage() << ","
            << player.GetLossPercentage() << ","
            << player.GetDrawPercentage() << "\n";
    }
}

void Parser::ExportTournamentsCSV(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return;

    out << "Tournament,TotalGames,UniquePlayers\n";
    for (const auto& [name, tournament] : pimpl->tournaments) {
        out << name << ","
            << tournament.GetTotalGames() << ","
            << tournament.GetUniquePlayers() << "\n";
    }
}

// === Static analysis ===

DatabaseStats Parser::AnalyzeFile(const std::string& filename, ProgressCallback callback) {
    Parser parser;
    parser.LoadFile(filename, callback);
    return parser.GetStats();
}

} // namespace chessDataLib
