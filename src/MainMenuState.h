#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "GameState.h"
#include "Button.h"

class MainMenuState :
	public State
{
	private:
	//private variables
	sf::RectangleShape background;
	sf::Font font;

	Button* gamestate_btn;
	//Functions
	void initFonts();
	void initKeybinds();
	public:
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		virtual ~MainMenuState();






	//Functions (pure virtual functions that were defined in State
	//must be defined here)
	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	//Can use "NULL" or 0 here (below) instead of nullptr..
	void render(sf::RenderTarget* target = nullptr); //can only have one default value for the paramter


};
#endif
