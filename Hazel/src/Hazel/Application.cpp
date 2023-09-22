#include "Application.h"
#include <iostream>

namespace Hazel
{
	Application::Application(void)
	{

	}
	Application::~Application(void)
	{

	}

	void Application::Run(void)
	{
		std::cout << "Welcome to Hazel Game Engine !" << std::endl;
		while (true);
	}
}