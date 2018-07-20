/*
 * Abstract class for every type of game choosen from main menu.
 */

#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	Game();
	virtual ~Game();

	virtual void run() = 0;
	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void display() = 0;
	virtual void clear() = 0;
};

#endif /* GAME_H_ */
