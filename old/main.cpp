#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

// 0 = Empty
// 1 = Sand
// 2 = Water

// g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system

int windowWidth = 1280, windowHeight = 720;

int shapeSize = 4;

int gridWidth = windowWidth / shapeSize, gridHeight = windowHeight / shapeSize;

bool isLeft = true;

int numOfSand = 0;


int main()
{
	int grid[gridWidth][gridHeight];
	std::vector<std::vector<sf::RectangleShape> > cells(windowWidth, std::vector<sf::RectangleShape>(windowHeight));

	srand (time(0));
	for (int x = 0; x < gridWidth; ++x){
		for (int y = 0; y < gridHeight; ++y){
			grid[x][y] = 0;

			sf::RectangleShape shape(sf::Vector2f(shapeSize, shapeSize));
			shape.setOrigin(shapeSize / 2, shapeSize / 2);

			shape.setPosition(x * shapeSize + shapeSize, y * shapeSize + shapeSize);

			cells[x][y] = shape;
		}
	}


	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sand Falling Game");
	
	window.setVerticalSyncEnabled(true);

	sf::Clock deltaClock;
	while (window.isOpen())
	{
		double dt = deltaClock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i localMousePosition = sf::Mouse::getPosition(window);
			if (localMousePosition.x >= 0 && localMousePosition.y >= 0) {
				int x = (localMousePosition.x - (shapeSize / 2)) / (shapeSize);
				int y = (localMousePosition.y - (shapeSize / 2)) / (shapeSize);

				if(grid[x][y] == 0){
					grid[x + 1][y] = 1;
					grid[x - 1][y] = 1;
					grid[x][y - 1] = 1;
					
					grid[x + 2][y] = 1;
					grid[x - 2][y] = 1;
					grid[x][y - 2] = 1;
					
					grid[x + 3][y] = 1;
					grid[x - 3][y] = 1;
					grid[x][y - 3] = 1;
					
					numOfSand += 9;
				} else {
					grid[x][y] = 0;
					grid[x + 1][y] = 0;
					grid[x - 1][y] = 0;
					grid[x][y + 1] = 0;
					grid[x][y - 1] = 0;
					
					numOfSand -= 4;
				}
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			sf::Vector2i localMousePosition = sf::Mouse::getPosition(window);
			if (localMousePosition.x >= 0 && localMousePosition.y >= 0) {
				int x = (localMousePosition.x - (shapeSize / 2)) / (shapeSize);
				int y = (localMousePosition.y - (shapeSize / 2)) / (shapeSize);

				if(grid[x][y] == 0){
					grid[x][y] = 2;
					grid[x + 1][y] = 2;
					grid[x - 1][y] = 2;
					grid[x + 2][y] = 2;
					grid[x - 2][y] = 2;
				}
			}
		}

		window.clear(sf::Color::Black);

		for (int x = 0; x < gridWidth; ++x){
			for (int y = 0; y < gridHeight; ++y){
				if (grid[x][y] == 1){
					cells[x][y].setFillColor(sf::Color(214, 184, 86));
				} 
				if (grid[x][y] == 2) {
					cells[x][y].setFillColor(sf::Color(0, 123, 255));
				}

				//Sand
				if (grid[x][y] == 1)
				{
					if (y == gridHeight - 2) {
						grid[x][y] = 1;
					}
					else if (grid[x][y + 1] == 1 || grid[x][y + 1] == 2) {
						if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 0){
							grid[x][y] = 0;
							if (isLeft) {
								grid[x - 1][y + 1] = 1;
							} else {
								grid[x + 1][y + 1] = 1;
							}
							isLeft = !isLeft;
						}
						else if (grid[x - 1][y + 1] == 0 && grid[x + 1][y + 1] == 1) {
							grid[x][y] = 0;
							grid[x - 1][y + 1] = 1;
						} 
						else if (grid[x + 1][y + 1] == 0 && grid[x - 1][y + 1] == 1) {
							grid[x][y] = 0;
							grid[x + 1][y + 1] = 1;
						} 
						else {
							grid[x][y] = 1;
						}
					} 
					
					else {
						grid[x][y] = 0;
						grid[x][y + 1] = 1;
					}
					
					window.draw(cells[x][y]);
				}

				if (grid[x][y] == 2)
				{
					grid[x][y] = 2;
					window.draw(cells[x][y]);
				}
			}
		}
		
		std::cout << numOfSand << std::endl;
		
		int fps = 1.f / dt;
		window.setTitle("FPS: " + std::to_string(fps));

		window.display();
	}
	return 0;
}
