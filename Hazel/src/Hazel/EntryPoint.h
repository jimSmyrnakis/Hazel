#pragma once
#include "Application.h"
#include "Log.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication(void);

int main(int argc, char** argv)
{
	Hazel::Log::Init();

	HZ_CORE_INFO("Hazel logger initiallized ");
	HZ_INFO("Application logger initiallized ");
	int a = 90;
	int b = (a * 7) / 100;
	HZ_WARN("this is a warning message with two integers {0} , {1} ", a, b);

	Hazel::Application* app = Hazel::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif 