/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *expression;
    QPushButton *pushButtonAC;
    QPushButton *pushButtonMinus;
    QPushButton *pushButtonIm;
    QPushButton *pushButtonEval;
    QPushButton *pushButtonIft;
    QPushButton *pushButtonMod;
    QPushButton *pushButtonInfeq;
    QPushButton *pushButtonNum;
    QPushButton *pushButtonSwap;
    QPushButton *pushButtonSpace;
    QPushButton *pushButtonDrop;
    QPushButton *pushButtonEq;
    QPushButton *pushButtonOr;
    QPushButton *pushButtonDen;
    QPushButton *pushButton2;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonNot;
    QPushButton *pushButtonDup;
    QPushButton *pushButton0;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonLastargs;
    QPushButton *pushButtonLeftPar;
    QPushButton *pushButtonMul;
    QPushButton *pushButtonSup;
    QPushButton *pushButtonAnd;
    QPushButton *pushButtonPoint;
    QPushButton *pushButton3;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonQuote;
    QPushButton *pushButton8;
    QPushButton *pushButtonComp;
    QPushButton *pushButtonDi;
    QPushButton *pushButton6;
    QPushButton *pushButton7;
    QPushButton *pushButtonInf;
    QPushButton *pushButtonDif;
    QPushButton *pushButton1;
    QPushButton *pushButtonNeg;
    QPushButton *pushButton5;
    QPushButton *pushButtonEnter;
    QPushButton *pushButton4;
    QPushButton *pushButtonLastop;
    QPushButton *pushButtonDiv;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonSupeq;
    QPushButton *pushButtonRightPar;
    QPushButton *pushButtonRe;
    QPushButton *pushButtonRedo;
    QLineEdit *Message;
    QTableWidget *vuePile;
    QSpinBox *nbLignes;
    QPushButton *pushButtonSound;
    QPushButton *pushButtonUndo;
    QPushButton *pushButton9;
    QStatusBar *statusBar;
    QButtonGroup *OpLogiques;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 1061);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	font: 10pt \"Calibri\";\n"
