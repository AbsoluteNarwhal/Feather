#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"

namespace Feather {

	class FEATHER_API Log {

	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define FT_CORE_INFO(...) ::Feather::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FT_CORE_SUCCESS(...) ::Feather::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FT_CORE_WARN(...) ::Feather::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FT_CORE_ERROR(...) ::Feather::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FT_CORE_FATAL(...) ::Feather::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define FT_LOG_INFO(...) ::Feather::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FT_LOG_SUCCESS(...) ::Feather::Log::GetClientLogger()->info(__VA_ARGS__)
#define FT_LOG_WARN(...) ::Feather::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FT_LOG_ERROR(...) ::Feather::Log::GetClientLogger()->error(__VA_ARGS__)
#define FT_LOG_FATAL(...) ::Feather::Log::GetClientLogger()->critical(__VA_ARGS__)