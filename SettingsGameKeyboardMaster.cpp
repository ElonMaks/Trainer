#include "SettingsGameKeyboardMaster.h"

SettingsGameKeyboardMaster::SettingsGameKeyboardMaster(
		SettingsListGameKeyboardMaster &settings, sf::RenderWindow &window,
		bool & exitGame) :
		settingsList(settings), scrollNumOfRounds(window, 820, 340, 200, 1, 6,
				3), exit(exitGame), startBtn(window, 840, 570, 210, 95), specialEffects(
				static_cast<sf::Vector2f>(window.getSize()), true) {
	this->window = &window;

	taskToSelect.push_back(
			new TaskKeyboardToSelect(TASK_1A2A3A, 120,
					140 + 50, window));
}

void SettingsGameKeyboardMaster::run(sf::Event &event) {
	specialEffects.brighten(400);
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

		// Leave loop in case of change phase → game
		if (state == GAME)
			break;

		window->clear();
		update();
		display();
	}
	// ************************************************************** //
}

void SettingsGameKeyboardMaster::update() {
	scrollNumOfRounds.update();
	settingsList.nRounds = scrollNumOfRounds.getValue();
	startBtn.update();

	if (startBtn.isPressed()) {
		state = PREGAME;
		toStartClk.restart();
		specialEffects.darken(300);
	}

	for (unsigned int i = 0; i < taskToSelect.size(); i++)
		taskToSelect[i]->update();

	specialEffects.update();

	switch (state) {
	case SETTINGS: {

	}
		break;
	case PREGAME: {
		if (toStartClk.getElapsedTime().asMilliseconds() > 320)
			state = GAME;
	}
		break;
	case GAME: {

	}
		break;
	}
}

void SettingsGameKeyboardMaster::display() {
	window->draw(scrollNumOfRounds);
	window->draw(startBtn);

//	window->draw(infoLine1);
//	window->draw(infoLine2);
	window->draw(nRoundsText);

	for (unsigned int i = 0; i < taskToSelect.size(); i++)
		window->draw(*taskToSelect[i]);

	window->draw(specialEffects);
	window->display();
}

SettingsGameKeyboardMaster::~SettingsGameKeyboardMaster() {
}
