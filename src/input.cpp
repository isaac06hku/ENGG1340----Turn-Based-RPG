#include "input.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

// Helper: Trim whitespace
static std::string trim(const std::string& str) {
    auto start = str.find_first_not_of(" \t");
    auto end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

Command InputHandler::parse_input(const std::string& input) {
    using namespace std;
    Command cmd;
    istringstream iss(trim(input));
    
    // Extract action (first word)
    if (!(iss >> cmd.action)) {
        return cmd;
    }

    // Convert action to lowercase, original case preserved for target
    transform(cmd.action.begin(), cmd.action.end(), cmd.action.begin(), [](unsigned char c) {return tolower(c);});

    // Extract target (remaining words + trimming)
    string target_part;
    while (iss >> target_part) {

        if (!cmd.target.empty()) {
            cmd.target += " ";
        }

        cmd.target += target_part;
    }

    return cmd;
}

bool InputHandler::validate_command(const Command& cmd, GameState state) {
    {
    using namespace std;

    if (state == GameState::INVALID || !cmd.action_is_valid()) {
        return false;
    }

    const auto get_actions = [](GameState s) -> const vector<string>& {
        static const vector<string> exploration = {"go", "look", "use", "talk"};
        static const vector<string> combat = {"attack", "block", "flee"};
        static const vector<string> dialogue = {"choose", "answer", "leave"};
        
        switch (s) {
            case GameState::EXPLORATION: return exploration;
            case GameState::COMBAT:     return combat;
            case GameState::DIALOGUE:   return dialogue;
            default:                    return exploration; // Fallback
        }
    };

    const auto& valid_actions = get_actions(state);
    return find(valid_actions.begin(), valid_actions.end(), cmd.action) != valid_actions.end();
    }
}