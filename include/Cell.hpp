#pragma once

#include <SFML/Graphics.hpp>

class Cell : public sf::Drawable, public sf::Transformable
{
public:
	Cell(int cellSize, int width, int height);
	void InitGrid();
	void ColorGrid();

	void ResetUpdateGrid();

	void ChangeGrid(int x, int y, int state);
	void ChangeUpdateGrid(int x, int y, bool state);

	bool ReturnUpdateGrid(int x, int y);
	int ReturnGrid(int x, int y);
		
	void AddGravity(int x, int y, int cellNumber, int gravity);
	void SwapCells(int xOne, int yOne, int xTwo, int yTwo);
	
	void UpdateSand(int x, int y);
	void UpdateWater(int x, int y);
	void UpdateStone(int x, int y);
	void UpdateWall(int x, int y);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	int width, height, cellSize;

	int **grid;
	bool **updateGrid;
	
	sf::VertexArray cellVertices;
};