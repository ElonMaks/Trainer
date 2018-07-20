#include "Program.h"

Program::Program() {
	window.create(sf::VideoMode(1100, 700), L"Robimy mózg",
			sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	state = MENU;
	exit = false;
}

void Program::run() {
	// *********************   MAIN LOOP   ************************ //
	while (!exit) {
		switch (state) {
		case MENU: {
			Menu menu(window);

			// Move main loop → menu
			menu.run();

			// Depending on state of menu, do an acitivity
			switch (menu.state) {
			case Menu::GAME: {
				switch (menu.typeOfGame) {
				case Menu::COLORS_CHESSBOARD: {
					game = new GameColorsChessboard(window, logBook);
					state = GAME;
				}
					break;
				case Menu::KEYBOARD_MASTER: {
					game = new GameKeyboardMaster(window, logBook);
					state = GAME;
				}
					break;
				}
			}
				break;
			case Menu::PROGRAM_END: {
				state = PROGRAM_END;
			}
				break;
			}
		}
			break;
		case GAME: {
			// Move main loop → game
			game->run();

			// Return to the menu after finish game
			state = MENU;
		}
			break;
		case PROGRAM_END: {
			// Convert data with player scores to html file
			logBook.saveToHTML();

			// Free memory
			delete game;

			exit = true;
		}
			break;
		}
	} // ************************************************************ //
}

Program::~Program() {
}
