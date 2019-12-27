
#ifndef GAME_H
#define GAME_H

#include "State.h"
class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	//delta time (used a LOT)
	//keeps track of how long it took to do
	//one update and one render call
	//it's gonna reset itself, helps us make sure
	//when we move objects around we will multiply it by dt.
	//this allows us to move the same amount, balances it out depending on computer's frame rates
	float dt;


	//Initialization
	void initWindow();


public:
	//Constructor/Destructor

	Game();
	virtual ~Game();


	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif