#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

//Represents a game location with connections, description, and art.
struct Location{
    std::string name; ///< Unique identifier (e.g., "Forest")

    std::string description; ///< Narrative text for players

    std::vector<std::string> connections; ///< Reachable locations (e.g., {"Village", "Cave"})

    std::string ascii_art_path; ///< File path to ASCII art (e.g., "assets/forest_art.txt")

    bool has_encounter; /// Can lead to a fight if true

};

//Manages game locations and movement validation.
class LocationManager{
    private:
    std::vector<Location> locations; // All loaded Locations
    std::vector<std::string> visited_locations; // Track visited locations for save file

    Location current_location; // Player's current location

    public:
    /*
     * @brief Validates if a move to `target` is allowed from current location.
     * @param target Location name (e.g., "Village")
     * @return True if movement is valid
    */
    bool validate_move(const std::string& target) const;

    /*
     * @brief Loads locations from a pipe-delimited text file.
     * @param filename Path to file (e.g., "locations.txt")
     * @return True if file was successfully loaded
    */
    bool load_locations(const std::string& filename);

    std::string get_current_location_name() const noexcept; // Get location name for save/load


    /*
     * @brief Gets the player's current location (noexcept guaranteed).
    */
    Location get_current_location() const noexcept;

};

#endif 