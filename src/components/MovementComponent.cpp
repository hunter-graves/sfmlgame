#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,
 float maxVelocity, float acceleration, float deceleration) :
			sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration) //this initializer list. cant send in null to a reference, have to referenbce something
{

	//this->maxVelocity = maxVelocity;
}

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

