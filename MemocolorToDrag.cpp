#include "MemocolorToDrag.h"

MemocolorToDrag::MemocolorToDrag(Color k, int x, int y,
		sf::RenderWindow &window) :
		Memocolor(k) {
	this->window = &window;

	dragged = false;
	alreadyUsed = false;
	draggedAgain = false;

	// Major rectangle
	rect.setPosition(x, y);

	// Set a shade and border
	shade.setPosition(x, y);
	shade.setSize(sf::Vector2f(60, 60));
	shade.setFillColor(sf::Color(40, 40, 40));
	border.setPosition(x - 2, y - 2);
	border.setSize(sf::Vector2f(60, 60));
	border.setFillColor(sf::Color(0, 0, 0));
}

void MemocolorToDrag::update(bool & ifHandlerIdle, Color & currentColor) {
	sf::Vector2i m_pos = sf::Mouse::getPosition(*window);

	// Check click on non-dragged MemocolorToDrag
	if (ifHandlerIdle) {
		if (!dragged) {
			if (m_pos.x > rect.getGlobalBounds().left - 8
					&& m_pos.y > rect.getGlobalBounds().top - 7
					&& m_pos.x
							< rect.getGlobalBounds().left
									+ rect.getGlobalBounds().width + 8
					&& m_pos.y
							< rect.getGlobalBounds().top
									+ rect.getGlobalBounds().height + 7) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					// Get pos of mouse and flag memocolor as dragged
					mousePosDiff = m_pos
							- static_cast<sf::Vector2i>(rect.getPosition());
					dragged = true;
					if (alreadyUsed)
						draggedAgain = true;
				}
			}
		}
	}
	// Turn off draggin if mouseup
	if (dragged && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		currentColor = color;
		dragged = false;
		draggedAgain = false;
		rect.setPosition(shade.getPosition());
	} // Update current position of mouse on dragged memocolor
	if (dragged) {
		rect.setPosition(static_cast<sf::Vector2f>(m_pos - mousePosDiff));
		ifHandlerIdle = false;
	}

}

void MemocolorToDrag::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
	target.draw(border);
	target.draw(shade);
	if (!alreadyUsed || draggedAgain)
		target.draw(rect);
}

MemocolorToDrag::~MemocolorToDrag() {
}
