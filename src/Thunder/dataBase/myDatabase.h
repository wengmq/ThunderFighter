#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QtGui/QWidget>
#include <QDebug>
#include <QTextCodec>
#include <QVariant>
#include <QString>
//添加数据库头文件
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
class myDatabase
{

public:
    static myDatabase *Instance()
    {
        static myDatabase *my_sqllite;//静态指针
        if(!my_sqllite)
        {
            my_sqllite = new myDatabase();
        }
            return my_sqllite;
    }

    myDatabase();
    ~myDatabase();


    bool executeSql(QString strSql);
    QSqlQuery *executeQuery(QString strSql);

    void close();

    QSqlDatabase database ;
    QSqlQuery *sqlQuery;

//    QString userName;
//    QString highScore;

};

#endif // MYDATABASE_H
