#include "GameColorsChessboard.h"

GameColorsChessboard::GameColorsChessboard(sf::RenderWindow &window,
		LogBook &logs) :
		chessboard(100, 100), logBook(logs), specialEffects(
				static_cast<sf::Vector2f>(window.getSize()), true) {
	phase = INTRO;
	exit = false;
	round = 0;

	goodChoices = 0;
	ifHandleIdle = false;

	this->window = &window;

	// Main background
	bgRectMain.setSize(static_cast<sf::Vector2f>(window.getSize()));
	bgRectMain.setFillColor(sf::Color(71, 138, 158));

	// Side background for points
	bgRectRight.setSize(static_cast<sf::Vector2f>(window.getSize()));
	bgRectRight.setFillColor(sf::Color(44, 169, 173));
	bgRectRight.setPosition(1450 + 400, -300);
	bgRectRight.setRotation(80);

	fontPorkys.loadFromFile("data/PORKYS.ttf");
	fontTahoma.loadFromFile("data/tahoma.ttf");

	currentField = NULL;
}

void GameColorsChessboard::run() {
	// At begging run settings' screen. Settings are set in struct "settings" sent by ref
	SettingsGameColorsChessboard settingsScreen(settings, *window, exit);
	settingsScreen.run(event);

	specialEffects.brighten(700);

	if (!exit)
		initialize();
	// ***********************   MAIN LOOP  ************************* //
	while (!exit) {
		while (window->pollEvent(event)) {
			// ESC / force quit == back to menu
			if (event.type == sf::Event::Closed
					|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
							&& event.type == sf::Event::KeyPressed)) {
				exit = true;
			}
		}

		window->clear();
		update();
		display();
	}
	// ************************************************************** //

}

void GameColorsChessboard::initialize() {
	// save number of colors in palette into var nColors
	nColors = settings.chosenPalette->colors.size();

	// create memoColors on right side which player can drag on board
	int center = 100 + 62 * 4; // todo overload getParams methods for Chessboard
	int topY = center - (nColors * 75 - 15) / 2;
	for (int i = 0; i < nColors; i++) {
		colorsToDrag.push_back(
				new MemocolorToDrag(
						settings.chosenPalette->colors[i]->getColor(), 710,
						topY + 75 * i, *window));
	}

	preStartTimer.restart();

	// use current time as seed for random generator
	std::srand(std::time(NULL));

	// set random, unique fields on chessboard and put
	// memocolors from chosen palette to them
	int n = 0;
	while (n < nColors) {
		int x = std::rand() % 8;
		int y = std::rand() % 8;
		bool busy = false;
		// Check if that field is already used...
		for (unsigned int i = 0; i < searchFields.size(); i++)
			if (searchFields[i]->chessField == &chessboard.field[x][y]) {
				busy = true;
				break;
			}
		// ...If not then put new memocolor here:
		if (!busy) {
			searchFields.push_back(
					new MemocolorOnBoard(
							settings.chosenPalette->colors[n]->getColor(),
							&chessboard.field[x][y]));
			n++;
		}
	}
	// and update them
	for (unsigned int i = 0; i < searchFields.size(); i++)
		searchFields[i]->update();

}

