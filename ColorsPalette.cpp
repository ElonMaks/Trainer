#include "ColorsPalette.h"

ColorsPalette::ColorsPalette(int x, int y, sf::RenderWindow &window) {
	active = false;
	bgRect.setPosition(x, y);

	this->window = &window;
}

void ColorsPalette::update(bool & wasClicked) {
	// Suit size to the number of colors
	bgRect.setSize(sf::Vector2f(colors.size() * 90, 80));

	// Set posistion of each color
	for (unsigned int i = 0; i < colors.size(); i++) {
		colors[i]->setPosition(bgRect.getPosition().x + (i+1) * 90 - 75,
				bgRect.getPosition().y + 10);
	}

	// Check mouse events
	sf::Vector2i localPosition;
	localPosition = sf::Mouse::getPosition(*window);

	if (localPosition.x > bgRect.getGlobalBounds().left
			&& localPosition.y > bgRect.getGlobalBounds().top
			&& localPosition.x
					< bgRect.getGlobalBounds().left + bgRect.getGlobalBounds().width
			&& localPosition.y
					< bgRect.getGlobalBounds().top + bgRect.getGlobalBounds().height) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// Click
			wasClicked = true;
		}
	} else {

	}

	if (active)
		bgRect.setFillColor(sf::Color(0, 155, 185));
	else
		bgRect.setFillColor(sf::Color(0, 25, 155));
}

void ColorsPalette::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
	target.draw(bgRect);
	for (unsigned int i = 0; i < colors.size(); i++)
		target.draw(*colors[i]);
}

ColorsPalette::~ColorsPalette() {
	// TODO Auto-generated destructor stub
}
