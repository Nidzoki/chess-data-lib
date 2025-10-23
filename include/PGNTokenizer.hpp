#pragma once

#include <string>
#include <vector>
#include <istream>

namespace chessDataLib {

/**
 * @brief Tokenizes a PGN input stream into tag blocks and move text.
 * 
 * Supports sequential parsing of PGN games from a file or stream.
 */
class PGNTokenizer {
public:
    /**
     * @brief Constructs a tokenizer from an input stream.
     * @param input Reference to an open input stream.
     */
    explicit PGNTokenizer(std::istream& input);

    /**
     * @brief Advances to the next PGN game block.
     * @return True if a game was found, false if end of stream.
     */
    bool NextGame();

    /**
     * @brief Returns the raw tag lines of the current game.
     * @return Vector of tag lines.
     */
    const std::vector<std::string>& GetCurrentTagLines() const;

    /**
     * @brief Returns the raw move text of the current game.
     * @return String containing move section.
     */
    const std::string& GetCurrentMoveText() const;

private:
    std::istream& input;
    std::vector<std::string> currentTagLines;
    std::string currentMoveText;
};

} // namespace chessDataLib
