#include "parser.hpp"
#include "utils/csv.hpp"
#include <fstream>
#include <iostream>
#include <limits>

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

// CSV-safe ExportPlayerStatsCSV
bool Parser::ExportPlayerStatsCSV(const std::string& path) const {
    std::ofstream ofs(path);
    if (!ofs.is_open()) {
        std::cerr << "ExportPlayerStatsCSV: failed to open " << path << "\n";
        return false;
    }

    ofs << "Player,TotalGames,Wins,Losses,Draws,WinPct,LossPct,DrawPct\n";

    for (const auto& kv : pimpl->players) {
        const auto& p = kv.second;
        const auto name = p.GetName();
        const auto total = p.GetTotalGames();
        const auto wins = p.GetWinsCount();
        const auto losses = p.GetLossCount();
        const auto draws = p.GetDrawCount();
        const auto wp = p.GetWinPercentage();
        const auto lp = p.GetLossPercentage();
        const auto dp = p.GetDrawPercentage();

        ofs
            << chessDataLib::utils::EscapeCSVField(name) << ','
            << total << ','
            << wins << ','
            << losses << ','
            << draws << ','
            << wp << ','
            << lp << ','
            << dp << '\n';
    }

    return true;
}

// CSV-safe ExportTournamentsCSV
bool Parser::ExportTournamentsCSV(const std::string& path) const {
    std::ofstream ofs(path);
    if (!ofs.is_open()) {
        std::cerr << "ExportTournamentsCSV: failed to open " << path << "\n";
        return false;
    }

    ofs << "Tournament,Games,TopPlayer\n";
    for (const auto& kv : pimpl->tournaments) {
        const auto& t = kv.second;
        const auto name = t.GetName();
        const auto games = t.GetTotalGames();

        // determine top player by game count in this tournament
        const auto& pgc = t.GetPlayerGameCount();
        std::string topPlayer;
        int topCount = -1;
        for (const auto& pp : pgc) {
            if (pp.second > topCount) {
                topCount = pp.second;
                topPlayer = pp.first;
            }
        }

        ofs
            << chessDataLib::utils::EscapeCSVField(name) << ','
            << games << ','
            << chessDataLib::utils::EscapeCSVField(topPlayer) << '\n';
    }

    return true;
}

// === Static analysis ===

DatabaseStats Parser::AnalyzeFile(const std::string& filename, ProgressCallback callback) {
    Parser parser;
    parser.LoadFile(filename, callback);
    return parser.GetStats();
}

} // namespace chessDataLib
