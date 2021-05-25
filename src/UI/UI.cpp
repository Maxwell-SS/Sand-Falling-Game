#include <SFML/Graphics.hpp>

#include "UI/UI.hpp"
#include "Common.hpp"

UI::UI(int ScreenWidth, int ScreenHeight) {
	this->ScreenWidth = ScreenWidth;
	this->ScreenHeight = ScreenHeight;
}

void UI::InitButtons(int ButtonArrayWidth, int ButtonArrayHeight) {
	this->ButtonArrayWidth = ButtonArrayWidth;
	this->ButtonArrayHeight = ButtonArrayHeight;
	
	UIelements.setPrimitiveType(sf::Quads);
	UIelements.resize(ButtonArrayWidth * ButtonArrayHeight * 4);
}

void UI::DrawButtons(int xPos, int yPos, float btnWidth, float btnHeight, int offset) {
	for (int x = 0; x < ButtonArrayWidth; ++x) {
		for (int y = 0; y < ButtonArrayHeight; ++y) {
			sf::Vertex* quad = &UIelements[(x + y * ButtonArrayWidth) * 4];
	
			quad[0].position = sf::Vector2f((xPos + (x * offset)), yPos + (y * offset));
			quad[1].position = sf::Vector2f((xPos + (x * offset)) + btnWidth, yPos + (y * offset));
			quad[2].position = sf::Vector2f((xPos + (x * offset)) + btnWidth, yPos + (y * offset) + btnHeight);
			quad[3].position = sf::Vector2f((xPos + (x * offset)), yPos + (y * offset) + btnHeight);

			if (y == 0) {
				// Eraser Color
				quad[0].color = sf::Color(226, 174, 180);
				quad[1].color = sf::Color(226, 174, 180);
				quad[2].color = sf::Color(226, 174, 180);
				quad[3].color = sf::Color(226, 174, 180);
			} else {
				quad[0].color = sf::Color(cellColors[y]);
				quad[1].color = sf::Color(cellColors[y]);
				quad[2].color = sf::Color(cellColors[y]);
				quad[3].color = sf::Color(cellColors[y]);
			}
		}
	}
}

bool UI::ButtonClicked(sf::Vector2i mousePosition) {
	for(int i = 0; i < UIelements.getVertexCount(); i += 4) {
		sf::Vector2f TopLeft = getTransform().transformPoint(UIelements[i].position);
		sf::Vector2f TopRight = getTransform().transformPoint(UIelements[i + 1].position);
		sf::Vector2f BottomRight = getTransform().transformPoint(UIelements[i + 2].position);
		sf::Vector2f BottomLeft = getTransform().transformPoint(UIelements[i + 3].position);
		
		if (mousePosition.x > TopLeft.x && mousePosition.x < TopRight.x && mousePosition.y > TopLeft.y && mousePosition.y < BottomRight.y) {
			selectedCell = i / 4;
			return true;
		} 
	}
	return false;
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = NULL;
	target.draw(UIelements, states);
}