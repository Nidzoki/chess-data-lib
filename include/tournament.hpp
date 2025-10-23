#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace chessDataLib {

/**
 * @brief Represents a chess tournament with player participation statistics.
 * 
 * Tracks tournament name, total games, unique players, and per-player game counts.
 */
class Tournament {
private:
    std::string name;  ///< Tournament name
    int totalGames = 0;  ///< Total number of games played
    int uniquePlayers = 0;  ///< Number of distinct players

    std::vector<std::string> players;  ///< List of unique player names
    std::unordered_map<std::string, int> playerGameCount;  ///< Games played per player

public:
    // === Constructors ===

    /**
     * @brief Constructs a tournament with a given name.
     * @param name Tournament name.
     */
    explicit Tournament(const std::string& name);

    /**
     * @brief Default constructor.
     */
    Tournament() = default;

    // === Getters ===

    /**
     * @brief Returns the tournament name.
     * @return Reference to the name string.
     */
    const std::string& GetName() const;

    /**
     * @brief Returns the total number of games played.
     * @return Integer game count.
     */
    int GetTotalGames() const;

    /**
     * @brief Returns the number of unique players.
     * @return Integer count of distinct players.
     */
    int GetUniquePlayers() const;

    /**
     * @brief Returns the list of unique player names.
     * @return Reference to the vector of player names.
     */
    const std::vector<std::string>& GetPlayers() const;

    /**
     * @brief Returns the map of player names to game counts.
     * @return Reference to the unordered map.
     */
    const std::unordered_map<std::string, int>& GetPlayerGameCount() const;

    // === Setters ===

    /**
     * @brief Sets the tournament name.
     * @param val New name string.
     */
    void SetName(const std::string& val);

    /**
     * @brief Sets the total number of games.
     * @param val New total game count.
     */
    void SetTotalGames(int val);

    /**
     * @brief Sets the number of unique players.
     * @param val New unique player count.
     */
    void SetUniquePlayers(int val);

    /**
     * @brief Sets the list of player names.
     * @param val New vector of player names.
     */
    void SetPlayers(const std::vector<std::string>& val);

    /**
     * @brief Sets the map of player game counts.
     * @param val New unordered map of player game counts.
     */
    void SetPlayerGameCount(const std::unordered_map<std::string, int>& val);

    // === Helpers ===

    /**
     * @brief Adds a player to the tournament and updates statistics.
     * 
     * Increments total game count. If the player is new, adds to list and increments unique count.
     * @param player Name of the player.
     */
    void AddPlayer(const std::string& player);

    /**
     * @brief Adds a game to the tournament's total count.
     * 
     * Increments the totalGames counter by one.
     */
    void AddGame();
};

} // namespace chessDataLib
