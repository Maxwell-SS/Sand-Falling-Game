#include <SFML/Graphics.hpp>

#include "Elements.hpp"

void Elements::InitSand() {
	Elements::Cell sand;
	sand.cellNumber = 1;
	sand.gravity = 1;

	sand.buoyancy = 0;
	sand.flammability = 0;

	sand.isSolid = true;
	sand.isLiquid = false;
	sand.isGas = false;

	sand.color = sf::Color(232,201,100);

	Elements::CellArray[sand.cellNumber] = sand;
}

void Elements::UpdateSand(int x, int y) {
	if (y == height - 1 || x == width - 1 || x == 0) {
		grid[x][y] = 1;
	} 
	else if (grid[x][y + 1] == 1 || grid[x][y + 1] == 3 || grid[x][y + 1] == 4) {
		if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 0){
			grid[x][y] = 0;
	
			if (y % 2 == 0) {
				grid[x - 1][y + 1] = 1;
				updateGrid[x - 1][y + 1] = true;
			} else {
				grid[x + 1][y + 1] = 1;
				updateGrid[x + 1][y + 1] = true;
			}
		}
		else if (grid[x - 1][y + 1] == 0) {
			grid[x][y] = 0;

			if (grid[x + 1][y + 1] == 1 || grid[x + 1][y + 1] == 3 || grid[x + 1][y + 1] == 4) {
				grid[x - 1][y + 1] = 1;
				updateGrid[x - 1][y + 1] = true;
			}
		}
		else if (grid[x + 1][y + 1] == 0) {
			grid[x][y] = 0;

			if (grid[x - 1][y + 1] == 1 || grid[x - 1][y + 1] == 3 || grid[x - 1][y + 1] == 4) {
				grid[x + 1][y + 1] = 1;
				updateGrid[x + 1][y + 1] = true;
			} 
		}
		else {
			grid[x][y] = 1;
			updateGrid[x][y] = true;
		}
	}
	else {
		AddGravity(x, y, 1, 1);
	}
}