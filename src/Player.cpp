#include "Player.h"

//Initializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{
	this->createMovementComponent(300.f, 15.f, 5.f);
}

//Constructor
Player::Player(float x, float y, sf::Texture& texture)
{
	this->initVariables();
	this->initComponents();
	this->setTexture(texture);
	this->setPosition(x, y);
}

//Destructor
Player::~Player()
{

}

