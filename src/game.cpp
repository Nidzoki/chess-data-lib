#include "include/game.hpp"

namespace chessDataLib {

// === Getters ===

const std::string& Game::GetEvent() const {
    return event;
}

const std::string& Game::GetSite() const {
    return site;
}

const std::string& Game::GetDate() const {
    return date;
}

const std::string& Game::GetRound() const {
    return round;
}

const std::string& Game::GetWhite() const {
    return white;
}

const std::string& Game::GetBlack() const {
    return black;
}

const std::string& Game::GetResult() const {
    return result;
}

const std::string& Game::GetWhiteElo() const {
    return whiteElo;
}

const std::string& Game::GetBlackElo() const {
    return blackElo;
}

const std::string& Game::GetEco() const {
    return eco;
}

const std::string& Game::GetOpening() const {
    return opening;
}

int Game::GetMoveCount() const {
    return moveCount;
}

// === Setters ===

void Game::SetEvent(const std::string& val) {
    event = val;
}

void Game::SetSite(const std::string& val) {
    site = val;
}

void Game::SetDate(const std::string& val) {
    date = val;
}

void Game::SetRound(const std::string& val) {
    round = val;
}

void Game::SetWhite(const std::string& val) {
    white = val;
}

void Game::SetBlack(const std::string& val) {
    black = val;
}

void Game::SetResult(const std::string& val) {
    result = val;
}

void Game::SetWhiteElo(const std::string& val) {
    whiteElo = val;
}

void Game::SetBlackElo(const std::string& val) {
    blackElo = val;
}

void Game::SetEco(const std::string& val) {
    eco = val;
}

void Game::SetOpening(const std::string& val) {
    opening = val;
}

void Game::SetMoveCount(int val) {
    moveCount = val;
}

// === Result helpers ===

bool Game::IsWhiteWin() const {
    return result == "1-0";
}

bool Game::IsBlackWin() const {
    return result == "0-1";
}

bool Game::IsDraw() const {
    return result == "1/2-1/2";
}

bool Game::IsUnknownResult() const {
    return result == "*";
}

} // namespace chessDataLib
