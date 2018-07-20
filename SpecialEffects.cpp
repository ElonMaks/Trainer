#include "SpecialEffects.h"

SpecialEffects::SpecialEffects(sf::Vector2f size, bool startDarken) {
	rect.setSize(size);
	rect.setFillColor(sf::Color(0, 0, 0, 0));

	effect = NONE;

	if (startDarken)
		alpha = 255;
	else
		alpha = 0;
}

void SpecialEffects::darken(int time) {
	fullTime = time;

	effect = DARKEN;
	threshold = 255;
	effectClk.restart();
}

void SpecialEffects::brighten(int time) {
	fullTime = time;

	effect = BRIGHTEN;
	threshold = 0;
	effectClk.restart();
}

void SpecialEffects::update() {
	switch (effect) {
	case DARKEN: {
		alpha = effectClk.getElapsedTime().asMilliseconds()
				/ static_cast<float>(fullTime) * 255;

		if (alpha >= threshold) {
			effect = NONE;
			alpha = threshold;
		}
	}
		break;
	case BRIGHTEN: {
		alpha = 255
				- effectClk.getElapsedTime().asMilliseconds()
						/ static_cast<float>(fullTime) * 255;

		if (alpha <= threshold) {
			effect = NONE;
			alpha = threshold;
		}
	}
		break;
	}

	rect.setFillColor(sf::Color(0, 0, 0, alpha));

}

void SpecialEffects::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
	target.draw(rect);
}

SpecialEffects::~SpecialEffects() {
}
