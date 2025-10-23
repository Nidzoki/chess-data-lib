#pragma once

#include "game.hpp"
#include <string>
#include <unordered_map>

namespace chessDataLib {

/**
 * @brief Builds a Game object from PGN tag pairs and move text.
 * 
 * Extracts metadata and initializes a Game instance.
 */
class PGNGameBuilder {
public:
    /**
     * @brief Constructs a Game from parsed tag pairs and move section.
     * @param tags Map of PGN tag keys to values.
     * @param moveText Raw move section as a string.
     * @return Constructed Game object.
     */
    static Game Build(const std::unordered_map<std::string, std::string>& tags, const std::string& moveText);
};

} // namespace chessDataLib
