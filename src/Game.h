
#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	sf::Clock dtClock;
	//delta time (used a LOT)
	//keeps track of how long it took to do
	//one update and one render call
	//it's gonna reset itself, helps us make sure
	//when we move objects around we will multiply it by dt.
	//this allows us to move the same amount, balances it out depending on computer's frame rates
	float dt;

	//State is an abstract class, we can only create references to it (pointers) rather
	//than state objects. When we go from menu state into game state and save and exit, we throw
	//away the game state and our new top state is main menu because it was right below game state!
	std::stack<State*> states;



	//Map
	std::map<std::string, int> supportedKeys;
	//Initialization
	void initWindow();

	//add supported keys
	void initKeys();

	//private function that pushes one state
	void initStates();




public:
	//Constructor/Destructor

	Game();
	virtual ~Game();


	//Functions


	//End Application

	void endApplication();
	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

#endif