#include "GameState.h"


//Constructor
GameState::GameState(sf::RenderWindow* window)
	: State(window)
{

}

//Destructor
GameState::~GameState()
{

}

//Updates
void GameState::update(const float& dt)
{
	std::cout << "Hello from GameState!" << "\n";
	this->updateKeybinds(dt);

	this->player.update(dt);
}

void GameState::updateKeybinds(const float & /*dt*/)
{
	//we chekc if we are pressing keys here but we always check if quit has been
	//pressed
	this->checkForQuit();

}

//Renders
void GameState::render(sf::RenderTarget* /*target*/)
{
	this->player.render(this->window);

}

//State management
void GameState::endState()
{
	std::cout << "Ending GameState!" << "\n";
}


