#pragma once
#include "common.hpp"

namespace big
{
	class featuress
	{
	public:
		void dx_init();
		void dx_on_tick();

		void script_init();
		void script_on_tick();
		static void script_func();
	public:
		bool m_opened{};
		bool godmode;
		bool nopolice;
	};

	inline featuress g_features;
}
