#ifndef CLOCKCONFIG_H
#define CLOCKCONFIG_H

#include <QWidget>
#include "cJSON.h"

class Config {
public:
    Config() = default;
    virtual ~Config() = default;

    virtual void loadConfig(void);
};

class Setting : public Config {
public:
    Setting();
    virtual ~Setting();

    enum DisplayUnit {
        sec,
        msec
    };

    enum Languague {
        Chinese,
        English
    };

    int StopwatchCount;
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
    virtual ~KeyShot();

    uint8_t StopwatchCount;
};

class About : public Config {
public:
    About();
    virtual ~About();
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
    void parseSettingConfig(cJSON* root);
    void parseKeyshotConfig(cJSON* root);
    void parseAboutConfig(cJSON* root);


    Setting* settingConfig;
    KeyShot* keyshotConfig;
    About* aboutConfig;
};

#endif // CLOCKCONFIG_H
