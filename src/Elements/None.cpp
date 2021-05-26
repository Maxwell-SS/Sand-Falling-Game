#include <SFML/Graphics.hpp>

#include "Elements.hpp"

Elements::Cell none;

void Elements::InitNone() {
	none.cellNumber = 0;
	none.gravity = 0;

	none.buoyancy = 0;
	none.flammability = 0;

	none.isSolid = false;
	none.isLiquid = false;
	none.isGas = false;

	none.color = sf::Color(0,0,0);

	CellArray[none.cellNumber] = none;
}