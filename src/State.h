#ifndef STATE_H
#define STATE_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <catch2/catch.hpp>
#include <PCH.hpp>

//We keep resources in State
class State
{
//We need an array (vector) to keep resources
private:
sf::RenderWindow* window;
std::vector<sf::Texture> textures;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	//If you inherit from state you MUST define an update and a render
	//in the child class. Virtual void ensures that we need to implement and override
	//these functions.
	virtual void endState() = 0; //end state function to ensure that we always have a way to end our state
	virtual void update(const float& dt) = 0;
	//render keeps the context
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

#endif