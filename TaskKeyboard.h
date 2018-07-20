/*
 * TaskKeyboard.h
 *
 *  Created on: 1 lut 2018
 *      Author: maks
 */

#ifndef TASKKEYBOARD_H_
#define TASKKEYBOARD_H_

#include "TaskKeyboardPrototype.h"
#include "KeyToPress.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class TaskKeyboard: public sf::Drawable, TaskKeyboardPrototype {
public:
//	TaskKeyboard(TaskSet set, sf::RenderWindow &window);
//	TaskKeyboard(const TaskKeyboard &);

	// only good method ?
	TaskKeyboard(std::vector<WhichKey> & keys, int x, int y,
			sf::RenderWindow &window);

	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	virtual ~TaskKeyboard();
private:
	bool finished;
	int currentKey;

	std::vector<KeyToPress*> keys;

	sf::Keyboard::Key lastPressed;

	// Fonts
	sf::Font font;

	// ******************** TO ENABLE SFML WORKS *****************
	sf::RenderWindow *window;

	friend class GameKeyboardMaster;
};

#endif /* TASKKEYBOARD_H_ */
