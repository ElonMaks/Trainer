#include "Menu.h"

Menu::Menu(sf::RenderWindow &window) :
		gameMemoryBtn(window, 160, 140, 320, 240), gameKeyboardBtn(window, 620,
				140, 320, 240), specialEffects(
				static_cast<sf::Vector2f>(window.getSize())) {
	this->window = &window;

	tileTex.loadFromFile("data/tiled-space-background.png");
	int tilesW = window.getSize().x / tileTex.copyToImage().getSize().x * 3;
	int tilesH = window.getSize().y / tileTex.copyToImage().getSize().y * 3;

	for (int x = 0; x < tilesW; x++)
		for (int y = 0; y < tilesH; y++) {
			bgTiles[x][y].setTexture(tileTex);
			bgTiles[x][y].setPosition(
					bgTiles[x][y].getGlobalBounds().width * (x - tilesW / 3),
					bgTiles[x][y].getGlobalBounds().height * (y - tilesH / 3));
		}

	typeOfGame = UNKNOWN;
	state = MENU;
	exit = false;

}

void Menu::run() {
	startClk.restart();

	while (!exit) {
		while (window->pollEvent(event)) {
			// ESC / force quit == end program
			if (event.type == sf::Event::Closed
					|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
							&& event.type == sf::Event::KeyPressed)) {
				state = PROGRAM_END;
			}
		}
		update();
		display();
	}

}

void Menu::update() {
	// Update buttons
	gameMemoryBtn.update();
	gameKeyboardBtn.update();
	if (gameMemoryBtn.isPressed()) {
		state = PREGAME;
		specialEffects.darken(330);
		gameStartedClk.restart();
		typeOfGame = COLORS_CHESSBOARD;
	}
	if (gameKeyboardBtn.isPressed()) {
		state = PREGAME;
		specialEffects.darken(330);
		gameStartedClk.restart();
		typeOfGame = KEYBOARD_MASTER;
	}

	// Do some activity depending on menu state
	switch (state) {
	case PREGAME: {
		specialEffects.update();

		if (gameStartedClk.getElapsedTime().asMilliseconds() >= 350) {
			state = GAME;
		}
	}
		break;
	case GAME: {
		exit = true;
	}
		break;
	case PROGRAM_END: {
		exit = true;
	}
		break;
	}

	specialEffects.update();
}

void Menu::display() {
	// Display everything
	window->clear();

	// 1 period = 3.2s * 4
	double moveX = sin(startClk.getElapsedTime().asMilliseconds() / (3200.0));
	double moveY = cos(startClk.getElapsedTime().asMilliseconds() / (3200.0));

	for (int x = 0; x < tilesW; x++)
		for (int y = 0; y < tilesH; y++) {
			window->draw(bgTiles[x][y]);

			bgTiles[x][y].move(moveX, moveY);
		}
	window->draw(gameMemoryBtn);
	window->draw(gameKeyboardBtn);

	window->draw(specialEffects);

	window->display();
}

Menu::~Menu() {
}
