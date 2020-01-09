#include "Player.h"

//Initializer functions
void Player::initVariables()
{
	//movement int state
	this->setPrev(0);
	//Idles
		if (!this->playerTextures["PLAYER_IDLE_RIGHT"].loadFromFile("resources/images/player/idle-right-animation.png")) //idle right
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}

			if (!this->playerTextures["PLAYER_IDLE_BR"].loadFromFile("resources/images/player/idle-down-right.png")) //idle down right
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}


		if (!this->playerTextures["PLAYER_IDLE_DL"].loadFromFile("resources/images/player/idle-down-left.png")) //idle down left
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}

		if (!this->playerTextures["PLAYER_IDLE_UL"].loadFromFile("resources/images/player/idle-up-left.png")) //idle up left
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}

		if (!this->playerTextures["PLAYER_IDLE_UR"].loadFromFile("resources/images/player/idle-up-right.png")) //idle up right
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}

	//Walks
			if (!this->playerTextures["PLAYER_WALK_FORWARD"].loadFromFile("resources/images/player/walk-forward.png")) //walk right
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}

		if (!this->playerTextures["PLAYER_WALK_BACKWARD"].loadFromFile("resources/images/player/walk-backward.png")) //walk left
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}
		if (!this->playerTextures["PLAYER_WALK_UP"].loadFromFile("resources/images/player/walk-up.png")) //walk up
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}
		if (!this->playerTextures["PLAYER_WALK_DOWN"].loadFromFile("resources/images/player/walk-down.png")) //walk down
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}
		if (!this->playerTextures["PLAYER_WALK_DR"].loadFromFile("resources/images/player/walk-down-right.png")) //walk down right
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}
		if (!this->playerTextures["PLAYER_WALK_DL"].loadFromFile("resources/images/player/walk-down-left.png")) //walk down left
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}
		if (!this->playerTextures["PLAYER_WALK_UL"].loadFromFile("resources/images/player/walk-up-left.png")) //walk up left
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}
			if (!this->playerTextures["PLAYER_WALK_UR"].loadFromFile("resources/images/player/walk-up-right.png")) //walk up right
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_WALK_TEXTURE";
	}

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

	/*this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 14, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_FORWARD", 10.f, 0, 0, 7, 0, 96, 64);
	this->animationComponent->addAnimation("WALK_UP", 10.f, 0, 0, 14, 0, 180, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 10.f, 0, 0, 6, 0, 96, 64);
	//this->animationComponent->addAnimation("WALK_BACKWARD", 10.f, 0, 0, 16, 0, 410, 410);*/

	//walk animation component
	this->animationComponent->addAnimation("WALK_FORWARD", 2.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_UP", 2.f, 0, 0, 12, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_DOWN", 2.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_BACKWARD", 2.f, 0, 0, 15, 0, 410, 410);
	//diagonal walk
	this->animationComponent->addAnimation("WALK_UL", 2.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_UR", 2.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_DL", 2.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("WALK_DR", 2.f, 0, 0, 15, 0, 410, 410);
	//Idle animation component
	this->animationComponent->addAnimation("IDLE_RIGHT", 5.f, 0, 0, 13, 0, 410, 410);
	this->animationComponent->addAnimation("IDLE_LEFT", 5.f, 0, 0, 13, 0, 410, 410);
	//diagonal idle
	this->animationComponent->addAnimation("IDLE_UL", 2.f, 0, 0, 14, 0, 410, 410);
	this->animationComponent->addAnimation("IDLE_DL", 2.f, 0, 0, 16, 0, 410, 410);
	this->animationComponent->addAnimation("IDLE_UR", 2.f, 0, 0, 15, 0, 410, 410);
	this->animationComponent->addAnimation("IDLE_DR", 2.f, 0, 0, 12, 0, 410, 410);


}

//Destructor
Player::~Player()
{

}

//Functions
void Player::update(const float& dt)
{

	this->movementComponent->update(dt);
	if(this->movementComponent->idle())
	{

		this->setTexture(this->playerTextures["PLAYER_IDLE_RIGHT"]);
		this->animationComponent->play("IDLE_RIGHT", dt);
	}

		else if(this->movementComponent->up())
		{

			if(this->movementComponent->forward())
			{
				this->setPrev(2);
				this->setTexture(this->playerTextures["PLAYER_WALK_UR"]);
				this->animationComponent->play("WALK_UR", dt);
				if(this->getPrev() != 2)
				this->animationComponent->checkTexture(this->getPrev());
			}
			else if(this->movementComponent->backward())
			{
				this->setPrev(3);
				this->setTexture(this->playerTextures["PLAYER_WALK_UL"]);
				this->animationComponent->play("WALK_UL", dt);
				if(this->getPrev() != 3)
					this->animationComponent->checkTexture(this->getPrev());
			}
			else
			{
				this->setPrev(1);
				this->setTexture(this->playerTextures["PLAYER_WALK_UP"]);
				this->animationComponent->play("WALK_UP", dt);
				if(this->getPrev() != 1)
					this->animationComponent->checkTexture(this->getPrev());

			}


		}

		else if(this->movementComponent->down())
		{
			if(this->movementComponent->forward())
			{
				this->setPrev(5);
				this->setTexture(this->playerTextures["PLAYER_WALK_DR"]);
				this->animationComponent->play("WALK_DR", dt);
				if(this->getPrev() != 5)
					this->animationComponent->checkTexture(this->getPrev());
			}
			else if(this->movementComponent->backward())
			{
				this->setPrev(6);
				this->setTexture(this->playerTextures["PLAYER_WALK_DL"]);
				this->animationComponent->play("WALK_DL", dt);
				if(this->getPrev() != 6)
					this->animationComponent->checkTexture(this->getPrev());
			}
			else
			{
				this->setPrev(4);
				this->setTexture(this->playerTextures["PLAYER_WALK_DOWN"]);
				this->animationComponent->play("WALK_DOWN", dt);
				if(this->getPrev() != 4)
					this->animationComponent->checkTexture(this->getPrev());
			}

		}

		 else if(this->movementComponent->backward())
		{
			this->setPrev(7);
			this->setTexture(this->playerTextures["PLAYER_WALK_BACKWARD"]);
			this->animationComponent->play("WALK_BACKWARD", dt);
			if(this->getPrev() != 7)
				this->animationComponent->checkTexture(this->getPrev());
		}

		else if(this->movementComponent->forward())
		{
			this->setPrev(8);
			this->setTexture(this->playerTextures["PLAYER_WALK_FORWARD"]);
			this->animationComponent->play("WALK_FORWARD", dt);
			if(this->getPrev() != 8)
				this->animationComponent->checkTexture(this->getPrev());
		}





}
