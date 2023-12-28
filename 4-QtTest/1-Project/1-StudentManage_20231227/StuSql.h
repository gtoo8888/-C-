#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QSqlError>
#include <QSqlDatabase>

struct StuInfo{
    int id;
    QString name = QString("");
    quint8 age = 0;
    quint16 grade = 0;
    quint16 classNum = 0;
    quint16 studentId = 0;
    QString phone = QString("");
};

struct UserInfo{
    QString userName = QString("");
    QString passWord = QString("");
    QString aut = QString("");
};

class StuSql : public QObject
{
    Q_OBJECT
public:
    explicit StuSql(QObject *parent = nullptr);
    static StuSql* mpStuSql;
    static StuSql *getInstance(){
        if(nullptr == mpStuSql){
            mpStuSql = new StuSql();
        }
        return mpStuSql;
    }

    bool handleSQLError(QSqlError err);
    void initDatabase(void);

    //查询所有学生数量
    quint32 getStuCnt(void);
    //查询第几页学生数据
    QList<StuInfo> getPageStu(quint32 page,quint32 cnt);
    //增加学生
    bool addStu(StuInfo stuInfo);
    //删除学生
    bool delStu(int id);
    //清空学生表
    bool clearStuTable();
    //修改学生信息
    bool updateStuInfo(StuInfo info);
    //查询所有用户
    QList<UserInfo> getAllUser();
    //查询用户名是否存在
    bool isExit(QString strUser);
    //修改用户信息
    bool updateUserInfo(UserInfo info);
    //添加单个用户
    bool addUser(UserInfo info);
    //删除单个用户
    bool delUser(QString strUserName);
signals:

private:
    QSqlDatabase sqliteDB;
};

#endif // STUSQL_H
