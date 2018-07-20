/*
 * Memocolor is field on the chessboard with location determined by ChessboardField pointer
 * and color initialized in constructor as well.
 *
 * In GameColorsChessboard it's used for searchColors vector which player is looking for
 * and for tickFields vector - in second case their state is set as EXPOSED outside from
 * class.
 *
 * To switch beetween states of animation there are just two methods: show() and hide().
 *
 */

#ifndef MEMOCOLORONBOARD_H_
#define MEMOCOLORONBOARD_H_

#include "ChessboardField.h"
#include "Memocolor.h"

#include <cmath>

class MemocolorOnBoard: public Memocolor {
public:
	MemocolorOnBoard(Color k, ChessboardField* f);
	virtual ~MemocolorOnBoard();

	enum State {
		HIDDEN, EXPOSE, EXPOSED, IMPLICIT
	};

	void show();
	void hide();

	void update();
private:
	State state;
	sf::Clock showTimer;
	float animationCounter;

	// pointer to chess field where the memocolor is located
	ChessboardField* chessField;

	friend class GameColorsChessboard;
};

#endif /* MEMOCOLORONBOARD_H_ */
