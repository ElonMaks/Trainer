#include "Button.h"

Button::Button(sf::RenderWindow &window, int x, int y, int w, int h) {

	this->setPosition(x, y);
	this->setSize(sf::Vector2f(w, h));
	this->setFillColor(sf::Color(129, 129, 129));

	this->window = &window;

	pressed = false;
}

Button::~Button() {
}

void Button::update() {
	// Resseting pressed boolean
	pressed = false;

	localPosition = sf::Mouse::getPosition(*window);

	if (localPosition.x > getGlobalBounds().left
			&& localPosition.y > getGlobalBounds().top
			&& localPosition.x
					< getGlobalBounds().left + getGlobalBounds().width
			&& localPosition.y
					< getGlobalBounds().top + getGlobalBounds().height) {
		// Mouse hover
		setFillColor(sf::Color(199, 199, 199));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// Click
			pressed = true;
		}
	} else {
		setFillColor(sf::Color(129, 129, 129));
	}
}

bool Button::isPressed() {
	return pressed;
}
