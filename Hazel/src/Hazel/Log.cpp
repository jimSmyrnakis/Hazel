#include "hzpch.h"
#include "Log.h"


namespace Hazel
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	

	void Log::Init(void)
	{
		spdlog::set_pattern("%^[%T] %n - %l: %v%$");//all loggers set globaly
		
		s_CoreLogger	= spdlog::stdout_color_mt("HAZEL");//set core logger name
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger	= spdlog::stdout_color_mt("APP");//set client logger name
		s_ClientLogger->set_level(spdlog::level::trace);
	}
};