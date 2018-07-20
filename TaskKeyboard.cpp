#include "TaskKeyboard.h"
//
//TaskKeyboard::TaskKeyboard(TaskSet set, sf::RenderWindow &window) :
//		TaskKeyboardPrototype(set) {
//	finished = false;
//	currentKey = 0;
//	lastPressed = sf::Keyboard::Unknown;
//
//	this->window = &window;
//
//	font.loadFromFile("data/tahoma.ttf");
//
//	// Get keys from prototype
//	for (int i = 0; i < TaskKeyboardPrototype::keys.size(); i++) {
//		keys.push_back(
//				new KeyToPress(TaskKeyboardPrototype::keys[i]->getKey(),
//						false, 40 + 80 * i, 30, font));
//	}
//}

TaskKeyboard::TaskKeyboard(std::vector<WhichKey> & keys, int x, int y,
		sf::RenderWindow &window) {
	this->window = &window;

	finished = false;
	currentKey = 0;
	lastPressed = sf::Keyboard::Unknown;

	font.loadFromFile("data/tahoma.ttf");

	// Get keys from prototype
	for (int i = 0; i < keys.size(); i++) {
		this->keys.push_back(
				new KeyToPress(keys[i], false, x + 80 * i, y, font));
	}
}

//TaskKeyboard::TaskKeyboard(const TaskKeyboard &org) {
//	finished = org.finished;
//	currentKey = org.currentKey;
//
//	// Copy all keys
//	for (int i = 0; i < org.keys.size(); i++) {
//		keys.push_back(new KeyToPress(*org.keys[i]));
//	}
//
//	lastPressed = org.lastPressed;
//	currentKey = org.currentKey;
//	font = org.font;
//	window = org.window;
//}

void TaskKeyboard::update() {
	if (!finished) {
		// If player has choosen correct key → go to next and set current as green
		if (sf::Keyboard::isKeyPressed(keys[currentKey]->key)) {
			keys[currentKey]->keyState = GOOD;
			lastPressed = keys[currentKey]->key;
			currentKey++;

			if (currentKey == keys.size()) {
				finished = true;
			}
		} else
			for (int i = sf::Keyboard::A; i < sf::Keyboard::Pause; i++) {
				if (sf::Keyboard::isKeyPressed(
						static_cast<sf::Keyboard::Key>(i))) {
					if (static_cast<sf::Keyboard::Key>(i) != lastPressed) {
						keys[currentKey]->keyState = BAD;
						lastPressed = static_cast<sf::Keyboard::Key>(i);
					}
				}
			}
	} else { // When task is finished...

	}

	for (unsigned int i = 0; i < keys.size(); i++) {
		keys[i]->update();
	}
}

void TaskKeyboard::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
	for (unsigned int i = 0; i < keys.size(); i++)
		target.draw(*keys[i]);
}

TaskKeyboard::~TaskKeyboard() {
	unsigned int s = keys.size();
	for (unsigned int i = 0; i < s; i++) {
		keys.erase(keys.begin());
	}
}
