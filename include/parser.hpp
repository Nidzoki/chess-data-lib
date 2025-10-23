#pragma once

#include "databaseStats.hpp"
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace chessDataLib {

/**
 * @brief Parses PGN files and extracts structured chess data.
 * 
 * Supports progress callbacks, file loading, and exporting statistics.
 */
class Parser {
public:
    /**
     * @brief Callback type for reporting parsing progress.
     * @param percent Completion percentage (0–100).
     * @param message Status message.
     */
    using ProgressCallback = std::function<void(int, const std::string&)>;

    /**
     * @brief Parses a PGN file and returns aggregated statistics.
     * @param filename Path to PGN file.
     * @param callback Optional progress callback.
     * @return Aggregated database statistics.
     */
    static DatabaseStats AnalyzeFile(const std::string& filename, ProgressCallback callback = nullptr);

    /**
     * @brief Constructs a new parser instance.
     */
    Parser();

    /**
     * @brief Destroys the parser instance.
     */
    ~Parser();

    /**
     * @brief Loads and parses a PGN file into internal structures.
     * @param filename Path to PGN file.
     * @param callback Optional progress callback.
     * @return True if parsing succeeded.
     */
    bool LoadFile(const std::string& filename, ProgressCallback callback = nullptr);

    /**
     * @brief Returns aggregated statistics after parsing.
     * @return Reference to the DatabaseStats object.
     */
    const DatabaseStats& GetStats() const;

    /**
     * @brief Returns the list of parsed games.
     * @return Reference to the vector of Game objects.
     */
    const std::vector<Game>& GetGames() const;

    /**
     * @brief Returns the map of parsed player statistics.
     * @return Reference to the unordered map of Player objects.
     */
    const std::unordered_map<std::string, Player>& GetPlayerStats() const;

    /**
     * @brief Returns the map of parsed tournaments.
     * @return Reference to the unordered map of Tournament objects.
     */
    const std::unordered_map<std::string, Tournament>& GetTournaments() const;

    /**
     * @brief Exports player statistics to a CSV file.
     * @param filename Output file path.
     */
    // Returns true on success, false on I/O failure
    bool ExportPlayerStatsCSV(const std::string& filename) const;

    /**
     * @brief Exports tournament statistics to a CSV file.
     * @param filename Output file path.
     */
    // Returns true on success, false on I/O failure
    bool ExportTournamentsCSV(const std::string& filename) const;

private:
    struct Impl; ///< Internal implementation (Pimpl idiom)
    std::unique_ptr<Impl> pimpl;
};

} // namespace chessDataLib
