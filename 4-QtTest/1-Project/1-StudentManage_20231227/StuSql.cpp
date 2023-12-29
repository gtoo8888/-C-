#include "StuSql.h"
#include "Utils.h"

#include <QSqlQuery>

StuSql* StuSql::mpStuSql = nullptr;

StuSql::StuSql(QObject *parent) : QObject(parent)
{
    initDatabase();
}


void StuSql::initDatabase()
{
    if(QSqlDatabase::drivers().isEmpty()){
        myDebug() << "no drivers found!";
    }
    // 改成选择文件
    sqliteDB = QSqlDatabase::addDatabase("QSQLITE");
    sqliteDB.setDatabaseName("E:\\Desktop\\languguetest\\Cplusplustest\\4-QtTest\\1-Project\\1-StudentManage_20231227\\StuInfo.db");
    if(!sqliteDB.open()){
        myDebug() << "open database success";
    }else{
        myDebug() << "open database error";
    }
}

// TODO: 垃圾写法
quint32 StuSql::getStuCnt()
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("select count(id) from student;");
    query.exec(strSQL);
    handleSQLError(query.lastError());
    quint32 cnt = 0;
    while(query.next()){
        cnt = query.value(0).toInt();
    }
    return cnt;
}

QList<StuInfo> StuSql::getPageStu(quint32 page, quint32 cnt)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("select * from student order by id limit %1 offset %2;").
            arg(cnt).arg(page*cnt);
    query.exec(strSQL);
    handleSQLError(query.lastError());

    StuInfo info;
    QList<StuInfo> infoList;
    while(query.next()){
        info.id = query.value(0).toInt();
        info.name = query.value(1).toString();
        info.age = query.value(2).toUInt();
//        info.grade = query.value(3).toUInt();
        info.classNum = query.value(4).toUInt();
        info.studentId = query.value(5).toUInt();
        info.phone = query.value(6).toString();
        infoList.push_back(info);
    }
    return infoList;
}

bool StuSql::addStu(StuInfo stuInfo)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("INSERT INTO 'student' VALUES (NULL, '%1', %2, %3, %4, %5, '%6', '-1');").
            arg(stuInfo.name).arg(stuInfo.age).arg(stuInfo.score).arg(stuInfo.classNum).
            arg(stuInfo.studentId).arg(stuInfo.phone);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

// TODO: 删除后ID有空缺
bool StuSql::delStu(int id)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("delete from student where id = %1;").arg(id);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

bool StuSql::clearStuTable()
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("delete from student;");
    query.exec(strSQL);
    handleSQLError(query.lastError());
    strSQL = QString("DELETE FROM sqlite_sequence WHERE name = 'student';");
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

bool StuSql::updateStuInfo(StuInfo info)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("update student set name='%1',age=%2,grade=%3,class=%4,studentid=%5,"
                             "phone='%6' where id=%8;").
            arg(info.name).arg(info.age).arg(info.score).arg(info.classNum).
            arg(info.studentId).arg(info.phone).arg(info.id);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

QList<UserInfo> StuSql::getAllUserInfo()
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("select * from username;");
    query.exec(strSQL);
    handleSQLError(query.lastError());

    UserInfo info;
    QList<UserInfo> infoList;
    while(query.next()){        
        info.id = query.value(0).toUInt();
        info.userName = query.value(1).toString();
        info.password = query.value(2).toString();
        QString authStr = query.value(3).toString();
        info.auth = authQStrtoEnum(authStr);
        info.isRememberPassword = query.value(4).toBool();
        infoList.push_back(info);
    }
    return infoList;
}

UserInfo StuSql::getUserInfofromName(QString userName)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("select * from username where username = '%1';").arg(userName);
    query.exec(strSQL);
    handleSQLError(query.lastError());

    UserInfo info;
    while(query.next()){
        info.id = query.value(0).toUInt();
        info.userName = query.value(1).toString();
        info.password = query.value(2).toString();
        QString authStr = query.value(3).toString();
        info.auth = authQStrtoEnum(authStr);
        info.isRememberPassword = query.value(4).toBool();
    }
    return info;
}

bool StuSql::isExit(QString strUser)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("select * from username where username='%1';").arg(strUser);
    query.exec(strSQL);
    handleSQLError(query.lastError());
    return query.next();
}

bool StuSql::updateUserPwd(UserInfo info)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("update username set password='%1' where id=%3;").
            arg(info.password).arg(info.id);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

bool StuSql::addUser(UserInfo info)
{
    QSqlQuery query(sqliteDB);
    QString strAuth = authEnumtoQStr(info.auth);
    QString strSQL = QString("INSERT INTO 'username' VALUES (NULL, '%1', '%2', '%3', %4);").
            arg(info.userName).arg(info.password).arg(strAuth).arg(info.isRememberPassword);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

bool StuSql::delUser(QString strUserName)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("delete from username where username='%1';").arg(strUserName);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

int StuSql::authQStrtoEnum(QString str)
{
    if(QString("admin") ==  str)
        return UserInfo::AuthType::Admin;
    else if(QString("teacher") ==  str)
        return UserInfo::AuthType::Teacher;
    else if(QString("student") ==  str)
        return UserInfo::AuthType::Student;
}

QString StuSql::authEnumtoQStr(int iEnum)
{
    if(UserInfo::AuthType::Admin ==  iEnum)
        return QString("admin");
    else if(UserInfo::AuthType::Teacher ==  iEnum)
        return QString("teacher");
    else if(UserInfo::AuthType::Student ==  iEnum)
        return QString("student");
}


bool StuSql::handleSQLError(QSqlError err){
    if(err.isValid()){
        QSqlError::ErrorType errType = err.type();
        switch (errType) {
        case QSqlError::ErrorType::NoError:
            myDebug() << "[No Error]";
            return true;
        case QSqlError::ErrorType::ConnectionError:
            myDebug() << "[Connection Error]:" << err.text();
            return false;
        case QSqlError::ErrorType::StatementError:
            myDebug() << "[Statement Error]:" << err.text();
            return false;
        case QSqlError::ErrorType::TransactionError:
            myDebug() << "[Transaction Error]:" << err.text();
            return false;
        case QSqlError::ErrorType::UnknownError:
            myDebug() << "[Unknown Error]:" << err.text();
            return false;
        default:
            myDebug() << "Unknown";
            return false;
        }
    }else{
//        myDebug() << "Sql Success!";
        return true;
    }
}


