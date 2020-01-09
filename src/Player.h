#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
class Player :
	public Entity
{
private:
	//Variables


	//Initializer functions
	void initVariables();
	void initComponents();



public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();
	//Map of textures for player
	std::map<std::string, sf::Texture> playerTextures;


		//Functions
	virtual void update(const float& dt);


};
#endif
