/*
 * Game for training pressing chosen keys as fast as possible. This training combine ked
 * of typing with speed of player reaction. When all keys are pressed (assigment is finished)
 * todo the next sequence of keys will be shown in random time (between 0.3s-1.4s).
 */

#ifndef GAMEKEYBOARDMASTER_H_
#define GAMEKEYBOARDMASTER_H_

#include "Game.h"
#include "LogBook.h"
#include "TaskKeyboard.h"
#include "TaskKeyboardThumbnail.h"
#include "SpecialEffects.h"
#include "SettingsGameKeyboardMaster.h"

#include <vector>

class GameKeyboardMaster: public Game {
public:
	GameKeyboardMaster(sf::RenderWindow &window, LogBook &logs);
	void run();
	void initialize();
	void update();
	void display();
	void clear();

	// program states
	enum KeyboardMasterGamePhase {
		INTRO, PRESTART, GAME, ASSIGMENT_DONE, WAIT4NEXT_ASSIGMENT, FINISHED
	};

	virtual ~GameKeyboardMaster();
private:
	// ********************* GENERAL ************************
	KeyboardMasterGamePhase phase;
	LogBook & logBook;
	SpecialEffects specialEffects;
	bool exit;

	// ******************* GAME COMPONENTS *******************
	// list of all possible tasks in this game
	std::vector<TaskKeyboardThumbnail*> avaibleTasks;

	// results of draw, tasks ...
	std::vector<TaskKeyboard> tasks;
	unsigned int currentTask;

	// all the user settings
	SettingsListGameKeyboardMaster settings;

	// timers
	sf::Clock cl1, nextClk;

	float nextTaskDelay;

	// text field for: 3 2 1 used in prestart phase
	sf::Text textCountdown;

	// timers
	sf::Clock preStartTimer, startTimer;
	sf::Clock endTimer;

	// fonts
	sf::Font fontPorkys, fontTahoma;

	// *************************************************************
	// other graphicals elements
	sf::RectangleShape bgRectMain;
	sf::RectangleShape bgRectRight;

	// ******************** TO ENABLE SFML WORKS *****************
	sf::RenderWindow *window;
	sf::Event event;
};

#endif /* GAMEKEYBOARDMASTER_H_ */
