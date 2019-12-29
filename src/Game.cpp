#include "Game.h"

//Static functions

//Initializer for window
void Game::initWindow()
{


	/*Creates a SFML window using options from a window.ini file*/
	std::ifstream infilestream("config/window.ini");

	//Default window settings
	sf::VideoMode window_bounds(800, 600);
	std::string title = "None";
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	//Load window config settings from window ini file
	if(infilestream.is_open())
	{
		std::getline(infilestream, title);
		infilestream >> window_bounds.width >> window_bounds.height;
		infilestream >> framerate_limit;
		infilestream >> vertical_sync_enabled;
	}

	infilestream.close();
	this->window = new sf::RenderWindow(window_bounds, title);
	//Set frame rate, turn off vsync
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

//Initialize Keys
void Game::initKeys()
{
	this->supportedKeys.emplace("ESCAPE", sf::Keyboard::Key::Escape);
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

	//std::cout << this->supportedKeys.at("A") << "\n";
}


//Initialize State
void Game::initStates()
{
	//we push a game state as we initialize the state
	this->states.push(new GameState(this->window, &this->supportedKeys));
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



