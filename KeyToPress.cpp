#include "KeyToPress.h"

KeyToPress::KeyToPress(WhichKey whichKey, bool small, int x, int y, sf::Font & font)
{
	keyState = DEFAULT;

	keySign.setFont(this->font = font);

	keyTex.loadFromFile("data/key.bmp");
	keyImg.setTexture(keyTex);
	keyImg.setPosition(x, y);

	keySign.setColor(sf::Color::Yellow);

	if (!small) {
		keySign.setPosition(x + 18, y + 8);
		keySign.setCharacterSize(32);
	} else {
		keySign.setPosition(x + 10, y + 5);
		keySign.setCharacterSize(24);
		keyImg.setScale(0.75, 0.75);
	}
	keySign.setStyle(sf::Text::Bold);

	switch (whichKey) {
	case KEY_1: {
		keySign.setString("1");
		key = sf::Keyboard::Num1;
	}
		break;
	case KEY_2: {
		keySign.setString("2");
		key = sf::Keyboard::Num2;
	}
		break;
	case KEY_3: {
		keySign.setString("3");
		key = sf::Keyboard::Num3;
	}
		break;
	case KEY_4: {
		keySign.setString("4");
		key = sf::Keyboard::Num4;
	}
		break;
	case KEY_5: {
		keySign.setString("5");
		key = sf::Keyboard::Num5;
	}
		break;
	case KEY_6: {
		keySign.setString("6");
		key = sf::Keyboard::Num6;
	}
		break;
	case KEY_7: {
		keySign.setString("7");
		key = sf::Keyboard::Num7;
	}
		break;
	case KEY_8: {
		keySign.setString("8");
		key = sf::Keyboard::Num8;
	}
		break;
	case KEY_9: {
		keySign.setString("9");
		key = sf::Keyboard::Num9;
	}
		break;
	case KEY_0: {
		keySign.setString("0");
		key = sf::Keyboard::Num0;
	}
		break;
	case KEY_a: {
		keySign.setString("A");
		key = sf::Keyboard::A;
	}
		break;
	case KEY_s: {
		keySign.setString("S");
		key = sf::Keyboard::S;
	}
		break;
	case KEY_m: {
		keySign.setString("M");
		key = sf::Keyboard::M;
	}
		break;
	case KEY_h: {
		keySign.setString("H");
		key = sf::Keyboard::H;
	}
		break;
	case KEY_z: {
		keySign.setString("Z");
		key = sf::Keyboard::Z;
	}
		break;
	case KEY_q: {
		keySign.setString("Q");
		key = sf::Keyboard::Q;
	}
		break;
	case KEY_w: {
		keySign.setString("W");
		key = sf::Keyboard::W;
	}
		break;
	case KEY_e: {
		keySign.setString("E");
		key = sf::Keyboard::Z;
	}
		break;
	case KEY_r: {
		keySign.setString("R");
		key = sf::Keyboard::R;
	}
		break;
	}
}

KeyToPress::KeyToPress(const KeyToPress& org) {
	keyState = org.keyState;
	key = org.key;
	keyTex = org.keyTex;
	keyImg = org.keyImg;

	keyImg.setTexture(keyTex);

	font = org.font;
	keySign = org.keySign;
}

void KeyToPress::update() {
	switch (keyState) {
	case DEFAULT: {
		keySign.setColor(sf::Color::Yellow);
	}
		break;
	case GOOD: {
		keySign.setColor(sf::Color::Green);
	}
		break;
	case BAD: {
		keySign.setColor(sf::Color::Red);
	}
		break;
	}
}

void KeyToPress::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(keyImg);
	target.draw(keySign);
}

KeyToPress::~KeyToPress() {
}
