/*
 * TaskKeyboardToSelect.h
 *
 *  Created on: 9 lip 2018
 *      Author: maks
 */

#ifndef TASKKEYBOARDTOSELECT_H_
#define TASKKEYBOARDTOSELECT_H_

#include "TaskKeyboardThumbnail.h"
#include "Button.h"

class TaskKeyboardToSelect: public TaskKeyboardThumbnail {
public:
	TaskKeyboardToSelect(TaskSet set, int x, int y,
			sf::RenderWindow &window);

	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool isSelected();

	virtual ~TaskKeyboardToSelect();
private:
	// selected task means it'll be used in game
	bool selected;

	// to detect mousedown (avoid multi-clicks)
	bool clickedBefore;

	sf::CircleShape circ;
	sf::CircleShape circBorder;

	sf::RectangleShape rect;
};

#endif /* TASKKEYBOARDTOSELECT_H_ */
