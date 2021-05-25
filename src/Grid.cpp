#include <SFML/Graphics.hpp>

#include "Elements.hpp"
#include "Common.hpp"

void Elements::InitGrid() {
	cellVertices.setPrimitiveType(sf::Quads);
	cellVertices.resize(width * height * 4);

	grid = new int *[width];
	updateGrid = new bool *[width];
	for(int i = 0; i < width; i++) {
		grid[i] = new int [height];
		updateGrid[i] = new bool [height];
	}
	
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y)
		{
			grid[x][y] = 0;
			updateGrid[x][y] = false;
			
			sf::Vertex* quad = &cellVertices[(x + y * width) * 4];

			quad[0].position = sf::Vector2f(x * cellSize, y * cellSize);
			quad[1].position = sf::Vector2f((x + 1) * cellSize, y * cellSize);
			quad[2].position = sf::Vector2f((x + 1) * cellSize, (y + 1) * cellSize);
			quad[3].position = sf::Vector2f(x * cellSize, (y + 1) * cellSize);
		}
	}
}

void Elements::ColorGrid() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y)
		{
			sf::Vertex* quad = &cellVertices[(x + y * width) * 4];
			
			quad[0].color = cellColors[grid[x][y]];
			quad[1].color = cellColors[grid[x][y]];
			quad[2].color = cellColors[grid[x][y]];
			quad[3].color = cellColors[grid[x][y]];
		}
	}
}

void Elements::ResetUpdateGrid() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			updateGrid[x][y] = false;
		}
	}
}