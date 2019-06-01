#include "myDatabase.h"

myDatabase::myDatabase()
{

    //设置本地编码 头文件 #include <QTextCodec> //编码
    QTextCodec *codec = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    //createConnection(strDatabase);

    //打印数据库的驱动的模块
    qDebug()<<":::::::::驱动::::::::::"<<QSqlDatabase::drivers();

    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
        database.setUserName("admin");
        database.setPassword("123456");
    }

    //打开数据库
    if(!database.open())
    {
        qDebug()<<"打开数据库失败！！"<<database.lastError();
    }
    else
    {
        qDebug()<<"打开数据库成功！！";
    }


    if(!executeSql("select *from user"))//没有用户表
    {
        QString str_creatTable = "CREATE TABLE user (name TEXT NOT NULL PRIMARY KEY, pwd TEXT NOT NULL, highScore INTEGER, question TEXT NOT NULL, answer TEXT NOT NULL, newUserFlag INT DEFAULT 1  );";
        executeSql(str_creatTable);
    }

}

myDatabase::~myDatabase()
{

}


bool myDatabase::executeSql(QString strSql)
{
    qDebug()<<strSql;
    //QSqlQuery sqlQuery(database);
    sqlQuery = new QSqlQuery(database);
    if(!sqlQuery->exec(strSql))
    {
        qDebug()<<"语句执行失败！！";
        return false;
    }
    else
    {
        qDebug()<<"语句执行成功！！";
    }
    return true;

}

QSqlQuery *myDatabase::executeQuery(QString strSql)
{
    qDebug()<<strSql;

    sqlQuery = new QSqlQuery(database);
    if(!sqlQuery->exec(strSql))
    {
        qDebug()<<"语句执行失败！！";
    }
    else
    {
        qDebug()<<"语句执行成功！！";
    }
    return sqlQuery;

}

void myDatabase::close()
{
    this->database.close();
}
