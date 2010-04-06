#include "recorder.h"
#include "ui_recorder.h"

Recorder::Recorder(QWidget *parent)
    : QWidget(parent), ui(new Ui::RecorderClass)
{
    ui->setupUi(this);

    currentSentence = -1;

    listSize = 0;

    connect(&playProcess, SIGNAL(finished(int)), this, SLOT(on_playProcess_finished(int)));

    fileSuffix = 0;
}

Recorder::~Recorder()
{
    QFile file(fileStoragePath + "/count.txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

     QTextStream out(&file);
     out << (fileSuffix + listSize);

     file.close();

    delete ui;
}

void Recorder::on_submitButton_clicked()
{
    QString text = ui->submittedText->toPlainText();

    QString path = ui->pathLine->text();

    if (text.size() == 0) {
        QMessageBox msgBox;
        msgBox.setText("Please input some text.");
        msgBox.exec();

        return;
    }

    QDir dir(path);

    if (!dir.exists()) {
        QMessageBox msgBox;
        msgBox.setText("The given directory does not exist.");
        msgBox.exec();

        return;
    }

    fileStoragePath = dir.absolutePath();



    QFile suffix(fileStoragePath + "/count.txt");
    if (!suffix.open(QIODevice::ReadOnly)) {
        suffix.close();

        fileSuffix = 0;

    } else {
        QTextStream in(&suffix);

        QString line = in.readLine();

        fileSuffix = line.toInt();
    }
    suffix.close();



    QFile file(fileStoragePath + "/sample.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QMessageBox msgBox;
        msgBox.setText("File could not be created at the specified directory.");
        msgBox.exec();

        return;
    }

    QTextStream out(&file);

    text = text.trimmed();

    text.replace("\n", " ");
    text.replace("-", " ");
    text.replace("\"", "");
    text.replace(",", "");
    text.replace(".", "");
    text.replace("!", "");
    text.replace("?", "");
    text.replace(":", "");
    text.replace(";", "");
    text.replace(")", "");
    text.replace("(", "");

    int flag = 1, pos = 0, lastPos = 0, stringNumber = 0;

    while (flag) {
       int wordCount = 0;

       while (wordCount < 10) {

           pos = text.indexOf(" ", pos + 1);

           if (pos == -1) {
               flag = 0;
               break;
           } else {
               wordCount++;
           }
       }

       if (wordCount == 10) {
           ui->sentenceList->addItem(text.mid(lastPos, pos - lastPos).toUpper().trimmed());

           out << "SAMPLE" << (stringNumber + fileSuffix) << " " << text.mid(lastPos, pos - lastPos).toUpper().trimmed() << "\n";

           stringNumber++;
       }

       if (flag == 0) {
           ui->sentenceList->addItem(text.mid(lastPos, text.size() - lastPos).toUpper().trimmed());

           out << "SAMPLE" << (stringNumber + fileSuffix) << " " << text.mid(lastPos, text.size() - lastPos).toUpper().trimmed() << "\n";

           stringNumber++;
       }

       lastPos = pos;
    }

    // Update list size
    listSize = ui->sentenceList->count();
    currentSentence = 0;

    // Set the selected item to the first sentence
    ui->sentenceList->setCurrentRow(0);

    // Set the bottom panel to enabled
    ui->recordBox->setEnabled(true);

    // Set the current action
    action = "Stop";

    // Disable Stop Button
    ui->stopButton->setEnabled(false);

    ui->submitBox->setEnabled(false);

    file.close();
}



void Recorder::on_sentenceList_itemClicked(QListWidgetItem* item)
{
    QString str = item->text();

    ui->currentSentence->setPlainText(str);

    currentSentence = ui->sentenceList->currentRow();

    ui->statusBox->setPlainText("Current Sentence Selected = " + QString::number(currentSentence));
}



void Recorder::on_sentenceList_itemSelectionChanged()
{
    QList<QListWidgetItem *> selectedItem = ui->sentenceList->selectedItems();

    this->on_sentenceList_itemClicked(selectedItem.at(0));
}



void Recorder::on_nextButton_clicked()
{
    int current = ui->sentenceList->currentRow();

    if (current < listSize - 1) {
        ui->sentenceList->setCurrentRow(current + 1);
    }

}



void Recorder::on_previousButton_clicked()
{
    int current = ui->sentenceList->currentRow();

    if (current > 0) {
        ui->sentenceList->setCurrentRow(current - 1);
    }

}



void Recorder::on_recordButton_clicked()
{
    ui->playButton->setEnabled(false);
    ui->recordButton->setEnabled(false);
    ui->stopButton->setEnabled(true);

    ui->sentenceList->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->previousButton->setEnabled(false);

    int num = fileSuffix + currentSentence;

    QString fullPath = fileStoragePath + "/sample" + QString::number(num) + ".wav";

    QStringList arguments;
    arguments << "-t" << "wav" << "-f" << "S16_LE" << "-r" << "48000" << fullPath;

    recordProcess.start("arecord", arguments);

    ui->statusBox->appendPlainText("Started Recording in " + fullPath + "...");
    action = "Record";




}

void Recorder::on_stopButton_clicked()
{
    ui->recordButton->setEnabled(true);
    ui->playButton->setEnabled(true);
    ui->stopButton->setEnabled(false);

    ui->sentenceList->setEnabled(true);
    ui->nextButton->setEnabled(true);
    ui->previousButton->setEnabled(true);

    ui->statusBox->appendPlainText("Stopped " + action + "ing...");

    if (QString(action).compare("Record") == 0)
        recordProcess.close();
    else if (QString(action).compare("Play") == 0)
        playProcess.close();

    action = "Stop";


}

void Recorder::on_playButton_clicked()
{
    ui->playButton->setEnabled(false);
    ui->recordButton->setEnabled(false);
    ui->stopButton->setEnabled(true);

    ui->sentenceList->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->previousButton->setEnabled(false);

    int num = fileSuffix + currentSentence;

    QString fullPath = fileStoragePath + "/sample" + QString::number(num) + ".wav";

    QStringList arguments;
    arguments << fullPath;

    playProcess.start("aplay", arguments);

    ui->statusBox->appendPlainText("Playback started on " + fullPath + "...");
    action = "Play";

}

void Recorder::on_playProcess_finished(int exitCode)
{
    this->on_stopButton_clicked();
}
