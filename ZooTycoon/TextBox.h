#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
class TextBox
{
public:
	TextBox();
	~TextBox();
	//for building a text box
	sf::Text build(double money,int CharacterSize,sf::Vector2f pos, sf::Text m_text);
protected:
	sf::Text text;
	sf::Text m_text;
};

