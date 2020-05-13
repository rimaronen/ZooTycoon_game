#pragma once
#include "Terrain.h"

class Snow :
	public Terrain
{
public:
	static const std::string NAME;
	Snow();
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "220";
};

