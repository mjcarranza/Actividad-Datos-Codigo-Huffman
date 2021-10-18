/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QTextEdit *toDecodeTxt;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *codeButton;
    QTextEdit *toCodeTxt;
    QPushButton *decodeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(843, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 63 30pt \"URW Bookman\";"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        toDecodeTxt = new QTextEdit(centralwidget);
        toDecodeTxt->setObjectName(QString::fromUtf8("toDecodeTxt"));
        toDecodeTxt->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        gridLayout->addWidget(toDecodeTxt, 2, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 63 30pt \"URW Bookman\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 63 30pt \"URW Bookman\";"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 63 30pt \"URW Bookman\";"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        codeButton = new QPushButton(centralwidget);
        codeButton->setObjectName(QString::fromUtf8("codeButton"));
        codeButton->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        gridLayout->addWidget(codeButton, 3, 0, 1, 1);

        toCodeTxt = new QTextEdit(centralwidget);
        toCodeTxt->setObjectName(QString::fromUtf8("toCodeTxt"));
        toCodeTxt->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        gridLayout->addWidget(toCodeTxt, 2, 0, 1, 1);

        decodeButton = new QPushButton(centralwidget);
        decodeButton->setObjectName(QString::fromUtf8("decodeButton"));
        decodeButton->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        gridLayout->addWidget(decodeButton, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8ae234;\">a codificar:</span></p></body></html>", nullptr));
        toDecodeTxt->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8ae234;\">Introduzca el texto</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8ae234;\">Introduzca el texto</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8ae234;\">a decodificar:</span></p></body></html>", nullptr));
        codeButton->setText(QCoreApplication::translate("MainWindow", "Codificar", nullptr));
        toCodeTxt->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        decodeButton->setText(QCoreApplication::translate("MainWindow", "Decodificar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
