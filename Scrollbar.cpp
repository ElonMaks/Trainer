#include "Scrollbar.h"

Scrollbar::Scrollbar(sf::RenderWindow &window, int x, int y, int width,
		int minValue, int maxValue, int defaultValue) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->value = defaultValue;
	this->minValue = minValue;
	this->maxValue = maxValue;

	this->window = &window;

//	font.loadFromFile("data/PORKYS.ttf");

	arrowLTex.loadFromFile("data/arrowL.png");
	arrowRTex.loadFromFile("data/arrowR.png");
	squareTex.loadFromFile("data/square.png");

	arrowL.setTexture(arrowLTex);
	arrowR.setTexture(arrowRTex);

	scrollRect.setFillColor(sf::Color { 30, 30, 30 });
	square.setTexture(&squareTex);

	arrowL.setPosition(x - 34, y);
	arrowR.setPosition(x + width, y);
	scrollRect.setPosition(x, y);
	scrollRect.setSize(sf::Vector2f(width, 34));
	square.setSize(sf::Vector2f(width/(maxValue-minValue+1), 34));

	clickThreshold = 120;
	clickStored = 0;

	isArrowLPressed = false;
	isArrowRPressed = false;

//	// Text
//	shownValue.setColor(sf::Color::Yellow);
//	shownValue.setFont(font);
//	shownValue.setPosition(x + width / 2, y - 45);
}

void Scrollbar::update() {

	if (clickStored >= clickThreshold) {
		value++;
		clickStored -= clickThreshold;
	} else if (-clickStored > clickThreshold) {
		value--;
		clickStored += clickThreshold;
	}

	localPosition = sf::Mouse::getPosition(*window);

	// Check if left arrow on scrollbar is clicked
	if (localPosition.x > arrowL.getGlobalBounds().left
			&& localPosition.y > arrowL.getGlobalBounds().top
			&& localPosition.x
					< arrowL.getGlobalBounds().left
							+ arrowL.getGlobalBounds().width
			&& localPosition.y
					< arrowL.getGlobalBounds().top
							+ arrowL.getGlobalBounds().height
			&& sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		// Increase value immediate after mouse click
		if (!isArrowLPressed) {
			value--;
			clickStored = 0;
		}

		isArrowLPressed = true;
		clickStored -= delta.getElapsedTime().asMilliseconds();
	} else {
		isArrowLPressed = false;
	}

	// Check if right arrow on scrollbar is clicked
	if (localPosition.x > arrowR.getGlobalBounds().left
			&& localPosition.y > arrowR.getGlobalBounds().top
			&& localPosition.x
					< arrowR.getGlobalBounds().left
							+ arrowR.getGlobalBounds().width
			&& localPosition.y
					< arrowR.getGlobalBounds().top
							+ arrowR.getGlobalBounds().height
			&& sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		// Increase value immediate after mouse click
		if (!isArrowRPressed) {
			value++;
			clickStored = 0;
		}

		isArrowRPressed = true;
		clickStored += delta.getElapsedTime().asMilliseconds();
	} else {
		isArrowRPressed = false;
	}

	delta.restart();

	if (value > maxValue)
		value = maxValue;
	if (value < minValue)
		value = minValue;

	// Update position of square
	square.setPosition(
			(value - minValue) / static_cast<float>(maxValue - minValue + 1) * width
					+ x, y);

	// Set string on current value
//	std::ostringstream ss;
//	ss << value;
//	shownValue.setString(ss.str());
}

int Scrollbar::getValue() {
	return value;
}

void Scrollbar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(arrowL);
	target.draw(arrowR);
	target.draw(scrollRect);
	target.draw(square);

//	target.draw(shownValue);
}

Scrollbar::~Scrollbar() {
}

