#include "myDatabase.h"

myDatabase::myDatabase()
{

    //���ñ��ر��� ͷ�ļ� #include <QTextCodec> //����
    QTextCodec *codec = QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    //createConnection(strDatabase);

    //��ӡ���ݿ��������ģ��
    qDebug()<<":::::::::����::::::::::"<<QSqlDatabase::drivers();

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

    //�����ݿ�
    if(!database.open())
    {
        qDebug()<<"�����ݿ�ʧ�ܣ���"<<database.lastError();
    }
    else
    {
        qDebug()<<"�����ݿ�ɹ�����";
    }


    if(!executeSql("select *from user"))//û���û���
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
        qDebug()<<"���ִ��ʧ�ܣ���";
        return false;
    }
    else
    {
        qDebug()<<"���ִ�гɹ�����";
    }
    return true;

}

QSqlQuery *myDatabase::executeQuery(QString strSql)
{
    qDebug()<<strSql;

    sqlQuery = new QSqlQuery(database);
    if(!sqlQuery->exec(strSql))
    {
        qDebug()<<"���ִ��ʧ�ܣ���";
    }
    else
    {
        qDebug()<<"���ִ�гɹ�����";
    }
    return sqlQuery;

}

void myDatabase::close()
{
    this->database.close();
}
