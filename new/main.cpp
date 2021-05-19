#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system

class Sand : public sf::Drawable, public sf::Transformable
{
public:
	Sand(sf::Vector2u tileSize, unsigned int width, unsigned int height) {
		this->tileSize = tileSize;
		this->width = width;
		this->height = height;
	}
	
	void InitGrid(int **tiles) {
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);
		
        for (unsigned int i = 0; i < width; ++i) {
            for (unsigned int j = 0; j < height; ++j)
            {
                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            }
        }
	}
	
    void UpdateGrid(int **tiles)
    {
        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i) {
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i][j];

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                if (tiles[i][j] == 0) {
                    quad[0].color = sf::Color::Black;
                    quad[1].color = sf::Color::Black;
                    quad[2].color = sf::Color::Black;
                    quad[3].color = sf::Color::Black;
                } else if (tiles[i][j] == 1) {
                    quad[0].color = sf::Color(232,201,100);
                    quad[1].color = sf::Color(232,201,100);
                    quad[2].color = sf::Color(232,201,100);
                    quad[3].color = sf::Color(232,201,100);
                } else if (tiles[i][j] == 2) {
                    quad[0].color = sf::Color(28,163,236);
                    quad[1].color = sf::Color(28,163,236);
                    quad[2].color = sf::Color(28,163,236);
                    quad[3].color = sf::Color(28,163,236);
                } else if (tiles[i][j] == 9) {
                    quad[0].color = sf::Color(192,192,192);
                    quad[1].color = sf::Color(192,192,192);
                    quad[2].color = sf::Color(192,192,192);
                    quad[3].color = sf::Color(192,192,192);
                }
            }
        }
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(m_vertices, states);
    }
	
	sf::Vector2u tileSize;
	unsigned int width, height;
	
    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};

// ------------------------------------------------------------------------

int main()
{
	int SAND = 1, WATER = 2, WALL = 9;
	bool isSand = true, isWater = false, isWall = false;

	int windowWidth = 1280, windowHeight = 720;
	int brushWidth = 2, brushHeight = 2;
	int gridWidth, gridHeight;

	int shapeSize = 9;

	bool isLeft = true;
	
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sand!!!");
	window.setFramerateLimit(60); 

    gridWidth = windowWidth / shapeSize;
    gridHeight = windowHeight / shapeSize;
	
	int **grid;
	grid = new int *[gridWidth];
	for(int i = 0; i <gridWidth; i++)
	    grid[i] = new int[gridHeight];
	
	bool **updateGrid;
	updateGrid = new bool *[gridWidth];
	for(int i = 0; i <gridWidth; i++)
	    updateGrid[i] = new bool[gridHeight];
	
	for (int x = 0; x < gridWidth; ++x) {
		for (int y = 0; y < gridHeight; ++y) {
			grid[x][y] = 0;
			updateGrid[x][y] = false;
		}
	}

    std::vector<std::vector<int> > sandPixel(gridWidth, std::vector<int>(gridHeight));

    Sand sand(sf::Vector2u(shapeSize, shapeSize), gridWidth, gridHeight);
	sand.InitGrid(grid);

    sf::Clock clock;
    while (window.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        int fps = 1.f / currentTime;
        window.setTitle("FPS: " + std::to_string(fps));
		
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i localMousePosition = sf::Mouse::getPosition(window);
            int xPos = localMousePosition.x / shapeSize;
            int yPos = localMousePosition.y / shapeSize;
			
			if (xPos >= 0 && yPos >= 0 && xPos <= windowWidth && yPos <= windowHeight) {
				for (int x = 0; x < brushWidth; ++x) {
					for (int y = 0; y < brushHeight; ++y) {
						if (x % 2 == 1 && y % 2 == 1) {
							if (isSand) {
								grid[xPos + x][yPos + y] = SAND;
								grid[xPos - x][yPos - y] = SAND;
							} else if (isWater) {
								grid[xPos][yPos] = WATER;
								grid[xPos][yPos] = WATER;
							} else if (isWall) {
								grid[xPos][yPos] = WALL;
								grid[xPos][yPos] = WALL;
							}
						}
					}
				}
			}
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        	isSand = true;
        	isWater = false;
        	isWall = false;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        	isSand = false;
        	isWater = true;
        	isWall = false;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
        	isSand = false;
        	isWater = false;
        	isWall = true;
        }
		
		for (int x = 0; x < gridWidth; ++x) {
			for (int y = 0; y < gridHeight; ++y) {
				
				if (grid[x][y] == 1 && updateGrid[x][y] == false)
				{
					if (y == gridHeight - 1 || x == gridWidth - 1 || x == 1) {
						grid[x][y] = 1;
						updateGrid[x][y] = true;
					}
					else if (grid[x][y + 1] == 1 || grid[x][y + 1] == 9) {
						if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 0){
							grid[x][y] = 0;
							if (y % 2 == 0) {
								grid[x - 1][y + 1] = 1;
								updateGrid[x - 1][y + 1] = true;
							} else {
								grid[x + 1][y + 1] = 1;
								updateGrid[x + 1][y + 1] = true;
							}
						}
						else if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 1) {
							grid[x][y] = 0;
							grid[x - 1][y + 1] = 1;
							updateGrid[x - 1][y + 1] = true;
						} 
						else if (grid[x + 1][y + 1] == 0 && grid[x - 1][y + 1] == 1) {
							grid[x][y] = 0;
							grid[x + 1][y + 1] = 1;
							updateGrid[x + 1][y + 1] = true;
						} 
						else {
							grid[x][y] = 1;
							updateGrid[x][y] = true;
						}
					} 
					
					else {
						updateGrid[x][y + 1] = true;
						grid[x][y + 1] = 1;
						grid[x][y] = 0;
					}					
				}

				else if (grid[x][y] == 2 && updateGrid[x][y] == false) 
				{
					if (y == gridHeight - 1 || x == gridWidth - 1 || x == 1) {
						grid[x][y] = 2;
					}
					else if (grid[x][y + 1] == 1 || grid[x][y + 1] == 2) {
						if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 0){
							grid[x][y] = 0;
							if (y % 2 == 0) {
								grid[x - 1][y + 1] = 2;
								updateGrid[x - 1][y + 1] = true;
							} else {
								grid[x + 1][y + 1] = 2;
								updateGrid[x + 1][y + 1] = true;
							}
						}
						else if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 2) {
							grid[x][y] = 0;
							grid[x - 1][y + 1] = 2;
							updateGrid[x - 1][y + 1] = true;
						} 
						else if (grid[x + 1][y + 1] == 0 && grid[x - 1][y + 1] == 2) {
							grid[x][y] = 0;
							grid[x + 1][y + 1] = 2;
							updateGrid[x + 1][y + 1] = true;
						} 
						else {
							grid[x][y] = 2;
							updateGrid[x][y] = true;
						}
					} 
					
					else {
						updateGrid[x][y + 1] = true;
						grid[x][y + 1] = 2;
						grid[x][y] = 0;
					}
				}

				else if (grid[x][y] == 9)
				{
					grid[x][y] = 9;
				}
			}
		}
		
		for (int x = 0; x < gridWidth; ++x) {
			for (int y = 0; y < gridHeight; ++y) {
				updateGrid[x][y] = false;
			}
		}

        window.clear();

        sand.UpdateGrid(grid);
        window.draw(sand);

        window.display();
    }

    return 0;
}
