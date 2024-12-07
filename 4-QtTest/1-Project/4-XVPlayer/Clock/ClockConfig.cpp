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

    QJsonDocument jsonDocu = QJsonDocument::fromJson(jsonData);

    if (jsonDocu.isObject()) {
        QJsonObject obj_root = jsonDocu.object();
        QStringList keys = obj_root.keys();
        for (auto key : keys) {
            QJsonValue value = obj_root.value(key);
            if (value.isString()) {
                qDebug() << key << ": " << value.toString();
            } else if (value.isDouble()) {
                qDebug() << key << ": " << value.toInt();
            } else if (value.isArray()) {
                QJsonArray arr = value.toArray();
                for (int i = 0; i < arr.count(); ++i) {
                    if (arr.at(i).isString()) {
                        qDebug() << key << ": " << arr.at(i).toString();
                    }
                    // 这里就不判断是否为其它类型了，因为测试文件已知为字符串，要写也和上面类似，无限套娃
                }
            } else if (value.isObject()) {
                QJsonObject subObj = value.toObject();
                QStringList subKeys = subObj.keys();
                for (auto subKey : subKeys) {
                    QJsonValue subValue = subObj.value(subKey);
                    if (subValue.isString()) {
                        qDebug() << subKey << ": " << subValue.toString();
                    }
                    // 这里就不判断是否为其它类型了，因为测试文件已知为字符串，要写也和上面类似，无限套娃
                }
            }
        }
    }
}
