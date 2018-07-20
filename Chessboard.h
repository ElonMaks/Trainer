/*
 * Chessboard separated for 8x8 fields (ChessboardField class) and indication
 * for every field on each side of chessboard.
 */

#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include <sstream>
#include <math.h>
#include "ChessboardField.h"

class Chessboard: public sf::Drawable {
public:
	Chessboard(int x, int y);
	virtual ~Chessboard();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	ChessboardField field[8][8];

	sf::RectangleShape forGridBg;

	// indication for fields, A - F / 1 - 8
	sf::Text indicationL[8], indicationR[8], indicationT[8], indicationB[8];

	sf::Font font;

	friend class GameColorsChessboard;
};

#endif /* CHESSBOARD_H_ */
