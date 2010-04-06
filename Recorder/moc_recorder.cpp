/****************************************************************************
** Meta object code from reading C++ file 'recorder.h'
**
** Created: Sun Nov 22 13:40:04 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "recorder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Recorder[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      34,    9,    9,    9, 0x08,
      58,    9,    9,    9, 0x08,
      84,    9,    9,    9, 0x08,
     112,    9,    9,    9, 0x08,
     136,    9,    9,    9, 0x08,
     180,  175,    9,    9, 0x08,
     226,    9,    9,    9, 0x08,
     261,  252,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Recorder[] = {
    "Recorder\0\0on_playButton_clicked()\0"
    "on_stopButton_clicked()\0"
    "on_recordButton_clicked()\0"
    "on_previousButton_clicked()\0"
    "on_nextButton_clicked()\0"
    "on_sentenceList_itemSelectionChanged()\0"
    "item\0on_sentenceList_itemClicked(QListWidgetItem*)\0"
    "on_submitButton_clicked()\0exitCode\0"
    "on_playProcess_finished(int)\0"
};

const QMetaObject Recorder::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Recorder,
      qt_meta_data_Recorder, 0 }
};

const QMetaObject *Recorder::metaObject() const
{
    return &staticMetaObject;
}

void *Recorder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Recorder))
        return static_cast<void*>(const_cast< Recorder*>(this));
    return QWidget::qt_metacast(_clname);
}

int Recorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_playButton_clicked(); break;
        case 1: on_stopButton_clicked(); break;
        case 2: on_recordButton_clicked(); break;
        case 3: on_previousButton_clicked(); break;
        case 4: on_nextButton_clicked(); break;
        case 5: on_sentenceList_itemSelectionChanged(); break;
        case 6: on_sentenceList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: on_submitButton_clicked(); break;
        case 8: on_playProcess_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
