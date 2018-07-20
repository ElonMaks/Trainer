/*
 * KeyToPress.h
 *
 *  Created on: 1 lut 2018
 *      Author: maks
 */

#ifndef KEYTOPRESS_H_
#define KEYTOPRESS_H_

#include "Global.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class KeyToPress: public sf::Drawable {
public:
	KeyToPress(WhichKey whichKey, bool small, int x, int y, sf::Font & font);
	KeyToPress(const KeyToPress&);

	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	virtual ~KeyToPress();
private:
	KeyState keyState;

	// SFML scancode for current key
	sf::Keyboard::Key key;

	sf::Texture keyTex;
	sf::Sprite keyImg;

	sf::Font font;
	sf::Text keySign;

	friend class TaskKeyboard;
	friend class TaskKeyboardThumbnail;
	friend class GameKeyboardMaster;
};

#endif /* KEYTOPRESS_H_ */
