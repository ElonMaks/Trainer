#include "SettingsGameKeyboardMaster.h"

SettingsGameKeyboardMaster::SettingsGameKeyboardMaster(
		SettingsListGameKeyboardMaster &settings, sf::RenderWindow &window,
		bool & exitGame) :
		settingsList(settings), scrollNumOfRounds(window, 820, 340, 200, 1, 6,
				3), exit(exitGame), startBtn(window, 840, 570, 210, 95), specialEffects(
				static_cast<sf::Vector2f>(window.getSize()), true) {
	this->window = &window;
	state = SETTINGS;
}

void SettingsGameKeyboardMaster::run(sf::Event &event) {
	initialize();
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

		// Leave main loop if detect change of phase → game
		if (state == GAME)
			break;

		window->clear();
		update();
		display();
	}
	// ************************************************************** //
}

void SettingsGameKeyboardMaster::initialize() {
	taskToSelect.push_back(
			new TaskKeyboardToSelect(TASK_1A2A3A, 120, 160 + 50, *window));
	taskToSelect.push_back(
			new TaskKeyboardToSelect(TASK_1A2A3A4A, 120, 160 + 120, *window));
	taskToSelect.push_back(
			new TaskKeyboardToSelect(TASK_SC_RINES, 120, 160 + 190, *window));
	taskToSelect.push_back(
			new TaskKeyboardToSelect(TASK_SC_LINGS, 120, 160 + 260, *window));
	taskToSelect.push_back(
			new TaskKeyboardToSelect(TASK_SC_HYDRAS, 120, 160 + 330, *window));
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
		if (toStartClk.getElapsedTime().asMilliseconds() > 320) {
			state = GAME;
			for (unsigned int i = 0; i < taskToSelect.size(); i++) {
				if (taskToSelect[i]->isSelected())
					settingsList.chosenTasks.push_back(
							(taskToSelect[i])->getPrototype());
			}
		}
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
