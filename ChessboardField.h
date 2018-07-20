/*
 * One black/white field on the chessboard which can be baseline for position of
 * MemoColors on the board and screen (ChessboardField* is element of MeMoColorOnBoard).
 */

#ifndef CHESSBOARDFIELD_H_
#define CHESSBOARDFIELD_H_

#include <SFML/Graphics.hpp>

#include "Global.h"

class ChessboardField: public sf::RectangleShape {
public:
	ChessboardField();
	ChessboardField(int x, int y, ChessColor k);
	virtual ~ChessboardField();

//	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	sf::Vector2f originalPos;
	ChessColor kolor;

	friend class Szachownica;
	friend class MemocolorOnBoard;
	friend class GraKolorySzachownica;
};

#endif /* CHESSBOARDFIELD_H_ */
