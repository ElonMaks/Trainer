#include "Memocolor.h"

Memocolor::Memocolor(Color color) {
	this->color = color;
	switch (color) {
	case Red: {
		rect.setFillColor(sf::Color(255, 0, 0));
	}
		break;
	case Brown: {
		rect.setFillColor(sf::Color(128, 64, 0));
	}
		break;
	case Orange: {
		rect.setFillColor(sf::Color(255, 128, 0));
	}
		break;
	case Yellow: {
		rect.setFillColor(sf::Color(255, 255, 0));
	}
		break;
	case Green: {
		rect.setFillColor(sf::Color(0, 255, 0));
	}
		break;
	case Teal: {
		rect.setFillColor(sf::Color(0, 128, 64));
	}
		break;
	case Blue: {
		rect.setFillColor(sf::Color(0, 64, 255));
	}
		break;
	case Purple: {
		rect.setFillColor(sf::Color(128, 0, 255));
	}
		break;
	case Pink: {
		rect.setFillColor(sf::Color(255, 0, 255));
	}
		break;
	}
	rect.setSize(sf::Vector2f(60, 60));
}

Color & Memocolor::getColor() {
	return color;
}

void Memocolor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(rect);
}

void Memocolor::setPosition(int x, int y) {
	rect.setPosition(x, y);
}

Memocolor::~Memocolor() {
	// TODO Auto-generated destructor stub
}

