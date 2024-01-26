#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <conio.h>
#include <chrono>
#include <thread>
#include "grid.cpp"

void printIntro() 
{
    std::cout << "========================================\n";
    std::cout << "       Conway's Game of Life\n";
    std::cout << "========================================\n";
    std::cout << "Created by Mohamed Syaheer Altaf\n\n";
    std::cout << "Hot Keys:\n";
    std::cout << "   i) Left-click to select/deselect grid\n";
    std::cout << "  ii) Spacebar to Pause/Resume simulation\n";
    std::cout << " iii) Escape to quit the simulation\n\n";
    std::cout << "Make sure the shared library is in the working directory: `sfml-graphics`, `sfml-window`, and `sfml-system`\n\n";
    std::cout << "Press any key to continue...\n";
    std::cout << "========================================\n";
}

int game_logic(Grid *g, int current_val, int x, int y, int maxX, int maxY) 
{
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            int wrappedX = (i + maxX)  % maxX;
            int wrappedY = (j + maxY)  % maxY;

            if (i == x && j == y) {
                continue;  // Skip the current cell
            }
            count += g->getValue(wrappedX, wrappedY);
        }
    }

    if (current_val == 1) {
        // Cell is alive
        if (count < 2 || count > 3) {
            return 0;  // Dies due to underpopulation or overpopulation
        } else {
            return 1;  // Survives to the next generation
        }
    } else {
        // Cell is dead
        if (count == 3) {
            return 1;  // Reproduction occurs, cell becomes alive
        } else {
            return 0;  // Stays dead
        }
    }
}

void startGame()
{
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int maxX = desktopMode.width;
    unsigned int maxY = desktopMode.height;
    unsigned int cellSize = 30;

    sf::RenderWindow window(desktopMode, "Game of Life", sf::Style::Fullscreen);
    Grid grid(maxX / cellSize, maxY / cellSize, cellSize);
    std::chrono::duration<double> sleepDuration(0.05); // Set duration to sleep

    // Flags
    bool mouseClicked = false;
    bool isPlay = false;

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::Space) {
                    isPlay = !isPlay;
                }
                if (event.key.code == sf::Keyboard::Delete) {
                    grid.clear();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left && !mouseClicked) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    int value = grid.getValue(mousePos.x / cellSize, mousePos.y / cellSize);
                    grid.setValue(mousePos.x / cellSize, mousePos.y / cellSize, !value);
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouseClicked = false;
                }
            }
        }

        if (isPlay) {
            Grid nextGenGrid = grid;  // Create a copy of the current grid for the next generation
            for (int i = 0; i < maxX / cellSize; i++) {
                for (int j = 0; j < maxY / cellSize; j++) {
                    int current_val = grid.getValue(i, j);
                    int val = game_logic(&grid, current_val, i, j, maxX / cellSize, maxY / cellSize);

                    nextGenGrid.setValue(i, j, val);
                }
            }
            grid = nextGenGrid;  // Update the grid with the next generation
            std::this_thread::sleep_for(sleepDuration);
        }

        window.clear();
        grid.draw(window);
        window.display();
    }
}

int main()
{
    printIntro();
    _getch();
    startGame();
    return 0;
}