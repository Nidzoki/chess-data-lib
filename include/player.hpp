#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace chessDataLib{

/**
 * @brief Represents a chess player and their game statistics.
 * 
 * Stores basic player information, game counts, results, opponent list,
 * and frequency of openings used.
 */

class Player {
private:
    std::string name;  ///< Player's name

    int totalGames = 0;     ///< Total number of games played
    int gamesAsWhite = 0;   ///< Games played as White
    int gamesAsBlack = 0;   ///< Games played as Black

    int wins = 0;           ///< Number of wins
    int losses = 0;         ///< Number of losses
    int draws = 0;          ///< Number of draws

    std::vector<std::string> opponents;  ///< List of opponent names
    std::unordered_map<std::string, int> openingFrequency; ///< Opening usage frequency

public:
    // === Getters ===

    /**
     * @brief Returns the player's name.
     * @return Reference to the name string.
     */
    const std::string& GetName() const;

    /**
     * @brief Returns the total number of games played.
     * @return Total game count.
     */
    int GetTotalGames() const;

    /**
     * @brief Returns the number of games played as White.
     * @return Game count as White.
     */
    int GetGamesAsWhiteCount() const;

    /**
     * @brief Returns the number of games played as Black.
     * @return Game count as Black.
     */
    int GetGamesAsBlackCount() const;

    /**
     * @brief Returns the number of wins.
     * @return Win count.
     */
    int GetWinsCount() const;

    /**
     * @brief Returns the number of losses.
     * @return Loss count.
     */
    int GetLossCount() const;

    /**
     * @brief Returns the number of draws.
     * @return Draw count.
     */
    int GetDrawCount() const;

    /**
     * @brief Calculates the win percentage.
     * @return Win percentage as a double.
     */
    double GetWinPercentage() const;

    /**
     * @brief Calculates the loss percentage.
     * @return Loss percentage as a double.
     */
    double GetLossPercentage() const;

    /**
     * @brief Calculates the draw percentage.
     * @return Draw percentage as a double.
     */
    double GetDrawPercentage() const;

    /**
     * @brief Returns the list of opponents.
     * @return Vector of opponent names.
     */
    const std::vector<std::string> GetOpponents() const;

    /**
     * @brief Returns the frequency of openings used.
     * @return Unordered map of opening names and their usage count.
     */
    const std::unordered_map<std::string, int> GetOpeningFrequency() const;

    // === Setters ===

    /**
     * @brief Sets the player's name.
     * @param val New name string.
     */
    void SetName(const std::string& val);

    /**
     * @brief Sets the total number of games played.
     * @param val New total game count.
     */
    void SetTotalGames(int val);

    /**
     * @brief Sets the number of games played as White.
     * @param val New count of games as White.
     */
    void SetGamesAsWhite(int val);

    /**
     * @brief Sets the number of games played as Black.
     * @param val New count of games as Black.
     */
    void SetGamesAsBlack(int val);

    /**
     * @brief Sets the number of wins.
     * @param val New win count.
     */
    void SetWins(int val);

    /**
     * @brief Sets the number of losses.
     * @param val New loss count.
     */
    void SetLosses(int val);

    /**
     * @brief Sets the number of draws.
     * @param val New draw count.
     */
    void SetDraws(int val);

    /**
     * @brief Sets the list of opponents.
     * @param val New vector of opponent names.
     */
    void SetOpponents(const std::vector<std::string>& val);

    /**
     * @brief Sets the opening frequency map.
     * @param val New unordered map of opening usage.
     */
    void SetOpeningFrequency(const std::unordered_map<std::string, int>& val);

    /**
     * @brief Adds an opponent to the player's list if not already present.
     * @param name Opponent's name.
     */
    void AddOpponent(const std::string& name);

    /**
     * @brief Increments the usage count for a given opening.
     * @param ecoCode Opening identifier (e.g. ECO code or name).
     */
    void IncrementOpening(const std::string& ecoCode);

    /**
     * @brief Resets all game statistics to zero.
     */
    void ResetStats();

    /**
     * @brief Merges statistics and data from another player into this one.
     * 
     * Adds game counts, results, opponents, and opening frequencies.
     * @param other The player whose data will be merged.
     */
    void MergeWith(const Player& other);

    /**
     * @brief Returns a formatted string summary of the player's statistics.
     * @return String containing name, game counts, results, and percentages.
     */
    std::string ToString() const;

};

} // namespace chessDataLib