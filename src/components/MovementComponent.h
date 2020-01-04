#ifndef MOVEMMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H
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
class MovementComponent
{
private:
	sf::Sprite& sprite;
	float maxVelocity;


	//Initializer functions
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;

public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity);
	virtual ~MovementComponent();

	//Accesors
	const sf::Vector2f& getVelocity() const;

	//Functions
	void update(const float& dt);
	void move(const float x, const float y, const float& dt);

};

#endif