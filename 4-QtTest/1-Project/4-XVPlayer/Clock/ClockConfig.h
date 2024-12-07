#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include <QWidget>

class Config {
    Config() = default;
    virtual ~Config() = default;

private:
    virtual void loadConfig(void);
};

class Setting : public Config {
public:
    Setting();
    ~Setting();

private:
    enum DisplayUnit {
        sec,
        msec
    };

    enum Languague {
        Chinese,
        English
    };

    uint8_t StopwatchCount;
    DisplayUnit displayUnit;
    bool bDrag;
    bool bSlowFastDisplay;
    bool bAUtoClean;
    uint16_t autoCleanTime;
    Languague languague;
};

class KeyShot : public Config {
public:
    KeyShot();
    ~KeyShot();

private:
    uint8_t StopwatchCount;
};

class About : public Config {
public:
    About();
    ~About();
};

// 未来可以使用ConfigInface替代ClockConfig，作为通用的配置接口类
class ConfigInface{
    ConfigInface();
    ~ConfigInface();
public:
    Setting* settingConfig;
    KeyShot* keyshotConfig;
    About* aboutConfig;
};

class ClockConfig
{
public:
    ClockConfig();
    ClockConfig(QString configPath);
    ~ClockConfig();

private:
    Setting* settingConfig;
    KeyShot* keyshotConfig;
    About* aboutConfig;
};

#endif // CLOCKCONFIG_H