void GameColorsChessboard::update() {
	specialEffects.update();

	for (unsigned int i = 0; i < searchFields.size(); i++)
		searchFields[i]->update();
	for (unsigned int i = 0; i < tickFields.size(); i++)
		tickFields[i]->update();
//	for (unsigned int i = 0; i < resultSings.size(); i++)
//		resultSings[i]->update();

	// TODO move it to separe class for side panel
	playerLabel.setString("Player:");
	playerLabel.setFont(fontTahoma);
	playerLabel.setCharacterSize(24);
	playerLabel.setColor(sf::Color::Yellow);
	playerLabel.setPosition(810, 25);

	switch (phase) {
	case INTRO: {
		// *************************** INTRO ******************************
		bgRectRight.setPosition(
				1850 - preStartTimer.getElapsedTime().asMilliseconds() / 2,
				bgRectRight.getPosition().y);

		if (preStartTimer.getElapsedTime().asMilliseconds() > 800) {
			bgRectRight.setPosition(1450, -300);
			startTimer.restart();
			phase = PRESTART;
		}
	}
		break;
	case PRESTART: {
		// ************************** PRESTART ****************************
		// Countdown 3 2 1
		if (startTimer.getElapsedTime().asSeconds() < 3) {
			if (startTimer.getElapsedTime().asSeconds() > 2)
				textCountdown.setString("1");
			else if (startTimer.getElapsedTime().asSeconds() > 1)
				textCountdown.setString("2");
			else if (startTimer.getElapsedTime().asSeconds() > 0)
				textCountdown.setString("3");

			textCountdown.setFont(fontPorkys);
			textCountdown.setCharacterSize(140);
			textCountdown.setColor(sf::Color(255, 30, 0));
			textCountdown.setOrigin(textCountdown.getGlobalBounds().width / 2,
					textCountdown.getGlobalBounds().height / 2);
			textCountdown.setPosition(360,
					730
							- static_cast<int>(static_cast<float>(startTimer.getElapsedTime().asMilliseconds())
									/ 1) % 1000);

		} else {
			textCountdown.setColor(sf::Color(0, 0, 0, 0));
			phase = EXPOSING;
			for (int i = 0; i < nColors; i++) {
				searchFields[i]->show();
			}
		}
	}
		break;
	case EXPOSING: {
		if (startTimer.getElapsedTime().asMilliseconds()
				> settings.time4Remember * 1000 + 3000 + 120 * 5.3) {
			for (int i = 0; i < nColors; i++) {
				searchFields[i]->hide();
			}
		}
		// Wait 1s before enable player to uncovering fields
		if (startTimer.getElapsedTime().asSeconds()
				> settings.time4Remember + 3 + 1) {
			phase = GAME;
		}
	}
		break;
	case GAME: {
		// ************************** GAME ****************************
		// Check if some memoColor is dragged
		bool anyDragged = false;
		for (int i = 0; i < nColors; i++)
			if (colorsToDrag[i]->dragged)
				anyDragged = true;
		// Free the handle if neither memocolor is dragged
		if (!anyDragged)
			ifHandleIdle = true;

		// Service for each memocolor with getting color of current dragged memocolor
		// and saving it to currentColor sent by ref
		for (int i = 0; i < nColors; i++)
			colorsToDrag[i]->update(ifHandleIdle, currentColor);

		sf::Vector2i m_pos = sf::Mouse::getPosition(*window);

		currentField = NULL;
		// Search for colission of memocolor with any chessboard field
		for (int x = 0; x < 8; x++)
			for (int y = 0; y < 8; y++) {
				if (!ifHandleIdle
						&& m_pos.x
								> chessboard.field[x][y].getGlobalBounds().left
										- 2
						&& m_pos.y
								> chessboard.field[x][y].getGlobalBounds().top
										- 2
						&& m_pos.x
								< chessboard.field[x][y].getGlobalBounds().left
										+ chessboard.field[x][y].getGlobalBounds().width
										+ 2
						&& m_pos.y
								< chessboard.field[x][y].getGlobalBounds().top
										+ chessboard.field[x][y].getGlobalBounds().height
										+ 2) {
					// Set field which is right now over the mouse with dragged memocolor
					currentField = &chessboard.field[x][y];
				}
			}
		if (currentField) {
			// Highlight frame on that field
			highlightFrame.setFillColor(sf::Color { 255, 0, 0 });
			highlightFrame.setPosition(currentField->getPosition());

			// If mouseUp, drag memocolor here by setting new tickColor
			if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				// If already there is any tickColor on same field, delete old first:
				for (unsigned int i = 0; i < tickFields.size(); i++)
					if (currentField == tickFields[i]->chessField) {
						// Set color of old field as unused
						for (int k = 0; k < nColors; k++) {
							if (tickFields[i]->color == colorsToDrag[k]->color)
								colorsToDrag[k]->alreadyUsed = false;
						}
						// and delete old field
						delete tickFields[i];
						tickFields.erase(tickFields.begin() + i);
						break;
					}
				// Also look for field with same color on board and delete it if exist
				for (unsigned int i = 0; i < tickFields.size(); i++)
					if (currentColor == tickFields[i]->color) {
						delete tickFields[i];
						tickFields.erase(tickFields.begin() + i);
						break;
					}
				// Finally put new field in state EXPOSED and update it
				tickFields.push_back(
						new MemocolorOnBoard(currentColor, currentField));
				tickFields[tickFields.size() - 1]->state =
						MemocolorOnBoard::EXPOSED;
				tickFields[tickFields.size() - 1]->update();

				// Flag dragged color as used
				for (int i = 0; i < nColors; i++) {
					if (tickFields[tickFields.size() - 1]->color
							== colorsToDrag[i]->color)
						colorsToDrag[i]->alreadyUsed = true;
				}
			}
		} else {
			// Make frames invisible if current memocolor is not dragged over board
			highlightFrame.setFillColor(sf::Color(0, 0, 0, 0));
		}

		// Check if all colors are already put on board. If yes, round is finished.
		if (tickFields.size() == nColors) {
			phase = CHECKRESULT;
		}
	}
		break;
	case CHECKRESULT: {
		// ************************** CHECK RESULT ****************************
		goodChoices = 0;
		// Check if tick fields are correct
		for (int i = 0; i < nColors; i++)
			for (int j = 0; j < nColors; j++) {
				if (tickFields[i]->chessField == searchFields[j]->chessField
						&& tickFields[i]->color == searchFields[j]->color) {
					goodChoices++;
					resultSings.push_back(
							new GoodOrBadSign(GoodOrBadSign::GOOD,
									tickFields[i]->chessField->getPosition()));
				}
			}
		// Create text with score
		std::ostringstream ss;
		ss << "Score: ";
		ss << goodChoices;
		ss << "/" << nColors;
		std::string napis = ss.str();
		scoreText.setString(napis);
		scoreText.setFont(fontTahoma);
		scoreText.setCharacterSize(46);
		if (goodChoices == nColors) {
			scoreText.setColor(sf::Color(0, 255, 0));
		} else
			scoreText.setColor(sf::Color(255, 0, 0));
		scoreText.setPosition(805, 110);

		// Hide bad player choices, replacing it by correct ones
		std::vector<MemocolorOnBoard*> incorrectFields;
		for (int i = 0; i < tickFields.size(); i++)
			for (int j = 0; j < nColors; j++) {
				if (tickFields[i]->color == searchFields[j]->color
						&& tickFields[i]->chessField
								!= searchFields[j]->chessField) {
					incorrectFields.push_back(tickFields[i]);
					resultSings.push_back(
							new GoodOrBadSign(GoodOrBadSign::BAD,
									tickFields[i]->chessField->getPosition()));
					for (int i = 0; i < incorrectFields.size(); i++)
								incorrectFields[i]->hide();
				}
			}
		phase = SHOWRESULT;
		endTimer.restart();
	} break;
	case SHOWRESULT: {
		// ************************** SHOW RESULT ****************************
		if (endTimer.getElapsedTime().asSeconds() > 3)
			for (int i = 0; i < nColors; i++)
				searchFields[i]->show();

		if (endTimer.getElapsedTime().asSeconds() > 8)
			phase = HIDERESULT;
	}
		break;
	case HIDERESULT: {
		// ************************** HIDE RESULT ****************************
		for (int i = 0; i < resultSings.size(); i++)
			resultSings.erase(resultSings.begin());

		for (int i = 0; i < tickFields.size(); i++)
			tickFields[i]->hide();

		for (int i = 0; i < searchFields.size(); i++)
			searchFields[i]->hide();

		if (endTimer.getElapsedTime().asSeconds() > 10) {
			clear();

			round++;
			// Check if it's last round of game
			if (round >= settings.nRounds)
				exit = true;
			else
				initialize();

			logBook.writeRecord(round, goodChoices, settings.time4Remember);

			// Start next round from prestart phase
			phase = PRESTART;
			startTimer.restart();
		}
	}
		break;
	}
}

