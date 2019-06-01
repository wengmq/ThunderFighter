/********************************************************************************
** Form generated from reading UI file 'rankingWidget.ui'
**
** Created: Tue Mar 26 19:46:51 2019
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKINGWIDGET_H
#define UI_RANKINGWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rankingWidget
{
public:
    QTableView *tableView;
    QPushButton *pushButton_before;
    QPushButton *pushButton_next;
    QLabel *label;

    void setupUi(QWidget *rankingWidget)
    {
        if (rankingWidget->objectName().isEmpty())
            rankingWidget->setObjectName(QString::fromUtf8("rankingWidget"));
        rankingWidget->resize(531, 703);
        tableView = new QTableView(rankingWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 100, 400, 498));
        tableView->setStyleSheet(QString::fromUtf8("font: 75 italic 14pt \"\346\226\271\346\255\243\350\210\222\344\275\223\";\n"
"gridline-color: rgb(85, 170, 255);"));
        pushButton_before = new QPushButton(rankingWidget);
        pushButton_before->setObjectName(QString::fromUtf8("pushButton_before"));
        pushButton_before->setGeometry(QRect(50, 640, 121, 41));
        pushButton_next = new QPushButton(rankingWidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(330, 640, 121, 41));
        label = new QLabel(rankingWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 640, 151, 31));

        retranslateUi(rankingWidget);

        QMetaObject::connectSlotsByName(rankingWidget);
    } // setupUi

    void retranslateUi(QWidget *rankingWidget)
    {
        rankingWidget->setWindowTitle(QApplication::translate("rankingWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_before->setText(QString());
        pushButton_next->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rankingWidget: public Ui_rankingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGWIDGET_H
