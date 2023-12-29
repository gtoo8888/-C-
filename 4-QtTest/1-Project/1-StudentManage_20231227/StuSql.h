#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDateTime>

struct StuInfo{
    enum SexType{
      Male = 0,
      Female,
      Unkonw
    };
    quint32 id;
    QString name = QString("");
    quint8 sex = SexType::Male;
    quint8 age = 0;
    quint16 classNum = 0;
    quint16 score = 0;
    quint16 studentId = 0;
    QDateTime brithDay = QDateTime::currentDateTime();
    QString phone = QString("");
};

struct UserInfo{
    enum AuthType{
      Admin = 0,
      Teacher,
      Student
    };
    qint32 id = -1;
    QString userName = QString("");
    QString password = QString("");
    int auth = AuthType::Admin;
    bool isRememberPassword = false;


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

    /************************用户处理********************************/
    // 查询所有用户
    QList<UserInfo> getAllUserInfo();
    // 通过用户名查找用户信息
    UserInfo getUserInfofromName(QString userName);
    //查询用户名是否存在
    bool isExit(QString strUser);
    //修改用户密码
    bool updateUserPwd(UserInfo info);
    //添加单个用户
    bool addUser(UserInfo info);
    //删除单个用户
    bool delUser(QString strUserName);
signals:

private:
    QSqlDatabase sqliteDB;

    int authQStrtoEnum(QString str);
    QString authEnumtoQStr(int iEnum);
};

#endif // STUSQL_H
