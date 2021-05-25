#include "MainMenuState.h"


void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(100.f, 100.f, 150.f, 50.f,
	 &this->font, "New Game", 50,
	sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
	sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["SETTINGS"] = new Button(100.f, 300.f, 150.f, 50.f,
	&this->font, "Settings", 50,
	sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
	sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EDITOR"] = new Button(100.f, 400.f, 150.f, 50.f,
	&this->font, "Editor", 50,
	sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
	sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EXIT_STATE"] = new Button(100.f, 500.f, 150.f, 50.f,
	&this->font, "Quit", 50,
	sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
	sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}


//Constructor
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initBackground();
}




//Destructor
MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


//fonts
void MainMenuState::initVariables()
{

}
void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)
		)
	);
	if(!this->backgroundTexture.loadFromFile("resources/images/background/background.png"))
	{
		throw "ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);

}

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

	std::ifstream infilestream("config/mainmenustate_keybinds.ini");
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





}

//Updates
void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();

	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
	//printf( "\033[2J" );

}

void MainMenuState::updateButtons()
{


	/* Updates all the buttons in this state and handles their functionality */
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	//new game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		//pointer to itself at all to push a state to its own state stack
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}


	//quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}


//Renders
void MainMenuState::render(sf::RenderTarget* target)
{

	if(!target)
	{
		target = this->window;
	}

	target->draw(this->background);
	this->renderButtons(target);

		//REMOVE LATER!!
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);

}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto &it : this->buttons)
	{
		it.second->render(target);
	}

}

//State management





