#pragma once
#include "Application.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication(void);

int main(int argc, char** argv)
{
	Hazel::Application* app = Hazel::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif 