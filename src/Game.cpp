#include "Game.h"

//Static functions

//Initializer for variables

void Game::initVariables()
{
	this->window = NULL;
	this->fullscreen = false;

	this->dt = 0.f;
}
//Initializer for window
void Game::initWindow()
{


	/*Creates a SFML window using options from a window.ini file*/
	std::ifstream infilestream("config/window.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	//Default window settings
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	std::string title = "None";
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialising_level = 0;

	//Load window config settings from window ini file
	if(infilestream.is_open())
	{
		std::getline(infilestream, title);
		infilestream >> window_bounds.width >> window_bounds.height;
		infilestream >> fullscreen;
		infilestream >> framerate_limit;
		infilestream >> vertical_sync_enabled;
		infilestream >> antialising_level;
	}

	infilestream.close();

	this->fullscreen = fullscreen;
	windowSettings.antialiasingLevel = antialising_level;
	if(fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
	else
		 this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);

	//Set frame rate, turn off vsync
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

//Initialize Keys
void Game::initKeys()
{

	std::ifstream infilestream("config/gamestate_keybinds.ini");

	if (infilestream.is_open())
	{
		std::string key ="";
		int key_value = 0;
		while (infilestream >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}
	}
	this->supportedKeys["ESCAPE"] = sf::Keyboard::Key::Escape;
	this->supportedKeys["A"] = sf::Keyboard::Key::A;
	this->supportedKeys["D"] = sf::Keyboard::Key::D;
	this->supportedKeys["W"] = sf::Keyboard::Key::W;
	this->supportedKeys["S"] = sf::Keyboard::Key::S;

	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << "\n";
	}

		//DEBUG PRINT (REMOVE LATER)
	//std::cout << this->supportedKeys.at("A") << "\n";
}


//Initialize State
void Game::initStates()
{
	//we push a game state as we initialize the state
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
	//this->states.push(new GameState(this->window, &this->supportedKeys));
}
//Constructors/Destructors

Game::Game()
{

	//initialize a window
	this->initWindow();
	this->initKeys();
	this->initStates();

}

Game::~Game()
{
	//Deletes the current window
	delete this->window;
	while(!this->states.empty())
	{
		delete this->states.top(); //this removes the data that the ptr is holding
		this->states.pop(); //this removes the actual ptr
	}
}


//Functions

//End Application
void Game::endApplication()
{
	std::cout << "End Application" << "\n";
}

//Update
void Game::update()
{
//call update to check if window has closed
 this->updateSFMLEvents();


	if(!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if(this->states.top()->getQuit())
		{
			this->states.top()->endState();
			//When we quit the game we need to do some quitty things...
			//save a char, play an animation, etc...
			//we could do this in the destructor
			delete this->states.top();
			this->states.pop();
		}
	}


	//End of Application
	else
	{
		this->endApplication();
		this->window->close(); //this would just close the game completely
	}
}

//UpdateDT
void Game::updateDt()
{
	//update DT w/ the time it takes to update and render one frame (top of the while loop in run)

	//get delta time as seconds
	this->dt = this->dtClock.restart().asSeconds();

	//Track delta time, it will slow down the more that is happening
	//in the game
	//std::cout << this->dt << "\n";
	//printf( "\033[2J" );
}

//UpdateSFML
void Game::updateSFMLEvents()
{

		//update SFML window event to close when closed
		while (this->window->pollEvent(this->sfEvent))
		{
			if (this->sfEvent.type == sf::Event::Closed)
			{
				this->window->close();
			}
		}



}


//Render
void Game::render()
{

	//clear window that was rendered
 	this->window->clear();
	//Render items
	if(!this->states.empty())
	{
		this->states.top()->render();
	}
	this->window->display();
}

//Core
void Game::run()
{

	//run the window, update and render
	while (this->window->isOpen())
	{

		//update DT, save how long, and use it
		this->updateDt();
		this->update();
		this->render();
	}
}



