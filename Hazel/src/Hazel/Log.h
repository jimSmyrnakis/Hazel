#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel
{
	class HAZEL_API Log
	{
	public:
		static void Init(void);

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger(void) { return Log::s_CoreLogger; }//logger for hazel engine dll debuging
		inline static std::shared_ptr<spdlog::logger>& getClientLogger(void) { return Log::s_ClientLogger; }//logger for client use this dll

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//dll hazel application macros - core macros
#define HZ_CORE_WARN(...)  Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)  Hazel::Log::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_ERROR(...) Hazel::Log::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_TRACE(...) Hazel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_FATAL(...) Hazel::Log::getCoreLogger()->fatal(__VA_ARGS__)
//dll user macros - client macros
#define HZ_WARN(...)       Hazel::Log::getClientLogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)       Hazel::Log::getClientLogger()->info(__VA_ARGS__)
#define HZ_ERROR(...)      Hazel::Log::getClientLogger()->error(__VA_ARGS__)
#define HZ_TRACE(...)      Hazel::Log::getClientLogger()->trace(__VA_ARGS__)
#define HZ_FATAL(...)      Hazel::Log::getClientLogger()->fatal(__VA_ARGS__)

