#include "SettingsGameColorsChessboard.h"
SettingsGameColorsChessboard::SettingsGameColorsChessboard(
		SettingsListGameColorsChessboard &settings, sf::RenderWindow &window,
		bool & exitGame) :
		settingsList(settings), palettes { { 15, 10, window },
					{ 15, 95, window }, { 15, 180, window }, { 15, 265, window }, {
							15, 350, window }, { 15, 435, window } },
				scrollSecs4Reveal(window, 50, 620, 700, 3, 30, 11),
				scrollNumOfRounds(window, 820, 340, 200, 1, 6, 3),
				exit(exitGame),
				startBtn(window, 840, 570, 210, 95),
				specialEffects(static_cast<sf::Vector2f>(window.getSize()), true) {
	this->window = &window;
	state = SETTINGS;

	fontTahoma.loadFromFile("data/tahoma.ttf");
	infoLine1.setStyle(sf::Text::Bold);
	infoLine2.setStyle(sf::Text::Bold);
	infoLine1.setCharacterSize(26);
	infoLine2.setCharacterSize(26);
	infoLine1.setColor(sf::Color::White);
	infoLine2.setColor(sf::Color::White);
	infoLine1.setFont(fontTahoma);
	infoLine2.setFont(fontTahoma);
	infoLine1.setPosition(590, 50);
	infoLine2.setPosition(730, 100);
	infoLine1.setString("Choose number of colors to remember");
	infoLine2.setString("by clicking on some palette.");

	time4revealText.setFont(fontTahoma);
	time4revealText.setCharacterSize(30);
	time4revealText.setColor(sf::Color::Yellow);
	time4revealText.setPosition(30, 560);

	nRoundsText.setFont(fontTahoma);
	nRoundsText.setCharacterSize(30);
	nRoundsText.setColor(sf::Color::Yellow);
	nRoundsText.setPosition(740, 280);

	// ********* CREATE PALLETES OF AVAIBLE COLORS **********
	// 4 basic colors palette
	palettes[0].colors.push_back(new Memocolor(Red));
	palettes[0].colors.push_back(new Memocolor(Yellow));
	palettes[0].colors.push_back(new Memocolor(Green));
	palettes[0].colors.push_back(new Memocolor(Blue));

	// 5 colors palette
	palettes[1].colors.push_back(new Memocolor(Red));
	palettes[1].colors.push_back(new Memocolor(Yellow));
	palettes[1].colors.push_back(new Memocolor(Green));
	palettes[1].colors.push_back(new Memocolor(Blue));
	palettes[1].colors.push_back(new Memocolor(Purple));

	// 6 colors palette
	palettes[2].colors.push_back(new Memocolor(Red));
	palettes[2].colors.push_back(new Memocolor(Orange));
	palettes[2].colors.push_back(new Memocolor(Yellow));
	palettes[2].colors.push_back(new Memocolor(Green));
	palettes[2].colors.push_back(new Memocolor(Blue));
	palettes[2].colors.push_back(new Memocolor(Purple));

	// 7 colors palette
	palettes[3].colors.push_back(new Memocolor(Red));
	palettes[3].colors.push_back(new Memocolor(Orange));
	palettes[3].colors.push_back(new Memocolor(Yellow));
	palettes[3].colors.push_back(new Memocolor(Green));
	palettes[3].colors.push_back(new Memocolor(Blue));
	palettes[3].colors.push_back(new Memocolor(Purple));
	palettes[3].colors.push_back(new Memocolor(Pink));

	// 8 colors palette
	palettes[4].colors.push_back(new Memocolor(Red));
	palettes[4].colors.push_back(new Memocolor(Orange));
	palettes[4].colors.push_back(new Memocolor(Yellow));
	palettes[4].colors.push_back(new Memocolor(Green));
	palettes[4].colors.push_back(new Memocolor(Teal));
	palettes[4].colors.push_back(new Memocolor(Blue));
	palettes[4].colors.push_back(new Memocolor(Purple));
	palettes[4].colors.push_back(new Memocolor(Pink));

	// 9 colors palette
	palettes[5].colors.push_back(new Memocolor(Red));
	palettes[5].colors.push_back(new Memocolor(Brown));
	palettes[5].colors.push_back(new Memocolor(Orange));
	palettes[5].colors.push_back(new Memocolor(Yellow));
	palettes[5].colors.push_back(new Memocolor(Green));
	palettes[5].colors.push_back(new Memocolor(Teal));
	palettes[5].colors.push_back(new Memocolor(Blue));
	palettes[5].colors.push_back(new Memocolor(Purple));
	palettes[5].colors.push_back(new Memocolor(Pink));
}

void SettingsGameColorsChessboard::run(sf::Event &event) {
	specialEffects.brighten(400);
	// ***********************   MAIN LOOP  ************************* //
	while (!exit) {

		while (window->pollEvent(event)) {
			// ESC / force quit == back to menu
			if (event.type == sf::Event::Closed
					|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
							&& event.type == sf::Event::KeyPressed)) {
				exit = true;
			}
		}

		// Leave loop in case of change phase → game
		if (state == GAME)
			break;

		window->clear();
		update();
		display();
	}
	// ************************************************************** //
}

void SettingsGameColorsChessboard::update() {
	scrollSecs4Reveal.update();
	scrollNumOfRounds.update();
	startBtn.update();

	std::ostringstream ss;
	ss << "Time for reveal colors on board:	" << scrollSecs4Reveal.getValue()
			<< "s";
	time4revealText.setString(ss.str());

	std::ostringstream ss2;
	ss2 << "Number of rounds:	" << scrollNumOfRounds.getValue();
	nRoundsText.setString(ss2.str());

	if (startBtn.isPressed()) {
		state = PREGAME;
		toStartClk.restart();
		specialEffects.darken(300);
	}

	// Set clicked palette as active and disable others
	for (int i = 0; i < nPalletes; i++) {
		bool wasClicked = false;
		palettes[i].update(wasClicked);
		if (wasClicked) {
			for (int j = 0; j < nPalletes; j++) {
				palettes[j].active = false;
			}
			palettes[i].active = true;
			settingsList.chosenPalette = &palettes[i];
		}
	}
	settingsList.time4Remember = scrollSecs4Reveal.getValue();
	settingsList.nRounds = scrollNumOfRounds.getValue();
	specialEffects.update();

	switch (state) {
	case SETTINGS: {

	}
		break;
	case PREGAME: {
		if (toStartClk.getElapsedTime().asMilliseconds() > 320)
			state = GAME;
	}
		break;
	case GAME: {

	}
		break;
	}
}

void SettingsGameColorsChessboard::display() {
	window->draw(scrollSecs4Reveal);
	window->draw(scrollNumOfRounds);
	window->draw(startBtn);

	for (int i = 0; i < nPalletes; i++)
		window->draw(palettes[i]);

	window->draw(infoLine1);
	window->draw(infoLine2);
	window->draw(time4revealText);
	window->draw(nRoundsText);

	window->draw(specialEffects);
	window->display();
}

SettingsGameColorsChessboard::~SettingsGameColorsChessboard() {
}
