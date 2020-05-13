#include "Savannah.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = '%';
const std::string Savannah::NAME = "Savannah";
bool Savannah::m_registerIt = Factory::registerTerrain(NAME, []() -> std::unique_ptr<Terrain> { return std::make_unique<Savannah>(); });
const sf::Vector2f IMAGE_SIZE{ 64, 40 };

Savannah::Savannah():Terrain(GameResources::instance().getsavannahTexture(),IMAGE_SIZE)
{
	m_symbol = symbol;
}
