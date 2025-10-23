#include "utils/csv.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>

namespace chessDataLib::utils {

static inline bool needs_quoting(const std::string& s) {
    for (char c : s) {
        if (c == ',' || c == '"' || c == '\n' || c == '\r') return true;
    }
    return false;
}

std::string EscapeCSVField(const std::string& field) {
    if (!needs_quoting(field)) return field;
    std::ostringstream out;
    out << '"';
    for (char c : field) {
        if (c == '"') out << "\"\"";
        else out << c;
    }
    out << '"';
    return out.str();
}

std::string Trim(const std::string& s) {
    auto l = s.begin();
    while (l != s.end() && std::isspace(static_cast<unsigned char>(*l))) ++l;
    auto r = s.end();
    while (r != l && std::isspace(static_cast<unsigned char>(*(r - 1)))) --r;
    return std::string(l, r);
}

} // namespace chessDataLib::utils