#include <iostream>
#include <unordered_map>
#include "utils/csv.hpp"
#include "PGNGameBuilder.hpp"
#include "game.hpp"

int main() {
    using namespace chessDataLib;
    using namespace chessDataLib::utils;

    // CSV escaping tests
    if (EscapeCSVField("a,b") != "\"a,b\"") {
        std::cerr << "CSV comma escaping failed\n";
        return 1;
    }
    if (EscapeCSVField("noquote") != "noquote") {
        std::cerr << "CSV no-quote failed\n";
        return 1;
    }
    if (EscapeCSVField("he\"llo") != "\"he\"\"llo\"") {
        std::cerr << "CSV quote escaping failed\n";
        return 1;
    }

    // Trim test
    if (Trim("  hello \n") != "hello") {
        std::cerr << "Trim failed\n";
        return 2;
    }

    // PGNGameBuilder move-count test
    PGNGameBuilder builder;
    std::unordered_map<std::string, std::string> tags; // empty for this test
    Game g = builder.Build(tags, "1. e4 e5 2. Nf3 Nc6 3. Bb5 a6");
    if (g.GetMoveCount() != 3) {
        std::cerr << "Move count detection failed, expected 3 got " << g.GetMoveCount() << "\n";
        return 3;
    }

    std::cout << "All tests passed\n";
    return 0;
}