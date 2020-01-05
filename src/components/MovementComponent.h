#pragma GCC diagnostic ignored "-Wignored-qualifiers"
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
	sf::Vector2f velocity;
	float acceleration;
	float deceleration;

	//Initializer functions


public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float deceleration, float acceleration);
	virtual ~MovementComponent();

	//Accesors
	const sf::Vector2f& getVelocity() const;

	//Functions
	const bool idle() const;
	const bool forward() const;
	const bool backward() const;
	const bool up() const;
	const bool down() const;
	void update(const float& dt);
	void move(const float x, const float y, const float& dt);

};

#endif