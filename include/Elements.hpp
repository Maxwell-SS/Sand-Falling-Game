#pragma once

#include <SFML/Graphics.hpp>

class Elements : public sf::Drawable, public sf::Transformable
{
public:
	struct Cell
	{
		int cellNumber;

		int gravity;

		int buoyancy;
		int flammability;

		bool isSolid;
		bool isLiquid;
		bool isGas;

		sf::Color color;
	};

public:
	int **grid;
	bool **updateGrid;
	
	int width, height;

	Cell CellArray[100];

public:
	// Misc.cpp
	Elements(int cellSize, int gridWdth, int gridHeight);
	void AddGravity(int x, int y, int cellNumber, int gravity);
	void SwapCells(int xOne, int yOne, int xTwo, int yTwo);

	// Start Grid.cpp
	void InitGrid();
	void ColorGrid();

	void ResetUpdateGrid();
	// End Grid.cpp
	
	// Start Logic.cpp
	void DefaultSand(Cell cellType);
	void DefaultWater(Cell cellType);
	void DefaultSteam(Cell cellType);
	void DefaultFire(Cell cellType);
	// End Logic.cpp

	// Sand.cpp
	void InitSand();
	void UpdateSand(int x, int y);

	// Water.cpp
	void InitWater();
	void UpdateWater(int x, int y);

	// Stone.cpp
	void InitStone();
	void UpdateStone(int x, int y);

	//Wall.cpp
	void InitWall();
	void UpdateWall(int x, int y);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	int cellSize;
	
	sf::VertexArray cellVertices;
};