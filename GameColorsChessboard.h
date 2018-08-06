/*
 * Harder version of classic memory game where the player has to remember location of
 * 4-9 various colors on 8x8 matrix. The board is classic chessboard (to make this challenge
 * more comfortable then playing on blank matrix).
 *
 * Game starts with showing each of colors (from chosen palette selected in settings screen)
 * in randomly selected fields on the board for a few seconds (time is set in settings). Then
 * game is going into proper phase, where player is enable to drag colors from colorsToDrag
 * (MemocolorToDrag vector) and put them into any place on chessboard as tickFields
 * (MemocolorOnBoard). When every color is already dragged challenge is finished. Game comes
 * into phase of checking result - tickFields which are incorrect are getting hidden and after
 * a short delay player is able to see them in correct places. At the same time player receive
 * points for the correct ones. Then stage is clear and round counter raises.
 */

#ifndef GAMECOLORSCHESSBOARD_H_
#define GAMECOLORSCHESSBOARD_H_

#include "Game.h"
#include "Chessboard.h"
#include "LogBook.h"
#include "SettingsGameColorsChessboard.h"
#include "MemocolorOnBoard.h"
#include "MemocolorToDrag.h"
#include "SpecialEffects.h"
#include "HighlightFrame.h"
#include "GoodOrBadSign.h"

#include <vector>

class GameColorsChessboard: public Game {
public:
	GameColorsChessboard(sf::RenderWindow &window, LogBook &logs);
	void run();
	void initialize();
	void update();
	void display();
	void clear();

	// program states
	enum MemoryChessGamePhase {
		INTRO,
		PRESTART,
		EXPOSING,
		GAME,
		CHECKRESULT,
		SHOWRESULT,
		HIDERESULT,
	};

	~GameColorsChessboard();
private:
	// ********************* GENERAL ************************
	MemoryChessGamePhase phase;
	LogBook & logBook; 		// results of game are saved here
	int round;				// number of current round count up from 0
	int goodChoices;		// variable used for counting n° good choices

	// all the user settings
	SettingsListGameColorsChessboard settings;

	// number of colors in palette chosen in settings
	int nColors;

	SpecialEffects specialEffects;
	bool exit;

	// ******************* GAME COMPONENTS *******************
	Chessboard chessboard;

	// colors hidden under board which user has to remember
	std::vector<MemocolorOnBoard*> searchFields;

	// fields selected by player
	std::vector<MemocolorOnBoard*> tickFields;

	// memocolors which user can drag on board
	std::vector<MemocolorToDrag*> colorsToDrag;

	// results - tick or cross drawed at the end ofround
	std::vector<GoodOrBadSign*> resultSings;

	// to enable frame as red fields, when mouse hovers over them
	HighlightFrame highlightFrame;

	ChessboardField* currentField;
	Color currentColor;
	bool ifHandleIdle;

	// text field for: 3 2 1 (used in prestart phase)
	sf::Text textCountdown;

	// Field with information about player results /obsolete
//	sf::RectangleShape scoreRect;

	// timers
	sf::Clock preStartTimer, startTimer;
	sf::Clock endTimer;

	// other graphicals elements
	sf::RectangleShape bgRectMain;
	sf::RectangleShape bgRectRight;

	// fonts
	sf::Font fontPorkys, fontTahoma;

	// ******* RIGHT SIDE FIELD TODO IN NEW CLASS (with template 4 *)*******
	sf::Text playerText, playerLabel;
	sf::Text exerciseNumText, exerciseNumLabel;
	sf::Text time4RemText, time4RemLabel;

	sf::Text scoreText, scoreLabel;

	// ******************** TO ENABLE SFML WORKS *****************
	sf::RenderWindow* window;
	sf::Event event;

	friend class SettingsGameColorsChessboard;
};

#endif /* GAMECOLORSCHESSBOARD_H_ */
