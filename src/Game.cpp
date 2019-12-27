#include "Game.h"

//Static functions

//Initializer functions
void Game::initWindow()
{
	/*Creates a SFML window using options from a window.ini file*/
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML RPG");
	//Set frame rate, turn off vsync
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}
//Constructors/Destructors

Game::Game()
{

	//initialize a window
	this->initWindow();
}

Game::~Game()
{
	//Deletes the current window
	delete this->window;
}


//Functions


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

void Game::updateSFMLEvents()
{

		//update SFML window event to close when closed
		while (this->window->pollEvent(this->sfEvent))
		{
			if (this->sfEvent.type == sf::Event::Closed)
				this->window->close();
		}



}

void Game::update()
{
	//call update to check if window has closed
 this->updateSFMLEvents();

/* Testing to make delta time slow
 for(size_t i =0; i < 10000; i++)
 {
	 std::cout << "." << "\n";
 }
 */
}

void Game::render()
{

	//clear window that was rendered
 	this->window->clear();
	//Render items
		this->window->display();
}

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


