#include "GoodOrBadSign.h"

GoodOrBadSign::GoodOrBadSign(WhatSign whatSign, sf::Vector2f pos) {
	goodChoiceTex.loadFromFile("data/good.png");
	badChoiceTex.loadFromFile("data/bad.png");

	switch (whatSign) {
	case GOOD: {
		sprite.setTexture(goodChoiceTex);
	}
		break;
	case BAD: {
		sprite.setTexture(badChoiceTex);
	}
		break;
	}

	sprite.setPosition(pos);
}

void GoodOrBadSign::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(sprite);
}

GoodOrBadSign::~GoodOrBadSign() {
// TODO Auto-generated destructor stub
}

