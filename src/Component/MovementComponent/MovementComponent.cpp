
#include "MovementComponent.h"

//Init movementcomponent variables
void MovementComponent::initVariables()
{

}

//Constructor
MovementComponent::MovementComponent(sf::Sprite& sprite,
 float maxVelocity, float acceleration, float deceleration) :
			sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration) //this initializer list. cant send in null to a reference, have to referenbce something
{

	this->initVariables();
}

//Destructor
MovementComponent::~MovementComponent()
{

}


//Accessors
const sf::Vector2f & MovementComponent::getVelocity() const
{
	return this->velocity;
}



//Functions
void MovementComponent::move(const float dir_x, const float dir_y, const float& /*dt*/)
{
		/*accelerating a sprite until it reaches the max velocity*/

	//Acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y +=  this->acceleration * dir_y;

	//if we move in positive direction, we are moving forward,
	//we will play forward animation
	/*if(dir_x > 0.f)
	{
		//can't be moving forward and backward at the same time
		this->movingForward = true;
		this->movingBackward = false;
	}*/

	//if we move in negative direction, we are moving backward
	//we will play backward animation
	/*if(dir_x < 0.f)
	{
		//can't be moving forward and backward at the same time
		this->movingBackward = true;
		this->movingForward = false;
	}*/



}


const bool MovementComponent::idle()
{
	//If our velocity vector is equal to 0, we have stopped moving completely,
	//so we are idle and we play idle animation
	if(this->velocity.x == 0.f && this->velocity.y == 0.f)
	{

		return true;
	}
		else
		return false;

}

const bool MovementComponent::forward() const
{
	if(this->velocity.x > 0.f)
	{
		return true;
	}
		else
		return false;
}

const bool MovementComponent::backward() const
{
	if(this->velocity.x < 0.f)
	{
		return true;
	}
		else
		return false;
}

const bool MovementComponent::up() const
{
	if(this->velocity.y < 0.f)
	{
		return true;
	}
		else
		return false;
}

const bool MovementComponent::down() const
{
	if(this->velocity.y > 0.f)
	{
		return true;
	}
		else
		return false;
}

void MovementComponent::update(const float & dt)
{
	/*Decelerates the sprite and controls the maximum velocity
	& moves the sprite. */


	//Deceleration
	if(this->velocity.x > 0.f) //check for right
	{

		//Max velocity checks
		if(this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//Deceleration y positive
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}

	else if(this->velocity.x < 0.f) //check for neg x
	{
		//Max velocity check for positive x
		if(this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

	//Deceleration
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}


	//Deceleration y
	if(this->velocity.y > 0.f) //check for right
	{

		//Max velocity checks
		if(this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Deceleration y positive
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}

	else if(this->velocity.y < 0.f) //check for neg y
	{
		//Max velocity check for positive y
		if(this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

	//Deceleration y
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}
	//Final move
 	this->sprite.move(this->velocity * dt); // uses velocity
}

