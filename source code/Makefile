SFML_INCLUDE_PATH = "Paste your <SFML-INCLUDE-PATH> here"
SFML_LIB_PATH = "Paste your <SFML-LIB-PATH> here"
CXX = g++
CXX_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC_FILES = grid.cpp main.cpp
make game: $(SRC_FILES)
	$(CXX) -I$(SFML_INCLUDE_PATH) -L$(SFML_LIB_PATH) $(SRC_FILES) -o game-of-life $(CXX_FLAGS)