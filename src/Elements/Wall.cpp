#include <SFML/Graphics.hpp>

#include "Elements.hpp"

void Elements::InitWall() {
	Elements::Cell wall;
	wall.cellNumber = 4;
	wall.gravity = 0;

	wall.buoyancy = 0;
	wall.flammability = 0;

	wall.isSolid = true;
	wall.isLiquid = false;
	wall.isGas = false;

	wall.color = sf::Color(204, 204, 204);

	Elements::CellArray[wall.cellNumber] = wall;
}

void Elements::UpdateWall(int x, int y) {
	//ChangeGrid(x, y, 4);
}
