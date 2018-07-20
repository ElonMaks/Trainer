#include "Chessboard.h"

Chessboard::Chessboard(int x, int y) {
	forGridBg.setPosition(x - 2, y - 2);
	forGridBg.setSize(sf::Vector2f(8 * 62 + 2, 8 * 62 + 2));
	forGridBg.setFillColor(sf::Color(64, 64, 64));

	// Assigment position and color for every chessfield
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2)
				field[i][j] = ChessboardField(i * 62 + x, j * 62 + y, W);
			else
				field[i][j] = ChessboardField(i * 62 + x, j * 62 + y, B);
		}
	font.loadFromFile("data/tahoma.ttf");

	// Prepare texts for indication for fields
	for (int i = 0; i < 8; i++) {
		// For int → string conversion
		std::ostringstream ssl, ssp, sst, ssb;

		// Left side numbers
		indicationL[i].setCharacterSize(34);
		indicationL[i].setColor(sf::Color::Black);
		indicationL[i].setFont(font);
		ssl << 8 - i;
		indicationL[i].setString(ssl.str());
		indicationL[i].setPosition(x - 32,
				y + i * 62 + 62
						- (62 - indicationL[i].getGlobalBounds().height / 2));

		// Right side numbers (reversed)
		indicationR[i].setCharacterSize(34);
		indicationR[i].setColor(sf::Color::Black);
		indicationR[i].setFont(font);
		indicationR[i].setRotation(180);
		ssp << 8 - i;
		indicationR[i].setString(ssp.str());
		indicationR[i].setPosition(62 * 8 + x + 32,
				y + i * 62
						+ (62 - indicationR[i].getGlobalBounds().height / 2));

		// Bottom side letters
		indicationB[i].setCharacterSize(34);
		indicationB[i].setColor(sf::Color::Black);
		indicationB[i].setFont(font);
		ssb << static_cast<char>(97 + i);
		indicationB[i].setString(ssb.str());
		indicationB[i].setPosition(
				x + i * 62
						+ (62 - indicationB[i].getGlobalBounds().width) / 2,
				y + 62 * 8 + 5);

		// Upper side letters (reversed)
		indicationT[i].setCharacterSize(34);
		indicationT[i].setColor(sf::Color::Black);
		indicationT[i].setFont(font);
		indicationT[i].setRotation(180);
		sst << static_cast<char>(97 + i);
		indicationT[i].setString(sst.str());
		indicationT[i].setPosition(
				x + i * 62 + 62
						- (62 - indicationT[i].getGlobalBounds().width) / 2,
				y - 5);
	}
}

void Chessboard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(forGridBg);

	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++) {
			target.draw(field[x][y]);
		}

	for (int i = 0; i < 8; i++) {
		target.draw(indicationL[i]);
		target.draw(indicationR[i]);
		target.draw(indicationB[i]);
		target.draw(indicationT[i]);
	}
}

Chessboard::~Chessboard() {
}
