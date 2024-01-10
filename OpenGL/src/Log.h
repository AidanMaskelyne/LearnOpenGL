#pragma once

#include <memory>

#include <spdlog/spdlog.h>

class Log {
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }
private:
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

#define TRACE(...)	Log::GetClientLogger()->trace(__VA_ARGS__)
#define INFO(...)	Log::GetClientLogger()->info(__VA_ARGS__)
#define WARN(...)	Log::GetClientLogger()->warn(__VA_ARGS__)
#define ERROR(...)	Log::GetClientLogger()->error(__VA_ARGS__)