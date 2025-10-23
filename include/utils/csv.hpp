#pragma once
#include <string>

namespace chessDataLib::utils {

// Escape a field for CSV output:
// - If field contains comma, quote, newline or CR, wrap in double quotes
// - Double quotes inside fields are doubled
std::string EscapeCSVField(const std::string& field);

// Trim whitespace from both ends of a string
std::string Trim(const std::string& s);

} // namespace chessDataLib::utils