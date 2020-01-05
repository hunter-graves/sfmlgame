#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <iostream>
#include <string>
#include <map>
#include <catch2/catch.hpp>
#include <PCH.hpp>
class AnimationComponent
{
private:
	class Animation
	{
	public:
		//Variables
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer;
		float timer; //the greater the animation timer, the slower the animation
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& texture_sheet,
				float animation_timer,
				int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
				: sprite(sprite), textureSheet(texture_sheet),
				animationTimer(animation_timer), width(width), height(height)
			{
				this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
				this->currentRect = this->startRect;
				this->endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);
				this->sprite.setTexture(this->textureSheet, true);
				this->sprite.setTextureRect(this->startRect);
			}
		//Functions
		void play(const float& dt)
		{
			/*update timer*/
			this->timer = 10.f * dt; //up and up and up and up
				if (this->timer >= this->animationTimer)
				{
					//reset timer
					//work on making this framerate independent later
					this->timer = 0.f;

					if(this->currentRect != this->endRect)
					{
						this->currentRect.left += this->width;
					}
					else //reset
					{
						this->currentRect.left = this->startRect.left;
					}
					this->sprite.setTextureRect(this->currentRect);
				}
		}


		void reset()
		{
			this->timer = 0.f;
			this->currentRect = this->startRect;

		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations; //we will add a bunch of animations to this

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();



	//Functions
	void addAnimation
	(
		const std::string key,
		float animation_timer,
		int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height
	);

	void play(const std::string key, const float& dt);

};
#endif