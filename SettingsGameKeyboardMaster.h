/*
 * SettingsGameKeyboardMaster.h
 *
 *  Created on: 31 mar 2018
 *      Author: maks
 */

#ifndef SETTINGSGAMEKEYBOARDMASTER_H_
#define SETTINGSGAMEKEYBOARDMASTER_H_

#include "Settings.h"
#include "Button.h"
#include "Scrollbar.h"
#include "SpecialEffects.h"
#include "TaskKeyboardToSelect.h"

class SettingsGameKeyboardMaster: public Settings {
public:
	SettingsGameKeyboardMaster(
			SettingsListGameKeyboardMaster &settings, sf::RenderWindow &window,
			bool & exitGame);

	// Settings states
	enum State {
		SETTINGS, PREGAME, GAME
	};

	void run(sf::Event &event);
	void update();
	void display();

	virtual ~SettingsGameKeyboardMaster();
private:
	SettingsListGameKeyboardMaster &settingsList;

	std::vector<TaskKeyboardToSelect*> taskToSelect;

	State state;

	bool &exit;

	sf::Clock toStartClk;

	sf::Text nRoundsText;
	Button startBtn;
	Scrollbar scrollNumOfRounds;

	SpecialEffects specialEffects;

	// ******************** TO ENABLE SFML WORKS *****************
	sf::RenderWindow *window;
};

#endif /* SETTINGSGAMEKEYBOARDMASTER_H_ */
