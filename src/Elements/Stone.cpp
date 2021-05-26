#include <SFML/Graphics.hpp>

#include "Elements.hpp"

Elements::Cell stone;

void Elements::InitStone() {
	stone.cellNumber = 3;
	stone.gravity = 1;

	stone.buoyancy = 0;
	stone.flammability = 0;

	stone.isSolid = true;
	stone.isLiquid = false;
	stone.isGas = false;

	stone.color = sf::Color(136,140,141);

	Elements::CellArray[stone.cellNumber] = stone;
}

void Elements::UpdateStone(int x, int y) {
	// if (y == height - 1 || x == width - 1 || x == 0) {
	// 	ChangeGrid(x, y, 3);
	// } 
	// else if (ReturnGrid(x, y + 1) == 1 || ReturnGrid(x, y + 1) == 3 || ReturnGrid(x, y + 1) == 4) {
	// 	ChangeGrid(x, y, 3);
	// }
	// else {
	// 	AddGravity(x, y, 3, 1);
	// }
}