#include <SFML/Graphics.hpp>
#include <iostream>

#include "Cell.hpp"
#include "UI.hpp"
#include "Common.hpp"

int windowWidth = 1280, windowHeight = 720;

int cellSize = 3, brushSize = 5, selectedCell = 0;

int gridWidth = windowWidth / cellSize;
int gridHeight = windowHeight / cellSize;

sf::Color cellColors[] = 
{
sf::Color(0, 0, 0), sf::Color(232,201,100), sf::Color(28,163,236),
sf::Color(136,140,141), sf::Color(70, 71, 62), sf::Color(240,127,19)
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "");
	window.setFramerateLimit(60);
	
	Cell cell(cellSize, gridWidth, gridHeight);
	cell.InitGrid();
	
	UI ui(gridWidth, gridHeight);
	ui.InitButtons(1, 6);
	ui.DrawButtons(windowWidth - 40, (windowHeight - windowHeight) + 10, 30, 30, 40);
	
		
	sf::Clock clock;
	while (window.isOpen())
	{
		double deltaTime = clock.restart().asSeconds();
		int fps = 1.f / deltaTime;
		window.setTitle("FPS: " + std::to_string(fps));
		
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
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i localMousePosition = sf::Mouse::getPosition(window);
			
			if (ui.ButtonClicked(localMousePosition) == false) {
				int xPos = localMousePosition.x / cellSize;
				int yPos = localMousePosition.y / cellSize;

				if (xPos > 0 && xPos < gridWidth - 1 && yPos > 0 && yPos < gridHeight - 1) {
					for (int x = 0; x < brushSize; ++x) {
						for (int y = 0; y < brushSize; ++y) {
							if (xPos - brushSize > 0 && xPos + brushSize < gridWidth - 1 && yPos - brushSize > 0 && yPos + brushSize < gridHeight - 1) {
								cell.ChangeGrid(xPos + x, yPos + y, selectedCell);
								cell.ChangeGrid(xPos - x, yPos - y, selectedCell);
								cell.ChangeGrid(xPos - x, yPos + y, selectedCell);
								cell.ChangeGrid(xPos + x, yPos - y, selectedCell);
							} 
							else {
								if (xPos - x > 0 && yPos - y > 0) {
									cell.ChangeGrid(xPos - x, yPos - y, selectedCell);
								}
								if (xPos + x < gridWidth - 1 && yPos + y < gridHeight - 1) {
									cell.ChangeGrid(xPos + x, yPos + y, selectedCell);
								}

								if (xPos - x > 0 && yPos + y < gridHeight - 1) {
									cell.ChangeGrid(xPos - x, yPos + y, selectedCell);
								}
								if (xPos + x < gridWidth - 1 && yPos - y > 0) {
									cell.ChangeGrid(xPos + x, yPos - y, selectedCell);
								}
							}
						}
					}
				}
			}
		}

		for (int x = 0; x < gridWidth; ++x) {
			for (int y = 0; y < gridHeight; ++y) {
				if (cell.ReturnGrid(x, y) == 1 && cell.ReturnUpdateGrid(x, y) == false) {
					cell.UpdateSand(x, y);
				}
				else if (cell.ReturnGrid(x, y) == 2 && cell.ReturnUpdateGrid(x, y) == false) {
					cell.UpdateWater(x, y);
				}
				else if (cell.ReturnGrid(x, y) == 3 && cell.ReturnUpdateGrid(x, y) == false) {
					cell.UpdateStone(x, y);
				} 
				else if (cell.ReturnGrid(x, y) == 4 && cell.ReturnUpdateGrid(x, y) == false) {
					cell.UpdateWall(x, y);
				}
				else if (cell.ReturnGrid(x, y) == 5 && cell.ReturnUpdateGrid(x, y) == false) {
					//cell.UpdateFire(x, y);
				}
			}
		}

		cell.ResetUpdateGrid();

		window.clear();

		cell.ColorGrid();
		window.draw(cell);
		
		window.draw(ui);

		window.display();
	}
	return 0;
}
