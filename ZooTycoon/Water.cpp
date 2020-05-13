#include "Water.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = '@';
const std::string Water::NAME = "Water";
bool Water::m_registerIt = Factory::registerTerrain("Water", []() -> std::unique_ptr<Terrain> { return std::make_unique<Water>(); });
const sf::Vector2f IMAGE_SIZE{ 64, 40 };

Water::Water():Terrain(GameResources::instance().getWaterTexture(),IMAGE_SIZE)
{
	m_symbol = symbol;
}
