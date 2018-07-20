/*
 * Program.h
 *
 *  Created on: 20 lut 2018
 *      Author: maks
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "Menu.h"
#include "GameColorsChessboard.h"
#include "GameKeyboardMaster.h"
#include "LogBook.h"

class Program {
public:
	Program();

	// Program states
	enum ProgramState {
		MENU, GAME, PROGRAM_END
	};

	void run();

	virtual ~Program();
private:
	ProgramState state;

	// Pointer to the dynamically allocated GAME
	Game *game;

	// Logbook, where every player score will be saved
	LogBook logBook;

	bool exit = false;

	sf::RenderWindow window;
	sf::Event event;

};

#endif /* PROGRAM_H_ */
