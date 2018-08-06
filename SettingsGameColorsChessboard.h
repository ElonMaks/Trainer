/*
 * Settings screen shown before run game with colors. User can choose here
 * number of rounds and time given for him to see position of color fields on boards.
 */

#ifndef SETTINGSGAMECOLORSCHESSBOARD_H_
#define SETTINGSGAMECOLORSCHESSBOARD_H_

#include "Settings.h"
#include "Button.h"
#include "ColorsPalette.h"
#include "Scrollbar.h"
#include "SpecialEffects.h"

const int nPalletes = 6;

class SettingsGameColorsChessboard: public Settings {
public:
	SettingsGameColorsChessboard(SettingsListGameColorsChessboard &settings,
			sf::RenderWindow &window, bool & exitGame);

	void run(sf::Event &event);
	void update();
	void display();

	virtual ~SettingsGameColorsChessboard();
private:

	enum State {
		SETTINGS, PREGAME, GAME
	};
	SettingsListGameColorsChessboard &settingsList;
	Scrollbar scrollSecs4Reveal;
	Scrollbar scrollNumOfRounds;

	State state;

	bool &exit;

	ColorsPalette palettes[nPalletes];

	SpecialEffects specialEffects;

	sf::Clock toStartClk;

	Button startBtn;

	sf::Font fontTahoma;
	sf::Text infoLine1;
	sf::Text infoLine2;

	sf::Text time4revealText;
	sf::Text nRoundsText;

	// ******************** TO ENABLE SFML WORKS *****************
	sf::RenderWindow *window;
//	sf::Event event;
};

#endif /* SETTINGSGAMECOLORSCHESSBOARD_H_ */
