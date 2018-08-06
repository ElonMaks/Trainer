#include "GameKeyboardMaster.h"

GameKeyboardMaster::GameKeyboardMaster(sf::RenderWindow &window, LogBook &logs) :
		logBook(logs), specialEffects(
				static_cast<sf::Vector2f>(window.getSize()), true) {

	this->window = &window;

	currentTask = 0;
	nextTaskDelay = 0;

	// set background
	bgRectMain.setSize(static_cast<sf::Vector2f>(window.getSize()));
	bgRectMain.setFillColor(sf::Color(151, 110, 183));

	bgRectRight.setSize(static_cast<sf::Vector2f>(window.getSize()));
	bgRectRight.setFillColor(sf::Color(128, 74, 149));
	bgRectRight.setPosition(1450, -300);
	bgRectRight.setRotation(80);

	fontPorkys.loadFromFile("data/PORKYS.ttf");
	fontTahoma.loadFromFile("data/tahoma.ttf");

	phase = INTRO;
	exit = false;
}

void GameKeyboardMaster::run() {
	// run settings' screen and save it into variable
	SettingsGameKeyboardMaster settingsScreen(settings, *window, exit);
	settingsScreen.run(event);

	specialEffects.brighten(700);

	if (!exit)
		initialize();
	// ***********************   MAIN LOOP  ************************* //
	while (!exit) {
		while (window->pollEvent(event)) {
			// ESC / force quit = back to menu
			if (event.type == sf::Event::Closed
					|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
							&& event.type == sf::Event::KeyPressed)) {
				exit = true;
			}
		}
		update();

		window->clear();
		display();
	}
	// ************************************************************ //
}

void GameKeyboardMaster::initialize() {
	//todo create task list
	for(unsigned int i = 0; i < settings.chosenTasks.size(); i++) {
		//avaibleTasks.push_back(new TaskKeyboardThumbnaiyzwal(settings.chosenTasks[i].keys, 40, 210 + i * 50, *window));
		// todo nowe wyzwanie ! drugi konstruktor, tworzenie thumbnail z grupy klawiszy
	}

	// use current time as seed for random generator
	std::srand(std::time(NULL));

	// set 5 random tasks from avaible pool
	for (int i = 0; i < 5; i++) {
		int x = std::rand() % avaibleTasks.size();
		tasks.push_back(TaskKeyboard(avaibleTasks[x]->getKeys(), 40, 30, *window));
	}
}

void GameKeyboardMaster::update() {
	switch (phase) {
	case INTRO: {
		bgRectRight.setPosition(
				1850 - preStartTimer.getElapsedTime().asMilliseconds() / 2,
				bgRectRight.getPosition().y);

		if (preStartTimer.getElapsedTime().asMilliseconds() > 800) {
			bgRectRight.setPosition(1450, -300);
			startTimer.restart();
			phase = PRESTART;
		}

	}
		break;
	case PRESTART: {
		// countdown 3 2 1
		if (startTimer.getElapsedTime().asSeconds() < 3) {
			if (startTimer.getElapsedTime().asSeconds() > 2)
				textCountdown.setString("1");
			else if (startTimer.getElapsedTime().asSeconds() > 1)
				textCountdown.setString("2");
			else if (startTimer.getElapsedTime().asSeconds() > 0)
				textCountdown.setString("3");

			textCountdown.setFont(fontPorkys);
			textCountdown.setCharacterSize(140);
			textCountdown.setColor(sf::Color(255, 30, 0));
			textCountdown.setOrigin(textCountdown.getGlobalBounds().width / 2,
					textCountdown.getGlobalBounds().height / 2);
//			textCountdown.setPosition(360, 300); stare center
			textCountdown.setPosition(360,
					730
							- static_cast<int>(static_cast<float>(startTimer.getElapsedTime().asMilliseconds())
									/ 1) % 1000);

		} else {
			textCountdown.setColor(sf::Color{0, 0, 0, 0});
			phase = GAME;
		}
	}
		break;
	case GAME: {
		tasks[currentTask].update();
		if (tasks[currentTask].finished) {
			phase = ASSIGMENT_DONE;
			cl1.restart();
		}
	}
		break;
	case ASSIGMENT_DONE: {
		// make all elements of tasks transparent
		int transparency = cl1.getElapsedTime().asMilliseconds() / 2.2;
		if (transparency > 255) {
			transparency = 255;

			if (currentTask + 1 == tasks.size())
				phase = FINISHED;
			else {
				// Get random time between 0.4 - 1.7s
				nextTaskDelay = (std::rand() % 1300) + 400;
				nextClk.restart();
				phase = WAIT4NEXT_ASSIGMENT;
			}
			break;
		}

		for (unsigned int i = 0; i < tasks[currentTask].keys.size(); i++) {
			tasks[currentTask].keys[i]->keyImg.setColor(sf::Color { 255, 255,
					255, 255 - transparency });
			tasks[currentTask].keys[i]->keySign.setColor(sf::Color { 255, 255,
					255, 255 - transparency });
			// todo narazie z dp...
			tasks[currentTask].keys[i]->keyImg.move(0, -3);
			tasks[currentTask].keys[i]->keySign.move(0, -3);
		}
	}
		break;
	case WAIT4NEXT_ASSIGMENT: {
		// delay then go to next task
		if (nextClk.getElapsedTime().asMilliseconds() > nextTaskDelay) {
			currentTask++;
			phase = GAME;
		}
	}
		break;
	case FINISHED: {
		// todo trzeba teraz ładnie przyznać punkty
		exit = true;
	}
		break;
	}
}

void GameKeyboardMaster::display() {
	window->draw(bgRectMain);
	window->draw(bgRectRight);

	if (phase >= GAME) {
		if (currentTask < tasks.size())
			window->draw(tasks[currentTask]);
	}

	// show thumbnails of all avaible tasks
	for (unsigned int i = 0; i < avaibleTasks.size(); i++)
		window->draw(*avaibleTasks[i]);

	window->draw(textCountdown);
	window->draw(specialEffects);

	window->display();
}

void GameKeyboardMaster::clear() {
	//todo clear function
}

GameKeyboardMaster::~GameKeyboardMaster() {
}

