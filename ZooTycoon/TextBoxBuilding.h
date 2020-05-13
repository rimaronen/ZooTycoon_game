#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextBox.h"
class TextBoxBuilding :public TextBox
{
public:
	TextBoxBuilding();
	~TextBoxBuilding();
	void setPrice(std::string price);
	void draw(sf::RenderWindow & window);
};


