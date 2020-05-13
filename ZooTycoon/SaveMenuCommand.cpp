#include "SaveMenuCommand.h"
#include "ToolBar.h"

void SaveMenuCommand::execute()
{
	m_toolBar.save();
}