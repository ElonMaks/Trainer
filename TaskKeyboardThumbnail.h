/*
 * ThumbnailTaskKeyboard.h
 *
 *  Created on: 27 mar 2018
 *      Author: maks
 */

#ifndef TASKKEYBOARDTHUMBNAIL_H_
#define TASKKEYBOARDTHUMBNAIL_H_

#include "TaskKeyboardPrototype.h"
#include "KeyToPress.h"

#include <SFML/Graphics.hpp>

class TaskKeyboardThumbnail: public sf::Drawable, TaskKeyboardPrototype {
public:
	TaskKeyboardThumbnail(TaskSet set, int x, int y,
			sf::RenderWindow &window);

	TaskKeyboardPrototype getPrototype();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	virtual ~TaskKeyboardThumbnail();
protected:
	std::vector<KeyToPress*> keys;

	// Fonts
	sf::Font font;

	// ******************** TO ENABLE SFML WORKS *****************
	sf::RenderWindow *window;

	friend class GameKeyboardMaster;
};

#endif /* TASKKEYBOARDTHUMBNAIL_H_ */
