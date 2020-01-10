#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	: sprite(sprite), textureSheet(texture_sheet), previousAnimation(NULL)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto &i : this->animations)
	{
		delete i.second;
	}
}



void AnimationComponent::addAnimation
(
	const std::string key,
	float animation_timer,
	int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height

)
{

		this->animations[key] = new Animation
		(

			this->sprite, this->textureSheet, animation_timer,
			start_frame_x, start_frame_y,
			frames_x, frames_y,
			width, height
		);

}

void AnimationComponent::play(const std::string key, const float& dt)
{
	if(this->previousAnimation != this->animations[key])
	{
		if(this->previousAnimation == NULL)
			this->previousAnimation = this->animations[key];
		else
		{

				this->previousAnimation->reset();
				this->previousAnimation = this->animations[key];

		}

	}
	this->animations[key]->play(dt);
}

void AnimationComponent::checkTexture(int prev)
{
	reset(this->currentTexture.at(prev));
}
void AnimationComponent::reset(const std::string key)
{
	this->animations[key]->reset();
}