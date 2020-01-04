#include "GameState.h"

//init keybinds
void GameState::initKeybinds()
{

	std::ifstream infilestream("config/gamestate_keybinds.ini");
	if (infilestream.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (infilestream >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

		infilestream.close();
	//WE CREATED FUNCTIONALITY that will used supported key a, d, w, s
	//which are all supported by our engine. Functionality is only for THIS state
	//so each state can have its own type of functionality based on each key.
	/*
	this->keybinds["CLOSE"] = this->supportedKeys->at("ESCAPE");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	*/
	//Later, we will be able to use files to load these keybinds in.
}

//Constructor
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
}

//Destructor
GameState::~GameState()
{

}


//Upodate input first
void GameState::updateInput(const float& dt)
{
	//we chekc if we are pressing keys here but we always check if quit has been
	//pressed
	this->checkForQuit();

//Update player input
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
	{
		this->player.move(dt, -1.f, 0.f);
	}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
	{
		this->player.move(dt, 1.f, 0.f);
	}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
	{
		this->player.move(dt, 0.f, -1.f);
	}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	{
		this->player.move(dt, 0.f, 1.f);
	}

}

//Updates
void GameState::update(const float& dt)
{
	//std::cout << "Hello from GameState!" << "\n";
	this->updateMousePositions();
	this->updateInput(dt);

	this->player.update(dt);
}



//Renders
void GameState::render(sf::RenderTarget* target)
{

	if(!target)
	{
		target = this->window;
	}
		this->player.render(target);



}

//State management
void GameState::endState()
{
	std::cout << "Ending GameState!" << "\n";
}




