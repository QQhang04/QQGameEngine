#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace QQhang {

    class QQH_API Log
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

// ----------- Core Engine -----------
#define QQH_CORE_TRACE(...)  ::QQhang::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QQH_CORE_INFO(...)   ::QQhang::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QQH_CORE_WARN(...)   ::QQhang::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QQH_CORE_ERROR(...)  ::QQhang::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QQH_CORE_FATAL(...)  ::QQhang::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// ----------- Client  -----------
#define QQH_TRACE(...)  ::QQhang::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QQH_INFO(...)   ::QQhang::Log::GetClientLogger()->info(__VA_ARGS__)
#define QQH_WARN(...)   ::QQhang::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QQH_ERROR(...)  ::QQhang::Log::GetClientLogger()->error(__VA_ARGS__)
#define QQH_FATAL(...)  ::QQhang::Log::GetClientLogger()->fatal(__VA_ARGS__)

// easy to strip log info
//#define QQH_CORE_INFO