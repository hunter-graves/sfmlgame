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

	std::map<std::string, Button*> buttons;

	//Functions
	void initFonts();
	void initKeybinds();
	void initButtons();
	void updateButtons();
	void renderButtons(sf::RenderTarget* target = nullptr);
	public:
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
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
