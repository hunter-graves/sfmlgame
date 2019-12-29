#ifndef STATE_H
#define STATE_H

#include "Entity.h"

//We keep resources in State
class State
{
//We need an array (vector) to keep resources
protected:
sf::RenderWindow* window;
std::vector<sf::Texture> textures;
bool quit;

private:


//Virtuals are runtime polymorphic...
//used to ensure that the correct function is aclled for an object,
//regardless of the type of reference or pointer used for the func call
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	//If you inherit from state you MUST define an update and a render
	//in the child class. Virtual void ensures that we need to implement and override
	//these functions.
	const bool& getQuit() const;
	virtual void endState() = 0; //end state function to ensure that we always have a way to end our state
	virtual void checkForQuit();
	virtual void updateKeybinds(const float& dt) = 0; // similarly, every child class has to define update keybinds
	virtual void update(const float& dt) = 0; //we dont want to save all these things here we do it in the game engine itself
	//render keeps the context
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

#endif