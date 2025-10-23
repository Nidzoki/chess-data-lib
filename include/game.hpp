#pragma once

#include <string>

namespace chessDataLib {

/**
 * @brief Represents a single chess game with metadata and result.
 * 
 * Stores PGN tag information such as players, date, event, result, and opening.
 * Does not store full move list or Player objects for memory efficiency.
 */
class Game {
private:
    std::string event;        ///< Event name
    std::string site;         ///< Location of the game
    std::string date;         ///< Date of the game
    std::string round;        ///< Round number or label

    std::string white;        ///< White player's name
    std::string black;        ///< Black player's name
    std::string result;       ///< Game result ("1-0", "0-1", "1/2-1/2", "*")

    std::string whiteElo;     ///< White player's Elo rating
    std::string blackElo;     ///< Black player's Elo rating

    std::string eco;          ///< ECO code of the opening
    std::string opening;      ///< Opening name

    int moveCount = 0;        ///< Number of moves played

public:
    // === Getters ===

    /**
     * @brief Returns the event name.
     * @return Reference to the event string.
     */
    const std::string& GetEvent() const;

    /**
     * @brief Returns the site/location of the game.
     * @return Reference to the site string.
     */
    const std::string& GetSite() const;

    /**
     * @brief Returns the date of the game.
     * @return Reference to the date string.
     */
    const std::string& GetDate() const;

    /**
     * @brief Returns the round identifier.
     * @return Reference to the round string.
     */
    const std::string& GetRound() const;

    /**
     * @brief Returns the name of the white player.
     * @return Reference to the white player's name.
     */
    const std::string& GetWhite() const;

    /**
     * @brief Returns the name of the black player.
     * @return Reference to the black player's name.
     */
    const std::string& GetBlack() const;

    /**
     * @brief Returns the result of the game.
     * @return Reference to the result string.
     */
    const std::string& GetResult() const;

    /**
     * @brief Returns the Elo rating of the white player.
     * @return Reference to the white Elo string.
     */
    const std::string& GetWhiteElo() const;

    /**
     * @brief Returns the Elo rating of the black player.
     * @return Reference to the black Elo string.
     */
    const std::string& GetBlackElo() const;

    /**
     * @brief Returns the ECO code of the opening.
     * @return Reference to the ECO string.
     */
    const std::string& GetEco() const;

    /**
     * @brief Returns the name of the opening.
     * @return Reference to the opening string.
     */
    const std::string& GetOpening() const;

    /**
     * @brief Returns the number of moves played in the game.
     * @return Integer move count.
     */
    int GetMoveCount() const;

    // === Setters ===

    /**
     * @brief Sets the event name.
     * @param val New event string.
     */
    void SetEvent(const std::string& val);

    /**
     * @brief Sets the site/location.
     * @param val New site string.
     */
    void SetSite(const std::string& val);

    /**
     * @brief Sets the date of the game.
     * @param val New date string.
     */
    void SetDate(const std::string& val);

    /**
     * @brief Sets the round identifier.
     * @param val New round string.
     */
    void SetRound(const std::string& val);

    /**
     * @brief Sets the white player's name.
     * @param val New white player name.
     */
    void SetWhite(const std::string& val);

    /**
     * @brief Sets the black player's name.
     * @param val New black player name.
     */
    void SetBlack(const std::string& val);

    /**
     * @brief Sets the result of the game.
     * @param val New result string.
     */
    void SetResult(const std::string& val);

    /**
     * @brief Sets the white player's Elo rating.
     * @param val New white Elo string.
     */
    void SetWhiteElo(const std::string& val);

    /**
     * @brief Sets the black player's Elo rating.
     * @param val New black Elo string.
     */
    void SetBlackElo(const std::string& val);

    /**
     * @brief Sets the ECO code of the opening.
     * @param val New ECO string.
     */
    void SetEco(const std::string& val);

    /**
     * @brief Sets the name of the opening.
     * @param val New opening string.
     */
    void SetOpening(const std::string& val);

    /**
     * @brief Sets the number of moves played.
     * @param val New move count.
     */
    void SetMoveCount(int val);

    // === Result helpers ===

    /**
     * @brief Checks if the result indicates a white win.
     * @return True if result is "1-0".
     */
    bool IsWhiteWin() const;

    /**
     * @brief Checks if the result indicates a black win.
     * @return True if result is "0-1".
     */
    bool IsBlackWin() const;

    /**
     * @brief Checks if the result indicates a draw.
     * @return True if result is "1/2-1/2".
     */
    bool IsDraw() const;

    /**
     * @brief Checks if the result is unknown or incomplete.
     * @return True if result is "*".
     */
    bool IsUnknownResult() const;
};

} // namespace chessDataLib
