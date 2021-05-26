#include <SFML/Graphics.hpp>
#include <iostream>

#include "Elements.hpp"
#include "UI/UI.hpp"
#include "Common.hpp"

int windowWidth = 1280, windowHeight = 720;

int cellSize = 3, brushSize = 5, selectedCell = 0, numberOfElements = 5;

int gridWidth = windowWidth / cellSize;
int gridHeight = windowHeight / cellSize;

sf::Color cellColors[] = 
{
sf::Color(0, 0, 0), sf::Color(232,201,100), sf::Color(28,163,236),
sf::Color(136,140,141), sf::Color(70, 71, 62)
};

int main()
{
	// SFML Window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "");
	window.setFramerateLimit(60);

	// Defining elements and initializing the grid
	Elements elements(cellSize, gridWidth, gridHeight);
	elements.InitGrid();
	
	// Defining the UI
	UI ui(gridWidth, gridHeight);
	// The UI works like a grid 
	ui.InitButtons(1, 5);
	ui.DrawButtons(windowWidth - 40, (windowHeight - windowHeight) + 10, 30, 30, 40);
	
	// Initializing all of the elements
	elements.InitNone();
	elements.InitSand();
	elements.InitWater();
	elements.InitStone();
	elements.InitWall();

	// Sorting cells into different arrays
	elements.SortCells();
	
	// Clock to get delta time
	sf::Clock clock;
	while (window.isOpen())
	{
		// Getting deltatime and converting it into fps
		double deltaTime = clock.restart().asSeconds();
		int fps = 1.f / deltaTime;
		window.setTitle("FPS: " + std::to_string(fps));

		// Handing window closing and mouse wheel inputs
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::MouseWheelMoved) {
				if (brushSize > 2) {
					brushSize = brushSize + event.mouseWheel.delta;
				} else {
					brushSize = brushSize + 1;
				}
				std::cout << brushSize << '\n';
			}
		}
		
		// Drawing whichever cell is selected
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i localMousePosition = sf::Mouse::getPosition(window);
			
			if (ui.ButtonClicked(localMousePosition) == false) {
				int xPos = localMousePosition.x / cellSize;
				int yPos = localMousePosition.y / cellSize;

				if (xPos > 0 && xPos < gridWidth - 1 && yPos > 0 && yPos < gridHeight - 1) {
					for (int x = 0; x < brushSize; ++x) {
						for (int y = 0; y < brushSize; ++y) {
							if (xPos - brushSize > 0 && xPos + brushSize < gridWidth - 1 && yPos - brushSize > 0 && yPos + brushSize < gridHeight - 1) {
								elements.grid[xPos + x][yPos + y] = selectedCell;
								elements.grid[xPos - x][yPos - y] = selectedCell;
								elements.grid[xPos - x][yPos + y] = selectedCell;
								elements.grid[xPos + x][yPos - y] = selectedCell;
							} 
							else {
								if (xPos - x > 0 && yPos - y > 0) {
									elements.grid[xPos - x][yPos - y] = selectedCell;
								}
								if (xPos + x < gridWidth - 1 && yPos + y < gridHeight - 1) {
									elements.grid[xPos + x][yPos + y] = selectedCell;
								}

								if (xPos - x > 0 && yPos + y < gridHeight - 1) {
									elements.grid[xPos - x][yPos + y] = selectedCell;
								}
								if (xPos + x < gridWidth - 1 && yPos - y > 0) {
									elements.grid[xPos + x][yPos - y] = selectedCell;
								}
							}
						}
					}
				}
			}
		}

		for (int x = 0; x < gridWidth; ++x) {
			for (int y = 0; y < gridHeight; ++y) {
				if (elements.grid[x][y] == 1 && elements.updateGrid[x][y] == false) {
					elements.UpdateSand(x, y);
				}
				else if (elements.grid[x][y] == 2 && elements.updateGrid[x][y] == false) {
					elements.UpdateWater(x, y);
				}
				else if (elements.grid[x][y] == 3 && elements.updateGrid[x][y] == false) {
					//elements.UpdateStone(x, y);
				} 
				else if (elements.grid[x][y] == 4 && elements.updateGrid[x][y] == false) {
					//elements.UpdateWall(x, y);
				}
			}
		}

		elements.ResetUpdateGrid();

		window.clear(sf::Color::White);

		elements.ColorGrid();
		window.draw(elements);
		
		window.draw(ui);

		window.display();
	}
	return 0;
}
