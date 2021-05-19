#pragma once

#include <SFML/Graphics.hpp>

class UI : public sf::Drawable, public sf::Transformable
{
public:
	UI(int ScreenWidth, int ScreenHeight);
	
	void InitButtons(int ButtonArrayWidth, int ButtonArrayHeight);
	void DrawButtons(int xPos, int yPos, float btnWidth, float btnHeight, int offset);
	
	bool ButtonClicked(sf::Vector2i mousePosition);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	int ScreenWidth, ScreenHeight;
	int ButtonArrayWidth, ButtonArrayHeight;
	
	sf::VertexArray UIelements;
};