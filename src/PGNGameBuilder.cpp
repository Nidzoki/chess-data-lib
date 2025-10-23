#include "include/PGNGameBuilder.hpp"

namespace chessDataLib {

Game PGNGameBuilder::Build(const std::unordered_map<std::string, std::string>& tags, const std::string& moveText) {
    Game game;

    if (tags.count("Event")) game.SetEvent(tags.at("Event"));
    if (tags.count("Site")) game.SetSite(tags.at("Site"));
    if (tags.count("Date")) game.SetDate(tags.at("Date"));
    if (tags.count("Round")) game.SetRound(tags.at("Round"));
    if (tags.count("White")) game.SetWhite(tags.at("White"));
    if (tags.count("Black")) game.SetBlack(tags.at("Black"));
    if (tags.count("Result")) game.SetResult(tags.at("Result"));
    if (tags.count("WhiteElo")) game.SetWhiteElo(tags.at("WhiteElo"));
    if (tags.count("BlackElo")) game.SetBlackElo(tags.at("BlackElo"));
    if (tags.count("ECO")) game.SetEco(tags.at("ECO"));
    if (tags.count("Opening")) game.SetOpening(tags.at("Opening"));

    // Heuristika: broj poteza = broj točaka (npr. "1. e4 e5 2. Nf3 Nc6" → 2 poteza)
    int moveCount = 0;
    for (char c : moveText) {
        if (c == '.') moveCount++;
    }
    game.SetMoveCount(moveCount);

    return game;
}

} // namespace chessDataLib
