#include "TaskKeyboardToSelect.h"

TaskKeyboardToSelect::TaskKeyboardToSelect(TaskSet set, int x, int y,
		sf::RenderWindow &window) :
		TaskKeyboardThumbnail(set, x, y, window) {
	selected = false;
	clickedBefore = false;

	// set position of circle to the left, near thumbnails of keys
	circ.setPosition(x - 50 + 2, y +3 + 2);
	circBorder.setPosition(x - 50, y+3);
	circ.setFillColor(sf::Color::Black);
	circBorder.setFillColor(sf::Color::Blue);
	circ.setRadius(18);
	circBorder.setRadius(20);

	// make a border for entirety
	rect.setPosition(x - 60 , y - 10);
	rect.setSize({520, 70});
	rect.setFillColor(sf::Color{30, 30, 30});
}

void TaskKeyboardToSelect::update() {
	sf::Vector2i localPosition = sf::Mouse::getPosition(*window);

	if (localPosition.x > rect.getGlobalBounds().left
			&& localPosition.y > rect.getGlobalBounds().top
			&& localPosition.x
					< rect.getGlobalBounds().left + rect.getGlobalBounds().width
			&& localPosition.y
					< rect.getGlobalBounds().top + rect.getGlobalBounds().height) {
		// click
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clickedBefore) {
			selected = 1 - selected;
			clickedBefore = true;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			clickedBefore = false;
		}
	}

	if (!selected) {
		rect.setFillColor(sf::Color(40, 40, 70));
		circ.setFillColor(sf::Color(30, 30, 30));
	}
	else {
		rect.setFillColor(sf::Color(150, 65, 130));
		circ.setFillColor(sf::Color(0, 195, 0));
	}
}

void TaskKeyboardToSelect::draw(sf::RenderTarget &target,
		sf::RenderStates states) const {
	target.draw(rect);
	TaskKeyboardThumbnail::draw(target, states);
	target.draw(circBorder);
	target.draw(circ);
}

bool TaskKeyboardToSelect::isSelected() {
	return selected;
}

TaskKeyboardToSelect::~TaskKeyboardToSelect() {
}
