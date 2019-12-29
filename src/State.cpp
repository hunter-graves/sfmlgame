#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->quit = false;
}

State::~State()
{

}

const bool & State::getQuit() const
{

	//if the function wants to quit, we quit
	return this->quit;
}
void State::checkForQuit()
{

	//evaluate quit to true if escape is pressed
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}