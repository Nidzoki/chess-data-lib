#pragma once

#include "tournament.hpp"
#include "game.hpp"
#include "player.hpp"
#include <string>
#include <vector>
#include <unordered_map>

namespace chessDataLib {

/**
 * @brief Aggregated statistics for a parsed PGN database.
 * 
 * Tracks global game counts, player and tournament metadata, and parsing performance.
 */
class DatabaseStats {
private:
    int totalGames = 0;
    int uniqueTournaments = 0;
    int uniquePlayers = 0;
    int whiteWins = 0;
    int blackWins = 0;
    int draws = 0;
    int unknownResults = 0;

    std::string mostActivePlayer;
    int maxGamesByPlayer = 0;

    std::string largestTournament;
    int maxGamesInTournament = 0;

    double parsingTimeSeconds = 0.0;

    std::vector<std::string> tournamentNames;
    std::vector<std::string> playerNames;

    std::unordered_map<std::string, Player> playerStats;
    std::unordered_map<std::string, Tournament> tournaments;

public:
    // === Getters ===

    /**
     * @brief Returns the total number of games parsed.
     */
    int GetTotalGames() const;

    /**
     * @brief Returns the number of unique tournaments.
     */
    int GetUniqueTournaments() const;

    /**
     * @brief Returns the number of unique players.
     */
    int GetUniquePlayers() const;

    /**
     * @brief Returns the number of games won by White.
     */
    int GetWhiteWins() const;

    /**
     * @brief Returns the number of games won by Black.
     */
    int GetBlackWins() const;

    /**
     * @brief Returns the number of drawn games.
     */
    int GetDraws() const;

    /**
     * @brief Returns the number of games with unknown result.
     */
    int GetUnknownResults() const;

    /**
     * @brief Returns the name of the most active player.
     */
    const std::string& GetMostActivePlayer() const;

    /**
     * @brief Returns the number of games played by the most active player.
     */
    int GetMaxGamesByPlayer() const;

    /**
     * @brief Returns the name of the largest tournament.
     */
    const std::string& GetLargestTournament() const;

    /**
     * @brief Returns the number of games in the largest tournament.
     */
    int GetMaxGamesInTournament() const;

    /**
     * @brief Returns the time taken to parse the PGN dataset.
     */
    double GetParsingTimeSeconds() const;

    /**
     * @brief Returns the list of tournament names.
     */
    const std::vector<std::string>& GetTournamentNames() const;

    /**
     * @brief Returns the list of player names.
     */
    const std::vector<std::string>& GetPlayerNames() const;

    /**
     * @brief Returns the map of player statistics.
     */
    const std::unordered_map<std::string, Player>& GetPlayerStats() const;

    /**
     * @brief Returns the map of tournaments.
     */
    const std::unordered_map<std::string, Tournament>& GetTournaments() const;

    // === Setters ===

    /**
     * @brief Sets the total number of games.
     */
    void SetTotalGames(int val);

    /**
     * @brief Sets the number of unique tournaments.
     */
    void SetUniqueTournaments(int val);

    /**
     * @brief Sets the number of unique players.
     */
    void SetUniquePlayers(int val);

    /**
     * @brief Sets the number of white wins.
     */
    void SetWhiteWins(int val);

    /**
     * @brief Sets the number of black wins.
     */
    void SetBlackWins(int val);

    /**
     * @brief Sets the number of draws.
     */
    void SetDraws(int val);

    /**
     * @brief Sets the number of unknown results.
     */
    void SetUnknownResults(int val);

    /**
     * @brief Sets the name of the most active player.
     */
    void SetMostActivePlayer(const std::string& val);

    /**
     * @brief Sets the number of games played by the most active player.
     */
    void SetMaxGamesByPlayer(int val);

    /**
     * @brief Sets the name of the largest tournament.
     */
    void SetLargestTournament(const std::string& val);

    /**
     * @brief Sets the number of games in the largest tournament.
     */
    void SetMaxGamesInTournament(int val);

    /**
     * @brief Sets the parsing time in seconds.
     */
    void SetParsingTimeSeconds(double val);

    /**
     * @brief Sets the list of tournament names.
     */
    void SetTournamentNames(const std::vector<std::string>& val);

    /**
     * @brief Sets the list of player names.
     */
    void SetPlayerNames(const std::vector<std::string>& val);

    /**
     * @brief Sets the map of player statistics.
     */
    void SetPlayerStats(const std::unordered_map<std::string, Player>& val);

    /**
     * @brief Sets the map of tournaments.
     */
    void SetTournaments(const std::unordered_map<std::string, Tournament>& val);

    // === Helpers ===

    /**
     * @brief Adds a tournament and updates tournament list and count.
     * @param name Tournament name.
     * @param tournament Tournament object.
     */
    void AddTournament(const std::string& name, const Tournament& tournament);

    /**
     * @brief Adds a player and updates player list and count.
     * @param name Player name.
     * @param stats Player object.
     */
    void AddPlayer(const std::string& name, const Player& stats);

    /**
     * @brief Increments result counters based on PGN result string.
     * @param result Result string ("1-0", "0-1", "1/2-1/2", "*").
     */
    void IncrementResultCount(const std::string& result);
};

} // namespace chessDataLib
