#ifndef GTOOLOGGER_H
#define GTOOLOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"

class GtooLogger
{
public:
    static GtooLogger* getInstance()
    {
        if (instanceLogger == nullptr) {
            instanceLogger = new GtooLogger();
        }
        return instanceLogger;
    }

    static void destroyInstance() {
        if (instanceLogger != nullptr) {
            delete instanceLogger;
            instanceLogger = nullptr;
        }
    }
  
    void logInitialize();
    void testLogger();

    void logInfo(const std::string& message) {
        logger->info(message);
    }

    void logWarn(const std::string& message) {
        logger->warn(message);
    }

    void logCritical(const std::string& message) {
        logger->critical(message);
    }

private:
    static GtooLogger* instanceLogger;
    GtooLogger();
    ~GtooLogger();
    GtooLogger(GtooLogger const&) = delete;
    void operator=(GtooLogger const&) = delete;

    std::shared_ptr<spdlog::sinks::basic_file_sink_mt> file_sink = nullptr;
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink = nullptr;
    std::shared_ptr<spdlog::logger> logger = nullptr;
};


#endif
