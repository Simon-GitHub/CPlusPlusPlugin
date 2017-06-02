#include "ShapePlugin.h"

ShapePlugin::ShapePlugin(const std::string &strName)
:PluginInstance(strName)
{
	//const std::string &strName
}

ShapePlugin::~ShapePlugin(void)
{
}

bool ShapePlugin::Load()
{
	return 1;
}

bool ShapePlugin::UnLoad()
{
	return 1;
}

std::string ShapePlugin::GetFileName() const
{
#if defined( _DEBUG    ) || defined( DEBUG )
	return "PluginShaped.dll";
#else
	return "PluginShape.dll";
#endif
}

std::string ShapePlugin::GetDisplayName() const
{
#if defined( _DEBUG    ) || defined( DEBUG )
	return "PluginShaped";
#else
	return "PluginShape";
#endif
}
