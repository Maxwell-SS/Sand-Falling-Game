#include <iostream>

#include "Elements.hpp"

void Elements::DefaultSand(Cell cellType, int x, int y) {
	if (y == height - 1 || x == width - 1 || x == 0) {
		grid[x][y] = cellType.cellNumber;
	}
	else if (grid[x][y + 1] == 1) {
		if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 0){
			grid[x][y] = 0;

			if (y % 2 == 0) {
				grid[x - 1][y + 1] = cellType.cellNumber;
				updateGrid[x - 1][y + 1] = true;
			} else {
				grid[x + 1][y + 1] = cellType.cellNumber;
				updateGrid[x + 1][y + 1] = true;
			}
		}
		else if (grid[x - 1][y + 1] == 0) {
			grid[x][y] = 0;

			if (grid[x + 1][y + 1] == 1) {
				grid[x - 1][y + 1] = cellType.cellNumber;
				updateGrid[x - 1][y + 1] = true;
			}
		}
		else if (grid[x + 1][y + 1] == 0) {
			grid[x][y] = 0;

			if (grid[x - 1][y + 1] == 1) {
				grid[x + 1][y + 1] = cellType.cellNumber;
				updateGrid[x + 1][y + 1] = true;
			}
		}
		else {
			grid[x][y] = cellType.cellNumber;
			updateGrid[x][y] = true;
		}
	}
	else {
		AddGravity(x, y, cellType.cellNumber, cellType.gravity);
	}
}

void Elements::DefaultWater(Cell cellType, int x, int y) {
	if (y == height - 1 || x == width - 1 || x == 0) {
		grid[x][y] = cellType.cellNumber;
	} 
	else if (grid[x][y + 1] == 1 || grid[x][y + 1] == 2 || grid[x][y + 1] == 3 || grid[x][y + 1] == 4) {
		grid[x][y] = 0;

		if (grid[x - 1][y] == 0 && grid[x + 1][y] == 0){
			grid[x][y] = 0;

			if (y % 2 == 0) {
				grid[x - 1][y] = cellType.cellNumber;
				updateGrid[x - 1][y] = true;
			} else {
				grid[x + 1][y] = cellType.cellNumber;
				updateGrid[x + 1][y] = true;
			}
		}

		else if (grid[x - 1][y] == 0) {
			grid[x][y] = 0;

			if (grid[x + 1][y] == 1 || grid[x + 1][y] == 2 || grid[x + 1][y] == 3 || grid[x + 1][y] == 4) {
				grid[x - 1][y] = cellType.cellNumber;
				updateGrid[x - 1][y] = true;
			}
		}

		else if (grid[x + 1][y] == 0) {
			grid[x][y] = 0;

			if (grid[x - 1][y] == 1 || grid[x - 1][y] == 2 || grid[x - 1][y] == 3 || grid[x - 1][y] == 4) {
				grid[x + 1][y] = cellType.cellNumber;
				updateGrid[x + 1][y] = true;
			}
		}

		else if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 0){
			grid[x][y] = 0;

			if (y % 2 == 0) {
				grid[x - 1][y + 1] = cellType.cellNumber;
				updateGrid[x - 1][y + 1] = true;
			} else {
				grid[x + 1][y + 1] = cellType.cellNumber;
				updateGrid[x + 1][y + 1] = true;
			}
		}

		else if (grid[x - 1][y + 1] == 0) {
			grid[x][y] = 0;

			if (grid[x + 1][y + 1] == 1 || grid[x + 1][y + 1] == 2 || grid[x + 1][y + 1] == 3 || grid[x + 1][y + 1] == 4) {
				grid[x - 1][y + 1] = cellType.cellNumber;
				updateGrid[x - 1][y + 1] = true;
			}
		}

		else if (grid[x + 1][y + 1] == 0) {
			grid[x][y] = 0;

			if (grid[x - 1][y + 1] == 1 || grid[x - 1][y + 1] == 2 || grid[x - 1][y + 1] == 3 || grid[x - 1][y + 1] == 4) {
				grid[x + 1][y + 1] = cellType.cellNumber;
				updateGrid[x + 1][y + 1] = true;
			}
		}

		else {
			grid[x][y] = cellType.cellNumber;
		}
	}
	else {
		AddGravity(x, y, cellType.cellNumber, 1);
	}	
}

void Elements::DefaultSteam(Cell cellType) {
	
	
}

void Elements::DefaultFire(Cell cellType) {
	
	
}