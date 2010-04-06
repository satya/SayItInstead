/********************************************************************************
** Form generated from reading ui file 'recorder.ui'
**
** Created: Mon Mar 16 00:33:18 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RECORDER_H
#define UI_RECORDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecorderClass
{
public:
    QGroupBox *submitBox;
    QPlainTextEdit *submittedText;
    QPushButton *submitButton;
    QLineEdit *pathLine;
    QGroupBox *recordBox;
    QListWidget *sentenceList;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPlainTextEdit *currentSentence;
    QFrame *line;
    QPushButton *playButton;
    QPushButton *stopButton;
    QPushButton *recordButton;
    QLabel *statusLabel;
    QPlainTextEdit *statusBox;
    QLabel *listLabel;
    QLabel *currentLabel;

    void setupUi(QWidget *RecorderClass)
    {
        if (RecorderClass->objectName().isEmpty())
            RecorderClass->setObjectName(QString::fromUtf8("RecorderClass"));
        RecorderClass->setEnabled(true);
        RecorderClass->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RecorderClass->sizePolicy().hasHeightForWidth());
        RecorderClass->setSizePolicy(sizePolicy);
        RecorderClass->setMinimumSize(QSize(640, 480));
        RecorderClass->setMaximumSize(QSize(640, 480));
        submitBox = new QGroupBox(RecorderClass);
        submitBox->setObjectName(QString::fromUtf8("submitBox"));
        submitBox->setGeometry(QRect(10, 10, 621, 191));
        submittedText = new QPlainTextEdit(submitBox);
        submittedText->setObjectName(QString::fromUtf8("submittedText"));
        submittedText->setGeometry(QRect(10, 50, 521, 131));
        submitButton = new QPushButton(submitBox);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(540, 20, 75, 23));
        pathLine = new QLineEdit(submitBox);
        pathLine->setObjectName(QString::fromUtf8("pathLine"));
        pathLine->setGeometry(QRect(10, 20, 521, 20));
        recordBox = new QGroupBox(RecorderClass);
        recordBox->setObjectName(QString::fromUtf8("recordBox"));
        recordBox->setEnabled(false);
        recordBox->setGeometry(QRect(10, 210, 621, 261));
        sentenceList = new QListWidget(recordBox);
        sentenceList->setObjectName(QString::fromUtf8("sentenceList"));
        sentenceList->setGeometry(QRect(10, 40, 311, 181));
        previousButton = new QPushButton(recordBox);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setGeometry(QRect(10, 230, 75, 23));
        nextButton = new QPushButton(recordBox);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(250, 230, 71, 23));
        currentSentence = new QPlainTextEdit(recordBox);
        currentSentence->setObjectName(QString::fromUtf8("currentSentence"));
        currentSentence->setGeometry(QRect(330, 40, 281, 61));
        currentSentence->setReadOnly(true);
        line = new QFrame(recordBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(320, 110, 20, 141));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        playButton = new QPushButton(recordBox);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(340, 170, 75, 23));
        stopButton = new QPushButton(recordBox);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(340, 140, 75, 23));
        recordButton = new QPushButton(recordBox);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setGeometry(QRect(340, 110, 75, 23));
        statusLabel = new QLabel(recordBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(430, 110, 41, 16));
        statusBox = new QPlainTextEdit(recordBox);
        statusBox->setObjectName(QString::fromUtf8("statusBox"));
        statusBox->setGeometry(QRect(430, 130, 181, 121));
        statusBox->setReadOnly(true);
        listLabel = new QLabel(recordBox);
        listLabel->setObjectName(QString::fromUtf8("listLabel"));
        listLabel->setGeometry(QRect(10, 20, 261, 16));
        currentLabel = new QLabel(recordBox);
        currentLabel->setObjectName(QString::fromUtf8("currentLabel"));
        currentLabel->setGeometry(QRect(330, 20, 251, 16));

        retranslateUi(RecorderClass);

        QMetaObject::connectSlotsByName(RecorderClass);
    } // setupUi

    void retranslateUi(QWidget *RecorderClass)
    {
        RecorderClass->setWindowTitle(QApplication::translate("RecorderClass", "Recorder", 0, QApplication::UnicodeUTF8));
        submitBox->setTitle(QApplication::translate("RecorderClass", "Submit Text", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("RecorderClass", "Submit", 0, QApplication::UnicodeUTF8));
        pathLine->setText(QApplication::translate("RecorderClass", "Enter full directory path here where you want to save the recorded files", 0, QApplication::UnicodeUTF8));
        recordBox->setTitle(QApplication::translate("RecorderClass", "Record Text", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("RecorderClass", "Previous", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("RecorderClass", "Next", 0, QApplication::UnicodeUTF8));
        playButton->setText(QApplication::translate("RecorderClass", "Play", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("RecorderClass", "Stop", 0, QApplication::UnicodeUTF8));
        recordButton->setText(QApplication::translate("RecorderClass", "Record", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("RecorderClass", "Status:", 0, QApplication::UnicodeUTF8));
        listLabel->setText(QApplication::translate("RecorderClass", "Sentence List:", 0, QApplication::UnicodeUTF8));
        currentLabel->setText(QApplication::translate("RecorderClass", "Current Sentence:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(RecorderClass);
    } // retranslateUi

};

namespace Ui {
    class RecorderClass: public Ui_RecorderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDER_H
