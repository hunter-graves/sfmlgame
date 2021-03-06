#ifndef ENTITY_H
#define ENTITY_H

#include "components/MovementComponent.h"
#include "components/AnimationComponent.h"

//Entity is our base for any type of character that we will have.
class Entity
{


private:
	void initVariables();
	int previous;

	//float previousXPosition;
	//protected is basically a step between private and public
	//anything under protected may be accessed in the child class
	//I can access them directly, don't need getters or setters
	//a player is going to be entity, it can use anything in here
	//sorry, school =]
	//I am making these members protected... ;]
protected:
	//something temporary to move around

	sf::Sprite sprite;
	//sf::Texture* texture; //we don't want to  load a new texture every time we create an entity, that's why we have a pointer

	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;


	//sf::Vector2f coordinates;

public:
		Entity();
		virtual ~Entity();

		//Component functions
		void setTexture(sf::Texture& texture);
		void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
		void createAnimationComponent(sf::Texture& texture_sheet);

		//Functions
		//void setPreviousXPosition(float previousXPosition);
		//float getPreviousXPosition();
		//void setCoordinates(sf::Vector2f coordinates);
		//sf::Vector2f getCoordinates();
		virtual void setPosition(const float x, const float y);
		virtual void move(const float dir_x, const float dir_y, const float& dt);
		virtual void update(const float& dt);
		virtual void render(sf::RenderTarget* target);
		void setPrev(int prev);
		int getPrev();
};

#endif