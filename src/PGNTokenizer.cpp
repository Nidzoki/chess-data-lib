#include "PGNTokenizer.hpp"
#include <sstream>

namespace chessDataLib {

PGNTokenizer::PGNTokenizer(std::istream& inputStream) : input(inputStream) {}

bool PGNTokenizer::NextGame() {
    currentTagLines.clear();
    currentMoveText.clear();

    std::string line;
    bool inTagSection = true;

    while (std::getline(input, line)) {
        if (line.empty()) {
            if (!currentTagLines.empty()) {
                inTagSection = false;
            }
            continue;
        }

        if (inTagSection && line.front() == '[') {
            currentTagLines.push_back(line);
        } else {
            inTagSection = false;
            currentMoveText += line + " ";
        }

        // Detekcija kraja igre: prazna linija nakon poteza
        if (!inTagSection && line.empty() && !currentMoveText.empty()) {
            break;
        }
    }

    return !currentTagLines.empty() || !currentMoveText.empty();
}

const std::vector<std::string>& PGNTokenizer::GetCurrentTagLines() const {
    return currentTagLines;
}

const std::string& PGNTokenizer::GetCurrentMoveText() const {
    return currentMoveText;
}

} // namespace chessDataLib
