#include <SFML/Graphics.hpp>
#include <iostream>

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
	gas = 0;
	liquid = 0;
	solid = 0;
	
	int gasTwo = 0;
	int liquidTwo = 0;
	int solidTwo = 0;
	
	for (int i = 0; i < numberOfElements; ++i) {
		
		std::cout << CellArray[i].cellNumber << std::endl;
		
		if (CellArray[i].isSolid) {
			solid += 1;
		}

		if (CellArray[i].isLiquid) {
			liquid += 1;
		}

		if (CellArray[i].isGas) {
			gas += 1;
		}
	}
	
	solidCells = new Cell[solid];
	liquidCells = new Cell[liquid];
	gasCells = new Cell[gas];
	
	for (int i = 0; i < numberOfElements; ++i) {		
		if (CellArray[i].isSolid) {
			solidCells[solidTwo] = CellArray[i];
			solidTwo += 1;
		}

		else if (CellArray[i].isLiquid) {
			liquidCells[liquidTwo] = CellArray[i];
			liquidTwo += 1;
		}

		else if (CellArray[i].isGas) {
			gasCells[gasTwo] = CellArray[i];
			gasTwo += 1;
		}
	}
}

void Elements::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = NULL;
	target.draw(cellVertices, states);
}