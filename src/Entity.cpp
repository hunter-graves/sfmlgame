#include "Entity.h"



void Entity::initVariables()
{
	this->movementComponent = NULL;
}
//Constructor
Entity::Entity()
{
	//Something temporrary to move around
	this->initVariables();
}

//Destructor
Entity::~Entity()
{
	delete this->movementComponent;//we delete sprite cuz it's inside, whereas texture is outside
	delete this->animationComponent;
}

void Entity::setTexture(sf::Texture& texture)
{

 this->sprite.setTexture(texture);
 //this->sprite->setTexture(*this->texture);
}



//Component functions
void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}


void Entity::createAnimationComponent(sf::Texture & texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void Entity::setPosition(const float x, const float y)
{
		this->sprite.setPosition(x, y);

}


//Move
void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if(this->movementComponent)
	{

		this->movementComponent->move(dir_x, dir_y, dt); //sets velocity
	}
}

void Entity::setPrev(int prev)
{
	this->previous = prev;
}
int Entity::getPrev()
{
	return this->previous;
}

/*
void Entity::setPreviousXPosition(float previousXPosition)
{
	this->previousXPosition = previousXPosition;
}

float Entity::getPreviousXPosition()
{
	return this->previousXPosition;
}
void Entity::setCoordinates(sf::Vector2f coordinates)
{
	this->coordinates.x = coordinates.x;
	this->coordinates.y = coordinates.y;
}
sf::Vector2f Entity::getCoordinates()
{
	return this->coordinates;
}
*/

//Update
void Entity::update(const float & dt)
{
	if(this->movementComponent)
		this->movementComponent->update(dt);
}

//Render
void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}