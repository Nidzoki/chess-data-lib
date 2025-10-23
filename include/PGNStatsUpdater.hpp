#pragma once

#include "game.hpp"
#include "player.hpp"
#include "tournament.hpp"
#include "databaseStats.hpp"
#include <unordered_map>
#include <string>

namespace chessDataLib {

/**
 * @brief Updates aggregated statistics based on a parsed Game.
 * 
 * Modifies player map, tournament map, and global statistics.
 */
class PGNStatsUpdater {
public:
    /**
     * @brief Updates all relevant statistics based on a single game.
     * @param game Parsed Game object.
     * @param players Reference to player map.
     * @param tournaments Reference to tournament map.
     * @param stats Reference to global database statistics.
     */
    static void Update(const Game& game,
                       std::unordered_map<std::string, Player>& players,
                       std::unordered_map<std::string, Tournament>& tournaments,
                       DatabaseStats& stats);
};

} // namespace chessDataLib
