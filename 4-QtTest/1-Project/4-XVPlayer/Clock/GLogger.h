#ifndef GLOGGER_H
#define GLOGGER_H

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"

// 日志类型，暂时无用
enum LoggerType {
    trace,
    debug,
    info,
    warn,
    critical,
    error
};

// 日志的配置项
struct LogConfig {
    LogConfig() {
        level = spdlog::level::debug;  // 日志等级
        path = "log/gtoo_log.log";
        size = 5 * 1024 * 1024;
        count = 10;
        bTruncate = true;  // 不追加，每次都用新的
    };
    ~LogConfig();

    spdlog::level::level_enum level;  // 当前日志等级
    std::string path;
    int64_t size;
    int count;
    bool bTruncate;  // 是否追加显示
};

class GLogger {
public:
    static GLogger* getInstance() {
        if (instanceLogger == nullptr) {
            instanceLogger = new GLogger();
        }
        return instanceLogger;
    }

    std::shared_ptr<spdlog::logger> getLogger() {  // FIXME 暂时无用
        return logger;
    }

    static void destroyInstance() {
        if (instanceLogger != nullptr) {
            delete instanceLogger;
            instanceLogger = nullptr;
        }
    }

    void logInitialize();
    void testLogger();
    void logMessage(const LoggerType type, const std::string& message);  // 暂时无用

    std::shared_ptr<spdlog::logger> logger = nullptr;                    // FIXME 这是共有的,应该是错误的
private:
    static GLogger* instanceLogger;
    GLogger();
    ~GLogger();
    GLogger(GLogger const&) = delete;
    void operator=(GLogger const&) = delete;

    std::shared_ptr<spdlog::sinks::basic_file_sink_mt> file_sink = nullptr;
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink = nullptr;
    LogConfig* nowConfig;
};

#define BASELOG(logInstance, level, ...)                                                              \
    (logInstance)->logger->log(spdlog::source_loc{__FILE__, __LINE__, __func__}, level, __VA_ARGS__); \
    (logInstance)->logger->flush();
#define LOG_TRC(...) BASELOG(GLogger::getInstance(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DBG(...) BASELOG(GLogger::getInstance(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INF(...) BASELOG(GLogger::getInstance(), spdlog::level::info, __VA_ARGS__)
#define LOG_WRN(...) BASELOG(GLogger::getInstance(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERR(...) BASELOG(GLogger::getInstance(), spdlog::level::err, __VA_ARGS__)
#define LOG_CRT(...) BASELOG(GLogger::getInstance(), spdlog::level::critical, __VA_ARGS__)

#endif  // GLOGGER_H
