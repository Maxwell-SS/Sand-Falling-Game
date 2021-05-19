#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Cell.hpp"
#include "Common.hpp"

Cell::Cell(int cellSize, int width, int height) {
	this->cellSize = cellSize;
	this->width = width;
	this->height = height;
}

void Cell::InitGrid() {
	cellVertices.setPrimitiveType(sf::Quads);
	cellVertices.resize(width * height * 4);

    grid = new int *[width];
    updateGrid = new bool *[width];
    for(int i = 0; i < width; i++) {
        grid[i] = new int [height];
        updateGrid[i] = new bool [height];
    }
	
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y)
        {
			grid[x][y] = 0;
			updateGrid[x][y] = false;
			
            sf::Vertex* quad = &cellVertices[(x + y * width) * 4];

            quad[0].position = sf::Vector2f(x * cellSize, y * cellSize);
            quad[1].position = sf::Vector2f((x + 1) * cellSize, y * cellSize);
            quad[2].position = sf::Vector2f((x + 1) * cellSize, (y + 1) * cellSize);
            quad[3].position = sf::Vector2f(x * cellSize, (y + 1) * cellSize);
        }
    }
}

void Cell::ColorGrid() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y)
        {
            sf::Vertex* quad = &cellVertices[(x + y * width) * 4];
			
            quad[0].color = cellColors[grid[x][y]];
            quad[1].color = cellColors[grid[x][y]];
            quad[2].color = cellColors[grid[x][y]];
            quad[3].color = cellColors[grid[x][y]];
        }
    }
}

void Cell::ResetUpdateGrid() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            updateGrid[x][y] = false;
        }
    }
}

void Cell::ChangeGrid(int x, int y, int state) {
    grid[x][y] = state;
}
void Cell::ChangeUpdateGrid(int x, int y, bool state) {
    updateGrid[x][y] = state;
}

bool Cell::ReturnUpdateGrid(int x, int y) {
    return updateGrid[x][y];
}
int Cell::ReturnGrid(int x, int y) {
    return grid[x][y];
}

void Cell::AddGravity(int x, int y, int cellNumber, int gravity) {
	ChangeUpdateGrid(x, y + gravity, true);
	ChangeGrid(x, y + gravity, cellNumber);
	ChangeGrid(x, y, 0);
}

void Cell::SwapCells(int xOne, int yOne, int xTwo, int yTwo) {
    int one = grid[xOne][yOne];
    int two = grid[xTwo][yTwo];

    grid[xOne][yOne] = two;
    grid[xTwo][yTwo] = one;
}

void Cell::UpdateSand(int x, int y) {
	if (y == height - 1 || x == width - 1 || x == 1) {
		ChangeGrid(x, y, 1);
	} 
	else if (ReturnGrid(x, y + 1) == 1 || ReturnGrid(x, y + 1) == 3 || ReturnGrid(x, y + 1) == 4) {
		if (ReturnGrid(x - 1, y + 1) == 0 && ReturnGrid(x + 1, y + 1) == 0){
			ChangeGrid(x, y, 0);
	
			if (y % 2 == 0) {
				ChangeGrid(x - 1, y + 1, 1);
				ChangeUpdateGrid(x - 1, y + 1, true);
			} else {
				ChangeGrid(x + 1, y + 1, 1);
				ChangeUpdateGrid(x + 1, y + 1, true);
			}
		}
		else if (ReturnGrid(x - 1, y + 1) == 0) {
			ChangeGrid(x, y, 0);

            if (ReturnGrid(x + 1, y + 1) == 1 || ReturnGrid(x + 1, y + 1) == 3 || ReturnGrid(x + 1, y + 1) == 4) {
                ChangeGrid(x - 1, y + 1, 1);
                ChangeUpdateGrid(x - 1, y + 1, true);
            }
		}
		else if (ReturnGrid(x + 1, y + 1) == 0) {
            ChangeGrid(x, y, 0);

            if (ReturnGrid(x - 1, y + 1) == 1 || ReturnGrid(x - 1, y + 1) == 3 || ReturnGrid(x - 1, y + 1) == 4) {
                ChangeGrid(x + 1, y + 1, 1);
                ChangeUpdateGrid(x + 1, y + 1, true);
            } 
		}
		else {
			ChangeGrid(x, y, 1);
			ChangeUpdateGrid(x, y, true);
		}
	}
	else {
		AddGravity(x, y, 1, 1);
	}
}

