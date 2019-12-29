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


	public:
		Entity();
		virtual ~Entity();

		//Functions
		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget& target) = 0;
};

#endif