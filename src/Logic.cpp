#include <iostream>

#include "Elements.hpp"

void Elements::DefaultSand(Cell cellType) {
	// if (y == height - 1 || x == width - 1 || x == 0) {
// 		grid[x][y] = 1;
// 	}
// 	else if (grid[x][y + 1] == 1 || grid[x][y + 1] == 3 || grid[x][y + 1] == 4) {
// 		if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 0){
// 			grid[x][y] = 0;
//
// 			if (y % 2 == 0) {
// 				grid[x - 1][y + 1] = 1;
// 				updateGrid[x - 1][y + 1] = true;
// 			} else {
// 				grid[x + 1][y + 1] = 1;
// 				updateGrid[x + 1][y + 1] = true;
// 			}
// 		}
// 		else if (grid[x - 1][y + 1] == 0) {
// 			grid[x][y] = 0;
//
// 			if (grid[x + 1][y + 1] == 1 || grid[x + 1][y + 1] == 3 || grid[x + 1][y + 1] == 4) {
// 				grid[x - 1][y + 1] = 1;
// 				updateGrid[x - 1][y + 1] = true;
// 			}
// 		}
// 		else if (grid[x + 1][y + 1] == 0) {
// 			grid[x][y] = 0;
//
// 			if (grid[x - 1][y + 1] == 1 || grid[x - 1][y + 1] == 3 || grid[x - 1][y + 1] == 4) {
// 				grid[x + 1][y + 1] = 1;
// 				updateGrid[x + 1][y + 1] = true;
// 			}
// 		}
// 		else {
// 			grid[x][y] = 1;
// 			updateGrid[x][y] = true;
// 		}
// 	}
// 	else {
// 		AddGravity(x, y, 1, 1);
// 	}
	std::cout << cellType.cellNumber << std::endl;
}

void Elements::DefaultWater(Cell cellType) {
	
	
}

void Elements::DefaultSteam(Cell cellType) {
	
	
}

void Elements::DefaultFire(Cell cellType) {
	
	
}