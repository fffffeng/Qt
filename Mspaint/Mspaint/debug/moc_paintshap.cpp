/****************************************************************************
** Meta object code from reading C++ file 'paintshap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../paintshap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintshap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PaintShap_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PaintShap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PaintShap_t qt_meta_stringdata_PaintShap = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PaintShap"
QT_MOC_LITERAL(1, 10, 14), // "SetCurrentShap"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "Shap::Number"
QT_MOC_LITERAL(4, 39, 8), // "num_shap"
QT_MOC_LITERAL(5, 48, 7), // "setSize"
QT_MOC_LITERAL(6, 56, 4), // "Size"
QT_MOC_LITERAL(7, 61, 9), // "setIsfill"
QT_MOC_LITERAL(8, 71, 1), // "b"
QT_MOC_LITERAL(9, 73, 9), // "setcolor1"
QT_MOC_LITERAL(10, 83, 15), // "Qt::GlobalColor"
QT_MOC_LITERAL(11, 99, 5), // "color"
QT_MOC_LITERAL(12, 105, 9) // "setcolor2"

    },
    "PaintShap\0SetCurrentShap\0\0Shap::Number\0"
    "num_shap\0setSize\0Size\0setIsfill\0b\0"
    "setcolor1\0Qt::GlobalColor\0color\0"
    "setcolor2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PaintShap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
      12,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void PaintShap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PaintShap *_t = static_cast<PaintShap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetCurrentShap((*reinterpret_cast< Shap::Number(*)>(_a[1]))); break;
        case 1: _t->setSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setIsfill((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setcolor1((*reinterpret_cast< Qt::GlobalColor(*)>(_a[1]))); break;
        case 4: _t->setcolor2((*reinterpret_cast< Qt::GlobalColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PaintShap::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PaintShap.data,
      qt_meta_data_PaintShap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PaintShap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaintShap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PaintShap.stringdata0))
        return static_cast<void*>(const_cast< PaintShap*>(this));
    return QWidget::qt_metacast(_clname);
}

int PaintShap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
