#include "TaskKeyboardThumbnail.h"

TaskKeyboardThumbnail::TaskKeyboardThumbnail(TaskSet set,
		int x, int y,
		sf::RenderWindow &window) : TaskKeyboardPrototype(set) {
	this->window = &window;

	font.loadFromFile("data/tahoma.ttf");

	// Get keys from prototype
	for (unsigned int i = 0; i < TaskKeyboardPrototype::keys.size(); i++) {
		keys.push_back(
				new KeyToPress(TaskKeyboardPrototype::keys[i], true, x + 50 * i, y,
						font));
	}
}

TaskKeyboardPrototype TaskKeyboardThumbnail::getPrototype() {
	return static_cast<TaskKeyboardPrototype>(*this);
}

void TaskKeyboardThumbnail::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
	for (unsigned int i = 0; i < keys.size(); i++)
		target.draw(*keys[i]);
}

TaskKeyboardThumbnail::~TaskKeyboardThumbnail() {
	unsigned int s = keys.size();
	for (unsigned int i = 0; i < s; i++) {
		keys.erase(keys.begin());
	}
}

