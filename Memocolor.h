/*
 * Memocolor.h
 *
 *  Created on: 14 mar 2018
 *      Author: maks
 */

#ifndef MEMOCOLOR_H_
#define MEMOCOLOR_H_

#include "Global.h"

#include <SFML/Graphics.hpp>

class Memocolor: public sf::Drawable {
public:
	Memocolor(Color color);

	Color & getColor();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPosition(int x, int y);

	virtual ~Memocolor();
protected:
	Color color;

	// Major rectangle
	sf::RectangleShape rect;

};

#endif /* MEMOCOLOR_H_ */
