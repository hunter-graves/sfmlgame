#include "Player.h"

//Initializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}

//Constructor
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();
	this->setPosition(x, y);

	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 13, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_FORWARD", 10.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_UP", 10.f, 0, 0, 12, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_DOWN", 10.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_BACKWARD", 10.f, 0, 0, 16, 0, 410, 410);

}

//Destructor
Player::~Player()
{

}

//Functions
void Player::update(const float& dt)
{
	//Entity::update(dt);
	this->movementComponent->update(dt);
	if(this->movementComponent->idle())
	this->animationComponent->play("IDLE_LEFT", dt);
		 if(this->movementComponent->up())
		this->animationComponent->play("WALK_UP", dt);
		 if(this->movementComponent->backward())
		this->animationComponent->play("WALK_BACKWARD", dt);
		if(this->movementComponent->forward())
		this->animationComponent->play("WALK_FORWARD", dt);
		 if(this->movementComponent->down())
		this->animationComponent->play("WALK_DOWN", dt);
	//else
	//{
		//this->setTexture(this->textures["PLAYER_WALK_SHEET"]);
	//	this->animationComponent->play("WALK_LEFT", dt);
	//}


}
