#include "WomanGuest.h"
#include "Factory.h"
#include "GameResources.h"


const sf::Vector2f IMAGE_SIZE{ 60, 60 };
const sf::Vector2u IMAGE_COUNT{ 8, 1 };
const sf::Vector2u IMAGE_RANGE_WALK_UP{ 0,6 };


// animation indexes
const size_t ANIM_WALK_UP = 0;
const size_t ANIM_WALK_DOWN = 1;
const size_t ANIM_WALK_LEFT = 2;
const size_t ANIM_WALK_RIGHT = 3;

const std::string WomanGuest::NAME = "WomanGuest";
bool WomanGuest::m_registerIt = Factory::registerGuest(NAME, []() -> std::unique_ptr<Guest> { return std::make_unique<WomanGuest>(); });
const char symbol = 'W';

WomanGuest::WomanGuest()
{
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getWomenTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE),
		std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getWomenTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE),
		std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getWomenTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE),
		std::make_unique<Sound>());
	addAnimationAndSound(std::make_unique<DynamicItemAnimation>(
		GameResources::instance().getWomenTexture(), IMAGE_COUNT, IMAGE_RANGE_WALK_UP, true, IMAGE_SIZE),
		std::make_unique<Sound>());
	m_symbol = symbol;
}

WomanGuest::~WomanGuest()
{
}

void WomanGuest::computeOffset(float deltaTime)
{

	//m_action = 1;

	switch (m_action)
	{
	case 0:
		walkAnimation();
		m_offset = { -getSpeed().x * deltaTime , -getSpeed().y * deltaTime };
		break;
	case 1:
		walkDownAnimation();
		m_offset = { getSpeed().x * deltaTime , getSpeed().y * deltaTime };
		break;
	case 2:
		walkLeftAnimation();
		m_offset = { -getSpeed().x * deltaTime , getSpeed().y * deltaTime };
		break;
	case 3:
		walkRightAnimation();
		m_offset = { getSpeed().x * deltaTime , -getSpeed().y * deltaTime };
		break;
	}
}

void WomanGuest::walkAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
}

void WomanGuest::walkDownAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
}

void WomanGuest::walkLeftAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_DOWN);
}

void WomanGuest::walkRightAnimation()
{
	DynamicItem::changeAnimation(ANIM_WALK_UP);
}

void WomanGuest::eatAnimation()
{
}

void WomanGuest::eatBackAnimation()
{
}

void WomanGuest::runAnimation()
{
}

void WomanGuest::runDownAnimation()
{
}
void WomanGuest::standFrontAnimation()
{
}

void WomanGuest::standBackAnimation()
{
}
void WomanGuest::specialAnimation()
{
}
