#include "HighlightFrame.h"

HighlightFrame::HighlightFrame() {
	line[0].setSize(sf::Vector2f(64, 2));
	line[1].setSize(sf::Vector2f(2, 64));
	line[2].setSize(sf::Vector2f(64, 2));
	line[3].setSize(sf::Vector2f(2, 64));
	setFillColor(sf::Color(0, 0, 0, 0));
}

void HighlightFrame::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
	for (int i = 0; i < 4; i++)
		target.draw(line[i]);
}

void HighlightFrame::setPosition(sf::Vector2f newPos) {
	line[0].setPosition(sf::Vector2f(-2, -2) + newPos);
	line[1].setPosition(sf::Vector2f(-2, -2) + newPos);
	line[2].setPosition(sf::Vector2f(-2, 60) + newPos);
	line[3].setPosition(sf::Vector2f(60, -2) + newPos);
}

void HighlightFrame::setFillColor(sf::Color color) {
	for (int i = 0; i < 4; i++)
		line[i].setFillColor(color);
}

HighlightFrame::~HighlightFrame() {
}

