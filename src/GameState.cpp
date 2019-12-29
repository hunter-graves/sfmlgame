#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window)
{

}

GameState::~GameState()
{

}


void GameState::update(const float& dt)
{
	std::cout << "Hello from GameState!" << "\n";
	this->updateKeybinds(dt);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << "\n";
	}
}

void GameState::render(sf::RenderTarget* target)
{


}

void GameState::updateKeybinds(const float & dt)
{
	//we chekc if we are pressing keys here but we always check if quit has been
	//pressed
	this->checkForQuit();

}

void GameState::endState()
{
	std::cout << "Ending GameState!" << "\n";
}
