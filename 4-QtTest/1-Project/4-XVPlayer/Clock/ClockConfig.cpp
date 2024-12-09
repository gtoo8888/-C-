#include "ClockConfig.h"
#include <QFile>
#include <QJsonArray>     // [ ]
#include <QJsonDocument>  // 解析Json
#include <QJsonObject>    // { }
#include <QJsonParseError>
#include <QJsonValue>     // int float double bool null { } [ ]
#include <QDebug>
#include "GLogger.h"

ClockConfig::ClockConfig() {
}

//ClockConfig::ClockConfig(QString configPath) {
//    QFile file(configPath);
//    QByteArray jsonData;
//    LOG_INF("ClockConfig::ClockConfig");
//    if (file.open(QIODevice::ReadOnly)) {
//        jsonData = file.readAll();
//        file.close();
//    }else{
//        LOG_ERR("file.open fail");
//    }

//    QJsonDocument jsonDocu = QJsonDocument::fromJson(jsonData);

//    if (jsonDocu.isObject()) {
//        QJsonObject obj_root = jsonDocu.object();
//        QStringList keys = obj_root.keys();
//        for (auto key : keys) {
//            QJsonValue value = obj_root.value(key);
//            if (value.isString()) {
//                qDebug() << key << ": " << value.toString();
//            } else if (value.isDouble()) {
//                qDebug() << key << ": " << value.toInt();
//            } else if (value.isArray()) {
//                QJsonArray arr = value.toArray();
//                for (int i = 0; i < arr.count(); ++i) {
//                    if (arr.at(i).isString()) {
//                        qDebug() << key << ": " << arr.at(i).toString();
//                    }
//                    // 这里就不判断是否为其它类型了，因为测试文件已知为字符串，要写也和上面类似，无限套娃
//                }
//            } else if (value.isObject()) {
//                QJsonObject subObj = value.toObject();
//                QStringList subKeys = subObj.keys();
//                for (auto subKey : subKeys) {
//                    QJsonValue subValue = subObj.value(subKey);
//                    if (subValue.isString()) {
//                        qDebug() << subKey << ": " << subValue.toString();
//                    }
//                    // 这里就不判断是否为其它类型了，因为测试文件已知为字符串，要写也和上面类似，无限套娃
//                }
//            }
//        }
//    }
//}



ClockConfig::ClockConfig(QString configPath) {
    QFile file(configPath);
    QByteArray jsonData;
    LOG_INF("ClockConfig::ClockConfig");
    if (file.open(QIODevice::ReadOnly)) {
        jsonData = file.readAll();
        file.close();
    }else{
        LOG_ERR("file.open fail");
    }

    settingConfig = new Setting();
    keyshotConfig = new KeyShot();
    aboutConfig = new About();


    char* date = jsonData.data();
    cJSON *root = cJSON_Parse(date);
    cJSON* cjsonConfig = cJSON_GetObjectItem(root, "config");
    cJSON* cjsonSetting = cJSON_GetObjectItem(cjsonConfig, "setting");
    parseSettingConfig(cjsonSetting);

}

//"setting": {
//  "StopwatchCount": 1,
//  "DisplayUnit": "sec",
//  "bDrag": false,
//  "bSlowFastDisplay": false,
//  "bAutoClean": true,
//  "autoCleanTime": 600,
//  "Language": "Chinese"
//},
//"keyshot": {
//  "StopwatchCount": 1
//},
//"about": {
//}

void ClockConfig::parseSettingConfig(cJSON *root)
{
    cJSON* cjsonStopwatchCount = cJSON_GetObjectItem(root, "StopwatchCount");
    cJSON* cjsonDisplayUnit = cJSON_GetObjectItem(root, "DisplayUnit");
    cJSON* cjsonBDrag = cJSON_GetObjectItem(root, "DisplayUnit");
    cJSON* cjsonBSlowFastDisplay = cJSON_GetObjectItem(root, "bDrag");
    cJSON* cjsonBAutoClean = cJSON_GetObjectItem(root, "bSlowFastDisplay");
    cJSON* cjsonAutoCleanTime = cJSON_GetObjectItem(root, "bAutoClean");
    cJSON* cjsonLanguage = cJSON_GetObjectItem(root, "Language");

    if(cjsonStopwatchCount->type == cJSON_Number){
        settingConfig->StopwatchCount = cjsonStopwatchCount->valueint;
    }else{
        LOG_ERR("cjsonStopwatchCount type error");
    }

    if(cjsonDisplayUnit->type == cJSON_String){
        if(strcmp(cjsonDisplayUnit->valuestring,"sec")){
            settingConfig->displayUnit = Setting::DisplayUnit::sec;
        }else if(strcmp(cjsonDisplayUnit->valuestring,"msec")){
            settingConfig->displayUnit = Setting::DisplayUnit::msec;
        }
    }else{
        LOG_ERR("cjsonDisplayUnit type error");
    }


//    if(cjsonBDrag->type == cJSON_False){
//        settingConfig->bDrag = false;
//    }else if(cjsonBDrag->type == cJSON_True){
//        settingConfig->bDrag = true;
//    }

//    LOG_INF("{:d} {:s}",stopwatchCount,displayUnit);
}

void ClockConfig::parseKeyshotConfig(cJSON *root)
{

}

void ClockConfig::parseAboutConfig(cJSON *root)
{

}

Setting::Setting()
{

}

KeyShot::KeyShot()
{

}

About::About()
{

}
