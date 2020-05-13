#pragma once
#include "MapItem.h"


class StaticItem : public MapItem
{
public:
	StaticItem();
	virtual void setPosition(sf::Vector2f position) override;
	StaticItem(sf::Texture * texture, const sf::Vector2f & size);
	virtual void draw(sf::RenderWindow& window);
	virtual const sf::Vector2f& getPosition() override { return m_rect->getPosition(); }
	void setTexture(sf::Texture * texture) { m_rect->setTexture(texture); }
	virtual const sf::FloatRect& getGlobalBounds() const override { return std::move(m_rect->getGlobalBounds()); }
	bool isPressed(const sf::Vector2f& pos) { return m_rect->getGlobalBounds().contains(pos); }
	virtual void increaseZooMoney(int amount) { m_price += amount; }
	virtual void decreaseZooMoney(int amount) { m_price -= amount; }
private:
	sf::Vector2f m_position;
};

