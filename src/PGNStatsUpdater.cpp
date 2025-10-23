#include "PGNStatsUpdater.hpp"
#include "player.hpp"
#include "game.hpp"
#include "tournament.hpp"
#include "databaseStats.hpp"

namespace chessDataLib {

void PGNStatsUpdater::Update(const Game& game,
                              std::unordered_map<std::string, Player>& players,
                              std::unordered_map<std::string, Tournament>& tournaments,
                              DatabaseStats& stats) {
    const std::string& white = game.GetWhite();
    const std::string& black = game.GetBlack();
    const std::string& result = game.GetResult();
    const std::string& event = game.GetEvent();

    // === Update result counters ===
    stats.IncrementResultCount(result);

    // === Update player stats ===
    for (const std::string& name : {white, black}) {
        if (!players.count(name)) {
            Player player;
            player.SetName(name);
            players[name] = player;
            stats.AddPlayer(name, players[name]);
        }
        players[name].IncrementGameCount();
    }

    if (result == "1-0") {
        players[white].IncrementWinCount();
        players[black].IncrementLossCount();
    } else if (result == "0-1") {
        players[black].IncrementWinCount();
        players[white].IncrementLossCount();
    } else if (result == "1/2-1/2") {
        players[white].IncrementDrawCount();
        players[black].IncrementDrawCount();
    }

    // === Update tournament stats ===
    if (!tournaments.count(event)) {
        tournaments[event] = Tournament(event);
        stats.AddTournament(event, tournaments[event]);
    }

    tournaments[event].AddGame();
    tournaments[event].AddPlayer(white);
    tournaments[event].AddPlayer(black);
}

} // namespace chessDataLib
