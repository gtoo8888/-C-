#include "StuSql.h"


#include <QDebug>
#include <QSqlQuery>

StuSql* StuSql::mpStuSql = nullptr;

StuSql::StuSql(QObject *parent) : QObject(parent)
{
    initDatabase();
//    StuInfo stuInfo;
//    stuInfo.age = 10;
//    stuInfo.name = QString("测试");
//    stuInfo.grade = 2;
//    stuInfo.classNum = 3;
//    stuInfo.studentId = 4;
//    stuInfo.phone = QString("11366667777");
//    addStu(stuInfo);
//    qDebug() << getStuCnt();
//    QList<StuInfo> infoList = getPageStu(2,3);
////    delStu(3);
//    StuInfo stuInfo2;
//    stuInfo2.id = 8;
//    stuInfo2.name = QString("麻了麻了2");
//    updateStuInfo(stuInfo2);

    UserInfo userInfo;
    userInfo.userName = QString("abc");
    userInfo.passWord = QString("123");
    userInfo.aut = QString("admin");
//    for(int i = 0;i < 10;i++){
//        addUser(userInfo);
//    }
//    userInfo.userName = QString("abc");
//    userInfo.passWord = QString("5555");
//    updateUserInfo(userInfo);
    auto l = getAllUser();
    qDebug() << isExit(QString("我的"));
    delUser("abc123");
}


void StuSql::initDatabase()
{
    if(QSqlDatabase::drivers().isEmpty()){
        qDebug() << "no drivers found!";
    }
    // 改成选择文件
    sqliteDB = QSqlDatabase::addDatabase("QSQLITE");
    sqliteDB.setDatabaseName("E:\\Desktop\\languguetest\\Cplusplustest\\4-QtTest\\1-Project\\1-StudentManage_20231227\\StuInfo.db");
    if(!sqliteDB.open()){
        qDebug() << "open database success";
    }else{
        qDebug() << "open database error";
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
            arg(page).arg(page*cnt);
    query.exec(strSQL);
    handleSQLError(query.lastError());

    StuInfo info;
    QList<StuInfo> infoList;
    while(query.next()){
        info.id = query.value(0).toInt();
        info.name = query.value(1).toString();
        info.age = query.value(2).toUInt();
        info.grade = query.value(3).toUInt();
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
            arg(stuInfo.name).arg(stuInfo.age).arg(stuInfo.grade).arg(stuInfo.classNum).
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
    return handleSQLError(query.lastError());

}

bool StuSql::updateStuInfo(StuInfo info)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("update student set name='%1',age=%2,grade=%3,class=%4,studentid=%5,"
                             "phone='%6' where id=%8;").
            arg(info.name).arg(info.age).arg(info.grade).arg(info.classNum).
            arg(info.studentId).arg(info.phone).arg(info.id);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

QList<UserInfo> StuSql::getAllUser()
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("select * from username;");
    query.exec(strSQL);
    handleSQLError(query.lastError());

    UserInfo info;
    QList<UserInfo> infoList;
    while(query.next()){
        info.userName = query.value(0).toString();
        info.passWord = query.value(1).toString();
        info.aut = query.value(2).toString();
        infoList.push_back(info);
    }
    return infoList;
}

bool StuSql::isExit(QString strUser)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("select * from username where username='%1';").arg(strUser);
    query.exec(strSQL);
    handleSQLError(query.lastError());
    return query.next();
}

bool StuSql::updateUserInfo(UserInfo info)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("update username set password='%1',auth='%2' where username='%3';").
            arg(info.passWord).arg(info.aut).arg(info.userName);
    query.exec(strSQL);
    return handleSQLError(query.lastError());
}

bool StuSql::addUser(UserInfo info)
{
    QSqlQuery query(sqliteDB);
    QString strSQL = QString("INSERT INTO 'username' VALUES ('%1', '%2', '%3');").
            arg(info.userName).arg(info.passWord).arg(info.aut);
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


bool StuSql::handleSQLError(QSqlError err){
    if(err.isValid()){
        QSqlError::ErrorType errType = err.type();
        switch (errType) {
        case QSqlError::ErrorType::NoError:
            qDebug() << "No Error";
            return true;
        case QSqlError::ErrorType::ConnectionError:
            qDebug() << "[Connection Error]:" << err.text();
            return false;
        case QSqlError::ErrorType::StatementError:
            qDebug() << "[Statement Error]:" << err.text();
            return false;
        case QSqlError::ErrorType::TransactionError:
            qDebug() << "[Transaction Error]:" << err.text();
            return false;
        case QSqlError::ErrorType::UnknownError:
            qDebug() << "[Unknown Error]:" << err.text();
            return false;
        default:
            qDebug() << "Unknown";
            return false;
        }
    }else{
        qDebug() << "Sql Success!";
        return true;
    }
}


