#include <SFML/Graphics.hpp>

#include "Elements.hpp"

Elements::Elements(int cellSize, int gridWdth, int gridHeight) {
	this->cellSize = cellSize;
	this->width = gridWdth;
	this->height = gridHeight;
}

void Elements::AddGravity(int x, int y, int cellNumber, int gravity) {
	updateGrid[x][y + gravity] = true;
	grid[x][y + gravity] = cellNumber;
	grid[x][y] = 0;
}

void Elements::SwapCells(int xOne, int yOne, int xTwo, int yTwo) {
	int one = grid[xOne][yOne];
	int two = grid[xTwo][yTwo];

	grid[xOne][yOne] = two;
	grid[xTwo][yTwo] = one;
}

void Elements::SortCells() {
	// for (int i = 0; i < numberOfElements; ++i) {
	// 	if (CellArray[i].isSolid) {
	// 		solidCells[i] = CellArray[i];
	// 	}

	// 	else if (CellArray[i].isLiquid) {
	// 		liquidCells[i] = CellArray[i];
	// 	}

	// 	else if (CellArray[i].isGas) {
	// 		gasCells[i] = CellArray[i];
	// 	}
	// }
}

void Elements::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = NULL;
	target.draw(cellVertices, states);
}