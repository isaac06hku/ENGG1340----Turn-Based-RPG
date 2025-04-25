#include "Location.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*
## Location System Usage

// Initialize
LocationManager world;
if (!world.load_locations("locations.txt")) { --Handle error-- } 

// Movement
if (world.validate_move("Village")) {
    Location new_loc = world.get_current_location();
    // Use new_loc.ascii_art_path for display
    // Check new_loc.has_encounter for battles
}
*/


bool LocationManager::load_locations(const std::string& filename) {
    // Expected file format per line:
    // Name|Description|Connection1,Connection2|ArtPath|hasEncounter
    // Example: "Forest|A woodland...|Village,Cave|assets/forest.txt|true"

    using namespace std;
    
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '/') { // Empty lines/comments skipped
            continue;
        }
        
        istringstream iss(line);
        Location loc;
        
        // Parse each field
        getline(iss, loc.name, '|');
        getline(iss, loc.description, '|');
        
        // Parse connections
        string connections_str;
        getline(iss, connections_str, '|');
        istringstream conn_stream(connections_str);
        string connection;
        while (getline(conn_stream, connection, ',')) {
            loc.connections.push_back(connection);
        }

        getline(iss, loc.ascii_art_path, '|');
        string encounter_str;
        getline(iss, encounter_str);
        loc.has_encounter = (encounter_str == "true");

        locations.push_back(loc);

    }

    return !locations.empty(); //Flase if no valid locations loaded
}

bool LocationManager::validate_move(const std::string& target) const {
    for (const auto& connection : current_location.connections) {
        if (connection == target) {
            return true;
        }
    }
    return false;
}

Location LocationManager::get_current_location() const noexcept {
    return current_location;
}