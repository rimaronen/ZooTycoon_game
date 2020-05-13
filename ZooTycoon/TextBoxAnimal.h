#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextBox.h"
class TextBoxAnimal:public TextBox
{
public:
	TextBoxAnimal();
	~TextBoxAnimal();
	void setPrice(std::string price);
	void draw(sf::RenderWindow & window);

};

