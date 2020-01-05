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
}

//Component functions
void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}
void Entity::setTexture(sf::Texture& texture)
{

 this->sprite.setTexture(texture);
 //this->sprite->setTexture(*this->texture);
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