"}\n"
"\n"
"QMainWindow {\n"
"	background-color: rgb(50,50,50);\n"
"}\n"
"\n"
"this->setFixedSize(500,500);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        expression = new QLineEdit(centralWidget);
        expression->setObjectName(QStringLiteral("expression"));
        expression->setEnabled(true);
        expression->setGeometry(QRect(20, 250, 311, 31));
        QPalette palette;
        QBrush brush(QColor(232, 232, 232, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        expression->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        expression->setFont(font1);
        pushButtonAC = new QPushButton(centralWidget);
        pushButtonAC->setObjectName(QStringLiteral("pushButtonAC"));
        pushButtonAC->setEnabled(true);
        pushButtonAC->setGeometry(QRect(340, 250, 41, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pushButtonAC->setFont(font2);
        pushButtonAC->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonAC->setMouseTracking(true);
        pushButtonAC->setAutoFillBackground(false);
        pushButtonAC->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(75,75,75);\n"
"     border-style: outset;\n"
"			font: 9pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonAC->setAutoDefault(false);
        pushButtonAC->setFlat(false);
        pushButtonMinus = new QPushButton(centralWidget);
        pushButtonMinus->setObjectName(QStringLiteral("pushButtonMinus"));
        pushButtonMinus->setGeometry(QRect(260, 610, 121, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        pushButtonMinus->setFont(font3);
        pushButtonMinus->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonMinus->setMouseTracking(true);
        pushButtonMinus->setAutoFillBackground(false);
        pushButtonMinus->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonIm = new QPushButton(centralWidget);
        pushButtonIm->setObjectName(QStringLiteral("pushButtonIm"));
        pushButtonIm->setGeometry(QRect(320, 460, 61, 31));
        pushButtonIm->setFont(font3);
        pushButtonIm->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonIm->setMouseTracking(true);
        pushButtonIm->setAutoFillBackground(false);
        pushButtonIm->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonEval = new QPushButton(centralWidget);
        pushButtonEval->setObjectName(QStringLiteral("pushButtonEval"));
        pushButtonEval->setGeometry(QRect(260, 330, 121, 71));
        pushButtonEval->setFont(font3);
        pushButtonEval->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonEval->setMouseTracking(true);
        pushButtonEval->setAutoFillBackground(false);
        pushButtonEval->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(75,75,75);\n"
"     border-style: outset;\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonIft = new QPushButton(centralWidget);
        pushButtonIft->setObjectName(QStringLiteral("pushButtonIft"));
        pushButtonIft->setGeometry(QRect(180, 330, 82, 41));
        pushButtonIft->setFont(font3);
        pushButtonIft->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonIft->setMouseTracking(true);
        pushButtonIft->setAutoFillBackground(false);
        pushButtonIft->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(147,165,141);\n"
"     border-style: outset;\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonMod = new QPushButton(centralWidget);
        pushButtonMod->setObjectName(QStringLiteral("pushButtonMod"));
        pushButtonMod->setGeometry(QRect(320, 520, 61, 31));
        pushButtonMod->setFont(font3);
        pushButtonMod->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonMod->setMouseTracking(true);
        pushButtonMod->setAutoFillBackground(false);
        pushButtonMod->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonInfeq = new QPushButton(centralWidget);
        OpLogiques = new QButtonGroup(MainWindow);
        OpLogiques->setObjectName(QStringLiteral("OpLogiques"));
        OpLogiques->addButton(pushButtonInfeq);
        pushButtonInfeq->setObjectName(QStringLiteral("pushButtonInfeq"));
        pushButtonInfeq->setGeometry(QRect(100, 440, 41, 31));
        pushButtonInfeq->setFont(font3);
        pushButtonInfeq->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonInfeq->setMouseTracking(true);
        pushButtonInfeq->setAutoFillBackground(false);
        pushButtonInfeq->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonNum = new QPushButton(centralWidget);
        pushButtonNum->setObjectName(QStringLiteral("pushButtonNum"));
        pushButtonNum->setGeometry(QRect(320, 430, 61, 31));
        pushButtonNum->setFont(font3);
        pushButtonNum->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonNum->setMouseTracking(true);
        pushButtonNum->setAutoFillBackground(false);
        pushButtonNum->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonSwap = new QPushButton(centralWidget);
        pushButtonSwap->setObjectName(QStringLiteral("pushButtonSwap"));
        pushButtonSwap->setGeometry(QRect(100, 330, 82, 41));
        pushButtonSwap->setFont(font2);
        pushButtonSwap->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonSwap->setMouseTracking(true);
        pushButtonSwap->setAutoFillBackground(false);
        pushButtonSwap->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"			font: 9pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonSpace = new QPushButton(centralWidget);
        pushButtonSpace->setObjectName(QStringLiteral("pushButtonSpace"));
        pushButtonSpace->setGeometry(QRect(20, 700, 241, 51));
        pushButtonSpace->setFont(font3);
        pushButtonSpace->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonSpace->setMouseTracking(true);
        pushButtonSpace->setAutoFillBackground(false);
        pushButtonSpace->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"	 border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonDrop = new QPushButton(centralWidget);
        pushButtonDrop->setObjectName(QStringLiteral("pushButtonDrop"));
        pushButtonDrop->setGeometry(QRect(140, 370, 41, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        pushButtonDrop->setFont(font4);
        pushButtonDrop->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonDrop->setMouseTracking(true);
        pushButtonDrop->setAutoFillBackground(false);
        pushButtonDrop->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"		font: 8pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonEq = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonEq);
        pushButtonEq->setObjectName(QStringLiteral("pushButtonEq"));
        pushButtonEq->setGeometry(QRect(20, 440, 41, 31));
        pushButtonEq->setFont(font3);
        pushButtonEq->setAutoFillBackground(false);
        pushButtonEq->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonOr = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonOr);
        pushButtonOr->setObjectName(QStringLiteral("pushButtonOr"));
        pushButtonOr->setGeometry(QRect(100, 410, 82, 31));
        pushButtonOr->setFont(font3);
        pushButtonOr->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonOr->setMouseTracking(true);
        pushButtonOr->setAutoFillBackground(false);
        pushButtonOr->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonDen = new QPushButton(centralWidget);
        pushButtonDen->setObjectName(QStringLiteral("pushButtonDen"));
        pushButtonDen->setGeometry(QRect(260, 430, 61, 31));
        pushButtonDen->setFont(font3);
        pushButtonDen->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonDen->setMouseTracking(true);
        pushButtonDen->setAutoFillBackground(false);
        pushButtonDen->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton2 = new QPushButton(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(pushButton2);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(100, 600, 81, 51));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(128, 128, 128, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton2->setPalette(palette1);
        pushButton2->setFont(font3);
        pushButton2->setCursor(QCursor(Qt::ArrowCursor));
        pushButton2->setMouseTracking(true);
        pushButton2->setAutoFillBackground(false);
        pushButton2->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonAdd = new QPushButton(centralWidget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(260, 640, 121, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush4(QColor(136, 171, 176, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(85, 255, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush6(QColor(51, 153, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        pushButtonAdd->setPalette(palette2);
        pushButtonAdd->setFont(font3);
        pushButtonAdd->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonAdd->setMouseTracking(true);
        pushButtonAdd->setAutoFillBackground(false);
        pushButtonAdd->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonNot = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonNot);
        pushButtonNot->setObjectName(QStringLiteral("pushButtonNot"));
        pushButtonNot->setGeometry(QRect(180, 410, 81, 31));
        pushButtonNot->setFont(font3);
        pushButtonNot->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonNot->setMouseTracking(true);
        pushButtonNot->setAutoFillBackground(false);
        pushButtonNot->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonDup = new QPushButton(centralWidget);
        pushButtonDup->setObjectName(QStringLiteral("pushButtonDup"));
        pushButtonDup->setGeometry(QRect(100, 370, 41, 41));
        pushButtonDup->setFont(font4);
        pushButtonDup->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonDup->setMouseTracking(true);
        pushButtonDup->setAutoFillBackground(false);
        pushButtonDup->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"	font: 8pt \"Calibri\";\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton0 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton0);
        pushButton0->setObjectName(QStringLiteral("pushButton0"));
        pushButton0->setGeometry(QRect(100, 650, 81, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton0->setPalette(palette3);
        pushButton0->setFont(font3);
        pushButton0->setCursor(QCursor(Qt::ArrowCursor));
        pushButton0->setMouseTracking(true);
        pushButton0->setAutoFillBackground(false);
        pushButton0->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonClear = new QPushButton(centralWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(180, 290, 201, 41));
        pushButtonClear->setFont(font3);
        pushButtonClear->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonClear->setMouseTracking(true);
        pushButtonClear->setAutoFillBackground(false);
        pushButtonClear->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonLastargs = new QPushButton(centralWidget);
        pushButtonLastargs->setObjectName(QStringLiteral("pushButtonLastargs"));
        pushButtonLastargs->setGeometry(QRect(20, 370, 82, 41));
        pushButtonLastargs->setFont(font2);
        pushButtonLastargs->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonLastargs->setMouseTracking(true);
        pushButtonLastargs->setAutoFillBackground(false);
        pushButtonLastargs->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"			font: 9pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonLeftPar = new QPushButton(centralWidget);
        pushButtonLeftPar->setObjectName(QStringLiteral("pushButtonLeftPar"));
        pushButtonLeftPar->setGeometry(QRect(20, 470, 81, 31));
        pushButtonLeftPar->setFont(font3);
        pushButtonLeftPar->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonLeftPar->setMouseTracking(true);
        pushButtonLeftPar->setAutoFillBackground(false);
        pushButtonLeftPar->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(176,172,136);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonMul = new QPushButton(centralWidget);
        pushButtonMul->setObjectName(QStringLiteral("pushButtonMul"));
        pushButtonMul->setGeometry(QRect(260, 580, 121, 31));
        pushButtonMul->setFont(font3);
        pushButtonMul->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonMul->setMouseTracking(true);
        pushButtonMul->setAutoFillBackground(false);
        pushButtonMul->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonSup = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonSup);
        pushButtonSup->setObjectName(QStringLiteral("pushButtonSup"));
        pushButtonSup->setGeometry(QRect(220, 440, 41, 31));
        pushButtonSup->setFont(font3);
        pushButtonSup->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonSup->setMouseTracking(true);
        pushButtonSup->setAutoFillBackground(false);
        pushButtonSup->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonAnd = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonAnd);
        pushButtonAnd->setObjectName(QStringLiteral("pushButtonAnd"));
        pushButtonAnd->setGeometry(QRect(20, 410, 82, 31));
        pushButtonAnd->setFont(font3);
        pushButtonAnd->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonAnd->setMouseTracking(true);
        pushButtonAnd->setAutoFillBackground(false);
        pushButtonAnd->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonPoint = new QPushButton(centralWidget);
        pushButtonPoint->setObjectName(QStringLiteral("pushButtonPoint"));
        pushButtonPoint->setGeometry(QRect(180, 650, 81, 51));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButtonPoint->setPalette(palette4);
        pushButtonPoint->setFont(font3);
        pushButtonPoint->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonPoint->setMouseTracking(true);
        pushButtonPoint->setAutoFillBackground(false);
        pushButtonPoint->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton3 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton3);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));
        pushButton3->setGeometry(QRect(180, 600, 81, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton3->setPalette(palette5);
        pushButton3->setFont(font3);
        pushButton3->setCursor(QCursor(Qt::ArrowCursor));
        pushButton3->setMouseTracking(true);
        pushButton3->setAutoFillBackground(false);
        pushButton3->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonEdit = new QPushButton(centralWidget);
        pushButtonEdit->setObjectName(QStringLiteral("pushButtonEdit"));
        pushButtonEdit->setGeometry(QRect(180, 370, 82, 41));
        pushButtonEdit->setFont(font3);
        pushButtonEdit->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonEdit->setMouseTracking(true);
        pushButtonEdit->setAutoFillBackground(false);
        pushButtonEdit->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(147,165,141);\n"
"     border-style: outset;\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonQuote = new QPushButton(centralWidget);
        pushButtonQuote->setObjectName(QStringLiteral("pushButtonQuote"));
        pushButtonQuote->setGeometry(QRect(100, 470, 81, 31));
        pushButtonQuote->setFont(font3);
        pushButtonQuote->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonQuote->setMouseTracking(true);
        pushButtonQuote->setAutoFillBackground(false);
        pushButtonQuote->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(176,172,136);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton8 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton8);
        pushButton8->setObjectName(QStringLiteral("pushButton8"));
        pushButton8->setGeometry(QRect(100, 500, 81, 51));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton8->setPalette(palette6);
        pushButton8->setFont(font3);
        pushButton8->setCursor(QCursor(Qt::ArrowCursor));
        pushButton8->setMouseTracking(true);
        pushButton8->setAutoFillBackground(false);
        pushButton8->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
" 	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonComp = new QPushButton(centralWidget);
        pushButtonComp->setObjectName(QStringLiteral("pushButtonComp"));
        pushButtonComp->setGeometry(QRect(260, 490, 121, 31));
        pushButtonComp->setFont(font3);
        pushButtonComp->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonComp->setMouseTracking(true);
        pushButtonComp->setAutoFillBackground(false);
        pushButtonComp->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonDi = new QPushButton(centralWidget);
        pushButtonDi->setObjectName(QStringLiteral("pushButtonDi"));
        pushButtonDi->setGeometry(QRect(260, 550, 121, 31));
        pushButtonDi->setFont(font3);
        pushButtonDi->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonDi->setMouseTracking(true);
        pushButtonDi->setAutoFillBackground(false);
        pushButtonDi->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton6 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton6);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));
        pushButton6->setGeometry(QRect(180, 550, 81, 51));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton6->setPalette(palette7);
        pushButton6->setFont(font3);
        pushButton6->setCursor(QCursor(Qt::ArrowCursor));
        pushButton6->setMouseTracking(true);
        pushButton6->setAutoFillBackground(false);
        pushButton6->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton7 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton7);
        pushButton7->setObjectName(QStringLiteral("pushButton7"));
        pushButton7->setGeometry(QRect(20, 500, 81, 51));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton7->setPalette(palette8);
        pushButton7->setFont(font3);
        pushButton7->setCursor(QCursor(Qt::ArrowCursor));
        pushButton7->setMouseTracking(true);
        pushButton7->setAcceptDrops(true);
        pushButton7->setAutoFillBackground(false);
        pushButton7->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonInf = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonInf);
        pushButtonInf->setObjectName(QStringLiteral("pushButtonInf"));
        pushButtonInf->setGeometry(QRect(180, 440, 41, 31));
        pushButtonInf->setFont(font3);
        pushButtonInf->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonInf->setMouseTracking(true);
        pushButtonInf->setAutoFillBackground(false);
        pushButtonInf->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonDif = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonDif);
        pushButtonDif->setObjectName(QStringLiteral("pushButtonDif"));
        pushButtonDif->setGeometry(QRect(60, 440, 41, 31));
        pushButtonDif->setFont(font3);
        pushButtonDif->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonDif->setMouseTracking(true);
        pushButtonDif->setAutoFillBackground(false);
        pushButtonDif->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton1 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton1);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(20, 600, 81, 51));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton1->setPalette(palette9);
        pushButton1->setFont(font3);
        pushButton1->setCursor(QCursor(Qt::ArrowCursor));
        pushButton1->setMouseTracking(true);
        pushButton1->setAutoFillBackground(false);
        pushButton1->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonNeg = new QPushButton(centralWidget);
        pushButtonNeg->setObjectName(QStringLiteral("pushButtonNeg"));
        pushButtonNeg->setGeometry(QRect(260, 400, 121, 31));
        pushButtonNeg->setFont(font3);
        pushButtonNeg->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonNeg->setMouseTracking(true);
        pushButtonNeg->setAutoFillBackground(false);
        pushButtonNeg->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton5 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton5);
        pushButton5->setObjectName(QStringLiteral("pushButton5"));
        pushButton5->setGeometry(QRect(100, 550, 81, 51));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton5->setPalette(palette10);
        pushButton5->setFont(font3);
        pushButton5->setCursor(QCursor(Qt::ArrowCursor));
        pushButton5->setMouseTracking(true);
        pushButton5->setAutoFillBackground(false);
        pushButton5->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonEnter = new QPushButton(centralWidget);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));
        pushButtonEnter->setGeometry(QRect(260, 670, 121, 81));
        pushButtonEnter->setFont(font3);
        pushButtonEnter->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonEnter->setMouseTracking(true);
        pushButtonEnter->setAutoFillBackground(false);
        pushButtonEnter->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(75,75,75);\n"
"     border-style: outset;\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton4 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton4);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));
        pushButton4->setGeometry(QRect(20, 550, 81, 51));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton4->setPalette(palette11);
        pushButton4->setFont(font3);
        pushButton4->setCursor(QCursor(Qt::ArrowCursor));
        pushButton4->setMouseTracking(true);
        pushButton4->setAutoFillBackground(false);
        pushButton4->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonLastop = new QPushButton(centralWidget);
        pushButtonLastop->setObjectName(QStringLiteral("pushButtonLastop"));
        pushButtonLastop->setGeometry(QRect(20, 330, 82, 41));
        pushButtonLastop->setFont(font2);
        pushButtonLastop->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonLastop->setMouseTracking(true);
        pushButtonLastop->setAutoFillBackground(false);
        pushButtonLastop->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"			font: 9pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonDiv = new QPushButton(centralWidget);
        pushButtonDiv->setObjectName(QStringLiteral("pushButtonDiv"));
        pushButtonDiv->setGeometry(QRect(260, 520, 61, 31));
        pushButtonDiv->setFont(font3);
        pushButtonDiv->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonDiv->setMouseTracking(true);
        pushButtonDiv->setAutoFillBackground(false);
        pushButtonDiv->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonBack = new QPushButton(centralWidget);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(20, 650, 81, 51));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButtonBack->setPalette(palette12);
        pushButtonBack->setFont(font3);
        pushButtonBack->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonBack->setMouseTracking(true);
        pushButtonBack->setAutoFillBackground(false);
        pushButtonBack->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	\n"
