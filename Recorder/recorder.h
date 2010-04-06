#ifndef RECORDER_H
#define RECORDER_H

#include <QtGui/QWidget>

#include <QListWidgetItem>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QProcess>

namespace Ui
{
    class RecorderClass;
}

class Recorder : public QWidget
{
    Q_OBJECT

public:
    Recorder(QWidget *parent = 0);
    ~Recorder();

private:
    Ui::RecorderClass *ui;
    int currentSentence;
    int listSize;
    QString action;
    QString fileStoragePath;
    QProcess recordProcess;
    QProcess playProcess;
    int fileSuffix;

private slots:
    void on_playButton_clicked();
    void on_stopButton_clicked();
    void on_recordButton_clicked();
    void on_previousButton_clicked();
    void on_nextButton_clicked();
    void on_sentenceList_itemSelectionChanged();
    void on_sentenceList_itemClicked(QListWidgetItem* item);
    void on_submitButton_clicked();
    void on_playProcess_finished(int exitCode);
};

#endif // RECORDER_H
