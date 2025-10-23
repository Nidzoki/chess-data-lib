#include "PGNTagParser.hpp"

namespace chessDataLib {

std::unordered_map<std::string, std::string> PGNTagParser::Parse(const std::vector<std::string>& tagLines) {
    std::unordered_map<std::string, std::string> tags;

    for (const std::string& line : tagLines) {
        if (line.empty() || line.front() != '[' || line.back() != ']') continue;

        size_t firstQuote = line.find('"');
        size_t lastQuote = line.rfind('"');
        if (firstQuote == std::string::npos || lastQuote <= firstQuote) continue;

        std::string key = line.substr(1, firstQuote - 2); // from after '[' to before space
        std::string value = line.substr(firstQuote + 1, lastQuote - firstQuote - 1);

        tags[key] = value;
    }

    return tags;
}

} // namespace chessDataLib
