#include <SFML/Graphics.hpp>

#include "Elements.hpp"

void Elements::InitWater() {
	Elements::Cell water;
	water.cellNumber = 2;
	water.gravity = 1;

	water.buoyancy = 0;
	water.flammability = 0;

	water.isSolid = false;
	water.isLiquid = true;
	water.isGas = false;

	water.color = sf::Color(204, 204, 204);

	Elements::CellArray[water.cellNumber] = water;
}

void Elements::UpdateWater(int x, int y) {
	// if (y == height - 1 || x == width - 1 || x == 0) {
	// 	ChangeGrid(x, y, 2);
	// } 
	// else if (ReturnGrid(x, y + 1) == 1 || ReturnGrid(x, y + 1) == 2 || ReturnGrid(x, y + 1) == 3 || ReturnGrid(x, y + 1) == 4) {
	// 	ChangeGrid(x, y, 0);

	// 	if (ReturnGrid(x - 1, y) == 0 && ReturnGrid(x + 1, y) == 0){
	// 		ChangeGrid(x, y, 0);
	
	// 		if (y % 2 == 0) {
	// 			ChangeGrid(x - 1, y, 2);
	// 			ChangeUpdateGrid(x - 1, y, true);
	// 		} else {
	// 			ChangeGrid(x + 1, y, 2);
	// 			ChangeUpdateGrid(x + 1, y, true);
	// 		}
	// 	}

	// 	else if (ReturnGrid(x - 1, y) == 0) {
	// 		ChangeGrid(x, y, 0);

	// 		if (ReturnGrid(x + 1, y) == 1 || ReturnGrid(x + 1, y) == 2 || ReturnGrid(x + 1, y) == 3 || ReturnGrid(x + 1, y) == 4) {
	// 			ChangeGrid(x - 1, y, 2);
	// 			ChangeUpdateGrid(x - 1, y, true);
	// 		}
	// 	}

	// 	else if (ReturnGrid(x + 1, y) == 0) {
	// 		ChangeGrid(x, y, 0);

	// 		if (ReturnGrid(x - 1, y) == 1 || ReturnGrid(x - 1, y) == 2 || ReturnGrid(x - 1, y) == 3 || ReturnGrid(x - 1, y) == 4) {
	// 			ChangeGrid(x + 1, y, 2);
	// 			ChangeUpdateGrid(x + 1, y, true);
	// 		}
	// 	}

	// 	else if (ReturnGrid(x - 1, y + 1) == 0 && ReturnGrid(x + 1, y + 1) == 0){
	// 		ChangeGrid(x, y, 0);
	
	// 		if (y % 2 == 0) {
	// 			ChangeGrid(x - 1, y + 1, 2);
	// 			ChangeUpdateGrid(x - 1, y + 1, true);
	// 		} else {
	// 			ChangeGrid(x + 1, y + 1, 2);
	// 			ChangeUpdateGrid(x + 1, y + 1, true);
	// 		}
	// 	}

	// 	else if (ReturnGrid(x - 1, y + 1) == 0) {
	// 		ChangeGrid(x, y, 0);

	// 		if (ReturnGrid(x + 1, y + 1) == 1 || ReturnGrid(x + 1, y + 1) == 2 || ReturnGrid(x + 1, y + 1) == 3 || ReturnGrid(x + 1, y + 1) == 4) {
	// 			ChangeGrid(x - 1, y + 1, 2);
	// 			ChangeUpdateGrid(x - 1, y + 1, true);
	// 		}
	// 	}

	// 	else if (ReturnGrid(x + 1, y + 1) == 0) {
	// 		ChangeGrid(x, y, 0);

	// 		if (ReturnGrid(x - 1, y + 1) == 1 || ReturnGrid(x - 1, y + 1) == 2 || ReturnGrid(x - 1, y + 1) == 3 || ReturnGrid(x - 1, y + 1) == 4) {
	// 			ChangeGrid(x + 1, y + 1, 2);
	// 			ChangeUpdateGrid(x + 1, y + 1, true);
	// 		}
	// 	}

	// 	else {
	// 		ChangeGrid(x, y, 2);
	// 	}
	// }
	// else {
	// 	AddGravity(x, y, 2, 1);
	// }
}