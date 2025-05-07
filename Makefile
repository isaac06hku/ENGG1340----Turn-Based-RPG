# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Source and Header files
SRC = src/main.cpp src/battle.cpp src/player.cpp src/utils.cpp
HEADERS = src/battle.h src/player.h src/core_types.h src/utils.h

# Output executable
OUT = game

# Build rules
all: $(OUT)

$(OUT): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)
# remove the files
clean:
	rm -f $(OUT)
