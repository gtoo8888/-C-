#include "StopwatchWdg.h"
#include "ui_StopwatchWdg.h"
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>

#include "spdlog/cfg/env.h"  // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h" // support for user defined types
#include "spdlog/cfg/env.h"

StopwatchWdg::StopwatchWdg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StopwatchWdg),
    maxClockNum(6)
{
    ui->setupUi(this);
    vlayout = new QVBoxLayout(this);
    ui->clockShowWdg->setLayout(vlayout);

    connect(ui->btnNewClock,&QPushButton::clicked,this,&StopwatchWdg::slotBtnNewClock);
    connect(ui->btnCleanClock,&QPushButton::clicked,this,&StopwatchWdg::slotBtnCleanClock);

//    logInitialize();
    testLogger();

}

StopwatchWdg::~StopwatchWdg()
{
    delete ui;
}

void StopwatchWdg::slotBtnNewClock(void)
{
    int nowClockNum = clockWdgVec.size();
    if (nowClockNum < maxClockNum){
        StopwatchClockWdg* stopwatchClockWdg = new StopwatchClockWdg(ui->clockShowWdg);
        clockWdgVec.push_back(stopwatchClockWdg);
        vlayout->addWidget(stopwatchClockWdg);
        stopwatchClockWdg->setClockIndex(clockWdgVec.size());
        connect(stopwatchClockWdg,&StopwatchClockWdg::sigClockCloseWnd,this,&StopwatchWdg::slotClockClock);
        stopwatchClockWdg->show();
    }else{
        QMessageBox box(QMessageBox::Warning, QString("警告"),QString("当前秒表达到最大%1个").arg(nowClockNum));
        box.exec();
    }
}

void StopwatchWdg::slotBtnCleanClock()
{
    for(auto it = clockWdgVec.begin();it != clockWdgVec.end();it++){
        StopwatchClockWdg* deleteClock = *it;
        delete deleteClock;
    }
    clockWdgVec.clear();
}

void StopwatchWdg::slotClockClock(int clockIndex)
{
    StopwatchClockWdg* nowClockClose = clockWdgVec[clockIndex-1];
    delete nowClockClose;
    clockWdgVec.erase(clockWdgVec.begin() + clockIndex-1);

    for(int idx = 0;idx < clockWdgVec.size();idx++){
        clockWdgVec[idx]->setClockIndex(idx+1);
    }
}



void StopwatchWdg::logInitialize(void)
{
    spdlog::cfg::load_env_levels();
    file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(nowConfig->path, !nowConfig->bTruncate); // 创建文件日志器
    //file_sink->set_level(nowLevel);
    console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();// 创建颜色控制台日志器
    //console_sink->set_level(nowLevel);
    logger = std::make_shared<spdlog::logger>("logger", spdlog::sinks_init_list{ file_sink, console_sink });
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [thread %t] [%^%l%$] [%s:%# %!] %v");
    logger->set_level(nowConfig->level); // 只有最终这个才控制输出等级
}

void StopwatchWdg::testLogger(void)
{
    spdlog::cfg::load_env_levels(); // ?
    // false表示追加模式，true表示覆盖模式
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt", true); // 创建文件日志器
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();// 创建颜色控制台日志器
    //auto console_sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();// 创建控制台日志器
    console_sink->set_level(spdlog::level::info);
    auto logger = std::make_shared<spdlog::logger>("logger", spdlog::sinks_init_list{ file_sink, console_sink });
    // %z表示时区
    // %l表示长日志级别，%L表示短日志级别
    // %v表示具体输出内容
    // %t线程号，%P进程号
    // [%s] 文件
    // [%#] 行号
    // [%!] 函数
    //logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e %z] [thread %t] [process %P] [%^%l%$] %v");// 显示信息最全的
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [thread %t] [%^%L%$] [%s:%# %!] v");

    logger->set_pattern("%+"); // 不知道什么作用

    logger->info("Hello World!\n");
    logger->info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    logger->debug("This message should not be displayed!");
    logger->info("This an info message with custom format");
    logger->warn("Easy padding in numbers like {:08d}", 12);
    logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    logger->info("Support for floats {:03.2f}", 1.23456);
    logger->info("Positional args are {1} {0}..", "too", "supported");
    logger->info("{:>8} aligned, {:<8} aligned", "right", "left");


    logger->log(spdlog::source_loc{ __FILE__, __LINE__, __func__ }, spdlog::level::info, "test");

    // 运行时候日志等级调整
    logger->set_level(spdlog::level::info);// Set global log level to info
    logger->debug("This message should not be displayed!");
    logger->set_level(spdlog::level::trace);// Set specific logger's log level
    logger->debug("This message should be displayed..");
}




