#include <SFML/Graphics.hpp>

#include "Elements.hpp"

Elements::Cell sand;

void Elements::InitSand() {
	sand.cellNumber = 1;
	sand.gravity = 1;

	sand.buoyancy = 0;
	sand.flammability = 0;

	sand.isSolid = true;
	sand.isLiquid = false;
	sand.isGas = false;

	sand.color = sf::Color(232,201,100);

	CellArray[sand.cellNumber] = sand;
}

void Elements::UpdateSand(int x, int y) {
	Elements::DefaultSand(sand, x, y);
}