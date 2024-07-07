#pragma once

#include "Core.h"

namespace Feather {

	class FEATHER_API Application {

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}