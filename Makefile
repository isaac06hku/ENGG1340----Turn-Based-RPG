CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC = src/main.cpp src/battle.cpp src/enemy.cpp src/input.cpp src/location.cpp src/player.cpp src/save_load.cpp src/utils.cpp
OUT = game

all: $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
