#pragma once

#include "Core.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application(void);
		virtual ~Application(void);

		void Run(void);
	};

	//Να οριστή απο τον πελάτη της dll βιβλιοθήκης
	Application* CreateApplication(void);
}
