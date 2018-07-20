/*
 * MemocolorToDrag is the field (in GameColorsChessboard it's 1 of 7 right after board)
 * which able user to drag over screen. Goal of dragging it is able user to  place it on
 * some ChessBoardField (after mouse is up).
 */

#ifndef MEMOCOLORTODRAG_H_
#define MEMOCOLORTODRAG_H_

#include "Memocolor.h"

#include <SFML/Graphics.hpp>

class MemocolorToDrag: public Memocolor {
public:
	MemocolorToDrag(Color k, int x, int y, sf::RenderWindow &window);
	virtual ~MemocolorToDrag();

	void update(bool & ifHandlerIdle, Color & currentColor);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:

	bool dragged;
	bool alreadyUsed;
	bool draggedAgain;

	// Shade of taken the element and the border
	sf::RectangleShape shade;
	sf::RectangleShape border;

	// Win ref, which is necessary to find mouse position
	sf::Window *window;

	sf::Vector2i mousePosDiff;

	friend class GameColorsChessboard;
};

#endif /* MEMOCOLORTODRAG_H_ */
