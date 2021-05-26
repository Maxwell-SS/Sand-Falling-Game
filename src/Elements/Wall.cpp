#include <SFML/Graphics.hpp>

#include "Elements.hpp"

Elements::Cell wall;

void Elements::InitWall() {
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
