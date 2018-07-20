/*
 * Menu.h
 *
 *  Created on: 21 lut 2018
 *      Author: maks
 */

#ifndef MENU_H_
#define MENU_H_

#include "Button.h"
#include "SpecialEffects.h"

#include <cmath>

const int tilesW = 30, tilesH = 30;

class Menu {
public:
	Menu(sf::RenderWindow & window);

	enum State {
		MENU, PREGAME, GAME, PROGRAM_END
	};

	enum TypeOfGame {
		UNKNOWN, COLORS_CHESSBOARD, KEYBOARD_MASTER
	};

	void run();
	void update();
	void display();

	virtual ~Menu();
private:
	State state;
	bool exit;

	TypeOfGame typeOfGame;

	// Background
	sf::Texture tileTex;
//	int tilesW, tilesH;
	sf::Sprite bgTiles[tilesW][tilesH];

	// Features of the title screen
	Button gameMemoryBtn;
	Button gameKeyboardBtn;

	SpecialEffects specialEffects;

	sf::Clock startClk, gameStartedClk;

	// ******************** TO ENABLE SFML WORKS *****************
	sf::Event event;
	sf::RenderWindow* window;

	friend class Program;
};

#endif /* MENU_H_ */
