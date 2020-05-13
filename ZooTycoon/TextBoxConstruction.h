#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextBox.h"
class TextBoxConstruction:public TextBox
{
public:
	TextBoxConstruction();
	~TextBoxConstruction();
	void setPrice(std::string price);
	void draw(sf::RenderWindow & window);

};

