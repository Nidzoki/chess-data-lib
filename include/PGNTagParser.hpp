#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace chessDataLib {

/**
 * @brief Parses PGN tag lines into key-value pairs.
 * 
 * Each line should follow the format: [Key "Value"]
 */
class PGNTagParser {
public:
    /**
     * @brief Parses a list of PGN tag lines into a map.
     * @param tagLines Vector of raw tag lines.
     * @return Map of tag keys to values.
     */
    static std::unordered_map<std::string, std::string> Parse(const std::vector<std::string>& tagLines);
};

} // namespace chessDataLib
