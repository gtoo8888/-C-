#ifndef STOPWATCHWDG_H
#define STOPWATCHWDG_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "StopwatchClockWdg.h"


#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/stdout_sinks.h"


namespace Ui {
class StopwatchWdg;
}

struct LogConfig { // 日志的配置项
    LogConfig();
    ~LogConfig();

    spdlog::level::level_enum level;// 当前日志等级
    std::string path;
    int64_t size;
    int count;
    bool bTruncate;// 是否追加显示
};

class StopwatchWdg : public QWidget
{
    Q_OBJECT

public:
    explicit StopwatchWdg(QWidget *parent = nullptr);
    ~StopwatchWdg();

private slots:
    void slotBtnNewClock(void);
    void slotBtnCleanClock(void);
    void slotClockClock(int clockIndex);

private:
    Ui::StopwatchWdg *ui;

    QVBoxLayout *vlayout;
    QVector<StopwatchClockWdg*>  clockWdgVec;
    uint8_t maxClockNum;

    void logInitialize(void);
    void testLogger(void);
    std::shared_ptr<spdlog::logger> logger = nullptr; // FIXME 这是共有的,应该是错误的
    std::shared_ptr<spdlog::sinks::basic_file_sink_mt> file_sink = nullptr;
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink = nullptr;

    LogConfig* nowConfig;
};

#define BASELOG(logInstance, level, ...) (logInstance)->logger->log(spdlog::source_loc{__FILE__, __LINE__, __func__}, level, __VA_ARGS__)
#define LOG_TRACE(...)     BASELOG(GtooLogger::getInstance(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...)     BASELOG(GtooLogger::getInstance(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...)      BASELOG(GtooLogger::getInstance(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...)      BASELOG(GtooLogger::getInstance(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...)     BASELOG(GtooLogger::getInstance(), spdlog::level::err, __VA_ARGS__)
#define LOG_CRITICAL(...)  BASELOG(GtooLogger::getInstance(), spdlog::level::critical, __VA_ARGS__)


#endif // STOPWATCHWDG_H
