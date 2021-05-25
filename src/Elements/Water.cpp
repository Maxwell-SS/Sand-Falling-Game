#include <SFML/Graphics.hpp>

#include "Elements.hpp"

Elements::Cell water;

void Elements::InitWater() {
	water.cellNumber = 2;
	water.gravity = 1;

	water.buoyancy = 0;
	water.flammability = 0;

	water.isSolid = false;
	water.isLiquid = true;
	water.isGas = false;

	water.color = sf::Color(28,163,236);

	Elements::CellArray[water.cellNumber] = water;
}

void Elements::UpdateWater(int x, int y) {
	Elements::DefaultSand(water, x, y);
}