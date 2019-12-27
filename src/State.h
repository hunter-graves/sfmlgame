#ifndef STATE_H
#define STATE_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <catch2/catch.hpp>
#include <PCH.hpp>

//We keep resources in State
class State
{
//We need an array (vector) to keep resources
private:
std::vector<sf::Texture> textures;

public:
	State();
	virtual ~State();

	//If you inherit from state you MUST define an update and a render
	//in the child class. Virtual void ensures that we need to implement and override
	//these functions.
	virtual void update() = 0;
	virtual void render() = 0;

};

#endif