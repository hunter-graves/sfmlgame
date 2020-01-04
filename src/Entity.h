#ifndef ENTITY_H
#define ENTITY_H

#include "components/MovementComponent.h"

//Entity is our base for any type of character that we will have.
class Entity
{


private:
	void initVariables();
	//protected is basically a step between private and public
	//anything under protected may be accessed in the child class
	//I can access them directly, don't need getters or setters
	//a player is going to be entity, it can use anything in here
	//sorry, school =]
	//I am making these members protected... ;]
protected:
	//something temporary to move around

	sf::Sprite sprite;
	sf::Texture* texture; //we don't want to  load a new texture every time we create an entity, that's why we have a pointer

	MovementComponent* movementComponent;

public:
		Entity();
		virtual ~Entity();

		//Component functions
		void setTexture(sf::Texture& texture);
		void createMovementComponent(const float maxVelocity);

		//Functions
		virtual void setPosition(const float x, const float y);
		virtual void move(const float& dt, const float dir_x, const float dir_y);
		virtual void update(const float& dt);
		virtual void render(sf::RenderTarget* target);
};

#endif