"	\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonSupeq = new QPushButton(centralWidget);
        OpLogiques->addButton(pushButtonSupeq);
        pushButtonSupeq->setObjectName(QStringLiteral("pushButtonSupeq"));
        pushButtonSupeq->setGeometry(QRect(140, 440, 41, 31));
        pushButtonSupeq->setFont(font3);
        pushButtonSupeq->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonSupeq->setMouseTracking(true);
        pushButtonSupeq->setAutoFillBackground(false);
        pushButtonSupeq->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(182,147,120);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonRightPar = new QPushButton(centralWidget);
        pushButtonRightPar->setObjectName(QStringLiteral("pushButtonRightPar"));
        pushButtonRightPar->setGeometry(QRect(180, 470, 81, 31));
        pushButtonRightPar->setFont(font3);
        pushButtonRightPar->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonRightPar->setMouseTracking(true);
        pushButtonRightPar->setAutoFillBackground(false);
        pushButtonRightPar->setStyleSheet(QLatin1String("QPushButton {\n"
"       background-color: rgb(176,172,136);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonRe = new QPushButton(centralWidget);
        pushButtonRe->setObjectName(QStringLiteral("pushButtonRe"));
        pushButtonRe->setGeometry(QRect(260, 460, 61, 31));
        pushButtonRe->setFont(font3);
        pushButtonRe->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonRe->setMouseTracking(true);
        pushButtonRe->setAutoFillBackground(false);
        pushButtonRe->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(136,171,176);\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonRedo = new QPushButton(centralWidget);
        pushButtonRedo->setObjectName(QStringLiteral("pushButtonRedo"));
        pushButtonRedo->setEnabled(true);
        pushButtonRedo->setGeometry(QRect(100, 290, 81, 41));
        pushButtonRedo->setFont(font2);
        pushButtonRedo->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonRedo->setMouseTracking(true);
        pushButtonRedo->setAutoFillBackground(false);
        pushButtonRedo->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"			font: 9pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonRedo->setAutoDefault(false);
        pushButtonRedo->setFlat(false);
        Message = new QLineEdit(centralWidget);
        Message->setObjectName(QStringLiteral("Message"));
        Message->setEnabled(true);
        Message->setGeometry(QRect(50, 20, 301, 31));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Base, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        Message->setPalette(palette13);
        Message->setFont(font1);
        Message->setReadOnly(true);
        vuePile = new QTableWidget(centralWidget);
        vuePile->setObjectName(QStringLiteral("vuePile"));
        vuePile->setGeometry(QRect(20, 50, 361, 191));
        nbLignes = new QSpinBox(centralWidget);
        nbLignes->setObjectName(QStringLiteral("nbLignes"));
        nbLignes->setGeometry(QRect(350, 20, 31, 31));
        pushButtonSound = new QPushButton(centralWidget);
        pushButtonSound->setObjectName(QStringLiteral("pushButtonSound"));
        pushButtonSound->setGeometry(QRect(20, 20, 31, 31));
        pushButtonSound->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"			font: 9pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButtonUndo = new QPushButton(centralWidget);
        pushButtonUndo->setObjectName(QStringLiteral("pushButtonUndo"));
        pushButtonUndo->setGeometry(QRect(20, 290, 81, 41));
        pushButtonUndo->setFont(font2);
        pushButtonUndo->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonUndo->setMouseTracking(true);
        pushButtonUndo->setAutoFillBackground(false);
        pushButtonUndo->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: rgb(100,100,100);\n"
"     border-style: outset;\n"
"			font: 9pt \"Calibri\";\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        pushButton9 = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButton9);
        pushButton9->setObjectName(QStringLiteral("pushButton9"));
        pushButton9->setGeometry(QRect(180, 500, 81, 51));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        pushButton9->setPalette(palette14);
        pushButton9->setFont(font3);
        pushButton9->setCursor(QCursor(Qt::ArrowCursor));
        pushButton9->setMouseTracking(true);
        pushButton9->setAutoFillBackground(false);
        pushButton9->setStyleSheet(QLatin1String("QPushButton {\n"
"     background-color: grey;\n"
"     border-style: outset;\n"
"	 color: white;\n"
" }\n"
"\n"
"QPushButton:hover { background-color: rgb(148,148,148); }"));
        MainWindow->setCentralWidget(centralWidget);
        pushButtonLastargs->raise();
        pushButtonDup->raise();
        pushButtonDrop->raise();
        pushButtonSwap->raise();
        pushButtonEdit->raise();
        pushButtonIft->raise();
        pushButton9->raise();
        pushButton6->raise();
        pushButtonRe->raise();
        pushButtonNeg->raise();
        pushButtonComp->raise();
        pushButtonDiv->raise();
        expression->raise();
        pushButtonAC->raise();
        pushButtonMinus->raise();
        pushButtonIm->raise();
        pushButtonEval->raise();
        pushButtonMod->raise();
        pushButtonInfeq->raise();
        pushButtonNum->raise();
        pushButtonEq->raise();
        pushButtonOr->raise();
        pushButtonDen->raise();
        pushButton2->raise();
        pushButtonAdd->raise();
        pushButton0->raise();
        pushButtonMul->raise();
        pushButtonSup->raise();
        pushButtonAnd->raise();
        pushButton8->raise();
        pushButtonDi->raise();
        pushButton7->raise();
        pushButtonInf->raise();
        pushButtonDif->raise();
        pushButton5->raise();
        pushButtonEnter->raise();
        pushButton4->raise();
        pushButtonLastop->raise();
        pushButtonBack->raise();
        pushButtonSupeq->raise();
        pushButtonRedo->raise();
        pushButton1->raise();
        pushButton3->raise();
        pushButtonPoint->raise();
        pushButtonNot->raise();
        pushButtonClear->raise();
        pushButtonRightPar->raise();
        Message->raise();
        vuePile->raise();
        nbLignes->raise();
        pushButtonSound->raise();
        pushButtonUndo->raise();
        pushButtonQuote->raise();
        pushButtonLeftPar->raise();
        pushButtonSpace->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        pushButtonAC->setDefault(false);
        pushButtonRedo->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        expression->setText(QString());
        pushButtonAC->setText(QApplication::translate("MainWindow", "AC", 0));
        pushButtonMinus->setText(QApplication::translate("MainWindow", "-", 0));
        pushButtonIm->setText(QApplication::translate("MainWindow", "IM", 0));
        pushButtonEval->setText(QApplication::translate("MainWindow", "EVAL", 0));
        pushButtonIft->setText(QApplication::translate("MainWindow", "IFT", 0));
        pushButtonMod->setText(QApplication::translate("MainWindow", "MOD", 0));
        pushButtonInfeq->setText(QApplication::translate("MainWindow", "\342\211\244", 0));
        pushButtonNum->setText(QApplication::translate("MainWindow", "NUM", 0));
        pushButtonSwap->setText(QApplication::translate("MainWindow", "SWAP", 0));
        pushButtonSpace->setText(QApplication::translate("MainWindow", "SPACE", 0));
        pushButtonDrop->setText(QApplication::translate("MainWindow", "DROP", 0));
        pushButtonEq->setText(QApplication::translate("MainWindow", "=", 0));
        pushButtonOr->setText(QApplication::translate("MainWindow", "OR", 0));
        pushButtonDen->setText(QApplication::translate("MainWindow", "DEN", 0));
        pushButton2->setText(QApplication::translate("MainWindow", "2", 0));
        pushButtonAdd->setText(QApplication::translate("MainWindow", "+", 0));
        pushButtonNot->setText(QApplication::translate("MainWindow", "NOT", 0));
        pushButtonDup->setText(QApplication::translate("MainWindow", "DUP", 0));
        pushButton0->setText(QApplication::translate("MainWindow", "0", 0));
        pushButtonClear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        pushButtonLastargs->setText(QApplication::translate("MainWindow", "LASTARGS", 0));
        pushButtonLeftPar->setText(QApplication::translate("MainWindow", "(", 0));
        pushButtonMul->setText(QApplication::translate("MainWindow", "*", 0));
        pushButtonSup->setText(QApplication::translate("MainWindow", ">", 0));
        pushButtonAnd->setText(QApplication::translate("MainWindow", "AND", 0));
        pushButtonPoint->setText(QApplication::translate("MainWindow", ".", 0));
        pushButton3->setText(QApplication::translate("MainWindow", "3", 0));
        pushButtonEdit->setText(QApplication::translate("MainWindow", "EDIT", 0));
        pushButtonQuote->setText(QApplication::translate("MainWindow", "'", 0));
        pushButton8->setText(QApplication::translate("MainWindow", "8", 0));
        pushButtonComp->setText(QApplication::translate("MainWindow", "$", 0));
        pushButtonDi->setText(QApplication::translate("MainWindow", "/", 0));
        pushButton6->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton7->setText(QApplication::translate("MainWindow", "7", 0));
        pushButtonInf->setText(QApplication::translate("MainWindow", "<", 0));
        pushButtonDif->setText(QApplication::translate("MainWindow", "!=", 0));
        pushButton1->setText(QApplication::translate("MainWindow", "1", 0));
        pushButtonNeg->setText(QApplication::translate("MainWindow", "NEG", 0));
        pushButton5->setText(QApplication::translate("MainWindow", "5", 0));
        pushButtonEnter->setText(QApplication::translate("MainWindow", "ENTER", 0));
        pushButton4->setText(QApplication::translate("MainWindow", "4", 0));
        pushButtonLastop->setText(QApplication::translate("MainWindow", "LASTOP", 0));
        pushButtonDiv->setText(QApplication::translate("MainWindow", "DIV", 0));
        pushButtonBack->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        pushButtonSupeq->setText(QApplication::translate("MainWindow", "\342\211\245", 0));
        pushButtonRightPar->setText(QApplication::translate("MainWindow", ")", 0));
        pushButtonRe->setText(QApplication::translate("MainWindow", "RE", 0));
        pushButtonRedo->setText(QApplication::translate("MainWindow", "REDO", 0));
        Message->setText(QString());
        pushButtonSound->setText(QApplication::translate("MainWindow", "son", 0));
        pushButtonUndo->setText(QApplication::translate("MainWindow", "UNDO", 0));
        pushButton9->setText(QApplication::translate("MainWindow", "9", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