void GameColorsChessboard::display() {
	window->draw(bgRectMain);
	window->draw(bgRectRight);

	window->draw(chessboard);

	for (int i = 0; i < nColors; i++)
		window->draw(*colorsToDrag[i]);

	for (int i = 0; i < nColors; i++)
		window->draw(*searchFields[i]);

	if (phase == GAME) {
		window->draw(highlightFrame);
	}

	for (unsigned int i = 0; i < tickFields.size(); i++)
		window->draw(*tickFields[i]);

	for (int i = 0; i < resultSings.size(); i++)
		window->draw(*resultSings[i]);

	// TODO move it to separe class for side panel
	window->draw(playerText);
	window->draw(playerLabel);
	window->draw(exerciseNumText);
	window->draw(exerciseNumLabel);
	window->draw(exerciseNumText);

	window->draw(textCountdown);
	window->draw(specialEffects);

	window->display();
}

void GameColorsChessboard::clear() {
	// Clear everything from current round
	for (int i = 0; i < nColors; i++) {
		tickFields.erase(tickFields.begin());
	}
	for (int i = 0; i < nColors; i++) {
		searchFields.erase(searchFields.begin());
	}
	for (int i = 0; i < nColors; i++) {
		colorsToDrag.erase(colorsToDrag.begin());
	}
	for (int i = 0; i < nColors; i++)
		colorsToDrag[i]->alreadyUsed = false;
}

GameColorsChessboard::~GameColorsChessboard() {
}
