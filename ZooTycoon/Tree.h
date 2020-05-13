#pragma once
#include "ConstructionItem.h"
class Tree :
	public ConstructionItem
{
public:
	static const std::string NAME;
	Tree();
	std::string getPrice() { return m_price; }
private:
	static bool m_registerIt;
	std::string m_price = "290";
};

