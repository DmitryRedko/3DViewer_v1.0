/****************************************************************************
** Meta object code from reading C++ file 'mainviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../viewer/mainviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainViewer_t {
    QByteArrayData data[15];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainViewer_t qt_meta_stringdata_MainViewer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainViewer"
QT_MOC_LITERAL(1, 11, 24), // "on_rotate_x_valueChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_rotate_y_valueChanged"
QT_MOC_LITERAL(4, 62, 24), // "on_rotate_z_valueChanged"
QT_MOC_LITERAL(5, 87, 26), // "on_zoom_scale_valueChanged"
QT_MOC_LITERAL(6, 114, 22), // "on_move_x_valueChanged"
QT_MOC_LITERAL(7, 137, 22), // "on_move_y_valueChanged"
QT_MOC_LITERAL(8, 160, 22), // "on_move_z_valueChanged"
QT_MOC_LITERAL(9, 183, 23), // "on_reset_model_released"
QT_MOC_LITERAL(10, 207, 18), // "on_fileBtm_clicked"
QT_MOC_LITERAL(11, 226, 18), // "on_openBtm_clicked"
QT_MOC_LITERAL(12, 245, 32), // "on_point_size_scale_valueChanged"
QT_MOC_LITERAL(13, 278, 5), // "value"
QT_MOC_LITERAL(14, 284, 32) // "on_line_width_scale_valueChanged"

    },
    "MainViewer\0on_rotate_x_valueChanged\0"
    "\0on_rotate_y_valueChanged\0"
    "on_rotate_z_valueChanged\0"
    "on_zoom_scale_valueChanged\0"
    "on_move_x_valueChanged\0on_move_y_valueChanged\0"
    "on_move_z_valueChanged\0on_reset_model_released\0"
    "on_fileBtm_clicked\0on_openBtm_clicked\0"
    "on_point_size_scale_valueChanged\0value\0"
    "on_line_width_scale_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void MainViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_rotate_x_valueChanged(); break;
        case 1: _t->on_rotate_y_valueChanged(); break;
        case 2: _t->on_rotate_z_valueChanged(); break;
        case 3: _t->on_zoom_scale_valueChanged(); break;
        case 4: _t->on_move_x_valueChanged(); break;
        case 5: _t->on_move_y_valueChanged(); break;
        case 6: _t->on_move_z_valueChanged(); break;
        case 7: _t->on_reset_model_released(); break;
        case 8: _t->on_fileBtm_clicked(); break;
        case 9: _t->on_openBtm_clicked(); break;
        case 10: _t->on_point_size_scale_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_line_width_scale_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainViewer.data,
    qt_meta_data_MainViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainViewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
