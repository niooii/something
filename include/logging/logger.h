// spdlog was like 50x faster :((

// // Logger.h
//
// #ifndef LOGGER_H
// #define LOGGER_H
//
// #include <chrono>
// #include <iostream>
// #include <set>
//
// #include "rang.h"
//
// class Logger
// {
// public:
//     enum LogLevel
//     {
//         Trace,
//         Info,
//         Debug,
//         Warn,
//         Critical,
//         Err,
//         Fatal,
//     };
//
// private:
//     inline static std::set<LogLevel> enabled_log_levels{};
//
//     static const char* level_to_str(LogLevel level)
//     {
//         switch (level)
//         {
//         case Trace:
//             return "TRACE";
//         case Info:
//             return "INFO";
//         case Debug:
//             return "DEBUG";
//         case Warn:
//             return "WARN";
//         case Critical:
//             return "CRITICAL";
//         case Err:
//             return "ERROR";
//         case Fatal:
//             return "FATAL";
//         default:
//             return "UNKNOWN";
//         }
//     }
//
//     static rang::fg level_to_color(LogLevel level)
//     {
//         using rang::fg;
//         switch (level)
//         {
//         case Trace:
//             return fg::gray;
//         case Info:
//             return fg::gray;
//         case Debug:
//             return fg::blue;
//         case Warn:
//             return fg::yellow;
//         case Critical:
//             return fg::magenta;
//         case Err:
//             return fg::magenta;
//         case Fatal:
//             return fg::red;
//         default:
//             return fg::reset;
//         }
//     }
//
//     static void print_prefixes(LogLevel level)
//     {
//         // diabolical time obtainment
//         using std::chrono::system_clock;
//         using std::chrono::time_point;
//         time_point<system_clock> t = system_clock::now();
//
//         time_t tt = system_clock::to_time_t(t);
//         tm local_time = *localtime(&tt);
//
//         std::cout << level_to_color(level) << std::format(
//             "[{}] {}:{}:{} ",
//             level_to_str(level),
//             local_time.tm_hour,
//             local_time.tm_min,
//             local_time.tm_sec);
//     };
//
// public:
//     static void SetLogLevel(LogLevel level, bool log)
//     {
//         if (log)
//             enabled_log_levels.insert(level);
//         else
//             enabled_log_levels.erase(level);
//     }
//
//     template <typename... Args>
//     static void log(LogLevel level, const char* format, Args&&... args)
//     {
//         if (enabled_log_levels.contains(level))
//         {
//             print_prefixes(level);
//             std::cout << std::vformat(std::string_view{format}, std::make_format_args(std::forward<Args>(args)...)) << "\n";
//         }
//     }
//
//     template <typename... Args>
//     static void trace(const char* format, Args&&... args)
//     {
//         log(Trace, format, std::forward<Args>(args)...);
//     }
//
//     template <typename... Args>
//     static void info(const char* format, Args&&... args)
//     {
//         log(Info, format, std::forward<Args>(args)...);
//     }
//
//     template <typename... Args>
//     static void debug(const char* format, Args&&... args)
//     {
//         log(Debug, format, std::forward<Args>(args)...);
//     }
//
//     template <typename... Args>
//     static void warn(const char* format, Args&&... args)
//     {
//         log(Warn, format, std::forward<Args>(args)...);
//     }
//
//     template <typename... Args>
//     static void critical(const char* format, Args&&... args)
//     {
//         log(Critical, format, std::forward<Args>(args)...);
//     }
//
//     template <typename... Args>
//     static void err(const char* format, Args&&... args)
//     {
//         log(Err, format, std::forward<Args>(args)...);
//     }
//
//     template <typename... Args>
//     static void fatal(const char* format, Args&&... args)
//     {
//         log(Fatal, format, std::forward<Args>(args)...);
//     }
// };
//
// #endif // LOGGER_H
