#include "MemocolorOnBoard.h"

MemocolorOnBoard::MemocolorOnBoard(Color k, ChessboardField* f) :
		Memocolor(k) {
	chessField = f;

	state = HIDDEN;

	animationCounter = 0;
}

void MemocolorOnBoard::show() {
	if (state != EXPOSE && state != EXPOSED) {
		showTimer.restart();
		state = EXPOSE;
	}
}

void MemocolorOnBoard::hide() {
	if (state != IMPLICIT && state != HIDDEN) {
		showTimer.restart();
		state = IMPLICIT;
	}
}

void MemocolorOnBoard::update() {
	switch (state) {
	case HIDDEN: {
		// set default size
		rect.setSize(sf::Vector2f(0, 0));
		rect.setPosition(chessField->originalPos);
		chessField->setPosition(chessField->originalPos);
		chessField->setSize(sf::Vector2f(60, 60));
	}
		break;
	case EXPOSE: {
		animationCounter = showTimer.getElapsedTime().asMilliseconds() / 5.3;
		float & x = animationCounter;

		if (animationCounter > 120) {
			animationCounter = 120;
			state = EXPOSED;
		}

		// first step - hide chessboard field
		chessField->setSize(
				sf::Vector2f(60,
						(animationCounter < 60) ?
								sin((60 - x) * 90 / 60 * M_PI / (180.0)) * 60 :
								0));
		chessField->setPosition(chessField->originalPos.x,
				(chessField->originalPos.y + animationCounter / 2));
		// second step - show memocolor
		rect.setSize(
				sf::Vector2f(60,
						(animationCounter > 60) ?
								sin((x - 60) * 90 / 60 * M_PI / (180.0)) * 60 :
								0));
		rect.setPosition(chessField->originalPos.x,
				chessField->originalPos.y + (60 - rect.getSize().y) / 2);
	}
		break;
	case EXPOSED: {
		// set default size
		rect.setPosition(chessField->originalPos);
		rect.setSize(sf::Vector2f(60, 60));
		chessField->setPosition(chessField->originalPos);
		chessField->setSize(sf::Vector2f(60, 60));
	}
		break;
	case IMPLICIT: {
		animationCounter = showTimer.getElapsedTime().asMilliseconds() / 5.3;
		float & x = animationCounter;

		if (animationCounter > 120)
			state = HIDDEN;

		// first step - hide memocolor
		rect.setSize(
				sf::Vector2f(60,
						(animationCounter < 60) ?
								sin((60 - x) * 90 / 60 * M_PI / (180.0)) * 60 :
								0));
		rect.setPosition(chessField->originalPos.x,
				chessField->originalPos.y
						+ ((animationCounter < 60) ? animationCounter / 2 : 0));
		// second step - show chessboard field
		chessField->setSize(
				sf::Vector2f(60,
						(animationCounter > 60) ? (animationCounter - 60) : 0));
		chessField->setPosition(chessField->originalPos.x,
				chessField->originalPos.y
						+ ((animationCounter > 60) ?
								(60 - chessField->getSize().y) / 2 : 0));

	}
		break;
	}
}

MemocolorOnBoard::~MemocolorOnBoard() {
}

