/*
 * Abstract class for each screen before game.
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "Global.h"

#include <SFML/Graphics.hpp>

class Settings {
public:
	Settings();
	virtual ~Settings();

	virtual void run(sf::Event &event) = 0;
};

#endif /* SETTINGS_H_ */
