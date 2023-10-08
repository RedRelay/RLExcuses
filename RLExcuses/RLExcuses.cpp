#include "pch.h"
#include "RLExcuses.h"


BAKKESMOD_PLUGIN(RLExcuses, "RLExcuses plugin", plugin_version, PLUGINTYPE_FREEPLAY)

void RLExcuses::onLoad()
{

	const std::string defaultExcusesFilePath = "";

	cvarManager->registerCvar("RLExcuses.isEnabled", "1", "Enable RL Excuses plugin",true, true, 0, true, 1);
	cvarManager->registerCvar("RLExcuses.excusesFilePath", defaultExcusesFilePath, "RL Excuses file path")
		.addOnValueChanged([this](std::string oldValue, CVarWrapper cvar) {
		// TODO : Reload excuses
		});;
	cvarManager->registerCvar("RLExcuses.isOnGoalEnabled", "1", "Enable excuses when you concede a goal", true, true, 0, true, 1);
	cvarManager->registerCvar("RLExcuses.isOnOwnGoalEnabled", "1", "Enable excuses when you score a own goal ", true, true, 0, true, 1);
	cvarManager->registerCvar("RLExcuses.isOnLostEnabled", "1", "Enable excuses when you lost the match", true, true, 0, true, 1);
	cvarManager->registerCvar("RLExcuses.isExplainForAssholeEnabled", "1", "Sometimes assholes don't get it and get triggered, enable it to explain when the match ends what's going and that's just for fun", true, true, 0, true, 1);
}

void RLExcuses::onUnload()
{
}