void Cell::UpdateWater(int x, int y) {
    if (y == height - 1 || x == width - 1 || x == 1) {
        ChangeGrid(x, y, 2);
    } 
	else if (ReturnGrid(x, y + 1) == 1 || ReturnGrid(x, y + 1) == 2 || ReturnGrid(x, y + 1) == 3 || ReturnGrid(x, y + 1) == 4) {
        ChangeGrid(x, y, 0);

        if (ReturnGrid(x - 1, y) == 0 && ReturnGrid(x + 1, y) == 0){
            ChangeGrid(x, y, 0);
    
            if (y % 2 == 0) {
                ChangeGrid(x - 1, y, 2);
                ChangeUpdateGrid(x - 1, y, true);
            } else {
                ChangeGrid(x + 1, y, 2);
                ChangeUpdateGrid(x + 1, y, true);
            }
        }

        else if (ReturnGrid(x - 1, y) == 0) {
            ChangeGrid(x, y, 0);

            if (ReturnGrid(x + 1, y) == 1 || ReturnGrid(x + 1, y) == 2 || ReturnGrid(x + 1, y) == 3 || ReturnGrid(x + 1, y) == 4) {
                ChangeGrid(x - 1, y, 2);
                ChangeUpdateGrid(x - 1, y, true);
            }
        }

        else if (ReturnGrid(x + 1, y) == 0) {
            ChangeGrid(x, y, 0);

            if (ReturnGrid(x - 1, y) == 1 || ReturnGrid(x - 1, y) == 2 || ReturnGrid(x - 1, y) == 3 || ReturnGrid(x - 1, y) == 4) {
                ChangeGrid(x + 1, y, 2);
                ChangeUpdateGrid(x + 1, y, true);
            }
        }

        else if (ReturnGrid(x - 1, y + 1) == 0 && ReturnGrid(x + 1, y + 1) == 0){
            ChangeGrid(x, y, 0);
    
            if (y % 2 == 0) {
                ChangeGrid(x - 1, y + 1, 2);
                ChangeUpdateGrid(x - 1, y + 1, true);
            } else {
                ChangeGrid(x + 1, y + 1, 2);
                ChangeUpdateGrid(x + 1, y + 1, true);
            }
        }

        else if (ReturnGrid(x - 1, y + 1) == 0) {
            ChangeGrid(x, y, 0);

            if (ReturnGrid(x + 1, y + 1) == 1 || ReturnGrid(x + 1, y + 1) == 2 || ReturnGrid(x + 1, y + 1) == 3 || ReturnGrid(x + 1, y + 1) == 4) {
                ChangeGrid(x - 1, y + 1, 2);
                ChangeUpdateGrid(x - 1, y + 1, true);
            }
        }

        else if (ReturnGrid(x + 1, y + 1) == 0) {
            ChangeGrid(x, y, 0);

            if (ReturnGrid(x - 1, y + 1) == 1 || ReturnGrid(x - 1, y + 1) == 2 || ReturnGrid(x - 1, y + 1) == 3 || ReturnGrid(x - 1, y + 1) == 4) {
                ChangeGrid(x + 1, y + 1, 2);
                ChangeUpdateGrid(x + 1, y + 1, true);
            }
        }

        else {
            ChangeGrid(x, y, 2);
        }
    }
	else {
		AddGravity(x, y, 2, 1);
	}
}

void Cell::UpdateStone(int x, int y) {
    if (y == height - 1 || x == width - 1 || x == 1) {
        ChangeGrid(x, y, 3);
    } 
    else if (ReturnGrid(x, y + 1) == 1 || ReturnGrid(x, y + 1) == 3 || ReturnGrid(x, y + 1) == 4) {
        ChangeGrid(x, y, 3);
    }
    else {
        AddGravity(x, y, 3, 1);
    }
}

void Cell::UpdateWall(int x, int y) {
	ChangeGrid(x, y, 4);
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = NULL;
    target.draw(cellVertices, states);
}