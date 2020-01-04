#include "MainMenuState.h"

//Constructor
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();
	this->gamestate_btn = new Button(100, 100, 150, 50, &this->font, "New Game",
	sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}




//Destructor
MainMenuState::~MainMenuState()
{
	delete this->gamestate_btn;
}

#include "GameState.h"


//fonts

void MainMenuState::initFonts()
{
	if(!this->font.loadFromFile("fonts/good-times-rg.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}
//init keybinds
void MainMenuState::initKeybinds()
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



//Upodate input first
void MainMenuState::updateInput(const float& /*dt*/)
{
	//we chekc if we are pressing keys here but we always check if quit has been
	//pressed

	this->checkForQuit();



}

//Updates
void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->gamestate_btn->update(this->mousePosView);
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	//printf( "\033[2J" );
}



//Renders
void MainMenuState::render(sf::RenderTarget* target)
{

	if(!target)
	{
		target = this->window;
	}

	target->draw(this->background);

	this->gamestate_btn->render(target);




}

//State management
void MainMenuState::endState()
{
	std::cout << "Ending GameState!" << "\n";
}




