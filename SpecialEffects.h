/*
 * Special effects to make cool transitions.
 *
 * Now only effects are darken(time) and brighten(time) entire screen.
 * To make effects works you have to update() and draw().
 */

#ifndef SPECIALEFFECTS_H_
#define SPECIALEFFECTS_H_

#include <SFML/Graphics.hpp>

class SpecialEffects: public sf::Drawable {
public:
	SpecialEffects(sf::Vector2f size, bool startDarken = false);
	~SpecialEffects(void);

	void darken(int time);
	void brighten(int time);

	enum Effect {
		NONE, DARKEN, BRIGHTEN
	};

	void update();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
	// Covering rectangle and its transparency
	sf::RectangleShape rect;
	int alpha;

	// Current effect which takes place now
	Effect effect;

	// Time from start of effect
	sf::Clock effectClk;
	int fullTime;

	// Min/max value on alpha
	int threshold;

};

#endif /* SPECIALEFFECTS_H_ */
