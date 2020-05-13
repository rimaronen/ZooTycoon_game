#pragma once
#include "CommandToolBar.h"

class SaveMenuCommand: public CommandToolBar
{
public:
	SaveMenuCommand(ToolBar& toolBar) : CommandToolBar(toolBar) {};
	virtual void execute() override;
};

