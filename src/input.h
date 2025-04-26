#ifndef INPUT_H
#define INPUT_H
#include <string>
#include <vector>

enum class GameState { INVALID, EXPLORATION, COMBAT, DIALOGUE };

struct Command {
    std::string action;  // "go", "attack", "use"
    std::string target;  // "Forest", "Potion"
    bool is_valid() const { return !action.empty(); }
};

class InputHandler {
public:
    static Command parse_input(const std::string& input);
    static bool validate_command(const Command& cmd, GameState state);
};

#endif