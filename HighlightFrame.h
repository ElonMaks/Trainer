/*
 * Helper class for GameColorsChessboard used for drawing red frames around fields
 * where player drags some memocolors.
 */

#ifndef HIGHLIGHTFRAME_H_
#define HIGHLIGHTFRAME_H_

#include <SFML/Graphics.hpp>

class HighlightFrame: public sf::Drawable {
public:
	HighlightFrame();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	~HighlightFrame();

	void setPosition(sf::Vector2f newPos);
	void setFillColor(sf::Color color);
private:
	sf::RectangleShape line[4];
};


#endif /* HIGHLIGHTFRAME_H_ */
