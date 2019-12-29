#ifndef ENTITY_H
#define ENTITY_H
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
//Entity is our base for any type of character that we will have.
class Entity
{


private:

	//protected is basically a step between private and public
	//anything under protected may be accessed in the child class
	//I can access them directly, don't need getters or setters
	//a player is going to be entity, it can use anything in here
	//sorry, school =]
	//I am making these members protected... ;]
protected:
	//something temporary to move around
	sf::RectangleShape shape;
	float movementSpeed;

public:
		Entity();
		virtual ~Entity();

		//Functions
		virtual void move(const float& dt, const float dir_x, const float dir_y);
		virtual void update(const float& dt);
		virtual void render(sf::RenderTarget* target);
};

#endif