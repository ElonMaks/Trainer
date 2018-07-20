/*
 * ColorsPalette.h
 *
 *  Created on: 13 mar 2018
 *      Author: maks
 */

#ifndef COLORSPALETTE_H_
#define COLORSPALETTE_H_

#include "Memocolor.h"

class ColorsPalette: public sf::Drawable {
public:
	ColorsPalette(int x, int y, sf::RenderWindow &window);
	virtual ~ColorsPalette();

	void update(bool & wasClicked);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	std::vector<Memocolor*> colors;

	bool active;

	sf::RectangleShape bgRect;

	sf::RenderWindow *window;

	friend class SettingsGameColorsChessboard;
	friend class GameColorsChessboard;

};

#endif /* COLORSPALETTE_H_ */
