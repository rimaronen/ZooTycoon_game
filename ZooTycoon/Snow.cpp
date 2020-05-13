#include "Snow.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = '^';
const std::string Snow::NAME = "Snow";
bool Snow::m_registerIt = Factory::registerTerrain(NAME, []() -> std::unique_ptr<Terrain> { return std::make_unique<Snow>(); });
const sf::Vector2f IMAGE_SIZE{ 64, 40 };

Snow::Snow():Terrain(GameResources::instance().getSnowTexture(),IMAGE_SIZE)
{
	m_symbol = symbol;
}
