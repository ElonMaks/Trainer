/*
 * Very simple button used for menu. It changes color on mouse hover.
 *
 * Only public method other than update and dislay is isPressed().
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.hpp>

class Button: public sf::RectangleShape {
public:
	Button(sf::RenderWindow &window, int x, int y, int w, int h);
	virtual ~Button();

	void update();
	bool isPressed();
private:
	// Win ref is necessary to find mouse pos
	sf::Window *window;
	sf::Vector2i localPosition;

	bool pressed;

};

#endif /* BUTTON_H_ */
