#include "ChessboardField.h"

ChessboardField::ChessboardField() {
}

ChessboardField::ChessboardField(int x, int y, ChessColor k) {
	originalPos = sf::Vector2f(x, y);
	setPosition(originalPos);
	setSize(sf::Vector2f(60, 60));

	kolor = k;

	if (kolor == B) {
		setFillColor(sf::Color{26, 26, 26});
	} else if (kolor == W) {
		setFillColor(sf::Color{230, 230, 230});
	}
}

ChessboardField::~ChessboardField() {
}

//void ChessboardField::draw(sf::RenderTarget &target,
//		sf::RenderStates states) const {
//	if (kolor == B) {
//
//	} else if (kolor == W) {
//
//	}
//}
