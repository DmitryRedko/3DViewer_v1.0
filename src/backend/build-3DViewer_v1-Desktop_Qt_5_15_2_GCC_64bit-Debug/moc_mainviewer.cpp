/****************************************************************************
** Meta object code from reading C++ file 'mainviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
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
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainViewer_t {
    QByteArrayData data[12];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainViewer_t qt_meta_stringdata_MainViewer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainViewer"
QT_MOC_LITERAL(1, 11, 15), // "updateLabelText"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "value"
QT_MOC_LITERAL(4, 34, 24), // "on_rotate_x_valueChanged"
QT_MOC_LITERAL(5, 59, 24), // "on_rotate_y_valueChanged"
QT_MOC_LITERAL(6, 84, 24), // "on_rotate_z_valueChanged"
QT_MOC_LITERAL(7, 109, 26), // "on_zoom_scale_valueChanged"
QT_MOC_LITERAL(8, 136, 22), // "on_move_x_valueChanged"
QT_MOC_LITERAL(9, 159, 22), // "on_move_y_valueChanged"
QT_MOC_LITERAL(10, 182, 22), // "on_move_z_valueChanged"
QT_MOC_LITERAL(11, 205, 23) // "on_reset_model_released"

    },
    "MainViewer\0updateLabelText\0\0value\0"
    "on_rotate_x_valueChanged\0"
    "on_rotate_y_valueChanged\0"
    "on_rotate_z_valueChanged\0"
    "on_zoom_scale_valueChanged\0"
    "on_move_x_valueChanged\0on_move_y_valueChanged\0"
    "on_move_z_valueChanged\0on_reset_model_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       8,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void MainViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLabelText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_rotate_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_rotate_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_rotate_z_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_zoom_scale_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_move_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_move_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_move_z_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_reset_model_released(); break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
