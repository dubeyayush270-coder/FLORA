#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace FLORA {
	class FLORA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core Log Macros
#define FL_CORE_TRACE(...)     ::FLORA::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FL_CORE_INFO(...)      ::FLORA::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FL_CORE_WARN(...)      ::FLORA::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FL_CORE_ERROR(...)     ::FLORA::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FL_CORE_FATAL(...)     ::FLORA::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define FL_TRACE(...)     ::FLORA::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FL_INFO(...)      ::FLORA::Log::GetClientLogger()->info(__VA_ARGS__)
#define FL_WARN(...)      ::FLORA::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FL_ERROR(...)     ::FLORA::Log::GetClientLogger()->error(__VA_ARGS__)
#define FL_FATAL(...)     ::FLORA::Log::GetClientLogger()->fatal(__VA_ARGS__)