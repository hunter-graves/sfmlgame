#ifndef STATE_H
#define STATE_H

#include "Player.h"

//We keep resources in State
class State
{

	private:
//We need an array (vector) to keep resources
protected:
std::stack<State*>* states; //pointer to a state stack pointer, a way to save each state into the universal state stack from game.h
sf::RenderWindow* window;
std::map<std::string, int>* supportedKeys;
std::map<std::string, int> keybinds;
bool quit;


//Track mouse position
sf::Vector2i mousePosScreen; //unsigned +/- direc
sf::Vector2i mousePosWindow; //restricted to window size
sf::Vector2f mousePosView; //needs to be big
//Resources
std::map<std::string, sf::Texture> textures;

//Functions
virtual void initKeybinds() = 0;



//Virtuals are runtime polymorphic...
//used to ensure that the correct function is aclled for an object,
//regardless of the type of reference or pointer used for the func call
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	//If you inherit from state you MUST define an update and a render
	//in the child class. Virtual void ensures that we need to implement and override
	//these functions.
	const bool& getQuit() const;
	void endState();
	 //end state function to ensure that we always have a way to end our state

	virtual void updateInput(const float& dt) = 0; // similarly, every child class has to define update keybinds
	virtual void update(const float& dt) = 0; //we dont want to save all these things here we do it in the game engine itself
	//render keeps the context
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	virtual void updateMousePositions();

};

#endif