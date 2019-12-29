#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"

class GameState :
	public State
{
	private:
	Entity player;

	public:
		GameState(sf::RenderWindow* window);
		virtual ~GameState();






	//Functions (pure virtual functions that were defined in State
	//must be defined here)
	void endState();
	void updateKeybinds(const float& dt);
	void update(const float& dt);
	//Can use "NULL" or 0 here (below) instead of nullptr..
	void render(sf::RenderTarget* target = nullptr); //can only have one default value for the paramter



};


#endif