#include "StaticItem.h"



StaticItem::StaticItem()
{
}

void StaticItem::setPosition(sf::Vector2f position)
{
	m_rect->setPosition(position);
	m_position = position;
}

StaticItem::StaticItem(sf::Texture * texture, const sf::Vector2f & size)
{
	m_texture.setSmooth(true);
	m_rect->setTexture(texture);
	m_rect->setOrigin({size.x / 2.0f, size.y / 2.0f });
	m_rect->setSize(size);
	
}

void StaticItem::draw(sf::RenderWindow& window)
{
	window.draw(*m_rect);
}



