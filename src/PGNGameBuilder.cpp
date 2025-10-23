#include "PGNGameBuilder.hpp"
#include <regex>
#include <sstream>

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

    // Robustly detect move count by finding move-number tokens like "1." or "23."
    try {
        std::regex mvnum(R"((\d+)\s*\.)");
        std::string s = moveText;
        std::size_t lastMoveNumber = 0;
        for (std::sregex_iterator it(s.begin(), s.end(), mvnum), end; it != end; ++it) {
            lastMoveNumber = std::stoul((*it)[1].str());
        }
        if (lastMoveNumber > 0) {
            // lastMoveNumber is the index of the last full move; store as full-move count
            game.SetMoveCount(static_cast<int>(lastMoveNumber));
        } else {
            // fallback: attempt to count move tokens (naive)
            std::istringstream iss(s);
            std::string tok;
            int moves = 0;
            while (iss >> tok) {
                // ignore move numbers if token ends with '.'
                if (!tok.empty() && tok.back() == '.') continue;
                ++moves;
            }
            // convert ply to move pairs (approx)
            game.SetMoveCount((moves + 1) / 2);
        }
    } catch (...) {
        // keep prior/default move-count if anything goes wrong
    }

    return game;
}

} // namespace chessDataLib
