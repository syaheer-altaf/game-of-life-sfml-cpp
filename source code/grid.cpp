#include <SFML/Graphics.hpp>
#include <vector>

class Grid 
{
    private:
        int gridSizeX;  // Number of grid cells in X direction
        int gridSizeY;  // Number of grid cells in Y direction
        int cellSize;  // Size of each grid cell

        std::vector<std::vector<int>> grid;  // Grid data

    public:
        Grid(int x, int y, int c) 
        {
            // Initialize the grid with default values
            gridSizeX = x;
            gridSizeY = y;
            cellSize = c;
            grid.resize(gridSizeX, std::vector<int>(gridSizeY, 0));
        }
        void clear()
        {
            grid.clear();
            grid.resize(gridSizeX, std::vector<int>(gridSizeY, 0));
        }
        
        void setValue(int x, int y, int value) 
        {
            // Set the value at a specific grid cell
            if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
                grid[x][y] = value;
            }
        }

        int getValue(int x, int y)
        {
            // Get the value at a specific grid cell
            if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
                return grid[x][y];
            }
            return 0;  // Invalid cell coordinates
        }

        void draw(sf::RenderWindow& window) 
        {
            // Draw the grid on the SFML window
            for (int i = 0; i < gridSizeX; ++i) {
                for (int j = 0; j < gridSizeY; ++j) {
                    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));

                    // Set cell position based on grid indices and cell size
                    cell.setPosition(i * cellSize, j * cellSize);

                    // Set cell color based on grid value
                    if (grid[i][j] == 1) {
                        cell.setFillColor(sf::Color::White);
                    }
                    else if (grid[i][j] == 0) {
                        cell.setFillColor(sf::Color::Black);
                        cell.setOutlineColor(sf::Color(225, 234, 247));
                        cell.setOutlineThickness(1.0);
                    }

                    // Draw the cell on the window
                    window.draw(cell);
                }
            }
        }
};