#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window;
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