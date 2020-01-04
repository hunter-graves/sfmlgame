#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <catch2/catch.hpp>
#include <PCH.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};
class Button {

private:
	short unsigned buttonState;
	sf::RectangleShape shape; //button's basic shape
	sf::Font* font;
	sf::Text text;


	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;



public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	//Functions
	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
	//accessors
 	bool isPressed() const;




};

#endif