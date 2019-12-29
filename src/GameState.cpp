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

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << "\n";
	}
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


}

//State management
void GameState::endState()
{
	std::cout << "Ending GameState!" << "\n";
}


