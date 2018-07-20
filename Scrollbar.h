#ifndef SCROLLBAR_H_
#define SCROLLBAR_H_

#include <SFML/Graphics.hpp>

#include <sstream>

class Scrollbar: public sf::Drawable {
public:
	Scrollbar(sf::RenderWindow &window, int x, int y, int width, int minValue,
			int maxValue, int defaultValue = 0);

	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int getValue();

	virtual ~Scrollbar();
private:
	// Win ref is necessary to find mouse pos
	sf::Window *window;
	sf::Vector2i localPosition;

	sf::Texture arrowLTex, arrowRTex, squareTex;

	int x, y, width;
	int minValue, maxValue;

	int value;

	int clickThreshold;
	int clickStored;
	bool isArrowLPressed, isArrowRPressed;

	// Time between frames
	sf::Clock delta;

//	sf::Font font;
//	sf::Text shownValue;

	// ********  GRAPHICAL COMPONENTS ********
	sf::Sprite arrowL, arrowR;
	sf::RectangleShape scrollRect;
	sf::RectangleShape square;
};

#endif /* SCROLLBAR_H_ */
