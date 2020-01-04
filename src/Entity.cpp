#include "Entity.h"



void Entity::initVariables()
{
	this->movementComponent = NULL;
	this->texture = NULL;
	this->sprite = NULL;
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
	delete this->sprite; //we delete sprite cuz it's inside, whereas texture is outside
}

//Component functions
void Entity::createMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(maxVelocity);
}
void Entity::createSprite(sf::Texture* texture)
{
 this->texture = texture;
 this->sprite = new sf::Sprite(*this->texture);
 //this->sprite->setTexture(*this->texture);
}

void Entity::setPosition(const float x, const float y)
{
	if (this->sprite)
	{
		this->sprite->setPosition(x, y);
	}
}


//Move
void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if(this->sprite && this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y); //sets velocity
		this->sprite->move(this->movementComponent->getVelocity() * dt); //this uses velocity
	}
}

//Update
void Entity::update(const float & /*dt*/)
{

}

//Render
void Entity::render(sf::RenderTarget * target)
{
	target->draw(*this->sprite);
}