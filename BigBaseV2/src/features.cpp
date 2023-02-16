#include "common.hpp"
#include "fiber_pool.hpp"
#include "gta/player.hpp"
#include "gta_util.hpp"
#include "gui.hpp"
#include "logger.hpp"
#include "memory/module.hpp"
#include "memory/pattern.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "features.hpp"
#include "renderer.hpp"
#include "script.hpp"

#include <imgui.h>
#include <StackWalker.h>

namespace big
{
	
	void featuress::script_init()
	{
	}

	void featuress::script_on_tick()
	{
		if (godmode)
		{
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		}
		else {
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
		}

		if (nopolice)
		{
			PLAYER::SET_MAX_WANTED_LEVEL(6);
			PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), 0, 0);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), 0);

		}
		
	}

	void featuress::script_func()
	{
		g_features.script_init();
		while (true)
		{
			g_features.script_on_tick();
			script::get_current()->yield();
		}
	}
}
