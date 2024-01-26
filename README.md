# Conway's Game of Life Simulation

## About Project
This project is a simple simulation of Conway's Game of Life. The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It's a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.

### Rules of the Game
1. **Birth:** A cell that is dead at time `t` will be alive at time `t+1` if exactly three of its eight neighbors were alive at time `t`.
2. **Death:** A cell can die by:
    - **Overpopulation:** if a cell is alive at time `t` and 4 or more of its neighbors are also alive at time `t`, the cell will be dead at time `t+1`.
    - **Underpopulation:** if a cell is alive at time `t` and 2 or fewer of its neighbors are alive at time `t`, it will be dead at time `t+1`.
3. **Survival:** A cell survives to the next generation if it has either 2 or 3 living neighbors.

## Installation

### Cloning and Building from Source
1. Clone the repository:
```
git clone https://github.com/syaheer-altaf/game-of-life-sfml-cpp.git

```
2. Navigate to the `source code` folder:
```
cd "source code"

```
3. In the `Makefile`, update the paths to your SFML library's include and lib directories.
4. Build the game using the Makefile:
```
make game

```
5. Ensure that the shared libraries `sfml-graphics`, `sfml-window`, and `sfml-system` are in your working directory, or include the `bin` folder of SFML in your environment path.

### Downloading Compiled Version for Windows
Alternatively, if you are on a Windows system, you can download the `windows-compiled` version from the repository to enjoy the simulation without building it from the source.

## Running the Simulation
After successful installation, run the program from the command line or by executing the compiled file. Follow the on-screen instructions to interact with the simulation.

## Contributions
Contributions to this project are welcome. Please ensure that you adhere to the project's coding standards and submit a pull request for any changes.

## License
[./LICENSE]

---
Enjoy exploring the fascinating world of cellular automata through Conway's Game of Life!