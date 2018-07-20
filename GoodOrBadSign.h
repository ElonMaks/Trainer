/*
 * GoodOrBadSign.h
 *
 *  Created on: 22 cze 2018
 *      Author: maks
 */

#ifndef GOODORBADSIGN_H_
#define GOODORBADSIGN_H_

#include <SFML/Graphics.hpp>

class GoodOrBadSign: public sf::Drawable {
public:
	enum WhatSign {
		GOOD, BAD
	};

	GoodOrBadSign(WhatSign whatSign, sf::Vector2f pos);
	virtual ~GoodOrBadSign();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
//	WhatSign whatSign;

	sf::Texture goodChoiceTex;
	sf::Texture badChoiceTex;

	sf::Sprite sprite;

};

#endif /* GOODORBADSIGN_H_ */
