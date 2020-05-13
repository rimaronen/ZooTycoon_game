#include "Tree.h"
#include "Factory.h"
#include "GameResources.h"

const char symbol = 'T';
const std::string Tree::NAME = "Tree";
bool Tree::m_registerIt = Factory::registerConstruction(NAME, []()->std::unique_ptr<ConstructionItem> { return std::make_unique<Tree>(); });
const sf::Vector2f IMAGE_SIZE{ 226,  194 };

Tree::Tree() :ConstructionItem(GameResources::instance().getTreeTexture(), IMAGE_SIZE)
{
	m_symbol = symbol;
}
